/*
	NovaCorps - Particle.h
		William Chapman
		
		12/26/2018 11:00:01 PM

	This header file describes the Particle class.

*/


#ifndef PARTICLE_H

	#define PARTICLE_H

	//Include any necessary files
	#include <SFML/Graphics/Sprite.hpp>

	class Particle : public sf::Transformable
	{
		//Private members
		private:

			//The time this particle has been alive
			float m_fLifeTime;

		//Public members
		public:

			//Constructor overloads
			Particle();

			//Destructor
			virtual ~Particle();
			
			//Getter, resetter, and Setter for lifetime of Particle
			float getLifeTime() const;
			void addLifeTime(float a_newLifeTime);
			void resetLifeTime();

	};


#endif
