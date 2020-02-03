/*
	NovaCorps - Player.h
		William Chapman

		20/11/2018 1:22:11 AM

	This header file describes the Player class.
	This concrete class should just be instantiated the once
	by the game and can be used to track the player's score lives, and other properties.

*/


#ifndef PLAYER_H

	#define PLAYER_H

	//Include any necessary files
	#include "Character.h"

	// -----------------------------
	// Class name		: PlayerMissile enum
	// Description		: An enum describing the types of missile the player can have
	//
	// Usage examples	:
	//
	//  if (player.missile() == PlayerMissile::standard)
	//		fireStandard();
	//  
	// -----------------------------
	enum class PlayerMissile{standard = 0, doublePower};

	class Player : public Character
	{
		//Private members
		private:
			
			//The current missile type
			PlayerMissile m_eMissile;

		//Public members
		public:

			//Constructor overloads
			Player();
			
			//Destructor
			virtual ~Player();

			//Virtual Update method override Character baseclass method
			virtual void update(float a_fDeltaTime) override;
			
			//Setter and getter for current missile type
			PlayerMissile missile() const;
			void missile(PlayerMissile a_eNewMissile);

	};


#endif
