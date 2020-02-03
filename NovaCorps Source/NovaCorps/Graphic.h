/*
	NovaCorps - Graphic.h
		William Chapman
		
		1/8/2019 12:12:42 AM

	This header file describes the Graphic class.

*/


#ifndef GRAPHIC_H

	#define GRAPHIC_H

	//Include any necessary files
	#include "ScreenElement2D.h"
	#include <SFML/Graphics/Rect.hpp>

	class Graphic : public ScreenElement2D
	{
		//Private members
		private:
			
		//Public members
		public:

			//Constructor overloads
			Graphic();
			Graphic(Animation* a_pNewAnimation, bool a_newActive);
			Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize);
			Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize, sf::FloatRect& a_newPosition);
			Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize, sf::FloatRect& a_newPosition, float a_newRotation);

			//Destructor
			virtual ~Graphic();
			
			//Virtual update method
			inline virtual void update(float a_fDeltaTime) override;

			//Called to render texture on the screen. Virtual to allow for override if you want to expand with your own special behaviours
			inline virtual void render() override;
			
			//Setter and getter for position of texture - don't have to interface with SFML transformable
			void rectSize(sf::FloatRect& a_newSize, sf::RenderWindow* a_pRenderWindow, bool a_bSetUpdateNeeded = true);

			//Setter and getter for position of texture - don't have to interface with SFML transformable
			void rectPosition(sf::FloatRect& a_newPosition, sf::RenderWindow* a_pRenderWindow, bool a_bSetUpdateNeeded = true);

	};


#endif
