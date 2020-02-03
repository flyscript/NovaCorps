/*
	NovaCorps - Animation.cpp
		William Chapman
		
		1/9/2019 10:55:24 AM

	This cpp file describes the Animation class.

*/

//Include helper
#include "Animation.h"

//Creates a blank Animation
Animation::Animation() :
	m_iPointer(0)
{

}

//Destructor
Animation::~Animation() = default;

//Update the animation
void Animation::update(float a_fDeltaTime)
{
	if (m_aAnimationSequence.size() > 1)
	{
		//Add delta time to ongoing state time
		time(time() + a_fDeltaTime);

		//If ongoing state time doesn't exceed AnimationState Time then end
		if (m_aAnimationSequence[m_iPointer]->time() > time()) return; 

		///// Going to next /////

		//Set ongoing blend time to difference between ongoing state time and AnimationState time
		time(time() - m_aAnimationSequence[m_iPointer]->time());

		//Increment Pointer and wrap to 0 if out of range
		m_iPointer = (m_iPointer + 1) % static_cast<int>(m_aAnimationSequence.size());

		//Set the new texture
		texture(m_aAnimationSequence[m_iPointer]->texture());
		
	}
	else if (!m_aAnimationSequence.empty())
	{
		texture(m_aAnimationSequence[0]->texture());
	}

}

//Adds an animation step to the animation
void Animation::addAnimationStep(AnimationState* a_pNewAnimationStep)
{
	if (m_aAnimationSequence.empty()) texture(a_pNewAnimationStep->texture());
	m_aAnimationSequence.push_back(a_pNewAnimationStep);
}