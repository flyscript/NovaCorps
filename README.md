# NovaCorps
This is a game that I created for one of my first C++ modules during my Bachelors degree.

It's a Galaxians-come-Space Invaders style game set in space, where you defend your ship from waves of enemy ships coming at you.

It uses SFML (Simple and Fast Multimedia Library), a multimedia system interface, as a basis from which to build a game engine. The game's own code is then integrated with that engine's simple draw() and update() loop.

The game can be run by downloading "NovaCorpsGame" and running the executable, and the source code can be found under "NovaCorps".

### Key Features:
* Strong object-oriented approach to [characters](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Character.cpp) and [weapons](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Missile.cpp)
* Custom [animations](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/AnimationState.cpp) and an [animation system](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Animation.cpp)
* Custom [particles](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Particle.cpp) and a [particle system](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/ParticleEmitter.cpp)
* Custom (random number generator)[https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/r.h]
* Custom [events](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Event.cpp) and [sequence manager](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/EventSequence.cpp)
* Efficient [pooling system](https://github.com/flyscript/NovaCorps/blob/master/NovaCorps/NovaCorps/Pool.h)

The pooling system can be found in its own repo at:
https://github.com/flyscript/ObjectPooler
