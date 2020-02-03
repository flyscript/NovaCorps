/*
	NovaCorps - GameObject.cpp
		William Chapman
		
		15/11/2018 20:35:07 AM

	This cpp file describes the non-concrete GameObject class.

*/

//TODO: Need to figure out how to integrate with SFML objects
//TODO: Look through getters and setters to see if any special updates need to be given to SFML texture when GameObject property is updated
//TODO: Boolean for getters that determines if you want to get the property of the raw SFML texture instead of the GAmeObject's value for accuracy?

//Include helper
#include "GameObject.h"

//Creates a blank GameObject that is inactive and non-simulated
GameObject::GameObject() :
	ScreenElement2D(nullptr, false),
	m_bSimulated(false), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Creates a GameObject that can have its activeAddresses variable defined
GameObject::GameObject(Animation* a_pNewAnimation, bool a_bNewActive) :
	ScreenElement2D(a_pNewAnimation, a_bNewActive),
	m_bSimulated(false), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Creates a GameObject with defined activeAddresses and simulated variables
GameObject::GameObject(Animation* a_pNewAnimation, bool a_bNewActive, bool a_bNewSimulated) :
	ScreenElement2D(a_pNewAnimation, a_bNewActive),
	m_bSimulated(a_bNewSimulated), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Creates a GameObject with defined simulated and position values, with activeAddresses set to true
GameObject::GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, bool a_bNewSimulated) :
	ScreenElement2D(a_pNewAnimation, sf::Vector2f(0.f, 0.f), a_vNewPosition, false),
	m_bSimulated(a_bNewSimulated), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Creates a GameObject with defined simulated and position values, with activeAddresses set to true
GameObject::GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, sf::Vector2f& a_vNewSize, bool a_bNewSimulated) :
	ScreenElement2D(a_pNewAnimation, a_vNewSize, a_vNewPosition, false),
	m_bSimulated(a_bNewSimulated), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Creates a GameObject with defined simulated, position, and rotation values, with activeAddresses set to true
GameObject::GameObject(Animation* a_pNewAnimation, sf::Vector2f& a_vNewPosition, sf::Vector2f& a_vNewSize, float a_fNewRotation, bool a_bNewSimulated) :
	ScreenElement2D(a_pNewAnimation, a_vNewSize, a_vNewPosition, false, a_fNewRotation),
	m_bSimulated(a_bNewSimulated), m_vVelocity(sf::Vector2f(0.f, 0.f)), m_fRotationalVelocity(0)
{
}

//Destructor
GameObject::~GameObject() = default;

//Checks for a collision between this object and another. Returns false if self.
bool GameObject::checkCollision(GameObject* a_oOther, bool a_bNeedsActive)
{
	//Setup properties for best practice and prevent jumping around in code to find reference
	const auto l_otherSize = a_oOther->size();
	const auto l_otherPos = a_oOther->position();

	//Check for a collision TODO: update to dot/cross logic
	return ((!a_bNeedsActive || (a_oOther->active() && active())) &&
		position().x - size().x / 2.f < l_otherPos.x + l_otherSize.x / 2.f && position().x + size().x / 2.f > l_otherPos.x - l_otherSize.x / 2.f &&
		position().y - size().y / 2.f < l_otherPos.y + l_otherSize.y / 2.f && position().y + size().y / 2.f > l_otherPos.y - l_otherSize.y / 2.f);

}

//Called to update position and rotation
inline void GameObject::physicsUpdate(float a_deltaTime)
{
	//Only simulate if it's set to do so
	if (active() && m_bSimulated)
	{
		position(position() + (m_vVelocity * a_deltaTime), m_vVelocity.x != 0 || m_vVelocity.y != 0);
		rotation(rotation() + (m_fRotationalVelocity * a_deltaTime));
	}
}

//Function empty by default
inline void GameObject::update(float a_deltaTime) 
{
	
}

//Called to update position and rotation
inline void GameObject::render()
{
}

//Setter and getter for physics simulation of object
bool GameObject::simulated() const
{
	return m_bSimulated;
}
void GameObject::simulated(bool a_bNewSimulated)
{
	m_bSimulated = a_bNewSimulated;
}

//Setter and getter for velocity of object
sf::Vector2f GameObject::velocity() const
{
	return m_vVelocity;
}
void GameObject::velocity(sf::Vector2f& a_vNewVelocity)
{
	m_vVelocity = a_vNewVelocity;
}

//Setter and getter for rotational velocity of object
float GameObject::rotationalVelocity() const
{
	return m_fRotationalVelocity;
}
void GameObject::rotationalVelocity(float a_newRotationalVelocity)
{
	m_fRotationalVelocity = a_newRotationalVelocity;
}