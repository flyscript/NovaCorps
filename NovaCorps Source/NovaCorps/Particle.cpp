/*
	NovaCorps - Particle.cpp
		William Chapman
		
		12/26/2018 11:00:01 PM

	This cpp file describes the Particle class.

*/

//Include helper
#include "Particle.h"

//Creates a blank Particle
Particle::Particle()
{
	m_fLifeTime = 0;
}

//Destructor
Particle::~Particle() = default;


//Getter, resetter, and incrementer for lifetime of Particle
float Particle::getLifeTime() const
{
	return m_fLifeTime;
}
void Particle::addLifeTime(float a_newLifeTime)
{
	m_fLifeTime += a_newLifeTime;
}
void Particle::resetLifeTime()
{
	m_fLifeTime = 0.f;
}