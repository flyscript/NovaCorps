/*
	NovaCorps - Rand.h
		William Chapman
		
		12/26/2018 9:50:34 PM

	This header file describes the R class.

*/

#ifndef R_H
	#define R_H

	#include <ctime>
	#include <random>

	namespace r
	{
		//Initialise the generator
		static std::mt19937 generator(static_cast<unsigned int>(time(nullptr)));
		static const float minimum = 1.0f / static_cast<float>(0xffffffff);

		// -----------------------------
		// Function name: r::andom
		// Description	: Creates a random number between 0 and 1
		//		  
		// Parameters	: 
		//
		// Returns		: A number of <type> (defaults to float) between 0 and 1
		// See also		: om(max), om(min, max)
		// -----------------------------
		template <typename returnType = float>
		returnType andom()
		{
			return static_cast<returnType>(generator() * minimum);
		}

		// -----------------------------
		// Function name: r::andom
		// Description	: Creates a random number between 0 and the given maximum
		//		  
		// Parameters	: <type> (defaults to float) maximum value
		//
		// Returns		: A number of <type> (defaults to float) between 0 and the maximum value
		// See also		: om(), om(min, max)
		// -----------------------------
		template <typename returnType = float, typename inputType = returnType>
		returnType andom(inputType a_maxValue)
		{
			return static_cast<returnType>(andom() * a_maxValue);
		}

		// -----------------------------
		// Function name: r::andom
		// Description	: Creates a random number between two values
		//		  
		// Parameters	: <type> (defaults to float) minimum value, <type> (defaults to float) maximum value
		//
		// Returns		: A number of <type> (defaults to float) between the minimum and maximum value
		// See also		: om(), om(max)
		// -----------------------------
		template <typename returnType = float, typename inputType = returnType>
		returnType andom(inputType a_minValue, inputType a_maxValue)
		{
			return static_cast<returnType>(a_minValue + andom<inputType>(a_maxValue - a_minValue));
		}

		// -----------------------------
		// Function name: r::coinFlip
		// Description	: Flips a virtual coin, result is either 1 or -1.
		//		  
		// Parameters	: 
		//
		// Returns		: -1 or 1, randomly
		// See also		: om(), om(max), om(min, max)
		// -----------------------------
		template <typename returnType = int>
		returnType coinFlip()
		{
			return static_cast<returnType>((-2 * andom(0, 2)) + 1);
			//return static_cast<returnType>(andom(0, 2));
		}

	};

#endif
