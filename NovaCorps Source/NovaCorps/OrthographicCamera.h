/*
	NovaCorps - OrthographicCamera.h
		William Chapman
		
		12/6/2018 1:40:00 PM

	This header file describes the OrthographicCamera class.

*/


#ifndef ORTHOGRAPHIC_CAMERA_H

	#define ORTHOGRAPHIC_CAMERA_H

	//Include any necessary files
	#include "Camera.h"

	class OrthographicCamera : public Camera
	{
		//Private members
		private:

			//Own pointer to the sprite
			sf::Sprite* m_pSprite;

			//Own pointer to the texture map
			std::map<const char*, sf::Texture>* m_pTextureMap;

			//Store iterators so we don't need to set aside memory each time
			int m_iIterator;
			std::map<const char*, sf::Texture>::iterator m_pTextureIterator;
			Particle** m_pParticles;
			
		//Public members
		public:

			//Constructor overloads
			OrthographicCamera();
			OrthographicCamera(sf::RenderWindow& a_renderWindow);
			OrthographicCamera(sf::Vector2f& a_cameraSize, sf::RenderWindow& a_renderWindow);
			OrthographicCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition);
			OrthographicCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraSize, sf::Vector2f& a_cameraPosition, sf::Vector2f& a_cameraScale);
			OrthographicCamera(sf::Vector2f& a_cameraSize);
			OrthographicCamera(sf::Vector2f& a_cameraSize, sf::Vector2f& a_cameraPosition, sf::Vector2f& a_cameraScale);

			//Destructor
			virtual ~OrthographicCamera();

			// -----------------------------
			// Function name: render
			// Description	: Will render a GameObject to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: GameObject* a_object, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(GameObject& a_object, bool a_bDrawToScreen = false) override;

			// -----------------------------
			// Function name: render
			// Description	: Will render Particles to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: ParticleEmitter a_drawable, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(ParticleEmitter& a_pParticleEmitter, bool a_bDrawToScreen = false) override;

			// -----------------------------
			// Function name: render
			// Description	: Will render a Graphic to the Camera's render window
			// Parameters	: Graphic& a_pGraphic
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(Graphic& a_pGraphic) override;

	};


#endif
