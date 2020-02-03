/*
	NovaCorps - Missile.h
		William Chapman
		
		20/11/2018 12:08:40 AM

	This header file describes the concrete Missile class.
	Missile exist for only a certain time period and head straight in a certain direction,
	and will damage a character when hit. If an exclusive target is set then it won't damage anything else.

*/


#ifndef MISSILE_H

	#define MISSILE_H

	//Include any necessary files
	#include "GameObject.h"
	#include "Character.h"
	
	class Missile : public GameObject
	{
		//Private members
		private:

			//The maximum time the missile will live for in microseconds
			float m_lifetime;

			//The time the missile was fired
			std::chrono::time_point<std::chrono::system_clock> m_startTime;

			//The damage that this missile will do to its target
			int m_damage;

			//If set, this points to a target that it will exclusively damage
			class Character* m_exclusiveTarget;

			//This points towards the creator, so the missile won't accidentally damage it (if no exclusive target is set)
			class Character* m_creator;

			//The second texture used for animation 
			const char* m_texture2;

			//The texture to be displayed upon detonation
			const char* m_detonationTexture;

		//Public members
		public:

			//Constructor overloads
			Missile();
			Missile(Animation* a_pNewAnimation);
			Missile(Animation* a_pNewAnimation, Character* a_newCreator);
			Missile(Animation* a_pNewAnimation, Character* a_newCreator, Character* a_newExclusiveTarget);
			Missile(Animation* a_pNewAnimation, float a_newLifetime);
			Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage);
			Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage, Character* a_newExclusiveTarget);
			Missile(Animation* a_pNewAnimation, float a_newLifetime, int a_newDamage, Character* a_newCreator, Character* a_newExclusiveTarget);

			//Destructor
			virtual ~Missile();

			//This method fires the Missile, setting up its properties such as simulated, active, and setting the start time
			virtual void fire();

			//This method detonates the Missile and subtracts health from its victim, then destroying itself
			virtual void detonate(Character* a_victim);

			//Virtual Update method tells Missile how to behave
			virtual void update(float a_deltaTime) override;

			//Setter and getter for lifetime of Missile
			float lifetime() const;
			void lifetime(float a_newLifetime);

			//Setter and getter for damage of Missile
			int damage() const;
			void damage(int a_newDamage);

			//Setter and getter for exclusive target of Missile
			Character* exclusiveTarget() const;
			void exclusiveTarget(Character* a_newExclusiveTarget);

			//Setter and getter for exclusive target of Missile
			Character* creator() const;
			void creator(Character* a_newCreator);

			//Setter and getter for detonation texture of Missile
			const char* detonationTexture() const;
			void detonationTexture(const char* a_newDetonationTexture);

	};


#endif
