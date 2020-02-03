/*
	NovaCorps - ScreenElement2D.cpp
		William Chapman
		
		1/8/2019 3:45:25 AM

	This cpp file describes the ScreenElement2D class.

*/

//Include helper
#include "ScreenElement2D.h"

//Creates a blank ScreenElement2D
ScreenElement2D::ScreenElement2D() :
	m_bActive(false), m_vSize(sf::Vector2f(0.f, 0.f)), m_vPosition(sf::Vector2f(0.f, 0.f)),	m_aAnimation(nullptr), m_cColour(sf::Color::White),
	m_fRotation(0), m_vSpriteScale(sf::Vector2f(1.f, 1.f)), m_vSpritePosition(sf::Vector2f(1.f, 1.f)), m_bRenderScaleNeedsUpdating(true), m_bRenderPositionNeedsUpdating(true)
{
	
}

ScreenElement2D::ScreenElement2D(Animation* a_pNewAnimation, bool a_newActive) :
	m_bActive(a_newActive), m_vSize(sf::Vector2f(0.f, 0.f)), m_vPosition(sf::Vector2f(0.f, 0.f)), m_aAnimation(a_pNewAnimation), m_cColour(sf::Color::White),
	m_fRotation(0), m_vSpriteScale(sf::Vector2f(1.f, 1.f)), m_vSpritePosition(sf::Vector2f(1.f, 1.f)), m_bRenderScaleNeedsUpdating(true), m_bRenderPositionNeedsUpdating(true)
{

}

ScreenElement2D::ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, bool a_newActive) :
	m_bActive(a_newActive), m_vSize(a_vNewSize), m_vPosition(sf::Vector2f(0.f, 0.f)), m_aAnimation(a_pNewAnimation), m_cColour(sf::Color::White), m_fRotation(0),
	m_vSpriteScale(sf::Vector2f(1.f, 1.f)), m_vSpritePosition(sf::Vector2f(1.f, 1.f)), m_bRenderScaleNeedsUpdating(true), m_bRenderPositionNeedsUpdating(true)
{

}

ScreenElement2D::ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, sf::Vector2f a_vNewPosition, bool a_newActive) :
	m_bActive(a_newActive), m_vSize(a_vNewSize), m_vPosition(a_vNewPosition), m_aAnimation(a_pNewAnimation), m_cColour(sf::Color::White), m_fRotation(0),
	m_vSpriteScale(sf::Vector2f(1.f, 1.f)), m_vSpritePosition(sf::Vector2f(1.f, 1.f)), m_bRenderScaleNeedsUpdating(true), m_bRenderPositionNeedsUpdating(true)
{

}

ScreenElement2D::ScreenElement2D(Animation* a_pNewAnimation, sf::Vector2f a_vNewSize, sf::Vector2f a_vNewPosition, bool a_newActive, float a_newRotation) :
	m_bActive(a_newActive), m_vSize(a_vNewSize), m_vPosition(a_vNewPosition), m_aAnimation(a_pNewAnimation), m_cColour(sf::Color::White), m_fRotation(a_newRotation),
	m_vSpriteScale(sf::Vector2f(1.f, 1.f)), m_vSpritePosition(sf::Vector2f(1.f, 1.f)), m_bRenderScaleNeedsUpdating(true), m_bRenderPositionNeedsUpdating(true)
{

}

//Destructor
ScreenElement2D::~ScreenElement2D() = default;

//Setter and getter for whether texture is to be shown in scene
bool ScreenElement2D::active() const
{
	return m_bActive;
}
void ScreenElement2D::active(bool a_bNewActive)
{
	m_bActive = a_bNewActive;
}

//Setter and getter for SFML texture of ScreenElement2D
Animation* ScreenElement2D::animation() const
{
	return m_aAnimation;
}

void ScreenElement2D::animation(Animation* a_pNewAnimation)
{
	m_aAnimation = a_pNewAnimation;
}

//Setter and getter for SFML colour of ScreenElement2D
sf::Color ScreenElement2D::colour() const
{
	return m_cColour;
}
void ScreenElement2D::colour(sf::Color& a_cNewColour)
{
	m_cColour = a_cNewColour;
}
//Setter and getter for size of object
sf::Vector2f ScreenElement2D::size() const
{
	return m_vSize;
}
void ScreenElement2D::size(sf::Vector2f& a_vNewSize, bool a_bSetUpdateNeeded)
{
	scaleUpdateNeeded(a_bSetUpdateNeeded);
	m_vSize = a_vNewSize;
}

//Setter and getter for position of object
sf::Vector2f ScreenElement2D::position() const
{
	return m_vPosition;
}
void ScreenElement2D::position(sf::Vector2f& a_vNewPosition, bool a_bSetUpdateNeeded)
{
	positionUpdateNeeded(a_bSetUpdateNeeded);
	m_vPosition = a_vNewPosition;
}

//Setter and getter for rotation of texture
float ScreenElement2D::rotation() const
{
	return m_fRotation;
}
void ScreenElement2D::rotation(float a_fNewRotation)
{
	m_fRotation = a_fNewRotation;
}

//Setter and getter for render scale
sf::Vector2f ScreenElement2D::renderScale() const
{
	return m_vSpriteScale;
}
void ScreenElement2D::renderScale(sf::Vector2f a_fNewScale)
{
	m_vSpriteScale = a_fNewScale;
	m_bRenderScaleNeedsUpdating = false;
}

//Setter and getter for render position
sf::Vector2f ScreenElement2D::renderPosition() const
{
	return m_vSpritePosition;
}
void ScreenElement2D::renderPosition(sf::Vector2f a_fNewPosition)
{
	m_vSpritePosition = a_fNewPosition;
	m_bRenderPositionNeedsUpdating = false;
}

bool ScreenElement2D::positionUpdateNeeded() const
{
	return m_bRenderPositionNeedsUpdating;
}
void ScreenElement2D::positionUpdateNeeded(bool a_bNewPositionNeeded)
{
	m_bRenderPositionNeedsUpdating = a_bNewPositionNeeded;
}

bool ScreenElement2D::scaleUpdateNeeded() const
{
	return m_bRenderScaleNeedsUpdating;
}
void ScreenElement2D::scaleUpdateNeeded(bool a_bNewPositionNeeded)
{
	m_bRenderScaleNeedsUpdating = a_bNewPositionNeeded;
}
