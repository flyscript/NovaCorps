/*
	NovaCorps - ParticleEmitter.cpp
		William Chapman
		
		12/26/2018 4:25:26 PM

	This cpp file describes the ParticleEmitter class.

*/

//Include helper
#include "ParticleEmitter.h"
#include "r.h"
#include <iostream>

//Creates a blank ParticleEmitter
ParticleEmitter::ParticleEmitter() :
	m_fEmissionRate(100), m_iMaxParticles(100), m_fLifeTime(2.f), m_fMaxRange(25.f), m_bHasGravity(false), m_bEmitting(false), m_bBeingModified(false),
	m_tLastEmission(std::chrono::system_clock::now()), m_vEmissionVelocity(sf::Vector2f(0.f, 1.f)), m_pParticles(new Pool<Particle>(m_iMaxParticles))
{
}

ParticleEmitter::ParticleEmitter(Animation* a_pNewAnimation, bool a_newActive, bool a_newSimulated) :
	GameObject(a_pNewAnimation, a_newActive, a_newSimulated),
	m_fEmissionRate(100), m_iMaxParticles(100), m_fLifeTime(2.f), m_fMaxRange(25.f), m_bHasGravity(false), m_bEmitting(false), m_bBeingModified(false),
	m_tLastEmission(std::chrono::system_clock::now()), m_vEmissionVelocity(sf::Vector2f(0.f, 1.f)), m_pParticles(new Pool<Particle>(m_iMaxParticles))
{
	
}

ParticleEmitter::ParticleEmitter(Animation* a_pNewAnimation, Particle& a_newParticle, bool a_newActive, bool a_newSimulated) :
	GameObject(a_pNewAnimation, a_newActive, a_newSimulated),
	m_fEmissionRate(100), m_iMaxParticles(100), m_fLifeTime(2.f), m_fMaxRange(25.f), m_bHasGravity(false), m_bEmitting(false), m_bBeingModified(false),
	m_tLastEmission(std::chrono::system_clock::now()), m_vEmissionVelocity(sf::Vector2f(0.f, 1.f)), m_pParticles(new Pool<Particle>(&a_newParticle, m_iMaxParticles))
{
}

//Destructor
ParticleEmitter::~ParticleEmitter()
{
	m_bBeingModified = true;
	delete m_pParticles;
};

//Updates the particles of the particle emitter
void ParticleEmitter::update(float a_deltaTime)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		//Eliminate particles that have exceeded their lifetime
		int l_numberParticles = 0;
		auto l_activeParticles = m_pParticles->activeAddresses(&l_numberParticles);

		if (l_activeParticles != nullptr)
		{
			for (int i = 0; i < l_numberParticles; i++)
			{
				//Update time
				l_activeParticles[i]->addLifeTime(a_deltaTime);

				//Update position and velocity
				//(sf::Vector2f(0.f, -9.81f) * static_cast<float>(m_bHasGravity))
				l_activeParticles[i]->setPosition(l_activeParticles[i]->getPosition() + (m_vEmissionVelocity * a_deltaTime));

				//std::cout << "Particle x: " << l_activeParticles[i]->getPosition().x << ", y: " << l_activeParticles[i]->getPosition().y << std::endl;

				//If particle has existed too long or is too far away
				if (l_activeParticles[i]->getLifeTime() > m_fLifeTime || (l_activeParticles[i]->getPosition().x*l_activeParticles[i]->getPosition().x + l_activeParticles[i]->getPosition().y*l_activeParticles[i]->getPosition().y) - (position().x*position().x + position().y*position().y) > m_fMaxRange)
				{
					l_activeParticles[i]->resetLifeTime();
					m_pParticles->release(l_activeParticles[i]);
				}
			}
		}

		if (m_bEmitting)
		{
			std::chrono::duration<float> l_emissionDelta = std::chrono::system_clock::now() - m_tLastEmission;
			int l_particlesToGenerate = static_cast<int>(m_fEmissionRate * l_emissionDelta.count());
			//if (l_particlesToGenerate != 0) std::cout << m_fEmissionRate << " Generating " << l_particlesToGenerate << " Particles" << std::endl;

			//generate appropriate number of particles
			for (int l_generate = 0; l_generate < l_particlesToGenerate && m_pParticles->activeCount() < m_iMaxParticles; l_generate++)
			{
				/*if (l_activeParticles != nullptr && m_pParticles->active() > 0)
				{
					std::cout << "Oldest Particle x: " << l_activeParticles[0]->getPosition().x << ", y: " << l_activeParticles[0]->getPosition().y << std::endl;

					std::cout << "Newest Particle x: " << l_activeParticles[m_pParticles->active() - 1]->getPosition().x << ", y: " << l_activeParticles[m_pParticles->active() - 1]->getPosition().y << std::endl;
				}*/

				Particle* l_particle = m_pParticles->getNext();
				l_particle->setPosition(position().x + r::andom(-size().x / 2.f, size().x / 2.f), position().y + r::andom(-size().y / 2.f, size().y / 2.f));

				m_tLastEmission = std::chrono::system_clock::now();
			}
		}

		m_bBeingModified = false;
	}
}

