/*
	NovaCorps - PlayerMissileStandard.cpp
		William Chapman
		
		1/16/2019 4:51:31 AM

	This cpp file describes the properties of the PlayerMissileStandard class.

*/

//Include helper
#include "PlayerMissileStandard.h"

//Creates a blank PlayerMissileStandard
PlayerMissileStandard::PlayerMissileStandard() : Missile(nullptr, 3.f, 1)
{
	size(sf::Vector2f(15.f, 40.f));
}

void PlayerMissileStandard::update()
{
	
}


//Destructor
PlayerMissileStandard::~PlayerMissileStandard() = default;
