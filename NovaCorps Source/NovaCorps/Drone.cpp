/*
	NovaCorps - Drone.cpp
		William Chapman
		
		1/7/2019 2:08:18 PM

	This cpp file describes the Drone class.

*/

//Include helper
#include "Drone.h"

//Creates a blank Drone
Drone::Drone() : 
	Alien(nullptr, 1, 10, 2.f, 0.0003f)
{
	fireDirection(sf::Vector2f(0.f, 400.f));
	fireFromOffset(sf::Vector2f(0.f, 35.f));
	size(sf::Vector2f(60.f, 60.f));
}

//Destructor
Drone::~Drone() = default;