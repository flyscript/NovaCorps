/*
	NovaCorps - InvaderMissile.h
		William Chapman
		
		12/23/2018 2:17:47 PM

	This header file describes the InvaderMissile class.

*/


#ifndef INVADER_MISSILE_

	#define INVADER_MISSILE_

	//Include any necessary files
	#include "AlienMissile.h"

class InvaderMissile : public AlienMissile
	{
		//Private members
		private:

		//Public members
		public:

			//Constructor overloads
			InvaderMissile();
			InvaderMissile(Player* a_pPlayer);

			//Destructor
			virtual ~InvaderMissile();
	};


#endif
