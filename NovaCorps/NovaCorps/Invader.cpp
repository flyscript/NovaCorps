/*
	NovaCorps - Invader.cpp
		William Chapman
		
		12/12/2018 10:08:12 AM

	This cpp file describes the Invader class.

*/

//Include helper
#include "Invader.h"

//Creates a blank Invader
Invader::Invader() :
	Alien(nullptr, 2, 10, 1.5f, 0.0006f)
{
	fireDirection(sf::Vector2f(0.f, 600.f));
	fireFromOffset(sf::Vector2f(0.f, 35.f));
	size(sf::Vector2f(60.f, 60.f));
}

//Destructor
Invader::~Invader() = default;