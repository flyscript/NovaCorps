/*
	NovaCorps - AnimationState.cpp
		William Chapman
		
		1/9/2019 10:57:23 AM

	This cpp file describes the AnimationState class.

*/

//Include helper
#include "AnimationState.h"

//Creates a blank AnimationState
AnimationState::AnimationState() :
	m_tTime(0.f), m_sTexture(nullptr)
{
}

//Creates an AnimationState with a defined texture and transparency
AnimationState::AnimationState(const char* a_sNewTexture, float a_fNewTime) :
	m_tTime(a_fNewTime), m_sTexture(a_sNewTexture)
{
}
//Destructor
AnimationState::~AnimationState() = default;

//Setter and getter for the time the AnimationState lasts
float AnimationState::time() const
{
	return m_tTime;
}
void AnimationState::time(float a_tNewTime)
{
	m_tTime = a_tNewTime;
}

//Setter and getter for texture of animation
const char* AnimationState::texture() const
{
	return m_sTexture;
}
void AnimationState::texture(const char* a_sNewTexture)
{
	m_sTexture = a_sNewTexture;
}