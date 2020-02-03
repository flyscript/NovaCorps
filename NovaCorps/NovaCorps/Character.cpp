/*
	NovaCorps - Character.cpp
		William Chapman
		
		11/20/2018 12:04:56 AM

	This cpp file describes the Character class, which inherits from GameObject.
	This is NOT non-concrete, so actual characters don't have to design their own class inheriting from this one,
	if it would be more efficient to instantiate a Character as a one-off or something.

*/

//Include helper
#include "Character.h"

//Creates a blank character
Character::Character() :
	GameObject(nullptr, sf::Vector2f(0.f,0.f), sf::Vector2f(0.f, 0.f), 0.f, true),
	m_iPoints(0), m_iHealth(0), m_iLives(0), m_fFireRate(0.f),
	m_tLastFire(std::chrono::system_clock::now()), m_fireFromOffset(sf::Vector2f(0.f, 0.f)), m_fireDirection(sf::Vector2f(0.f, 0.f))
{
}

//Creates a Character with a texture, health, and firerate property
Character::Character(Animation* a_pNewAnimation, int a_iNewHealth, float a_fNewFireRate) :
	GameObject(a_pNewAnimation, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f, true),
	m_iPoints(0), m_iHealth(a_iNewHealth), m_iLives(a_iNewHealth), m_fFireRate(a_fNewFireRate),
	m_tLastFire(std::chrono::system_clock::now()), m_fireFromOffset(sf::Vector2f(0.f, 0.f)), m_fireDirection(sf::Vector2f(0.f, 0.f))
{
}

//Creates a Character with a texture, health, and firerate property
Character::Character(Animation* a_pNewAnimation, int a_iNewHealth, float a_fNewFireRate, int a_iNewPoints) :
	GameObject(a_pNewAnimation, sf::Vector2f(0.f, 0.f), sf::Vector2f(0.f, 0.f), 0.f, true),
	m_iPoints(a_iNewPoints), m_iHealth(a_iNewHealth), m_iLives(a_iNewHealth), m_fFireRate(a_fNewFireRate),
	m_tLastFire(std::chrono::system_clock::now()), m_fireFromOffset(sf::Vector2f(0.f, 0.f)), m_fireDirection(sf::Vector2f(0.f, 0.f))
{
}

//Destructor
Character::~Character()
{
	
};

//Virtual fire method can be overriden, provides standard firing capability
bool Character::fire()
{
	//TODO: in setup add all missiles to gameloop, but inactive
	//release all missiles so they can be used again

	//If not exceeding fire rate:
	if (active() && m_fFireRate < std::chrono::duration<float>(std::chrono::system_clock::now() - m_tLastFire).count())
	{
		m_tLastFire = std::chrono::system_clock::now();

		//std::cout << "Firing value [" << l_chance << "] was less than firing chance [" << m_fireChance << "], Firing." << std::endl;

		return true;
	}

	return false;
}

//Setter and getter for points that killing this Character is worth - or how many points the player has collected
int Character::points() const
{
	return m_iPoints;
}
void Character::points(bool a_newPoints)
{
	m_iPoints = a_newPoints;
}

//Setter and getter for last fire
std::chrono::time_point<std::chrono::system_clock> Character::lastFire() const
{
	return m_tLastFire;
}
void Character::lastFire(std::chrono::time_point<std::chrono::system_clock> a_newLastFire)
{
	m_tLastFire = a_newLastFire;
}



//Setter and getter for health of Character
int Character::health() const
{
	return m_iHealth;
}
void Character::health(int a_newHealth)
{
	m_iHealth = a_newHealth;
}

//Setter and getter for lives of Character
int Character::lives() const
{
	return m_iLives;
}
void Character::lives(int a_newLives)
{
	m_iLives = a_newLives;
}

//Setter and getter for how quickly the Character can fire
float Character::fireRate() const
{
	return m_fFireRate;
}
void Character::fireRate(float a_newFireRate)
{
	m_fFireRate = a_newFireRate;
}

//Setter and getter for offset Character fires from
sf::Vector2f Character::fireFromOffset() const
{
	return m_fireFromOffset;
}
void Character::fireFromOffset(sf::Vector2f& a_newFireFromOffset)
{
	m_fireFromOffset = a_newFireFromOffset;
}
//Setter and getter for direction Character fires in
sf::Vector2f Character::fireDirection() const
{
	return m_fireDirection;
}
void Character::fireDirection(sf::Vector2f& a_newFireDirection)
{
	m_fireDirection = a_newFireDirection;
}