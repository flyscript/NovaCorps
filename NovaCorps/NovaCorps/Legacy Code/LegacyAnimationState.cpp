/*
	NovaCorps - AnimationState.cpp
		William Chapman
		
		1/9/2019 10:57:23 AM

	This cpp file describes the AnimationState class.

*/
/*
//Include helper
#include "AnimationState.h"

//Creates a blank AnimationState
AnimationState::AnimationState() :
	m_tTime(0.f), m_tBlendTime(0.f), m_sTexture(nullptr), m_cColour(sf::Color::White),
	m_vOffset(sf::Vector2f(0.f, 0.f)), m_fRotation(0.f), m_eBlendingMode(AnimationBlendingMode::snap)
{
}

//Creates an AnimationState with a defined texture and transparency
AnimationState::AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour) :
	m_tTime(0.f), m_tBlendTime(0.f), m_sTexture(a_sNewTexture), m_cColour(a_cNewColour),
	m_vOffset(sf::Vector2f(0.f, 0.f)), m_fRotation(0.f), m_eBlendingMode(AnimationBlendingMode::snap)
{
}

//Creates an AnimationState with a defined texture and transparency and offset
AnimationState::AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour, AnimationBlendingMode a_eNewBlendingMode) :
	m_tTime(0.f), m_tBlendTime(0.f), m_sTexture(a_sNewTexture), m_cColour(a_cNewColour),
	m_vOffset(sf::Vector2f(0.f, 0.f)), m_fRotation(0.f), m_eBlendingMode(a_eNewBlendingMode)
{
}

//Creates an AnimationState with a defined texture, transparency, time, blend time, and offset
AnimationState::AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour, float a_fNewTime, float a_fNewBlendTime, AnimationBlendingMode a_eNewBlendingMode) :
	m_tTime(a_fNewTime), m_tBlendTime(a_fNewBlendTime), m_sTexture(a_sNewTexture), m_cColour(a_cNewColour),
	m_vOffset(sf::Vector2f(0.f, 0.f)), m_fRotation(0.f), m_eBlendingMode(a_eNewBlendingMode)
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

//Setter and getter for the time the AnimationState takes to blend in
float AnimationState::blendTime() const
{
	return m_tBlendTime;
}
void AnimationState::blendTime(float a_tNewBlendTime)
{
	m_tBlendTime = a_tNewBlendTime;
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

//Setter and getter for offset of AnimationState
sf::Vector2f AnimationState::offset() const
{
	return m_vOffset;
}
void AnimationState::offset(sf::Vector2f a_fNewOffset)
{
	m_vOffset = a_fNewOffset;
}

//Setter and getter for SFML colour of ScreenElement2D
sf::Color AnimationState::colour() const
{
	return m_cColour;
}
void AnimationState::colour(sf::Color a_cNewColour)
{
	m_cColour = a_cNewColour;
}

//Setter and getter for rotation of texture
float AnimationState::rotation() const
{
	return m_fRotation;
}
void AnimationState::rotation(float a_fNewRotation)
{
	m_fRotation = a_fNewRotation;
}

//Setter and getter for the blending mode
AnimationBlendingMode AnimationState::blendingMode() const
{
	return m_eBlendingMode;
}
void AnimationState::blendingMode(AnimationBlendingMode a_eNewBlendingMode)
{
	m_eBlendingMode = a_eNewBlendingMode;
}*/