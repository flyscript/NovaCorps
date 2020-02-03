/*
	NovaCorps - AnimationState.h
		William Chapman
		
		1/9/2019 10:57:23 AM

	This header file describes the AnimationState class.

*/
/*

#ifndef AnimationState_h

	#define AnimationState_h

	//Include any necessary files
	#include <SFML/System/Vector2.hpp>
	#include <SFML/Graphics/Color.hpp>

	enum class AnimationBlendingMode{snap = 0, linear};

	class AnimationState
	{
		//Private members
		private:

			//The time that the animation lasts before the next one comes in
			float m_tTime;

			//The time that the animation takes to blend in
			float m_tBlendTime;

			//The Texture address for this AnimationState
			const char* m_sTexture;

			//The colour of the texture in this AnimationState
			sf::Color m_cColour;
			
			//The offset of the texture from the object position in this AnimationState
			sf::Vector2f m_vOffset;

			//The rotation of the texture in this AnimationState
			float m_fRotation;

			//The way that this animation will blend in
			AnimationBlendingMode m_eBlendingMode;


		//Public members
		public:

			//Constructor overloads
			AnimationState();
			AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour);
				AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour, AnimationBlendingMode a_eNewBlendingMode);
			AnimationState(const char* a_sNewTexture, sf::Color a_cNewColour, float a_fNewTime, float a_fNewBlendTime, AnimationBlendingMode a_eNewBlendingMode);

			//Destructor
			virtual ~AnimationState();
			
			//Setter and getter for the time the AnimationState lasts
			float time() const;
			void time(float a_tNewTime);

			//Setter and getter for animation of the AnimationState
			const char* texture() const;
			void texture(const char* a_sNewTexture);

			//Getter and Setter for property of AnimationState
			sf::Vector2f offset() const;
			void offset(sf::Vector2f a_fNewOffset);

			//Setter and getter for colour of AnimationState
			sf::Color colour() const;
			void colour(sf::Color a_cNewColour);

			//Setter and getter for rotation of AnimationState
			float rotation() const;
			void rotation(float a_fNewRotation);

			//Setter and getter for the blending mode
			AnimationBlendingMode blendingMode() const;
			void blendingMode(AnimationBlendingMode a_eNewBlendingMode);

			//Setter and getter for the time the AnimationState takes to blend in
			float blendTime() const;
			void blendTime(float a_tNewBlendTime);

	};


#endif
*/