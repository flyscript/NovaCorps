/*
	NovaCorps - Animation.cpp
		William Chapman
		
		1/9/2019 10:55:24 AM

	This cpp file describes the Animation class.

*/
/*
//Include helper
#include "Animation.h"
#include <iostream>

//Creates a blank Animation
Animation::Animation() :
	m_iPointer(1)
{

}

//Destructor
Animation::~Animation() = default;

//Blends between sequences
void Animation::blend(float a_fDeltaTime)
{
	//std::cout << "Size: " << m_aAnimationSequence.size() << std::endl;
	//std::cout << "Pointer: " << m_iPointer << std::endl;
	//std::cout << "State: " << m_aAnimationSequence[-m_iPointer] << std::endl;
	//std::cout << "Blend Time: " << m_aAnimationSequence[-m_iPointer]->blendTime() << std::endl;

	if (m_aAnimationSequence[(-m_iPointer)-1] != nullptr)
	{
		//(delta time / AnimationState blend time)		
		const float l_fPercentIncrease = a_fDeltaTime / m_aAnimationSequence[(-m_iPointer)-1]->blendTime();

		//last AnimationState
		const int l_iLastPointer = (-m_iPointer - 1) + (static_cast<int>(m_aAnimationSequence.size())*(m_iPointer - 1 == 0));

		switch (m_aAnimationSequence[((-m_iPointer) - 1)]->blendingMode())
		{

		case AnimationBlendingMode::linear:

			//Increase each own property by (delta time / AnimationState blend time) * (AnimationState property - last AnimationState property)

			texture(m_aAnimationSequence[((-m_iPointer) - 1)]->texture());
			colour(colour() + sf::Color(
				static_cast<sf::Uint8>(l_fPercentIncrease * (m_aAnimationSequence[-m_iPointer]->colour().r - m_aAnimationSequence[-l_iLastPointer]->colour().r)),
				static_cast<sf::Uint8>(l_fPercentIncrease * (m_aAnimationSequence[-m_iPointer]->colour().g - m_aAnimationSequence[-l_iLastPointer]->colour().g)),
				static_cast<sf::Uint8>(l_fPercentIncrease * (m_aAnimationSequence[-m_iPointer]->colour().b - m_aAnimationSequence[-l_iLastPointer]->colour().b)),
				static_cast<sf::Uint8>(l_fPercentIncrease * (m_aAnimationSequence[-m_iPointer]->colour().a - m_aAnimationSequence[-l_iLastPointer]->colour().a))
			));
			offset(l_fPercentIncrease * (m_aAnimationSequence[((-m_iPointer) - 1)]->offset() - m_aAnimationSequence[-l_iLastPointer]->offset()));
			rotation(l_fPercentIncrease * (m_aAnimationSequence[((-m_iPointer) - 1)]->rotation() - m_aAnimationSequence[-l_iLastPointer]->rotation()));

			break;

		case AnimationBlendingMode::snap:

			//Go straight to it

			texture(m_aAnimationSequence[((-m_iPointer) - 1)]->texture());
			colour(m_aAnimationSequence[((-m_iPointer) - 1)]->colour());
			offset(m_aAnimationSequence[((-m_iPointer) - 1)]->offset());
			rotation(m_aAnimationSequence[((-m_iPointer) - 1)]->rotation());
			break;
		}
	}
}

//Update the animation
void Animation::update(float a_fDeltaTime)
{
	if (m_aAnimationSequence.size() > 1)
	{
		//Are we blending (Is pointer negative?)
		if (m_iPointer > 0)
		{//No		
			//Add delta time to ongoing state time
			time(time() + a_fDeltaTime);

			//Does ongoing state time exceed AnimationState Time?
			if (m_aAnimationSequence[m_iPointer - 1]->time() > time())
			{//No
				return;
			}
			//Yes

			////////Starting New Blend////////

			//Set ongoing blend time to difference between ongoing state time and AnimationState time
			blendTime(time() - m_aAnimationSequence[m_iPointer - 1]->time());

			//Increment Pointer. Wrap to 0 if out of range. Set it to negative.
			m_iPointer = -(1 + (m_iPointer % static_cast<int>(m_aAnimationSequence.size())));

		}
		else
		{//Yes
			//Add to self.blendingTime (use self.time as the last update time)
			blendTime(blendTime() + a_fDeltaTime);

			//Does ongoing blend time now exceed blend time for this AnimationState?
			if (blendTime() > m_aAnimationSequence[((-m_iPointer) - 1)]->blendTime())
			{//Yes
				//Make Pointer positive
				m_iPointer = -m_iPointer;

				//Set ongoing state time to difference between ongoing blend time and blend time of the AnimationState
				time(blendTime() - m_aAnimationSequence[m_iPointer - 1]->blendTime());

				return;
			}
		}

		//blend the animation
		blend(a_fDeltaTime);
	}
	else
	{
		blend(0.f);
	}
}

//Adds an animation step to the animation
void Animation::addAnimationStep(AnimationState* a_pNewAnimationStep)
{
	m_aAnimationSequence.push_back(a_pNewAnimationStep);
}
*/