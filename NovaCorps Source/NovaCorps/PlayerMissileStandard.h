/*
	NovaCorps - PlayerMissileStandard.h
		William Chapman
		
		1/16/2019 4:51:31 AM

	This header file describes the members of the PlayerMissileStandard class.

*/


#ifndef PlayerMissileStandard_h

	#define PlayerMissileStandard_h

	//Include any necessary files
	#include "Missile.h"

	class PlayerMissileStandard : public Missile
	{
		//Private members
		private:
			
		//Public members
		public:

			//Constructor overloads
			PlayerMissileStandard();

			//Destructor
			virtual ~PlayerMissileStandard();

			//Virtual Update method
			virtual void update();
		
	};


#endif
