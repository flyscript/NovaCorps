/*
	NovaCorps - PerspectiveCamera.h
		William Chapman
		
		12/6/2018 1:40:13 PM

	This header file describes the PerspectiveCamera class.

*/


#ifndef PERSPECTIVE_CAMERA_H

	#define PERSPECTIVE_CAMERA_H

	//Include any necessary files
	#include "Camera.h"

	class PerspectiveCamera : public Camera
	{
		//Private members
		private:
			
			//The field of view of the Camera
			float m_fieldOfView;

		//Public members
		public:

			//Constructor overloads
			PerspectiveCamera();
			PerspectiveCamera(sf::RenderWindow& a_renderWindow);
			PerspectiveCamera(sf::RenderWindow& a_renderWindow, float a_fieldOfView);
			PerspectiveCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition);
			PerspectiveCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition, float a_fieldOfView);
			PerspectiveCamera(float a_fieldOfView);
			PerspectiveCamera(float a_fieldOfView, sf::Vector2f& a_cameraPosition);

			//Destructor
			virtual ~PerspectiveCamera();

			// -----------------------------
			// Function name: render
			// Description	: Will render a GameObject to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: GameObject* a_object, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(GameObject& a_object, bool a_drawToScreen = false) override;
			
			// -----------------------------
			// Function name: render
			// Description	: Will render Particles to the Camera's render window, in worldspace if drawToScreen is false
			// Parameters	: ParticleEmitter a_drawable, [bool drawToScreen = false]
			//
			// Returns		: 
			// See also		: Other render() methods
			// -----------------------------
			inline virtual void render(ParticleEmitter& a_particleEmitter, bool a_drawToScreen = false) override;
			
			// -----------------------------
			// Function name: fieldOfView
			// Description	: Getter for Field of View of the Camera
			// Parameters	:
			//
			// Returns		: A float representing the angular field of view of the camera
			// See also		: 
			// -----------------------------
			float fieldOfView();
			// -----------------------------
			// Function name: fieldOfView
			// Description	: Setter for Field of View of the Camera
			// Parameters	: float a_fieldOfView
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void fieldOfView(float a_fieldOfView);

	};


#endif
