/*
	NovaCorps - Scene.h
		NTI
		
		12/11/2018 8:01:58 PM

	This header file describes the Scene class.

*/


#ifndef SCENE_H

	#define SCENE_H

	//Include any necessary files
	#include <chrono>	
	#include "OrthographicCamera.h"

	class Scene
	{
		//Private members
		private:

			//The camera this scene is using
			Camera* m_camera;

			//The list of gameobjects that are in the scene
			std::vector<GameObject*>* m_gameObjects;

			//The list of graphics that are in the scene
			std::vector<Graphic*>* m_gameGraphics;

			//The time of the last second, used to throttle render and update requests
			std::chrono::time_point<std::chrono::system_clock> m_lastSecond;

		//Public members
		public:

			//Constructor overloads
			Scene();
			Scene(Camera& a_camera);
			Scene(Camera& a_camera, std::chrono::time_point<std::chrono::system_clock> a_lastUpdate);

			//Destructor
			virtual ~Scene();

			//Getter and Setter for camera of Scene
			Camera& camera() const;
			void camera(Camera& a_newCamera);
			
			// -----------------------------
			// Function name: update
			// Description	: Loops through all GameObjects, running physics and update logic. Will automatically update the last update time.
			// Parameters	: float Delta Time
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void update(float a_timeDelta);

			// -----------------------------
			// Function name: render
			// Description	: Loops through all GameObjects, rendering them as they should be rendered
			// Parameters	: float Delta Time, <bool> full control [=false] determines whether or not the scene will be responsible for clearing and then drawing the render window
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void render(bool a_fullControl = false);

			// -----------------------------
			// Function name: add
			// Description	: Adds a GameObject to the scene so that it can be simulated or rendered.
			//					Automatically loads its texture if it had not ben loaded previously.
			// Parameters	: GameObject*
			//
			// Returns		: 
			// See also		: addGraphic
			// -----------------------------
			void addObject(GameObject* a_gameObject);

			// -----------------------------
			// Function name: add
			// Description	: Adds a Graphic to the scene so that it can be rendered.
			//		  Automatically loads its texture if it had not ben loaded previously.
			// Parameters	: Graphic*
			//
			// Returns		: 
			// See also		: addObject
			// -----------------------------
			void addGraphic(Graphic* a_gameGraphic);

	};


#endif
