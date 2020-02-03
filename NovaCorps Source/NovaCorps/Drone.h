/*
	NovaCorps - Drone.h
		William Chapman
		
		1/7/2019 2:08:18 PM

	This header file describes the Drone class.

*/


#ifndef DRONE_H

	#define DRONE_H

	//Include any necessary files
	#include "Alien.h"

	class Drone : public Alien
	{
		//Private members
		private:


		//Public members
		public:

			//Constructor overloads
			Drone();

			//Destructor
			virtual ~Drone();

	};


#endif
