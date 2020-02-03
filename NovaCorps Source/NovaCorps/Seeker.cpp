/*
	NovaCorps - Seeker.cpp
		William Chapman
		
		1/7/2019 2:08:34 PM

	This cpp file describes the Seeker class.

*/

//Include helper
#include "Seeker.h"

//Creates a blank Seeker
Seeker::Seeker() :
	Alien(nullptr, 3, 10, 5.f, 0.0001f)
{
	fireDirection(sf::Vector2f(0.f, 350.f));
	fireFromOffset(sf::Vector2f(0.f, 35.f));
	size(sf::Vector2f(60.f, 60.f));
}

//Destructor
Seeker::~Seeker() = default;