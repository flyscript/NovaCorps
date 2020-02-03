/*
	NovaCorps - Invader.h
		William Chapman
		
		12/12/2018 10:08:12 AM

	This header file describes the Invader class.

*/


#ifndef INVADER_H

	#define INVADER_H

	//Include any necessary files
	#include "Alien.h"

	class Invader : public Alien
	{
		//Private members
		private:
			
		//Public members
		public:

			//Constructor overloads
			Invader();

			//Destructor
			virtual ~Invader();

	};


#endif
