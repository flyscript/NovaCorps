/*
	NovaCorps - AlienMissile.cpp
		William Chapman
		
		12/5/2018 11:13:22 AM

	This cpp file describes the AlienMissile class.

*/

//Include helper
#include "AlienMissile.h"

//Creates an AlienMissile with a player
AlienMissile::AlienMissile() : Missile(nullptr, 10.f, 1)
{
	lifetime(10.f);
	damage(1);
}

//Creates an AlienMissile with a player
AlienMissile::AlienMissile(Player* a_player, Animation* a_pNewAnimation) : Missile(a_pNewAnimation, 10.f, 1, a_player)
{
	lifetime(10.f);
	damage(1);
	exclusiveTarget(a_player);
}

//Destructor
AlienMissile::~AlienMissile() = default;