/*
	NovaCorps - Character.h
		William Chapman
		
		20/11/2018 12:04:56 AM

	This header file describes the Character class, which inherits from GameObject.
	This is not an abstract class, so actual characters don't have to design their own class inheriting
	from this one, if it would be more efficient to instantiate a Character as a one-off or something.

*/


#ifndef CHARACTER_H

	#define CHARACTER_H

	//Include any necessary files
	#include <chrono>
	#include "GameObject.h"

	//enum class MissileType { none = 0, player, drone, invader, seeker };

	// -----------------------------
	// Class name		: Character
	// Description		: A class of GameObject that can me killed or interacted with by the player
	//
	// Usage examples	:
	//
	//  Character myChar();
	//  
	//  myChar.points(50);
	//	myChar.fire();
	//  
	// -----------------------------
	class Character : public GameObject
	{
		//Private members
		private:

			//The points that killing this Character is worth - or how many points the player has collected
			int m_iPoints;

			//How much health this Character has
			int m_iHealth;

			//The number of lives that the Character has
			int m_iLives;
			
			//The maximum rate of fire that this Character has
			float m_fFireRate;
			
			//This will help determine whether or not the character is firing and provide a way of tracking the firerate
			std::chrono::time_point<std::chrono::system_clock> m_tLastFire;
			
			//The offset from the centre of the character from where missiles fire
			sf::Vector2f m_fireFromOffset;

			//The direction and speed of the Character's fire
			sf::Vector2f m_fireDirection;


		//Public members
		public:

			//Constructor overloads
			Character();
			Character(Animation* a_pNewAnimation, int a_iNewHealth, float a_fNewFireRate);
			Character(Animation* a_pNewAnimation, int a_iNewHealth, float a_fNewFireRate, int a_iNewPoints);

			//Destructor
			virtual ~Character();
			
			//Virtual fire method can be overriden, provides standard firing capability, returns true if fired successfully
			virtual bool fire();

			//Setter and getter for points of Character
			int points() const;
			void points(bool a_newPoints);

			//Setter and getter for last fire
			std::chrono::time_point<std::chrono::system_clock> lastFire() const;
			void lastFire(std::chrono::time_point<std::chrono::system_clock> a_newLastFire);

			//Setter and getter for health of Character
			int health() const;
			void health(int a_newHealth);

			//Setter and getter for number of lives that the Character has
			int lives() const;
			void lives(int a_iNewLives);

			//Setter and getter for how quickly the Character can fire
			float fireRate() const;
			void fireRate(float a_newFireRate);

			//Setter and getter for offset Character fires from
			sf::Vector2f fireFromOffset() const;
			void fireFromOffset(sf::Vector2f& a_newFireFromOffset);

			//Setter and getter for direction Character fires in
			sf::Vector2f fireDirection() const;
			void fireDirection(sf::Vector2f& a_newFireDirection);

	};


#endif
