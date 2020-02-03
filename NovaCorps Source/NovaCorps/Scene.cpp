/*
	NovaCorps - Scene.cpp
		William Chapman
		
		12/11/2018 8:01:58 PM

	This cpp file describes the Scene class.

*/

//Include helper
#include "Scene.h"
#include "OrthographicCamera.h"
#include <iostream>
#include "Invader.h"

//Creates a blank Scene
Scene::Scene() : 
m_camera(new OrthographicCamera()), m_gameObjects(new std::vector<GameObject*>), 
m_gameGraphics(new std::vector<Graphic*>), m_lastSecond(std::chrono::system_clock::now())
{
	//Conservatively reserve slots for GameObjects
	m_gameObjects->reserve(100);
	m_gameGraphics->reserve(50);

}

Scene::Scene(Camera& a_camera) :
m_camera(&a_camera), m_gameObjects(new std::vector<GameObject*>),
m_gameGraphics(new std::vector<Graphic*>), m_lastSecond(std::chrono::system_clock::now())
{
	//Conservatively reserve slots for GameObjects
	m_gameObjects->reserve(100);
	m_gameGraphics->reserve(50);
	
}

Scene::Scene(Camera& a_camera, std::chrono::time_point<std::chrono::system_clock> a_lastUpdate) :
m_camera(&a_camera), m_gameObjects(new std::vector<GameObject*>),
m_gameGraphics(new std::vector<Graphic*>), m_lastSecond(a_lastUpdate)
{
	//Conservatively reserve slots for GameObjects
	m_gameObjects->reserve(100);
	m_gameGraphics->reserve(50);

}

//Destructor
Scene::~Scene()
{
	try
	{
		delete m_gameObjects;
	}
	catch (const std::exception&) {}
	try
	{
		delete m_gameGraphics;
	}
	catch (const std::exception&) {}

}

void Scene::update(float a_timeDelta)
{
	//update all GameObjects
	for (GameObject* object : *m_gameObjects)
	{
		//std::cout << "Looped to Object [" << object->animation() << "]" << std::endl;
		if (object != nullptr && object->active())
		{
			//std::cout << "Updating Object [" << object->animation() << "]" << std::endl;
			if (object->simulated()) object->physicsUpdate(a_timeDelta);
			object->update(a_timeDelta);
		}

	}

	//update all Graphics
	for (Graphic* graphic : *m_gameGraphics)
	{
		if (graphic != nullptr && graphic->active())
		{
			//std::cout << "Updating Graphic [" << graphic->animation() << "]" << std::endl;
			graphic->update(a_timeDelta);
		}
	}
}

void Scene::render(bool a_fullControl)
{
	//Clear window
	if (a_fullControl) m_camera->renderWindow().clear();

	//render all GameObjects
	for (GameObject* object : *m_gameObjects)
	{
		if (object != nullptr && object->active())
		{
			//std::cout << "Rendering Object [" << object->animation() << "]" << std::endl;
			m_camera->render(*object);
		}
	}

	//render all Graphics
	for (Graphic* graphic : *m_gameGraphics)
	{
		if (graphic != nullptr && graphic->active())
		{
			//std::cout << "Rendering Graphic [" << graphic->animation() << "]" << std::endl;
			m_camera->render(*graphic);
		}
	}

	//Display new window buffer
	if (a_fullControl) m_camera->renderWindow().display();
}


void Scene::addObject(GameObject* a_gameObject)
{
	m_gameObjects->push_back(a_gameObject);
}

void Scene::addGraphic(Graphic* a_gameGraphic)
{
	m_gameGraphics->push_back(a_gameGraphic);
}

//Setter and getter for camera of Scene
Camera& Scene::camera() const
{
	return *m_camera;
}
void Scene::camera(Camera& a_newCamera)
{
	m_camera = &a_newCamera;
}
