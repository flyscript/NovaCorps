/*
	NovaCorps - ParticleEmitter.h
		William Chapman
		
		12/26/2018 4:25:26 PM

	This header file describes the ParticleEmitter class.

*/


#ifndef PARTICLE_EMITTER_H

	#define PARTICLE_EMITTER_H

	#include <chrono>
	#include "GameObject.h"
	#include "Particle.h"
	#include "Pool.h"
	#include "SFML/Graphics/Drawable.hpp"
	#include "SFML/Graphics/Texture.hpp"
	#include "SFML/Graphics/RenderTarget.hpp"
	#include "SFML/Graphics/RenderStates.hpp"

//Include any necessary files

	class ParticleEmitter : public GameObject
	{
		//Private members
		private:

			//Describes the number of particles emitted every second
			float m_fEmissionRate;
			
			//The maximum number of particles that the emitter will control
			int m_iMaxParticles;

			//The maximum lifetime of particles
			float m_fLifeTime;

			//The maximum range of particles
			float m_fMaxRange;

			//Whether or not the particles will be affected by gravity
			bool m_bHasGravity;

			//Whether or not the emitter is currently emitting
			bool m_bEmitting;

			//Whether or not the emitter is currently being modified - stops conflicts and data races
			bool m_bBeingModified;

			//The time of the last emission and gaps between emissions
			std::chrono::time_point<std::chrono::system_clock> m_tLastEmission;

			//The direction that particles will move in
			sf::Vector2f m_vEmissionVelocity;

			//The particles
			Pool<Particle>* m_pParticles;

		//Public members
		public:

			//Constructor overloads
			ParticleEmitter();
			ParticleEmitter(Animation* a_pNewAnimation, bool a_newActive = false, bool a_newSimulated = false);
			ParticleEmitter(Animation* a_pNewAnimation, Particle& a_newParticle, bool a_newActive = false, bool a_newSimulated = false);

			//Destructor
			virtual ~ParticleEmitter();

			//Virtual Update method
			virtual void update(float a_deltaTime) override;
		
			//Access to particles
			Particle** getParticles(int* a_particleNum);

			//Scales the emission rate, max particles, lifetime, and velocity by a given factor
			bool scaleSpeed(float a_scale);

			//Getter and Setter for emission rate of ParticleEmitter
			float emissionRate() const;
			bool emissionRate(float a_newEmissionRate);

			//Getter and Setter for maximum particles of ParticleEmitter
			int maxParticles() const;
			bool maxParticles(int a_newMaxParticles);

			//Getter and Setter for lifetime of particles
			float lifeTime() const;
			bool lifeTime(float a_newLifeTime);

			//Getter and Setter for maximum range of particles
			float maxRange() const;
			bool maxRange(float a_newMaxRange);

			//Getter and Setter for if particles have gravity
			bool hasGravity() const;
			bool hasGravity(bool a_newHasGravity);

			//Getter and Setter for if particles are emitting
			bool emitting() const;
			bool emitting(bool a_newEmitting);

			//Getter and Setter for emission velocity of ParticleEmitter
			sf::Vector2f emissionVelocity() const;
			bool emissionVelocity(sf::Vector2f& a_newEmissionVelocity);

	};


#endif
