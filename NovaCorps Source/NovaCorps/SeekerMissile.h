/*
	NovaCorps - SeekerMissile.h
		William Chapman
		
		11/23/2018 12:19:16 PM

	This header file describes the SeekerMissile class, inheriting from the Missile class.
	The seeker missile has slight added functionality that it will track a target by a defined smoothing factor every Update.

*/


#ifndef SEEKER_MISSILE_H

	#define SEEKER_MISSILE_H

	//Include any necessary files
	#include "Missile.h"

	class SeekerMissile : public Missile
	{
		//Private members
		private:

			//The target that the missile is tracking. Not necessarily the m_exclusiveTarget, which could also be null.
			Character* m_trackingTarget;

			//The 0-2 'accuracy' of the Missile. 0 doesn't even track, 1 = perfect accuracy, values higher than 1 create an unstable missile.
			float m_accuracy;

		//Public members
		public:

			//Constructor overloads
			SeekerMissile();
			SeekerMissile(Animation* a_pNewAnimation, Character& a_newTrackingTarget, float a_newAccuracy);

			//Destructor
			virtual ~SeekerMissile();

			//Special Update override gives Seeker Missile unique behaviour ontop of regular Missile
			virtual void update(float a_fDeltaTime) override;
			
			//Setter and getter for Tracking Target of SeekerMissile
			Character& trackingTarget();
			void trackingTarget(Character& a_newTrackingTarget);

			//Setter and getter for Accuracy of SeekerMissile
			float accuracy();
			void accuracy(float a_newAccuracy);

	};


#endif
