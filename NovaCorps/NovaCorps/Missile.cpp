/*
	NovaCorps - Missile.cpp
		William Chapman
		
		11/20/2018 12:08:40 AM

	This cpp file describes the Missile class.

*/

//Include helper
#include "Missile.h"
#include <iostream>

//Creates a blank Missile and doesn't add it to GameObjects collection
Missile::Missile()
{
	m_lifetime = 5;
	m_damage = 5;
	m_exclusiveTarget = nullptr;
	m_creator = nullptr;
}

//Creates a blank Missile with a texture and doesn't add it to GameObjects collection
Missile::Missile(Animation* a_pNewAnimation)
{
	m_lifetime = 5;
	m_damage = 5;
	m_exclusiveTarget = nullptr;
	m_creator = nullptr;
}

//Creates a default Missile but with a defined creator
Missile::Missile(Animation* a_pNewAnimation, Character* a_newCreator) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = 5;
	m_damage = 5;
	m_exclusiveTarget = nullptr;
	m_creator = a_newCreator;
}

//Creates a default Missile but with a defined creator and exclusive target
Missile::Missile(Animation* a_pNewAnimation, Character* a_newCreator, Character* a_newExclusiveTarget) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = 5;
	m_damage = 5;
	m_exclusiveTarget = a_newExclusiveTarget;
	m_creator = a_newCreator;
	simulated(true);
}

//Creates a Missile with a defined damage amount
Missile::Missile(Animation* a_pNewAnimation, float a_newLifetime) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = a_newLifetime;
	m_damage = 5;
	m_exclusiveTarget = nullptr;
	m_creator = nullptr;
	simulated(true);
}

//Creates a Missile with a defined damage amount and lifetime
Missile::Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = a_newLifetime;
	m_damage = a_newDamage;
	m_exclusiveTarget = nullptr;
	m_creator = nullptr;
	simulated(true);
}


//Creates a Missile with a defined creator, damage stat, and lifetime
Missile::Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage, Character* a_newExclusiveTarget) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = a_newLifetime;
	m_damage = a_newDamage;
	m_exclusiveTarget = a_newExclusiveTarget;
	m_creator = nullptr;
	simulated(true);
}

//Creates a Missile with a defined creator, target, damage stat, and lifetime
Missile::Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage, Character* a_newCreator, Character* a_newExclusiveTarget) : GameObject(a_pNewAnimation, false)
{
	m_lifetime = a_newLifetime;
	m_damage = a_newDamage;
	m_exclusiveTarget = a_newExclusiveTarget;
	m_creator = a_newCreator;
	simulated(true);
}

//Destructor
Missile::~Missile() = default;


//This method fires the Missile, setting up its properties such as simulated, active, and setting the start time
void Missile::fire()
{
	//Start timer
	m_startTime = std::chrono::system_clock::now();

	//Enable missile
	active(true);
	simulated(true);
}

//This method detonates the Missile and subtracts health from its victim, then destroying itself
void Missile::detonate(Character* a_victim)
{
	//TODO: Animation then remove

	//Make target take damage
	if (a_victim != nullptr)
	{
		//std::cout << "Detonation " << a_victim->health();
		a_victim->health(a_victim->health() - m_damage);
		//std::cout << " to " << a_victim->health() << std::endl;
	}

	//Remove missile
	active(false);
	simulated(false);
}

//Virtual Update method tells Missile how to behave
void Missile::update(float a_deltaTime)
{
	if (m_lifetime < std::chrono::duration<float>(std::chrono::system_clock::now() - m_startTime).count())
	{
		detonate(nullptr);
		return;
	}

	//Faster to check against the exclusive target. != nullptr not technically necessary but it is stylistically preferred.
	if (m_exclusiveTarget != nullptr)
	{
		//TODO: dot/cross collision check with target.
		if (checkCollision(m_exclusiveTarget))
		{
			detonate(m_exclusiveTarget);
		}
	}
	else
	{
		//TODO: Go through all objects and do dot/cross
		/*
		
		foreach(character in arrayOfAllCharacters)
		{
			if (dot/cross magic of character == true)
			{
				detonate(character);
				break; //is this totally necessary if we just deleted ourselves?
			}
		}

		 */
	}
}


//Setter and getter for lifetime of Missile
float Missile::lifetime() const
{
	return m_lifetime;
}
void Missile::lifetime(float a_newLifetime)
{
	m_lifetime = a_newLifetime;
}

//Setter and getter for damage of Missile
int Missile::damage() const
{
	return m_damage;
}
void Missile::damage(int a_newDamage)
{
	m_damage = a_newDamage;
}

//Setter and getter for exclusive target of Missile
Character* Missile::exclusiveTarget() const
{
	return m_exclusiveTarget;
}
void Missile::exclusiveTarget(Character* a_newExclusiveTarget)
{
	m_exclusiveTarget = a_newExclusiveTarget;
}


//Setter and getter for exclusive target of Missile
Character* Missile::creator() const
{
	return m_creator;
}
void Missile::creator(Character* a_newCreator)
{
	m_creator = a_newCreator;
}

//Setter and getter for detonation texture of Missile
const char* Missile::detonationTexture() const
{
	return m_detonationTexture;
}
void Missile::detonationTexture(const char* a_newDetonationTexture)
{
	m_detonationTexture = a_newDetonationTexture;
}
