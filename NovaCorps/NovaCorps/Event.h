/*
	NovaCorps - Event.h
		William Chapman
		
		12/29/2018 11:22:05 AM

	This header file describes the Event class.

*/


#ifndef EVENT_H

	#define EVENT_H

	//Include any necessary files
	#include <iostream>
	#include <functional>

	class Event
	{
		//Private members
		private:

			//Just a default return of true. Can't hang up an entire EventSequence sequence by entering a blank event.
			bool defaultInvoke();

			//Function pointer to code called when invoked
			std::function<bool(Event*)> m_invokePointer;

		//Public members
		public:

			Event();
			Event(std::function<bool(Event*)> a_newMethod);

			virtual ~Event();
			
			//Runs this event, returns whether or not it was successfully invoked
			bool invoke();

			//Sets the invokable method to a new one
			void setInvoke(std::function<bool(Event*)> a_newMethod);
	};


#endif
