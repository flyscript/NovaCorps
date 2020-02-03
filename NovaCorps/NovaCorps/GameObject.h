/*
	NovaCorps - GameObject.h
		William Chapman
		
		15/11/2018 20:35:07 AM

	This header file describes the non-concrete GameObject class that all GameObjects will inherit.
	This allows for size, position, velocity, update methods and various other common features.

	//TODO: rewrite code to return value& instead of value*
	   
*/

#ifndef GAME_OBJECT_H

	#define GAME_OBJECT_H

	//Include necessary files
	#include "ScreenElement2D.h"
	#include <SFML/System/Vector2.hpp>

	class GameObject : public ScreenElement2D
	{
		//Private members
		private:
			
			//Whether or not the object will have its physics simulated
			bool m_bSimulated;

			//The x, y velocity of the object
			sf::Vector2f m_vVelocity;
			
			//The rotational velocity of the object
			float m_fRotationalVelocity;

		//Public members
		public:

			//Constructor overloads
			GameObject();
			GameObject(Animation* a_pNewAnimation, bool a_bNewActive);
			GameObject(Animation* a_pNewAnimation, bool a_bNewActive, bool a_bNewSimulated);
			GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, bool a_bNewSimulated);
			GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, sf::Vector2f& a_vNewSize, bool a_bNewSimulated);
			GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, sf::Vector2f& a_vNewSize, float a_fNewRotation, bool a_bNewSimulated);
						
			//Destructor
			virtual ~GameObject();

			//Checks for a collision between this object and another. Returns false if self.
			bool checkCollision(GameObject* a_oOther, bool a_bNeedsActive = true);

			//Called to update position and rotation. Virtual to allow for override if you want to expand with your own special behaviours
			inline virtual void physicsUpdate(float a_fDeltaTime);
			
			//Virtual update method
			inline virtual void update(float a_fDeltaTime) override;

			//Called to render texture on the screen. Virtual to allow for override if you want to expand with your own special behaviours
			inline virtual void render() override;
			
			//Setter and getter for physics simulation of object
			bool simulated() const;
			void simulated(bool a_bNewSimulated);

			//Setter and getter for velocity of object
			sf::Vector2f velocity() const;
			void velocity(sf::Vector2f& a_vNewVelocity);

			//Setter and getter for rotational velocity of object
			float rotationalVelocity() const;
			void rotationalVelocity(float a_fNewRotationalVelocity);

	};


#endif
