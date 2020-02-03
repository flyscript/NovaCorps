/*
	NovaCorps - NovaCorps.h
		William Chapman

		12/11/2018 10:38:29 AM

	This header file describes the main game class

*/

#ifndef NOVA_CORPS_h

	#define NOVA_CORPS_h

	#include "Drone.h"
	#include "EventSequence.h"
	#include "Invader.h"
	#include "InvaderMissile.h"
	#include "OrthographicCamera.h"
	#include "ParticleEmitter.h"
	#include "Player.h"
	#include "PlayerMissileStandard.h"
	#include "Pool.h"
	#include "Scene.h"
	#include "Seeker.h"
	#include "SeekerMissile.h"
	#include <SFML/Graphics/Font.hpp>
	#include <SFML/Graphics/RenderWindow.hpp>
	#include <SFML/Graphics/Text.hpp>
	#include <SFML/Audio.hpp>
	#include <SFML/Window/Keyboard.hpp>

	// -----------------------------
	// Class name		: GameMode enum
	// Description		: An enum describing the current mode the game is in
	//
	// Usage examples	:
	//
	//  if (curentGameMode = GameMode::playing)
	//		update();
	//  
	// -----------------------------
	enum class GameMode { end = 0, menu, playing, gameOver, settings};

	// -----------------------------
	// Class name		: Button enum
	// Description		: An enum describing the game's button
	//
	// Usage examples	:
	//
	//  if (currentButton = Button::play)
	//		play();
	//  
	// -----------------------------
	enum class Button { play = 0, controls, settings, quit, back};

	// -----------------------------
	// Class name		: NovaCorps
	// Description		: What do you think its the fukkin game
	//
	// Usage examples	:
	//
	//  NovaCorps game;
	//  game.run();
	//  
	// -----------------------------
	class NovaCorps
	{
		//Private members
		private:

			//Whether or not the game is currently running
			GameMode m_eGameMode;

			//The currently selected button
			Button m_eButton;

			//The last pressed key
			sf::Keyboard::Key m_eLastKey;

			//The current round the game is on
			int m_iRound;

			//The window the game will use to render things
			sf::RenderWindow* m_pRenderWindow;

			//The Camera that the game will use to render everything
			OrthographicCamera* m_pCamera;

			//The scene of the game
			Scene* m_pScene;

			//Pre-initialise textures
			Animation* m_pPlayButtonAnimation;
			AnimationState* m_pPlayButtonAnimState0;
			AnimationState* m_pPlayButtonAnimState1;
			Animation* m_pControlsButtonAnimation;
			AnimationState* m_pControlsButtonAnimState0;
			AnimationState* m_pControlsButtonAnimState1;
			Animation* m_pSettingsButtonAnimation;
			AnimationState* m_pSettingsButtonAnimState0;
			AnimationState* m_pSettingsButtonAnimState1;
			Animation* m_pQuitButtonAnimation;
			AnimationState* m_pQuitButtonAnimState0;
			AnimationState* m_pQuitButtonAnimState1;
			Animation* m_pBackButtonAnimation;
			AnimationState* m_pBackButtonAnimState0;
			AnimationState* m_pBackButtonAnimState1;
			Animation* m_pPlayerRunningAnimation;
			AnimationState* m_pPlayerRunningAnimState0;
			AnimationState* m_pPlayerRunningAnimState1;
			Animation* m_pPlayerLeftAnimation;
			AnimationState* m_pPlayerLeftAnimState0;
			AnimationState* m_pPlayerLeftAnimState1;
			Animation* m_pPlayerRightAnimation;
			AnimationState* m_pPlayerRightAnimState0;
			AnimationState* m_pPlayerRightAnimState1;
			Animation* m_pPlayerDieAnimation;
			AnimationState* m_pPlayerDieAnimState0;
			AnimationState* m_pPlayerDieAnimState1;
			Animation* m_pDroneRunningAnimation;
			AnimationState* m_pDroneRunningAnimState0;
			AnimationState* m_pDroneRunningAnimState1;
			Animation* m_pDroneDieAnimation;
			AnimationState* m_pDroneDieAnimState0;
			AnimationState* m_pDroneDieAnimState1;
			Animation* m_pInvaderRunningAnimation;
			AnimationState* m_pInvaderRunningAnimState0;
			AnimationState* m_pInvaderRunningAnimState1;
			Animation* m_pInvaderDieAnimation;
			AnimationState* m_pInvaderDieAnimState0;
			AnimationState* m_pInvaderDieAnimState1;
			Animation* m_pSeekerRunningAnimation;
			AnimationState* m_pSeekerRunningAnimState0;
			AnimationState* m_pSeekerRunningAnimState1;
			Animation* m_pSeekerDieAnimation;
			AnimationState* m_pSeekerDieAnimState0;
			AnimationState* m_pSeekerDieAnimState1;
			Animation* m_pPlayerMissileStandardAnimation;
			AnimationState* m_pPlayerMissileStandardAnimState0;
			AnimationState* m_pPlayerMissileStandardAnimState1;
			Animation* m_pPlayerMissileDoubleAnimation;
			AnimationState* m_pPlayerMissileDoubleAnimState0;
			AnimationState* m_pPlayerMissileDoubleAnimState1;
			Animation* m_pDroneMissileAnimation;
			AnimationState* m_pDroneMissileAnimState0;
			AnimationState* m_pDroneMissileAnimState1;
			Animation* m_pInvaderMissileAnimation;
			AnimationState* m_pInvaderMissileAnimState0;
			AnimationState* m_pInvaderMissileAnimState1;
			Animation* m_pSeekerMissileAnimation;
			AnimationState* m_pSeekerMissileAnimState0;
			AnimationState* m_pSeekerMissileAnimState1;
			Animation* m_pTitleAnimation;
			AnimationState* m_pTitleAnimState;
			Animation* m_pGameOverAnimation;
			AnimationState* m_pGameOverAnimState;
			Animation* m_pPlayPromptAnimation;
			AnimationState* m_pPlayPromptAnimState0;
			AnimationState* m_pPlayPromptAnimState1;
			Animation* m_pMovePromptAnimation;
			AnimationState* m_pMovePromptAnimState0;
			AnimationState* m_pMovePromptAnimState1;
			Animation* m_pShootPromptAnimation;
			AnimationState* m_pShootPromptAnimState0;
			AnimationState* m_pShootPromptAnimState1;
			Animation* m_pParticleAnimation;
			AnimationState* m_pParticleAnimState;

			//The manager the game will use to play sounds
			//TODO: Make an actual sound manager
			sf::Sound m_sSoundManager;
			sf::Sound m_sSoundManager2;
			sf::Sound m_sSoundManager3;

			sf::SoundBuffer m_sStartSound;
			sf::SoundBuffer m_sGameOverSound;
			sf::SoundBuffer m_sMenuStartupSound;
			sf::SoundBuffer m_sPlayerAppearSound;
			sf::SoundBuffer m_sInvaderAppearSound;
			sf::SoundBuffer m_sPlayerFireSound;
			sf::SoundBuffer m_sEnemyFireSound;
			sf::Music m_sTitleMusic;
			sf::Music m_sBackgroundMusic;

			// and text
			sf::Font m_cFont;
			sf::Text m_cPointsText;
			sf::Text m_cHealthText;
			sf::Text m_cRoundText;
						 
			//The size of the game screen
			sf::Vector2u m_vScreenSize;

			//Starfield
			ParticleEmitter* m_pStars;
			ParticleEmitter* m_pStars2;
			ParticleEmitter* m_pStars3;

			//Array of waves
			EventSequence* m_aWaves[10];

			//The graphics
			Graphic* m_pTitleCard;
			Graphic* m_pPlayButton;
			Graphic* m_pControlsButton;
			Graphic* m_pSettingsButton;
			Graphic* m_pQuitButton;
			Graphic* m_pBackButton;
			Graphic* m_pPlayPrompt;
			Graphic* m_pMovePrompt;
			Graphic* m_pShootPrompt;

			//The player
			Player* m_pPlayer;
			PlayerMissileStandard* m_aBasePlayerStandardMissile;
			Pool<PlayerMissileStandard>* m_aPlayerStandardMissiles;
			PlayerMissileStandard* m_aBasePlayerDoubleMissile;
			Pool<PlayerMissileStandard>* m_aPlayerDoubleMissiles;

			//Pool of Drones, their missiles and a base missile
			Pool<Drone>* m_pDrones;
			InvaderMissile* m_pBaseDroneMissile;
			Pool<InvaderMissile>* m_pDroneMissiles;

			//Pool of Invaders, their missiles and a base missile
			Pool<Invader>* m_pInvaders;
			InvaderMissile* m_pBaseInvaderMissile;
			Pool<InvaderMissile>* m_pInvaderMissiles;

			//Pool of Seekers, their missiles and a base missile
			Pool<Seeker>* m_pSeekers;
			InvaderMissile* m_pBaseSeekerMissile;
			Pool<InvaderMissile>* m_pSeekerMissiles;
			
			//For throttling
			std::chrono::time_point<std::chrono::system_clock> m_tLastUpdate;
			float m_fUpdateDeltaTime;

			//Frames ("Cycles", calculations can be made for any thread) per second variables
			std::chrono::time_point<std::chrono::system_clock> m_tLastSecond;
			int m_iUpdatesThisSecond;
			int m_iFramesThisSecond;
			int m_iLogicThisSecond;

			bool m_bShakeCam;
			sf::Vector2f m_vShakeFactor;

			// -----------------------------
			// Function name: loadGame
			// Description	: Loads assets and objects for the game
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadGame();

			// -----------------------------
			// Function name: loadAssets
			// Description	: Loads the assets
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadAssets();

			// -----------------------------
			// Function name: loadStars
			// Description	: Loads the stars
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadStars();

			void loadGraphics();

			// -----------------------------
			// Function name: loadCharacters
			// Description	: Loads the characters
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadCharacters();

			// -----------------------------
			// Function name: loadMissiles
			// Description	: Loads the missiles
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadMissiles();

			// -----------------------------
			// Function name: loadEvents
			// Description	: Loads the events
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void loadEvents();

			// -----------------------------
			// Function name: update
			// Description	: Runs update logic for the game, aside from scene.update()
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void update();

			// -----------------------------
			// Function name: logic
			// Description	: Runs game logic for the game, such as input
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void logic();

			// -----------------------------
			// Function name: render
			// Description	: Runs render logic for the game, aside from scene.render()
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void render();

			// -----------------------------
			// Function name: setup
			// Description	: Sets up variables for running of the game
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void setup();

			// -----------------------------
			// Function name: gameOver
			// Description	: When called, ends the game
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void gameOver();

			// -----------------------------
			// Function name: nextRound
			// Description	: When called, sets up the next round and attributes any bonuses necesary
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void nextRound();
			
			// -----------------------------
			// Function name: menu
			// Description	: When called, sets up the menu
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void menu();

		//Public members
		public:

			//Constructor/Destructor
			NovaCorps();
			~NovaCorps();

			// -----------------------------
			// Function name: run
			// Description	: When called, runs through the main game loop
			// Parameters	: 
			//
			// Returns		: 
			// See also		: 
			// -----------------------------
			void run();


	};

