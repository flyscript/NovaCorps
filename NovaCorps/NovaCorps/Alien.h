/*
	NovaCorps - Alien.h
		William Chapman
		
		19/11/2018 1:40:30 AM

	This header file describes the Alien class.
	This isn't concrete, and aliens will describe their own behaviours in their own classes.

*/


#ifndef ALIEN_H

	#define ALIEN_H

	//Include any necessary files
	#include "Character.h"

// -----------------------------
	// Class name		: Alien
	// Description		: Individual Aliens will inherit from this
	//
	// Usage examples	:
	//
	//  class Marvin : public Alien
	//  {
	//  }
	//  
	// -----------------------------
	class Alien : public Character
	{
		//Private members
		private:

			//Chance alien has of firing
			float m_fFireChance;

		//Public members
		public:

			//Constructor overloads
			Alien(Animation* a_pNewAnimation, int a_iNewHealth, int a_iNewPoints, float a_fNewFireRate, float a_fNewFireChance);

			//Destructor
			virtual ~Alien();

			// -----------------------------
			// Function name: update
			// Description	: Virtual Update method overrides Character baseclass method with own behaviour
			// Parameters	: float a_DeltaTime
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			virtual void update(float a_DeltaTime) override;

			bool fire() override;

			//Setter and getter for how likely the Character is to fire
			float fireChance() const;
			void fireChance(float a_newFireChance);

	};


#endif
