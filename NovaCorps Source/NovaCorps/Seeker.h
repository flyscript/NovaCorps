/*
	NovaCorps - Seeker.h
		William Chapman
		
		1/7/2019 2:08:34 PM

	This header file describes the Seeker class.

*/


#ifndef SEEKER_H

	#define SEEKER_H

	//Include any necessary files
	#include "Alien.h"

	class Seeker : public Alien
	{
		//Private members
		private:
			
		//Public members
		public:

			//Constructor overloads
			Seeker();

			//Destructor
			virtual ~Seeker();
			
	};


#endif