#endif



/*alien variables
var wave = [ //describes wave layout
	["mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom", "mushroom"],
		["invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader"],
		["invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader", "invader"],
		["skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully"],
		["skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully", "skully"]
];



/ ufo
if (stepsToNextUFO == stepsSinceLastUFO)
{
	stepsToNextUFO = 0;
	stepsSinceLastUFO = 0;
	ufoPos += ufoDir;

	if (ufoPos > -58 && ufoPos < 1338)
	{
		var ufoImage = new Image();
		ufoImage.src = "Images/Aliens/ufo.png";
		alienCanvas.drawImage(ufoImage, ufoPos, 45);
	}
	else
	{
		console.log("Out of range")
			ufoDir = ufoDir * -1;
		stepsToNextUFO = 250 + Math.floor(Math.random() * 500);
	}
}
else
{
	stepsSinceLastUFO++;
}

//TODO: Put in for loop through all aliens (Find a way to make it part of their update?)
{
	// calculate alien direction when out of bounds
	if (alienPos < 0)
	{
		alienPos = 0;
		row++;
		alienDirection = 1; //TODO: change to GameObject velocity
	}
	else if (alienPos * row * alienStep > xMaxWidth) //TODO:alien pos is a position in an array, update this for new GameObject position
	{
		row++;
		alienDirection = -1; //TODO: change to GameObject velocity
		alienPos = Math.floor(xMaxWidth / (row * alienStep)); //3 hours that took me
	}


	if (75 + ((sizes[wave[y][x]][1] + sizes[wave[y][x]][3]) * y) + (row * rowDepth) > 500)
	{
		reachedEarth = true;
	}
}

//TODO: way of telling that all aliens are dead has been removed as of now remember to put that back in

if (reachedEarth)
{
	gameOver();
}
else
{
	//play sound
	alienPos = alienPos + alienDirection;
	var audio = new Audio("Sounds/invaderStep" + (alienPos % 4) + ".wav");
	audio.playbackRate = 0.5 + ((row - 1) * 0.45);
	audio.play();
}

*/