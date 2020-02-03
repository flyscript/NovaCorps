/*
	NovaCorps - Animation.h
		William Chapman
		
		1/9/2019 10:55:24 AM

	This header file describes the Animation class.

*/
/*

#ifndef Animation_h

	#define Animation_h

	//Include any necessary files
	#include "AnimationState.h"
	#include <vector>

	class Animation : public AnimationState
	{
		//Private members
		private:

			//TODO: use AnimationState::time() as the current time used on the thing

			//Pointer to the current animation state being calculated. Negative when blending to that mode. (De)incrementation used to count from 1 so no -0.
			int m_iPointer;
			
			//The animation step events sequence
			std::vector<AnimationState*> m_aAnimationSequence;

			//Blends between sequences
			void blend(float a_fDeltaTime);

		//Public members
		public:

			//Constructor overloads
			Animation();

			//Destructor
			virtual ~Animation();

			//update method
			void update(float a_fDeltaTime);

			//Virtual Update method
			void addAnimationStep(AnimationState* a_pNewAnimationStep);

	};


#endif
*/