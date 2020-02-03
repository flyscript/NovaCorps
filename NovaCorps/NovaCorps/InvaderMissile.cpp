/*
	NovaCorps - InvaderMissile.cpp
		William Chapman
		
		12/23/2018 2:17:47 PM

	This cpp file describes the InvaderMissile class.

*/

//Include helper
#include "InvaderMissile.h"

//Creates a blank InvaderMissile		//const char* a_texture, float a_newLifetime, int a_newDamage, Character& a_newExclusiveTarget
InvaderMissile::InvaderMissile() : AlienMissile(nullptr, nullptr)
{
	lifetime(5.f);
	size(sf::Vector2f(15.f, 15.f));
}

//Creates a blank InvaderMissile with a player		//const char* a_texture, float a_newLifetime, int a_newDamage, Character& a_newExclusiveTarget
InvaderMissile::InvaderMissile(Player* a_pPlayer) : AlienMissile(a_pPlayer, nullptr)
{
	lifetime(5.f);
	size(sf::Vector2f(15.f, 15.f));
}

//Destructor
InvaderMissile::~InvaderMissile() = default;