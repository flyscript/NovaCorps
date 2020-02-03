/*
	NovaCorps - AlienMissile.h
		William Chapman
		
		12/5/2018 11:13:22 AM

	This header file describes the AlienMissile class. Very empty other than the needed definition of a Player in the constructor.,

*/


#ifndef ALIEN_MISSILE_H

	#define ALIEN_MISSILE_H

	//Include any necessary files
	#include "Missile.h"
	#include "Player.h"

	class AlienMissile : public Missile
	{
		//Private members
		private:

		//Public members
		public:

			//Constructor
			AlienMissile();
			AlienMissile(Player* a_pPlayer, Animation* a_pNewAnimation);

			//Destructor
			virtual ~AlienMissile();

	};


#endif
