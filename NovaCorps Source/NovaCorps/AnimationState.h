/*
	NovaCorps - AnimationState.h
		William Chapman
		
		1/9/2019 10:57:23 AM

	This header file describes the AnimationState class.

*/


#ifndef AnimationState_h

	#define AnimationState_h

	//Include any necessary files
	#include <SFML/System/Vector2.hpp>
	#include <SFML/Graphics/Color.hpp>

	class AnimationState
	{
		//Private members
		private:

			//The time that the animation lasts before the next one comes in
			float m_tTime;
			
			//The Texture address for this AnimationState
			const char* m_sTexture;
			

		//Public members
		public:

			//Constructor overloads
			AnimationState();
			AnimationState(const char* a_sNewTexture, float a_fNewTime);

			//Destructor
			virtual ~AnimationState();
			
			//Setter and getter for the time the AnimationState lasts
			float time() const;
			void time(float a_tNewTime);

			//Setter and getter for animation of the AnimationState
			const char* texture() const;
			void texture(const char* a_sNewTexture);
	};


#endif
