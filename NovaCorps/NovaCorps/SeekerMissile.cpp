/*
	NovaCorps - SeekerMissile.cpp
		NTI
		
		11/23/2018 12:19:16 PM

	This cpp file describes the SeekerMissile class.

*/

//Include helper
#include "SeekerMissile.h"

//Creates a blank SeekerMissile
SeekerMissile::SeekerMissile() : Missile(nullptr)
{
	m_accuracy = 0.5f;
}

SeekerMissile::SeekerMissile(Animation* a_pNewAnimation, Character& a_newTrackingTarget, float a_newAccuracy) : Missile(a_pNewAnimation)
{
	m_accuracy = a_newAccuracy;
	m_trackingTarget = &a_newTrackingTarget;
}

//Destructor
SeekerMissile::~SeekerMissile() = default;

//Special Update override gives Seeker Missile unique behaviour ontop of regular Missile
void SeekerMissile::update(float a_fDeltaTime)
{
	//If the target exists, do some tracking
	if (m_trackingTarget != nullptr)
	{
		//Save the velocity's magnitude
		float l_magnitude = sqrt(velocity().x*velocity().x+velocity().y*velocity().y);

		//Set the velocity vector to original vector + (targetPos-missilePos)*accuracy //TODO: check unity game app for old missile code
		velocity(velocity() + (m_trackingTarget->position() - position())*m_accuracy);

		//Set velocity magnitude to original magnitude to conserve the actual speed
		//Divide by current magnitude to get magnitude of 1 then multiply by original magnitude
		float l_newMagnitude = sqrt(velocity().x*velocity().x + velocity().y*velocity().y);
		velocity(velocity() / l_newMagnitude * l_magnitude);

	}

	//Once tracking is done, run regular Missile Update code for this missile.
	Missile::update(a_fDeltaTime);
}


//Setter and getter for Tracking Target of SeekerMissile
Character& SeekerMissile::trackingTarget()
{
	return *m_trackingTarget;
}
void SeekerMissile::trackingTarget(Character& a_newTrackingTarget)
{
	m_trackingTarget = &a_newTrackingTarget;
}

//Setter and getter for Accuracy of SeekerMissile
float SeekerMissile::accuracy()
{
	return m_accuracy;
}
void SeekerMissile::accuracy(float a_newAccuracy)
{
	m_accuracy = a_newAccuracy;
}