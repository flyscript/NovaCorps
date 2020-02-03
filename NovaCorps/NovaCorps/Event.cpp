/*
	NovaCorps - Event.cpp
		William Chapman
		
		12/29/2018 11:22:05 AM

	This cpp file describes the Event class.

*/

//Include helper
#include "Event.h"
#include <iostream>

//Creates a blank Event
Event::Event() : m_invokePointer(&Event::defaultInvoke)
{
}

//Create a Event with given invokable code
Event::Event(std::function<bool(Event*)> a_newMethod) : m_invokePointer(a_newMethod)
{
}

//Destructor
Event::~Event() = default;


//Just a default return of true. Can't hang up an entire EventSequence sequence by entering a blank event.
bool Event::defaultInvoke()
{
	//std::cout << "Default Invoke" << std::endl;
	return true;
}

//Runs this event, returns whether or not it was successfully invoked
bool Event::invoke()
{
	//std::cout << "Event Invoked" << std::endl;
	auto result = m_invokePointer(this);
	//std::cout << "Invoke Finished: returning result" << std::endl;
	return result;
}

//Sets the invokable method to a new one
void Event::setInvoke(std::function<bool(Event*)> a_newMethod)
{
	m_invokePointer = a_newMethod;
}