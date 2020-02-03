/*
	NovaCorps - Camera.cpp
		Will Chapman
		
		11/29/2018 3:47:03 PM

	This cpp file describes the non-concrete Camera class that other cameras will inherit from.

*/

//Include helper
#include "Camera.h"
#include <iostream>

//Creates a blank Camera
Camera::Camera()
{
	//Set window Camera renders to default
	m_renderWindow = nullptr;
}

Camera::Camera(sf::RenderWindow& a_renderWindow)
{
	//Set window Camera renders to the given argument
	m_renderWindow = &a_renderWindow;

	//Set the Camera scale to the default
	setScale(static_cast<float>(a_renderWindow.getSize().x), static_cast<float>(a_renderWindow.getSize().y));
	setOrigin(getScale() / 2.f);
	windowScaleReset();
}

Camera::Camera(const sf::Vector2f& a_cameraPosition, const sf::Vector2f& a_cameraScale)
{
	//Set position of the Camera to the given argument
	setPosition(a_cameraPosition);

	//Set window Camera renders to the given argument
	m_renderWindow = nullptr;

	//Set the Camera scale to the given argument
	setScale(a_cameraScale);
	setOrigin(getScale() / 2.f);
	windowScaleReset();
}

Camera::Camera(sf::RenderWindow& a_renderWindow, const sf::Vector2f& a_cameraPosition, const sf::Vector2f& a_cameraScale)
{
	//Set position of the Camera to the given argument
	setPosition(a_cameraPosition);

	//Set window Camera renders to the given argument
	m_renderWindow = &a_renderWindow;

	//Set the Camera scale to the given argument
	setScale(a_cameraScale);
	setOrigin(getScale() / 2.f);
	windowScaleReset();
}

//Destructor
Camera::~Camera() = default;

//Will render an sf::Drawable to the Camera's render window
inline void Camera::render(sf::Drawable& a_drawable) const
{
	m_renderWindow->draw(a_drawable, sf::RenderStates());
}

//Will render an sf::Drawable to a given render window, as from the perspective of this Camera
inline void Camera::render(sf::Drawable& a_drawable, sf::RenderWindow& a_renderWindow) const
{
	a_renderWindow.draw(a_drawable, sf::RenderStates());
}

//Setter and getter for the RenderWindow the Camera will render to
sf::RenderWindow& Camera::renderWindow()
{
	return *m_renderWindow;
}
void Camera::renderWindow(sf::RenderWindow& a_renderWindow)
{
	m_renderWindow = &a_renderWindow;
}

//Getter for the sprite all Cameras will use for rendering
sf::Sprite* Camera::sprite()
{
	return &m_sprite;
}

//loads a texture into the camera so that it can be rendered
void Camera::loadTexture(const char* a_texturePath)
{
	//std::cout << "Attempting to load ''" << a_texturePath << "''" << std::endl;

	auto const l_iterator = m_textureMap.find(a_texturePath);
	if (l_iterator == m_textureMap.end())
	{
		sf::Texture l_newTexture;
		if (l_newTexture.loadFromFile(a_texturePath))
		{
			m_textureMap[a_texturePath] = l_newTexture;
			//std::cout << "Loaded ''" << a_texturePath << "''" << std::endl;
		}
		else
		{
			//std::cout << "Failed to load ''" << a_texturePath << "''" << std::endl;
		}
	}
	else
	{
		//std::cout << "''" << a_texturePath << "'' was already loaded" << std::endl;
	}
}

//Return the texture map - can't be const otherwise will not return the same instance of m_textureMap, which is needed for iterators
std::map<const char*, sf::Texture>* Camera::textureMap()
{
	return &m_textureMap;
}

void Camera::windowScale(float a_factorX, float a_factorY)
{
	m_windowScale = sf::Vector2f(a_factorX, a_factorY);
}
void Camera::windowScale(const sf::Vector2f& a_factors)
{
	m_windowScale = a_factors;
}
void Camera::windowScaleReset()
{
	m_windowScale = sf::Vector2f(m_renderWindow->getSize().x / getScale().x, m_renderWindow->getSize().y / getScale().y);
}
void Camera::windowScaleReset(sf::RenderWindow& a_renderWindow)
{
	m_windowScale = sf::Vector2f(a_renderWindow.getSize().x / getScale().x, a_renderWindow.getSize().y / getScale().y);
}
const sf::Vector2f& Camera::windowScale() const
{
	return m_windowScale;
}

