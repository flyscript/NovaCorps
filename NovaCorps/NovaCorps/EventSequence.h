/*
	NovaCorps - EventSequence.h
		William Chapman
		
		12/28/2018 11:12:10 PM

	This header file describes the EventSequence class.

*/


#ifndef EVENT_SEQUENCE_H

	#define EVENT_SEQUENCE_H

	//Include any necessary files
	#include <chrono>
	#include <map>
	#include "Event.h"

	class EventSequence
	{
		//Private members
		private:

			//Whether or not the wave has already started. Same effect could be achieved by defaulting the start
			//time to 0 and checking if it's more than that, but would require more processing than a !false.
			bool m_bIsRunning;

			//The start time of the wave
			std::chrono::time_point<std::chrono::system_clock> m_tStartTime;

			//The wave events sequence
			std::map<std::chrono::duration<float>, Event*> m_mEventSequence;

			//The maximum float value, stored as an int to stop Woverflow
			static int s_iMaxFloat;

		//Public members
		public:

			//Constructor overloads
			EventSequence();

			//Destructor
			virtual ~EventSequence();

			//Starts the sequence
			void start();

			//Pauses the sequence
			void pause();

			//Stops the sequence, resets it and sets it back to the start
			void stop();

			//Update method
			void update();
			
			//Adds an event to the wave
			void addEvent(std::chrono::duration<float> a_Ttime, Event* a_waveEvent);

	};



#endif