//Returns the particles and sets an int* to the number of them
Particle** ParticleEmitter::getParticles(int* a_particleNum)
{
	return m_pParticles->activeAddresses(a_particleNum);
}


//Scales the emission rate, max particles, lifetime, and velocity by a given factor
bool ParticleEmitter::scaleSpeed(float a_scale)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		//i.e: twice as fast, only needs to live half as long
		m_fLifeTime /= a_scale;
		int l_numberParticles = 0;
		auto l_activeParticles = m_pParticles->activeAddresses(&l_numberParticles);

		if (l_activeParticles != nullptr)
		{
			for (int i = 0; i < l_numberParticles; i++)
			{
				//Update time. I.e: twice as fast, particles have "lived" half as long to get there
				l_activeParticles[i]->addLifeTime(l_activeParticles[i]->getLifeTime()/a_scale - l_activeParticles[i]->getLifeTime());
			}
		}

		//i.e twice as fast, velocity is doubled
		m_vEmissionVelocity *= a_scale;

		//i.e twice as fast, needs twice as many per second
		m_fEmissionRate *= a_scale;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for emission rate of ParticleEmitter
float ParticleEmitter::emissionRate() const
{
	return 1.f / m_fEmissionRate;
}
bool ParticleEmitter::emissionRate(float a_newEmissionRate)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_fEmissionRate = a_newEmissionRate;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for maximum particles of ParticleEmitter
int ParticleEmitter::maxParticles() const
{
	return m_iMaxParticles;
}
bool ParticleEmitter::maxParticles(int a_newMaxParticles)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_pParticles->size(a_newMaxParticles);
		m_iMaxParticles = a_newMaxParticles;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for lifetime of particles
float ParticleEmitter::lifeTime() const
{
	return m_fLifeTime;
}
bool ParticleEmitter::lifeTime(float a_newLifeTime)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_fLifeTime = a_newLifeTime;

		m_bBeingModified = false;

		return true;
	}
		
	return false;
}

//Getter and Setter for maximum range of particles
//NOTE: Returns the square of the range
float ParticleEmitter::maxRange() const
{
	return m_fMaxRange;
}
bool ParticleEmitter::maxRange(float a_newMaxRange)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_fMaxRange = a_newMaxRange * a_newMaxRange;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for if particles have gravity
bool ParticleEmitter::hasGravity() const
{
	return m_bHasGravity;
}
bool ParticleEmitter::hasGravity(bool a_newHasGravity)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_bHasGravity = a_newHasGravity;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for if particles are emitting
bool ParticleEmitter::emitting() const
{
	return m_bEmitting;
}
bool ParticleEmitter::emitting(bool a_newEmitting)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_bEmitting = a_newEmitting;

		m_bBeingModified = false;

		return true;
	}

	return false;
}

//Getter and Setter for emission direction of ParticleEmitter
sf::Vector2f ParticleEmitter::emissionVelocity() const
{
	return m_vEmissionVelocity;
}
bool ParticleEmitter::emissionVelocity(sf::Vector2f& a_newEmissionVelocity)
{
	if (!m_bBeingModified)
	{
		m_bBeingModified = true;

		m_vEmissionVelocity = a_newEmissionVelocity;

		m_bBeingModified = false;

		return true;
	}

	return false;
}