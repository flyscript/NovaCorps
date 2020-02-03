/*
	NovaCorps - ScreenElement2D.h
		William Chapman
		
		1/8/2019 3:45:25 AM

	This header file describes the ScreenElement2D class.

*/


#ifndef SCREEN_ELEMENT_2D_H

	#define SCREEN_ELEMENT_2D_H

	//Include any necessary files
	#include "Animation.h"
	#include <SFML/Graphics/Color.hpp>
	#include <SFML/Graphics/RenderWindow.hpp>

	class ScreenElement2D
	{
		//Private members
		private:
			
			//Whether or not this element will be active in the scene
			bool m_bActive;

			//The x, y size of the object
			sf::Vector2f m_vSize;

			//The x, y position of the object
			sf::Vector2f m_vPosition;

			//The Animation for this element
			Animation* m_aAnimation;
			
			//The colour of the element
			sf::Color m_cColour;
						
			//The rotation of the element
			float m_fRotation;

			//Stores the scale of the sprite so it doesn't have to be calculated every frame
			sf::Vector2f m_vSpriteScale;

			//Stores the position of the sprite so it doesn't have to be calculated every frame
			sf::Vector2f m_vSpritePosition;

			//Whether or not the scale of the element needs to be updated next render
			bool m_bRenderScaleNeedsUpdating;

			//Whether or not the position of the element needs to be updated next render
			bool m_bRenderPositionNeedsUpdating;


		//Public members
		public:

			//Constructor overloads
			ScreenElement2D();
			ScreenElement2D(Animation* a_pNewAnimation, bool a_newActive);
			ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, bool a_newActive);
			ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, sf::Vector2f a_vNewPosition, bool a_newActive);
			ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, sf::Vector2f a_vNewPosition, bool a_newActive, float a_newRotation);

			//Destructor
			virtual ~ScreenElement2D();
			
			//Virtual update method. = 0 makes it non-concrete.
			virtual void update(float a_fDeltaTime) = 0;

			//Called before element is rendered to allow for any special behaviour
			virtual void render() = 0;
			
			//Setter and getter for animation of the element
			Animation* animation() const;
			void animation(Animation* a_pNewAnimation);

			//Setter and getter for colour of element - shifts colour of animation
			sf::Color colour() const;
			void colour(sf::Color& a_cNewColour);

			//Setter and getter for size of object
			sf::Vector2f size() const;
			void size(sf::Vector2f& a_vNewSize, bool a_bSetUpdateNeeded = true);

			//Setter and getter for position of object
			sf::Vector2f position() const;
			void position(sf::Vector2f& a_vNewPosition, bool a_bSetUpdateNeeded = true);

			//Setter and getter for whether element is to be shown in the scene
			bool active() const;
			void active(bool a_bNewActive);

			//Setter and getter for rotation of element
			float rotation() const;
			void rotation(float a_fNewRotation);

			//Setter and getter for render scalar
			sf::Vector2f renderScale() const;
			void renderScale(sf::Vector2f a_fNewScale);

			//Setter and getter for render position
			sf::Vector2f renderPosition() const;
			void renderPosition(sf::Vector2f a_fNewPosition);

			//Setter and getter for whether element is to be shown in the scene
			bool scaleUpdateNeeded() const;
			void scaleUpdateNeeded(bool a_bNewScaleNeeded);

			//Setter and getter for whether element is to be shown in the scene
			bool positionUpdateNeeded() const;
			void positionUpdateNeeded(bool a_bNewPositionNeeded);
	};


#endif
