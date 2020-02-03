/*
	NovaCorps - Camera.h
		Will Chapman
		
		11/29/2018 3:47:03 PM

	This header file describes the non-concrete Camera class that other cameras will inherit from.

*/


#ifndef CAMERA_H

	#define CAMERA_H

	//Include any necessary files
	#include "GameObject.h"
	#include "Graphic.h"
	#include <map>
	#include "ParticleEmitter.h"
	#include <SFML/Graphics/RenderWindow.hpp>

	// -----------------------------
	// Class name		: Camera
	// Description		: Used as a control for rendering objects to the screen
	//
	// Usage examples	:
	//
	//  Camera cam(70.f, [RenderWindow]);
	//  
	//  cam.render([GameObject*]);
	//  
	// -----------------------------
	class Camera : public sf::Transformable
	{
		//Private members
		private:

			//The pointer to the window that the Camera will render to
			sf::RenderWindow* m_renderWindow;

			//The sprite that the camera will use for all renders
			sf::Sprite m_sprite;

			//The dictionary containing key/value pairs of image paths and their loaded textures
			std::map<const char*, sf::Texture> m_textureMap;

			//Used internally to control the size of the window versus the camera size
			sf::Vector2f m_windowScale;


			
		//Public members
		public:


			//Constructor overloads
			Camera();
			Camera(sf::RenderWindow& a_renderWindow);
			Camera(const sf::Vector2f& a_cameraPosition, const sf::Vector2f& a_cameraScale);
			Camera(sf::RenderWindow& a_renderWindow, const sf::Vector2f& a_cameraPosition, const sf::Vector2f& a_cameraScale);

			//Destructor
			virtual ~Camera();
			
			// -----------------------------
			// Function name: render
			// Description	: Will render an sf::Drawable to the Camera's render window
			// Parameters	: sf::Drawable* a_drawable
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline void render(sf::Drawable& a_pDrawable) const;

			// -----------------------------
			// Function name: render
			// Description	: Will render an sf::Drawable to a given render window, as from the perspective of this Camera
			// Parameters	: sf::Drawable* a_drawable, sf::RenderWindow* a_renderWindow
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline void render(sf::Drawable& a_pDrawable, sf::RenderWindow& a_pRenderWindow) const;

			// -----------------------------
			// Function name: render
			// Description	: Will render a GameObject to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: GameObject* a_object, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(GameObject& a_pObject, bool a_bDrawToScreen = false) = 0;
			
			// -----------------------------
			// Function name: render
			// Description	: Will render Particles to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: ParticleEmitter a_drawable, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(ParticleEmitter& a_pParticleEmitter, bool a_bDrawToScreen = false) = 0;
						
			// -----------------------------
			// Function name: render
			// Description	: Will render a Graphic to the Camera's render window
			// Parameters	: Graphic& a_pGraphic
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(Graphic& a_pGraphic) = 0;
						
			// -----------------------------
			// Function name: renderWindow
			// Description	: Getter for the RenderWindow the Camera will render to
			// Parameters	:
			//
			// Returns		: An sf::RenderWindow reference to the Camera's render window
			// See also		: 
			// -----------------------------
			sf::RenderWindow& renderWindow();

			// -----------------------------
			// Function name: renderWindow
			// Description	: Setter for the RenderWindow the Camera will render to
			// Parameters	: sf::RenderWindow* a_renderWindow
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void renderWindow(sf::RenderWindow& a_renderWindow);

			// -----------------------------
			// Function name: sprite
			// Description	: Getter for the sprite all Cameras will use for rendering
			// Parameters	:
			//
			// Returns		: An sf::RenderWindow reference to the Camera's render window
			// See also		: 
			// -----------------------------
			sf::Sprite* sprite();
			
			// -----------------------------
			// Function name: loadTexture
			// Description	: Will load a texture into the camera so that it can be rendered
			// Parameters	: const char* Path to the texture image
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadTexture(const char* a_texturePath);

			// -----------------------------
			// Function name: textureMap
			// Description	: Retrieves the texture map
			// Parameters	: const char* Path to the texture image
			//
			// Returns		: The map of textures
			// See also		: 
			// -----------------------------
			std::map<const char*, sf::Texture>* textureMap();

			void windowScale(float factorX, float factorY);
			void windowScale(const sf::Vector2f& factors);
			void windowScaleReset();
			void windowScaleReset(sf::RenderWindow& a_renderWindow);
			const sf::Vector2f& windowScale() const;
			

			/*inline virtual void shake(bool a_shake) = 0;
			inline virtual bool shake() = 0;

			inline virtual void shakeFactor(sf::Vector2f a_shakeFactor) = 0;
			inline virtual sf::Vector2f shakeFactor() = 0;*/
	};


#endif
