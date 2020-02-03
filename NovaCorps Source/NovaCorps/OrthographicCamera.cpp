/*
	NovaCorps - OrthographicCamera.cpp
		William Chapman
		
		12/6/2018 1:40:00 PM

	This cpp file describes the OrthographicCamera class.

*/

//Include helper
#include "OrthographicCamera.h"
#include <iostream>

//Creates a blank PerspectiveCamera
OrthographicCamera::OrthographicCamera() :
Camera(), 
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
	
}

//Creates an OrthographicCamera with just a RenderWindow
OrthographicCamera::OrthographicCamera(sf::RenderWindow& a_renderWindow) :
Camera(a_renderWindow),
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
}

//Creates an OrthographicCamera with a RenderWindow and a non-default position
OrthographicCamera::OrthographicCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition) :
Camera(a_renderWindow, a_cameraPosition, sf::Vector2f(1920.f, 1080.f)),
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
}

//Creates an OrthographicCamera with a non-default size and a non-default position
OrthographicCamera::OrthographicCamera(sf::Vector2f& a_cameraSize, sf::RenderWindow& a_renderWindow) :
Camera(a_renderWindow),
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
	//Set camera size (stored in Transformable.scale) to given argument
	setScale(a_cameraSize);
}

//Creates an OrthographicCamera with a RenderWindow, a non-default size, and a non-default position
OrthographicCamera::OrthographicCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraSize, sf::Vector2f& a_cameraPosition, sf::Vector2f& a_cameraScale) :
Camera(a_renderWindow, a_cameraPosition, a_cameraScale),
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
	//Set camera size (stored in Transformable.scale) to given argument
	setScale(a_cameraSize);
}

//Creates an OrthographicCamera with a non-default size
OrthographicCamera::OrthographicCamera(sf::Vector2f& a_cameraSize) :
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
	//Set camera size (stored in Transformable.scale) to given argument
	setScale(a_cameraSize);
}

//Creates an OrthographicCamera with a non-default size and non-default position
OrthographicCamera::OrthographicCamera(sf::Vector2f& a_cameraSize, sf::Vector2f& a_cameraPosition, sf::Vector2f& a_cameraScale) :
Camera(a_cameraPosition, a_cameraScale),
m_pSprite(sprite()), m_pTextureMap(textureMap())
{
	//Set camera size (stored in Transformable.scale) to given argument
	setScale(a_cameraSize);
}

//Destructor
OrthographicCamera::~OrthographicCamera() = default;


//Will render a GameObject to the Camera's render window
inline void OrthographicCamera::render(GameObject& a_pObject, bool a_drawToScreen)
{
	//Get the texture
	m_pTextureIterator = m_pTextureMap->find(a_pObject.animation()->texture());

	if (m_pTextureIterator != m_pTextureMap->end())
	{
		//Apply texture
		m_pSprite->setTexture(m_pTextureIterator->second, true);

		//Set colour
		m_pSprite->setColor(a_pObject.colour());

		//Now set the origin of that sprite to the center of the sprite
		m_pSprite->setOrigin(m_pTextureIterator->second.getSize().x / 2.f, m_pTextureIterator->second.getSize().y / 2.f);

		//Scale the sprite based on its size and texture size, and the size of the camera
		if (a_pObject.positionUpdateNeeded())
		{
			a_pObject.renderPosition(
				(getScale() / 2.f) + sf::Vector2f((a_pObject.position().x - getPosition().x) * windowScale().x,
				(a_pObject.position().y - getPosition().y) * windowScale().y)
			);
		}
		m_pSprite->setPosition(a_pObject.renderPosition());

		if (a_drawToScreen)
		{
			m_pSprite->setScale(1.f, 1.f);
		}
		else //For worldspace
		{
			//Get difference between camera and object positions, add that to half the camera size to get relative position
			if (a_pObject.scaleUpdateNeeded())
			{
				a_pObject.renderScale(
					sf::Vector2f(windowScale().x*(a_pObject.size().x / m_pTextureIterator->second.getSize().x),
						windowScale().y*(a_pObject.size().y / m_pTextureIterator->second.getSize().y))
				);
			}
			m_pSprite->setScale(a_pObject.renderScale());
		}

		//Render the sprite
		renderWindow().draw(*m_pSprite, sf::RenderStates());
	}
}

