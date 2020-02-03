/*
	NovaCorps - Graphic.cpp
		William Chapman

		1/8/2019 12:12:42 AM

	This cpp file describes the Graphic class.

*/

//Include helper
#include "Graphic.h"
#include <SFML/Graphics/RenderWindow.hpp>

//Creates a blank Graphic that is inactive and has blank properties
Graphic::Graphic() :
	ScreenElement2D()
{
}

//Creates a Graphic with an animation and a custom active value
Graphic::Graphic(Animation* a_pNewAnimation, bool a_newActive) :
	ScreenElement2D(a_pNewAnimation, a_newActive)
{
}

//Creates a Graphic with an animation and a defined size
Graphic::Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize) :
	ScreenElement2D(a_pNewAnimation, true)
{
	rectSize(a_newSize, a_pRenderWindow);
}

//Creates a Graphic with an animation, and a defined size and position
Graphic::Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize, sf::FloatRect& a_newPosition) :
	ScreenElement2D(a_pNewAnimation, true)
{
	rectSize(a_newSize, a_pRenderWindow);
	rectPosition(a_newPosition, a_pRenderWindow);
}

//Creates a Graphic with an animation, and a defined size, position, and rotation
Graphic::Graphic(Animation* a_pNewAnimation, sf::RenderWindow* a_pRenderWindow, sf::FloatRect& a_newSize, sf::FloatRect& a_newPosition, float a_newRotation) :
	ScreenElement2D(a_pNewAnimation, true)
{
	rotation(a_newRotation);
	rectSize(a_newSize, a_pRenderWindow);
	rectPosition(a_newPosition, a_pRenderWindow);
}

//Destructor
Graphic::~Graphic() = default;

//Function empty by default
inline void Graphic::update(float a_deltaTime)
{

}

//Called to update position and rotation
inline void Graphic::render()
{
}

//Setter for size of Graphic
void Graphic::rectSize(sf::FloatRect& a_newSize, sf::RenderWindow* a_pRenderWindow, bool a_bSetUpdateNeeded)
{
	size(sf::Vector2f(
		((a_newSize.width*a_pRenderWindow->getSize().x)) + a_newSize.left,
		((a_newSize.height*a_pRenderWindow->getSize().y)) + a_newSize.top
	), a_bSetUpdateNeeded);
}

//Setter for position of Graphic
void Graphic::rectPosition(sf::FloatRect& a_newPosition, sf::RenderWindow* a_pRenderWindow, bool a_bSetUpdateNeeded)
{
	position(sf::Vector2f(
		((a_newPosition.width*a_pRenderWindow->getSize().x)) + a_newPosition.left,
		((a_newPosition.height*a_pRenderWindow->getSize().y)) + a_newPosition.top
	), a_bSetUpdateNeeded);
}

//TODO: make new missiles and invaders work
//TODO: make a couple waves
//TODO: Make settings
//TODO: make controls
//TODO: make quit
//TODO: find out memory leaks and why it errors on quit for some reason
//TODO: Stretch - Make sound manager.