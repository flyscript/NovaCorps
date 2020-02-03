/*
	NovaCorps - Player.cpp
		William Chapman

		20/11/2018 1:22:11 AM

	This cpp file describes the Player class.
	This concrete class should just be instantiated the once
	by the game and can be used to track the player's score lives, and other properties.

*/

//Include helper
#include "Player.h"

//Creates the Player
Player::Player() :
	Character(nullptr, 3, 0.0f, 0)
{
	lives(3);
	fireFromOffset(sf::Vector2f(0.f, -80.f));
	missile(PlayerMissile::standard);
	size(sf::Vector2f(75.f, 75.f));
}

//Destructor
Player::~Player() = default;

//Update method
void Player::update(float a_fDeltaTime)
{

}

//Setter and getter for current missile of Player
PlayerMissile Player::missile() const
{
	return m_eMissile;
}
void Player::missile(PlayerMissile a_eNewMissile)
{
	m_eMissile = a_eNewMissile;
	switch (a_eNewMissile)
	{
	case PlayerMissile::standard:
		fireDirection(sf::Vector2f(0.f, -900.f));
		fireRate(0.2f);
		break;
	case PlayerMissile::doublePower:
		fireDirection(sf::Vector2f(0.f, -1750.f));
		fireRate(0.1f);
		break;

	}
}