//Will render a system of Particles to a given render window, as from the perspective of this Camera
inline void OrthographicCamera::render(ParticleEmitter& a_particleEmitter, bool a_drawToScreen)
{
	//Get the particles under the emitter's control
	m_pTextureIterator = m_pTextureMap->find(a_particleEmitter.animation()->texture());

	//If there are any particles (could also be l_numParticles > 0) and the texture exists
	if (m_pTextureIterator != m_pTextureMap->end() && getPosition().x && m_pTextureIterator->second.getSize().x && a_particleEmitter.getParticles(&m_iIterator)[0]->getPosition().x)
	{
		m_pParticles = a_particleEmitter.getParticles(&m_iIterator);

		//Set the scale for this particle //TODO: future expandability for particles to change size
		sf::Vector2f l_spriteScale(m_pParticles[0]->getScale().x / m_pTextureIterator->second.getSize().x, m_pParticles[0]->getScale().y / m_pTextureIterator->second.getSize().y);

		//Apply texture //TODO: future expandability for multiple textures 
		m_pSprite->setTexture(m_pTextureIterator->second, true);

		//Set colour
		m_pSprite->setColor(a_particleEmitter.colour());

		//Now set the origin of that sprite to the center of the sprite
		m_pSprite->setOrigin(m_pTextureIterator->second.getSize().x / 2.f, m_pTextureIterator->second.getSize().y / 2.f);

		if (a_drawToScreen)
		{
			//Scale the sprite to the particle's scale, as it's in screenspace
			m_pSprite->setScale(1.f, 1.f);

			for (m_iIterator; m_iIterator > -1; m_iIterator--)
			{
				//Set position of sprite to the actual position, as it's in screenspace
				m_pSprite->setPosition(m_pParticles[m_iIterator]->getPosition());


				//Render the sprite
				renderWindow().draw(*m_pSprite, sf::RenderStates());
			}
		}
		else
		{
			//Scale the sprite based on its size and texture size, and the size of the camera
			m_pSprite->setScale(windowScale().x*l_spriteScale.x, windowScale().y*l_spriteScale.y);

			for (m_iIterator; m_iIterator > -1; m_iIterator--)
			{
				//Get difference between camera and object positions, add that to half the camera size to get relative position
				m_pSprite->setPosition(
					(getScale() / 2.f) + 
					sf::Vector2f(
						(m_pParticles[m_iIterator]->getPosition().x - getPosition().x) * windowScale().x,
						(m_pParticles[m_iIterator]->getPosition().y - getPosition().y) * windowScale().y
					)
				);
								
				//Render the sprite
				renderWindow().draw(*m_pSprite, sf::RenderStates());
			}
		}
	}
}

//Will render a system of Particles to a given render window, as from the perspective of this Camera
inline void OrthographicCamera::render(Graphic& a_pGraphic)
{
	//Get the texture
	if (a_pGraphic.animation() != nullptr)
	{
		m_pTextureIterator = m_pTextureMap->find(a_pGraphic.animation()->texture());

		if (m_pTextureIterator != m_pTextureMap->end())
		{			
			//Apply texture
			m_pSprite->setTexture(m_pTextureIterator->second, true);

			//Now set the origin of that sprite to the center of the sprite
			m_pSprite->setOrigin(m_pTextureIterator->second.getSize().x / 2.f, m_pTextureIterator->second.getSize().y / 2.f);

			//Set colour
			m_pSprite->setColor(a_pGraphic.colour());
			
			//Scale the sprite to the graphic's scale
			if (a_pGraphic.scaleUpdateNeeded())
			{
				a_pGraphic.renderScale(
					sf::Vector2f(
						windowScale().x * (a_pGraphic.size().x / m_pTextureIterator->second.getSize().x),
						windowScale().y * (a_pGraphic.size().y / m_pTextureIterator->second.getSize().y))
				);
			}
			m_pSprite->setScale(a_pGraphic.renderScale());

			//Set position of sprite to the graphic's position
			if (a_pGraphic.positionUpdateNeeded())
			{
				a_pGraphic.renderPosition(
					sf::Vector2f(
						windowScale().x*a_pGraphic.position().x,
						windowScale().y*a_pGraphic.position().y)
				);
			}
			m_pSprite->setPosition(a_pGraphic.renderPosition());
			
			//Render the sprite
			renderWindow().draw(*m_pSprite, sf::RenderStates());
		}
	}
}