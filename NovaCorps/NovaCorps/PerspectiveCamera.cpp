/*
	NovaCorps - PerspectiveCamera.cpp
		William Chapman
		
		12/6/2018 1:40:13 PM

	This cpp file describes the PerspectiveCamera class.

*/

//Include helper
#include "PerspectiveCamera.h"

//Creates a blank PerspectiveCamera
PerspectiveCamera::PerspectiveCamera()
{
	//Set field of view to default
	m_fieldOfView = 70;
}

//Creates a Camera with just a RenderWindow
PerspectiveCamera::PerspectiveCamera(sf::RenderWindow& a_renderWindow) : Camera (a_renderWindow)
{
	//Set field of view to default
	m_fieldOfView = 70;
}

//Creates a Camera with a RenderWindow and a non-default field of view
PerspectiveCamera::PerspectiveCamera(sf::RenderWindow& a_renderWindow, float a_fieldOfView) : Camera(a_renderWindow)
{
	//Set field of view to the given argument
	m_fieldOfView = a_fieldOfView;
}

//Creates a Camera with a RenderWindow and a non-default position
PerspectiveCamera::PerspectiveCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition) : Camera (a_renderWindow)
{
	//Set field of view to default
	m_fieldOfView = 70;

	//Set position to given value
	setPosition(a_cameraPosition);
}

//Creates a Camera with a RenderWindow, a non-default position, and a non-default field of view
PerspectiveCamera::PerspectiveCamera(sf::RenderWindow& a_renderWindow, sf::Vector2f& a_cameraPosition, float a_fieldOfView) : Camera(a_renderWindow)
{
	//Set field of view to the given argument
	m_fieldOfView = a_fieldOfView;

	//Set position to given value
	setPosition(a_cameraPosition);
}

//Creates a Camera with a non-default field of view
PerspectiveCamera::PerspectiveCamera(float a_fieldOfView)
{
	//Set field of view to the given argument
	m_fieldOfView = a_fieldOfView;
}

//Creates a Camera with a non-default field of view and non-default position
PerspectiveCamera::PerspectiveCamera(float a_fieldOfView, sf::Vector2f& a_cameraPosition)
{
	//Set field of view to the given argument
	m_fieldOfView = a_fieldOfView;

	//Set position to given value
	setPosition(a_cameraPosition);
}

//Destructor
PerspectiveCamera::~PerspectiveCamera() = default;


//Will render a GameObject to the Camera's render window
void PerspectiveCamera::render(GameObject& a_object, bool a_drawToScreen)
{

}

//Will render a Particle system to the Camera's render window, as from the perspective of this Camera
void PerspectiveCamera::render(ParticleEmitter& a_object, bool a_drawToScreen)
{

}

//Setter and getter for Field of View of the Camera
float PerspectiveCamera::fieldOfView()
{
	return m_fieldOfView;
}
void PerspectiveCamera::fieldOfView(float a_fieldOfView)
{
	m_fieldOfView = a_fieldOfView;
}