/*
	NovaCorps - Alien.cpp
		William Chapman
		
		16/11/2018 1:40:30 AM

	This cpp file describes the Alien class.
	This isn't concrete, and aliens will describe their own behaviours in their own classes.

*/

//Include helper
#include "Alien.h"
#include "r.h"

//Creates a blank Alien
Alien::Alien(Animation* a_pNewAnimation, int a_iNewHealth, int a_iNewPoints, float a_fNewFireRate, float a_fNewFireChance) :
Character(a_pNewAnimation, a_iNewHealth, a_fNewFireRate, a_iNewPoints), m_fFireChance(a_fNewFireChance)
{
}

//Destructor
Alien::~Alien() = default;

//Update
void Alien::update(float a_DeltaTime)
{
	//Bounce off walls
	if (position().x > 1920)
	{
		velocity(sf::Vector2f(-velocity().x, velocity().y));
		position(sf::Vector2f(1920, position().y));
	}
	else if (position().x < 0)
	{
		velocity(sf::Vector2f(-velocity().x, velocity().y));
		position(sf::Vector2f(0, position().y));
	}

	//Delete if gone past player or dead
	if (health() <= 0 || position().y > 1150 || position().y < -150)
	{
		//Deactivate, will be released by game loop
		active(false);

		//reset health to maximum
		health(lives());
	}
}
//Virtual fire method can be overriden, provides standard firing capability
bool Alien::fire()
{
	//TODO: in setup add all missiles to gameloop, but inactive
	//release all missiles so they can be used again

	//If not exceeding fire rate:
	if (active() && fireRate() < std::chrono::duration<float>(std::chrono::system_clock::now() - lastFire()).count()
		&& m_fFireChance > r::andom())
	{
		lastFire(std::chrono::system_clock::now());

		//std::cout << "Firing value [" << l_chance << "] was less than firing chance [" << m_fireChance << "], Firing." << std::endl;

		return true;
	}

	return false;
}

//Setter and getter for how likely the Alien is to fire
float Alien::fireChance() const
{
	return m_fFireChance;
}
void Alien::fireChance(float a_newFireChance)
{
	m_fFireChance = a_newFireChance;
}