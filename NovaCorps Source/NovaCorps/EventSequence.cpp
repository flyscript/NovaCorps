/*
	NovaCorps - EventSequence.cpp
		William Chapman
		
		12/28/2018 11:12:10 PM

	This cpp file describes the EventSequence class.

*/

//Include helper
#include "EventSequence.h"

int EventSequence::s_iMaxFloat = static_cast<int>(std::pow(2, sizeof(float) * 8) / 2 - 1);

//Creates a blank EventSequence
EventSequence::EventSequence()
{
	//std::cout << "Max float: " << s_iMaxFloat << std::endl;
	
	m_bIsRunning = false;
}

//Destructor
EventSequence::~EventSequence()
{
	//Delete every pointer to every wave event
	for (auto l_waveEventIt : m_mEventSequence)
	{
		m_mEventSequence.erase(l_waveEventIt.first);
	}
}

//Starts the sequence
void EventSequence::start()
{
	if (!m_bIsRunning)
	{
		m_bIsRunning = true;

		m_tStartTime = std::chrono::system_clock::now();
	}
}

//Pauses the sequence
void EventSequence::pause()
{
	m_bIsRunning = false;
}

//Stops the sequence, resets it and sets it back to the start
void EventSequence::stop()
{
	m_bIsRunning = false;

	for (auto l_event : m_mEventSequence)
	{
		if (l_event.first.count() > 9999999.f)
		{
			/*
			Anything bigger than the huge number needs to have that subtracted to resort it.
			See EventSequence::update for further info on how this works.
			*/
			std::swap(m_mEventSequence[l_event.first - std::chrono::duration<float>(9999999.f)], m_mEventSequence[l_event.first]);
			m_mEventSequence.erase(l_event.first);
		}
	}
}

//Update method
void EventSequence::update()
{
	//If the wave is running, there are events to execute, and the next one is ready to execute
	if (m_bIsRunning && !m_mEventSequence.empty() && m_mEventSequence.begin()->first < std::chrono::system_clock::now() - m_tStartTime)
	{
		//Attempt to invoke event
		auto cond = m_mEventSequence.begin()->second->invoke();
		if (cond)
		{
			/*
			Add a huge number to the time that can be removed later. This sorts it to the end; making the new
			first event in the sequence being the next to be invoked while keeping invoked events in order.
			When the sequence is stopped, all of these sorted-to-the-end events can have their time decreased
			by the same amount. This change of the key is done by swapping map[time] and map[newTime] (which
			is nullptr) and then deleting map[time] (also known as eventSequence.begin()).
			*/
			std::swap(m_mEventSequence[m_mEventSequence.begin()->first + std::chrono::duration<float>(99999.f)], m_mEventSequence.begin()->second);
			m_mEventSequence.erase(m_mEventSequence.begin());
		}
	}
}

//Adds an event to the sequence and sorts it chronologically. If the given time is the same as an existing Event's it will overwrite.
void EventSequence::addEvent(std::chrono::duration<float> a_Ttime, Event* a_waveEvent)
{
	if (!m_bIsRunning)// || (std::chrono::system_clock::now() - m_tStartTime) < a_time)
	{
		//TODO: in case of overwrite, delete old Event* to prevent memory leaks
		m_mEventSequence[a_Ttime] = a_waveEvent;
	}
}