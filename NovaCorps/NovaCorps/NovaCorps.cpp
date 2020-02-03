/*
	NovaCorps - NovaCorps.cpp
		William Chapman

		12/11/2018 10:38:29 AM

	This cpp file describes the main game class

*/

//Include helper
#include <cstdlib>
#include <iostream>
#include "NovaCorps.h"
#include <SFML/Window.hpp>
#include <thread>
#include "r.h"

//Constructor
NovaCorps::NovaCorps() :
m_eGameMode(GameMode::menu),
m_eButton(Button::play),
m_iRound(0),
m_pRenderWindow(new sf::RenderWindow(sf::VideoMode(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height), "NovaCorps", sf::Style::Fullscreen)),
m_pCamera(new OrthographicCamera(*m_pRenderWindow)),
m_pScene(new Scene(*m_pCamera)),
m_pPlayButtonAnimation(new Animation()),
m_pPlayButtonAnimState0(new AnimationState("Assets/Images/UI/MenuButtons/playButton0Selected.png", 0.4f)),
m_pPlayButtonAnimState1(new AnimationState("Assets/Images/UI/MenuButtons/playButton1Selected.png", 0.4f)),
m_pControlsButtonAnimation(new Animation()),
m_pControlsButtonAnimState0(new AnimationState("Assets/Images/UI/MenuButtons/controlsButton0.png", 0.4f)),
m_pControlsButtonAnimState1(new AnimationState("Assets/Images/UI/MenuButtons/controlsButton0.png", 0.4f)),
m_pSettingsButtonAnimation(new Animation()),
m_pSettingsButtonAnimState0(new AnimationState("Assets/Images/UI/MenuButtons/settingsButton0.png", 0.4f)),
m_pSettingsButtonAnimState1(new AnimationState("Assets/Images/UI/MenuButtons/settingsButton0.png", 0.4f)),
m_pQuitButtonAnimation(new Animation()),
m_pQuitButtonAnimState0(new AnimationState("Assets/Images/UI/MenuButtons/quitButton0.png", 0.4f)),
m_pQuitButtonAnimState1(new AnimationState("Assets/Images/UI/MenuButtons/quitButton0.png", 0.4f)),
m_pBackButtonAnimation(new Animation()),
m_pBackButtonAnimState0(new AnimationState("Assets/Images/UI/MenuButtons/backButton0Selected.png", 0.4f)),
m_pBackButtonAnimState1(new AnimationState("Assets/Images/UI/MenuButtons/backButton1Selected.png", 0.4f)),
m_pPlayerRunningAnimation(new Animation()),
m_pPlayerRunningAnimState0(new AnimationState("Assets/Images/Player/player0.png", 0.1f)),
m_pPlayerRunningAnimState1(new AnimationState("Assets/Images/Player/player1.png", 0.1f)),
m_pPlayerLeftAnimation(new Animation()),
m_pPlayerLeftAnimState0(new AnimationState("Assets/Images/Player/playerLeft0.png", 0.1f)),
m_pPlayerLeftAnimState1(new AnimationState("Assets/Images/Player/playerLeft1.png", 0.1f)),
m_pPlayerRightAnimation(new Animation()),
m_pPlayerRightAnimState0(new AnimationState("Assets/Images/Player/playerRight0.png", 0.1f)),
m_pPlayerRightAnimState1(new AnimationState("Assets/Images/Player/playerRight1.png", 0.1f)),
m_pPlayerDieAnimation(new Animation()),
m_pPlayerDieAnimState0(new AnimationState("Assets/Images/Player/playerDie0.png", 0.2f)),
m_pPlayerDieAnimState1(new AnimationState("Assets/Images/Player/playerDie1.png", 0.2f)),
m_pDroneRunningAnimation(new Animation()),
m_pDroneRunningAnimState0(new AnimationState("Assets/Images/Enemies/Drone/drone0.png", 0.1f)),
m_pDroneRunningAnimState1(new AnimationState("Assets/Images/Enemies/Drone/drone1.png", 0.1f)),
m_pDroneDieAnimation(new Animation()),
m_pDroneDieAnimState0(new AnimationState("Assets/Images/Enemies/Drone/drone0.png", 0.1f)),
m_pDroneDieAnimState1(new AnimationState("Assets/Images/Enemies/Drone/drone0.png", 0.1f)),
m_pInvaderRunningAnimation(new Animation()),
m_pInvaderRunningAnimState0(new AnimationState("Assets/Images/Enemies/Invader/invader0.png", 0.1f)),
m_pInvaderRunningAnimState1(new AnimationState("Assets/Images/Enemies/Invader/invader1.png", 0.1f)),
m_pInvaderDieAnimation(new Animation()),
m_pInvaderDieAnimState0(new AnimationState("Assets/Images/Enemies/Invader/invader0.png", 0.1f)),
m_pInvaderDieAnimState1(new AnimationState("Assets/Images/Enemies/Invader/invader0.png", 0.1f)),
m_pSeekerRunningAnimation(new Animation()),
m_pSeekerRunningAnimState0(new AnimationState("Assets/Images/Enemies/Seeker/seeker0.png", 0.1f)),
m_pSeekerRunningAnimState1(new AnimationState("Assets/Images/Enemies/Seeker/seeker1.png", 0.1f)),
m_pSeekerDieAnimation(new Animation()),
m_pSeekerDieAnimState0(new AnimationState("Assets/Images/Enemies/Seeker/seeker0.png", 0.1f)),
m_pSeekerDieAnimState1(new AnimationState("Assets/Images/Enemies/Seeker/seeker0.png", 0.1f)),
m_pPlayerMissileStandardAnimation(new Animation()),
m_pPlayerMissileStandardAnimState0(new AnimationState("Assets/Images/Missiles/playerMissileStandard0.png", 0.1f)),
m_pPlayerMissileStandardAnimState1(new AnimationState("Assets/Images/Missiles/playerMissileStandard1.png", 0.1f)),
m_pPlayerMissileDoubleAnimation(new Animation()),
m_pPlayerMissileDoubleAnimState0(new AnimationState("Assets/Images/Missiles/playerMissileDouble0.png", 0.1f)),
m_pPlayerMissileDoubleAnimState1(new AnimationState("Assets/Images/Missiles/playerMissileDouble1.png", 0.1f)),
m_pDroneMissileAnimation(new Animation()),
m_pDroneMissileAnimState0(new AnimationState("Assets/Images/Missiles/droneMissile0.png", 0.075f)),
m_pDroneMissileAnimState1(new AnimationState("Assets/Images/Missiles/droneMissile1.png", 0.075f)),
m_pInvaderMissileAnimation(new Animation()),
m_pInvaderMissileAnimState0(new AnimationState("Assets/Images/Missiles/invaderMissile0.png", 0.075f)),
m_pInvaderMissileAnimState1(new AnimationState("Assets/Images/Missiles/invaderMissile1.png", 0.075f)),
m_pSeekerMissileAnimation(new Animation()),
m_pSeekerMissileAnimState0(new AnimationState("Assets/Images/Missiles/seekerMissile0.png", 0.075f)),
m_pSeekerMissileAnimState1(new AnimationState("Assets/Images/Missiles/seekerMissile1.png", 0.075f)),
m_pTitleAnimation(new Animation()),
m_pTitleAnimState(new AnimationState("Assets/Images/UI/Cards/title.png", 10000.f)),
m_pGameOverAnimation(new Animation()),
m_pGameOverAnimState(new AnimationState("Assets/Images/UI/Cards/gameOver.png", 10000.f)),
m_pPlayPromptAnimation(new Animation()),
m_pPlayPromptAnimState0(new AnimationState("Assets/Images/UI/Prompts/pressToPlayPrompt0.png", 0.4f)),
m_pPlayPromptAnimState1(new AnimationState("Assets/Images/UI/Prompts/pressToPlayPrompt1.png", 0.4f)),
m_pMovePromptAnimation(new Animation()),
m_pMovePromptAnimState0(new AnimationState("Assets/Images/UI/Prompts/pressToMovePrompt0.png", 0.45f)),
m_pMovePromptAnimState1(new AnimationState("Assets/Images/UI/Prompts/pressToMovePrompt1.png", 0.45f)),
m_pShootPromptAnimation(new Animation()),
m_pShootPromptAnimState0(new AnimationState("Assets/Images/UI/Prompts/pressToShootPrompt0.png", 0.45f)),
m_pShootPromptAnimState1(new AnimationState("Assets/Images/UI/Prompts/pressToShootPrompt1.png", 0.45f)),
m_pParticleAnimation(new Animation()),
m_pParticleAnimState(new AnimationState("Assets/Images/Particles/particle.png", 10000.f)),
m_pTitleCard(new Graphic(m_pTitleAnimation, m_pRenderWindow, sf::FloatRect(600.f, 430.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.25f))),
m_pPlayPrompt(new Graphic(m_pPlayPromptAnimation, m_pRenderWindow, sf::FloatRect(637.f, 60.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.5f))),
m_pMovePrompt(new Graphic(m_pMovePromptAnimation, m_pRenderWindow, sf::FloatRect(1077.f, 197.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.5f))),
m_pShootPrompt(new Graphic(m_pShootPromptAnimation, m_pRenderWindow, sf::FloatRect(855.f, 75.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.6f))),
m_pPlayButton(new Graphic(m_pPlayButtonAnimation, m_pRenderWindow, sf::FloatRect(180.f, 113.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.6f))),
m_pControlsButton(new Graphic(m_pControlsButtonAnimation, m_pRenderWindow, sf::FloatRect(349.f, 113.f, 0.f, 0.f), sf::FloatRect(0.f, 10.f, 0.5f, 0.7f))),
m_pSettingsButton(new Graphic(m_pSettingsButtonAnimation, m_pRenderWindow, sf::FloatRect(349.f, 113.f, 0.f, 0.f), sf::FloatRect(0.f, 20.f, 0.5f, 0.8f))),
m_pQuitButton(new Graphic(m_pQuitButtonAnimation, m_pRenderWindow, sf::FloatRect(181.f, 113.f, 0.f, 0.f), sf::FloatRect(0.f, 30.f, 0.5f, 0.9f))),
m_pBackButton(new Graphic(m_pBackButtonAnimation, m_pRenderWindow, sf::FloatRect(637.f, 60.f, 0.f, 0.f), sf::FloatRect(0.f, 0.f, 0.5f, 0.8f))),
m_pPlayer(new Player()),
m_aBasePlayerStandardMissile(new PlayerMissileStandard()),
m_aBasePlayerDoubleMissile(new PlayerMissileStandard()),
m_pBaseDroneMissile(new InvaderMissile()), //TODO: see if I can initialise with a player too (have InvaderMissile() and overload InvaderMissile(player*)
m_pBaseInvaderMissile(new InvaderMissile()),
m_pBaseSeekerMissile(new InvaderMissile()),
m_tLastUpdate(std::chrono::system_clock::now()),
m_tLastSecond(std::chrono::system_clock::now()),
m_iUpdatesThisSecond(0),
m_iFramesThisSecond(0),
m_iLogicThisSecond(0),
m_bShakeCam(false)
{

	//Set render window to be fullscreen
	m_pRenderWindow->setPosition(sf::Vector2i(0, 0));

	//Hide mouse cursor
	m_pRenderWindow->setMouseCursorVisible(false);

	//VSync
	m_pRenderWindow->setVerticalSyncEnabled(true);

	//Set up camera
	m_pCamera->setPosition(sf::VideoMode::getDesktopMode().width / 2.f, sf::VideoMode::getDesktopMode().height / 2.f);

	//Load everything
	loadGame();
}

//Destructor
NovaCorps::~NovaCorps()
{
	//Delete missiles (pool has method of deleting its own contents when destructed)
	delete m_pDroneMissiles;
	delete m_pInvaderMissiles;
	delete m_pSeekerMissiles;
	delete m_aPlayerStandardMissiles;

	//Delete Scene (deletes everything added to it, no need to delete m_pStars, player, etc)
	delete m_pScene;
	
	//Delete Stars
	delete m_pStars;
	delete m_pStars2;
	delete m_pStars3; 

	//Delete Animations
	delete m_pPlayerRunningAnimation;
	delete m_pPlayerRunningAnimState0;
	delete m_pPlayerRunningAnimState1;
	delete m_pPlayerDieAnimation;
	delete m_pPlayerDieAnimState0;
	delete m_pPlayerDieAnimState1;
	delete m_pDroneRunningAnimation;
	delete m_pDroneRunningAnimState0;
	delete m_pDroneRunningAnimState1;
	delete m_pDroneDieAnimation;
	delete m_pDroneDieAnimState0;
	delete m_pDroneDieAnimState1;
	delete m_pInvaderRunningAnimation;
	delete m_pInvaderRunningAnimState0;
	delete m_pInvaderRunningAnimState1;
	delete m_pInvaderDieAnimation;
	delete m_pInvaderDieAnimState0;
	delete m_pInvaderDieAnimState1;
	delete m_pSeekerRunningAnimation;
	delete m_pSeekerRunningAnimState0;
	delete m_pSeekerRunningAnimState1;
	delete m_pSeekerDieAnimation;
	delete m_pSeekerDieAnimState0;
	delete m_pSeekerDieAnimState1;
	delete m_pPlayerMissileStandardAnimation;
	delete m_pPlayerMissileStandardAnimState0;
	delete m_pPlayerMissileStandardAnimState1;
	delete m_pDroneMissileAnimation;
	delete m_pDroneMissileAnimState0;
	delete m_pDroneMissileAnimState1;
	delete m_pInvaderMissileAnimation;
	delete m_pInvaderMissileAnimState0;
	delete m_pInvaderMissileAnimState1;
	delete m_pSeekerMissileAnimation;
	delete m_pSeekerMissileAnimState0;
	delete m_pSeekerMissileAnimState1;
	delete m_pTitleAnimation;
	delete m_pTitleAnimState;
	delete m_pGameOverAnimation;
	delete m_pGameOverAnimState;
	delete m_pPlayPromptAnimation;
	delete m_pPlayPromptAnimState0;
	delete m_pPlayPromptAnimState1;
	delete m_pMovePromptAnimation;
	delete m_pMovePromptAnimState0;
	delete m_pMovePromptAnimState1;
	delete m_pShootPromptAnimation;
	delete m_pShootPromptAnimState0;
	delete m_pShootPromptAnimState1;
	delete m_pParticleAnimation;
	delete m_pParticleAnimState;

	//Delete wave EventSequence
	for (auto wave : m_aWaves)
	{
		delete wave;
	}

	//Delete camera
	delete m_pCamera;

}

//Load everything
void NovaCorps::loadGame()
{
	//Load the assets
	loadAssets();

	//Load in the stars
	loadStars();

	//Load in the Graphics
	loadGraphics();

	//Load in the characters
	loadCharacters();

	//Load in the Missiles
	loadMissiles();

	//Load the events
	loadEvents();
}

//Load game assets
void NovaCorps::loadAssets()
{
	//Player
	m_pScene->camera().loadTexture("Assets/Images/Player/player0.png");
	m_pScene->camera().loadTexture("Assets/Images/Player/player1.png");
	m_pPlayerRunningAnimation->addAnimationStep(m_pPlayerRunningAnimState0);
	m_pPlayerRunningAnimation->addAnimationStep(m_pPlayerRunningAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Player/playerLeft0.png");
	m_pScene->camera().loadTexture("Assets/Images/Player/playerLeft1.png");
	m_pPlayerLeftAnimation->addAnimationStep(m_pPlayerLeftAnimState0);
	m_pPlayerLeftAnimation->addAnimationStep(m_pPlayerLeftAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Player/playerRight0.png");
	m_pScene->camera().loadTexture("Assets/Images/Player/playerRight1.png");
	m_pPlayerRightAnimation->addAnimationStep(m_pPlayerRightAnimState0);
	m_pPlayerRightAnimation->addAnimationStep(m_pPlayerRightAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Player/playerDie0.png");
	m_pScene->camera().loadTexture("Assets/Images/Player/playerDie1.png");
	m_pPlayerDieAnimation->addAnimationStep(m_pPlayerDieAnimState0);
	m_pPlayerDieAnimation->addAnimationStep(m_pPlayerDieAnimState1);

	//Enemies
	m_pScene->camera().loadTexture("Assets/Images/Enemies/Drone/drone0.png");
	m_pScene->camera().loadTexture("Assets/Images/Enemies/Drone/drone1.png");
	m_pDroneRunningAnimation->addAnimationStep(m_pDroneRunningAnimState0);
	m_pDroneRunningAnimation->addAnimationStep(m_pDroneRunningAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Enemies/Invader/invader0.png");
	m_pScene->camera().loadTexture("Assets/Images/Enemies/Invader/invader1.png");
	m_pInvaderRunningAnimation->addAnimationStep(m_pInvaderRunningAnimState0);
	m_pInvaderRunningAnimation->addAnimationStep(m_pInvaderRunningAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Enemies/Seeker/seeker0.png");
	m_pScene->camera().loadTexture("Assets/Images/Enemies/Seeker/seeker1.png");
	m_pSeekerRunningAnimation->addAnimationStep(m_pSeekerRunningAnimState0);
	m_pSeekerRunningAnimation->addAnimationStep(m_pSeekerRunningAnimState1);

	//Missiles
	m_pScene->camera().loadTexture("Assets/Images/Missiles/playerMissileStandard0.png");
	m_pScene->camera().loadTexture("Assets/Images/Missiles/playerMissileStandard1.png");
	m_pPlayerMissileStandardAnimation->addAnimationStep(m_pPlayerMissileStandardAnimState0);
	m_pPlayerMissileStandardAnimation->addAnimationStep(m_pPlayerMissileStandardAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Missiles/playerMissileDouble0.png");
	m_pScene->camera().loadTexture("Assets/Images/Missiles/playerMissileDouble1.png");
	m_pPlayerMissileDoubleAnimation->addAnimationStep(m_pPlayerMissileDoubleAnimState0);
	m_pPlayerMissileDoubleAnimation->addAnimationStep(m_pPlayerMissileDoubleAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Missiles/droneMissile0.png");
	m_pScene->camera().loadTexture("Assets/Images/Missiles/droneMissile1.png");
	m_pDroneMissileAnimation->addAnimationStep(m_pDroneMissileAnimState0);
	m_pDroneMissileAnimation->addAnimationStep(m_pDroneMissileAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Missiles/invaderMissile0.png");
	m_pScene->camera().loadTexture("Assets/Images/Missiles/invaderMissile1.png");
	m_pInvaderMissileAnimation->addAnimationStep(m_pInvaderMissileAnimState0);
	m_pInvaderMissileAnimation->addAnimationStep(m_pInvaderMissileAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/Missiles/seekerMissile0.png");
	m_pScene->camera().loadTexture("Assets/Images/Missiles/seekerMissile1.png");
	m_pSeekerMissileAnimation->addAnimationStep(m_pSeekerMissileAnimState0);
	m_pSeekerMissileAnimation->addAnimationStep(m_pSeekerMissileAnimState1);

	//Particles
	m_pScene->camera().loadTexture("Assets/Images/Particles/particle.png");
	m_pParticleAnimation->addAnimationStep(m_pParticleAnimState);

	//Text and fonts
	//std::cout << "Loading Font" << std::endl;
	m_cFont.loadFromFile("Assets/Fonts/pointFont.ttf");

	//Cards
	m_pScene->camera().loadTexture("Assets/Images/UI/Cards/title.png");
	m_pTitleAnimation->addAnimationStep(m_pTitleAnimState);

	m_pScene->camera().loadTexture("Assets/Images/UI/Cards/gameOver.png");
	m_pGameOverAnimation->addAnimationStep(m_pGameOverAnimState);

	//Prompts
	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToPlayPrompt0.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToPlayPrompt1.png");
	m_pPlayPromptAnimation->addAnimationStep(m_pPlayPromptAnimState0);
	m_pPlayPromptAnimation->addAnimationStep(m_pPlayPromptAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToMovePrompt0.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToMovePrompt1.png");
	m_pMovePromptAnimation->addAnimationStep(m_pMovePromptAnimState0);
	m_pMovePromptAnimation->addAnimationStep(m_pMovePromptAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToShootPrompt0.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/Prompts/pressToShootPrompt1.png");
	m_pShootPromptAnimation->addAnimationStep(m_pShootPromptAnimState0);
	m_pShootPromptAnimation->addAnimationStep(m_pShootPromptAnimState1);

	//Buttons
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/playButton0.png");
	//m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/playButton1.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/playButton0Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/playButton1Selected.png");
	m_pPlayButtonAnimation->addAnimationStep(m_pPlayButtonAnimState0);
	m_pPlayButtonAnimation->addAnimationStep(m_pPlayButtonAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/controlsButton0.png");
	//m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/controlsButton1.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/controlsButton0Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/controlsButton1Selected.png");
	m_pControlsButtonAnimation->addAnimationStep(m_pControlsButtonAnimState0);
	m_pControlsButtonAnimation->addAnimationStep(m_pControlsButtonAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/settingsButton0.png");
	//m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/settingsButton1.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/settingsButton0Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/settingsButton1Selected.png");
	m_pSettingsButtonAnimation->addAnimationStep(m_pSettingsButtonAnimState0);
	m_pSettingsButtonAnimation->addAnimationStep(m_pSettingsButtonAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/quitButton0.png");
	//m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/quitButton1.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/quitButton0Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/quitButton1Selected.png");
	m_pQuitButtonAnimation->addAnimationStep(m_pQuitButtonAnimState0);
	m_pQuitButtonAnimation->addAnimationStep(m_pQuitButtonAnimState1);

	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/backButton0Selected.png");
	//m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/backButton1Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/backButton0Selected.png");
	m_pScene->camera().loadTexture("Assets/Images/UI/MenuButtons/backButton1Selected.png");
	m_pBackButtonAnimation->addAnimationStep(m_pBackButtonAnimState0);
	m_pBackButtonAnimation->addAnimationStep(m_pBackButtonAnimState1);

	//Sounds
	m_sStartSound.loadFromFile("Assets/Audio/GameSounds/start.ogg");
	m_sGameOverSound.loadFromFile("Assets/Audio/GameSounds/gameOver.ogg");
	m_sMenuStartupSound.loadFromFile("Assets/Audio/GameSounds/menuStartup.ogg");
	m_sPlayerAppearSound.loadFromFile("Assets/Audio/Characters/Player/appear.ogg");
	m_sInvaderAppearSound.loadFromFile("Assets/Audio/Characters/Invader/appear.ogg");
	m_sPlayerFireSound.loadFromFile("Assets/Audio/Firing/playerFire.ogg");
	m_sEnemyFireSound.loadFromFile("Assets/Audio/Firing/alienFire.ogg");

	//Music
	m_sTitleMusic.openFromFile("Assets/Audio/GameSounds/menuBackground.ogg");
	m_sBackgroundMusic.openFromFile("Assets/Audio/GameSounds/background.ogg");

}

//Load the stars up
void NovaCorps::loadStars()
{
	//Starfield
	Particle l_particle;
	l_particle.setScale(3.f, 3.f);

	m_pStars = new ParticleEmitter(m_pParticleAnimation, l_particle, true, false);
	m_pStars->emitting(true);
	m_pStars->maxParticles(200);
	m_pStars->lifeTime(11.0f);
	m_pStars->emissionRate(14.7f);
	m_pStars->maxRange(2000.f);
	m_pStars->position(sf::Vector2f(960.f, 100.f));
	m_pStars->size(sf::Vector2f(1920.f, 0.f));
	m_pStars->emissionVelocity(sf::Vector2f(0.f, 80.f));
	m_pStars->scaleSpeed(100.f);

	m_pStars2 = new ParticleEmitter(m_pParticleAnimation, l_particle, true, false);
	m_pStars2->emitting(true);
	m_pStars2->maxParticles(200);
	m_pStars2->lifeTime(14.67f);
	m_pStars2->emissionRate(11.f);
	m_pStars2->maxRange(2000.f);
	m_pStars2->position(sf::Vector2f(960.f, 100.f));
	m_pStars2->size(sf::Vector2f(1920.f, 0.f));
	m_pStars2->emissionVelocity(sf::Vector2f(0.f, 60.f));
	m_pStars2->scaleSpeed(100.f);

	m_pStars3 = new ParticleEmitter(m_pParticleAnimation, l_particle, true, false);
	m_pStars3->emitting(true);
	m_pStars3->maxParticles(200);
	m_pStars3->lifeTime(22.f);
	m_pStars3->emissionRate(7.3f);
	m_pStars3->maxRange(2000.f);
	m_pStars3->position(sf::Vector2f(960.f, 100.f));
	m_pStars3->size(sf::Vector2f(1920.f, 0.f));
	m_pStars3->emissionVelocity(sf::Vector2f(0.f, 40.f));
	m_pStars3->scaleSpeed(100.f);
}

//Load in the Graphics
void NovaCorps::loadGraphics()
{
	//Some graphics, such as title graphics, are not loaded into the scene's graphics list so as not to use CPU time uneccessarily when playing

	//Add prompts
	m_pScene->addGraphic(m_pMovePrompt);
	m_pMovePrompt->active(false);
	m_pScene->addGraphic(m_pShootPrompt);
	m_pShootPrompt->active(false);

	//Setup Buttons
	m_pControlsButton->colour(sf::Color(150U, 150U, 150U, 100U));
	m_pSettingsButton->colour(sf::Color(150U, 150U, 150U, 100U));

	//Text
	m_cPointsText.setCharacterSize(50);
	m_cPointsText.setFillColor(sf::Color::White);
	m_cPointsText.setPosition(sf::Vector2f(75.f, 980.f));
	m_cHealthText.setCharacterSize(50);
	m_cHealthText.setFillColor(sf::Color::White);
	m_cHealthText.setPosition(sf::Vector2f(1700.f, 980.f));
	m_cRoundText.setCharacterSize(50);
	m_cRoundText.setFillColor(sf::Color::White);
	m_cPointsText.setPosition(sf::Vector2f(75.f, 10.f));
}

//Load the characters into memory
void NovaCorps::loadCharacters()
{

	//Add player to scene
	m_pPlayer->animation(m_pPlayerRunningAnimation);
	m_pScene->addObject(m_pPlayer);
	
	//Make pool of drones
	Drone l_drone;
	l_drone.animation(m_pDroneRunningAnimation);
	l_drone.position(sf::Vector2f(500.f, 200.f));
	l_drone.velocity(sf::Vector2f(420.f, 40.f));
	m_pDrones = new Pool<Drone>(&l_drone, 100);

	//Add all drones to scene
	auto l_drones = m_pDrones->activeAddresses(nullptr);
	for (int i = 0; i < m_pDrones->size(); i++) m_pScene->addObject(l_drones[i]);

	//Make pool of invaders
	Invader l_invader;
	l_invader.animation(m_pInvaderRunningAnimation);
	l_invader.position(sf::Vector2f(500.f, 200.f));
	l_invader.velocity(sf::Vector2f(420.f, 40.f));
	m_pInvaders = new Pool<Invader>(&l_invader, 100);

	//Add all invaders to scene
	auto l_invaders = m_pInvaders->activeAddresses(nullptr);
	for (int i = 0; i < m_pInvaders->size(); i++) m_pScene->addObject(l_invaders[i]);

	//Make pool of seekers
	Seeker l_seeker;
	l_seeker.animation(m_pSeekerRunningAnimation);
	l_seeker.position(sf::Vector2f(500.f, 200.f));
	l_seeker.velocity(sf::Vector2f(420.f, 40.f));
	m_pSeekers = new Pool<Seeker>(&l_seeker, 100);

	//Add all seekers to scene
	auto l_seekers = m_pSeekers->activeAddresses(nullptr);
	for (int i = 0; i < m_pSeekers->size(); i++) m_pScene->addObject(l_seekers[i]);
}

//Load the missiles into memory
void NovaCorps::loadMissiles()
{
	//Make a pool of drone missiles
	m_aBasePlayerStandardMissile->animation(m_pPlayerMissileStandardAnimation);
	m_aPlayerStandardMissiles = new Pool<PlayerMissileStandard>(m_aBasePlayerStandardMissile, 30);

	m_aBasePlayerDoubleMissile->animation(m_pPlayerMissileDoubleAnimation);
	m_aBasePlayerDoubleMissile->size(sf::Vector2f(32.f, 40.f));
	m_aPlayerDoubleMissiles = new Pool<PlayerMissileStandard>(m_aBasePlayerDoubleMissile, 30);

	//Make a pool of drone missiles
	m_pBaseDroneMissile->exclusiveTarget(m_pPlayer);
	m_pBaseDroneMissile->animation(m_pDroneMissileAnimation);
	m_pBaseDroneMissile->size(sf::Vector2f(5.f, 20.f));
	m_pDroneMissiles = new Pool<InvaderMissile>(m_pBaseDroneMissile, 30);

	//Make a pool of invader missiles
	m_pBaseInvaderMissile->exclusiveTarget(m_pPlayer);
	m_pBaseInvaderMissile->animation(m_pInvaderMissileAnimation);
	m_pInvaderMissiles = new Pool<InvaderMissile>(m_pBaseInvaderMissile, 30);

	//Make a pool of seeker missiles
	m_pBaseSeekerMissile->exclusiveTarget(m_pPlayer);
	m_pBaseSeekerMissile->size(sf::Vector2f(19.f, 50.f));
	m_pBaseSeekerMissile->animation(m_pSeekerMissileAnimation);
	m_pSeekerMissiles = new Pool<InvaderMissile>(m_pBaseSeekerMissile, 30);

	//Add all missiles to scene
	auto l_playerMissiles = m_aPlayerStandardMissiles->activeAddresses(nullptr);
	for (int i = 0; i < m_aPlayerStandardMissiles->size(); i++) m_pScene->addObject(l_playerMissiles[i]);
	auto l_playerDoubleMissiles = m_aPlayerDoubleMissiles->activeAddresses(nullptr);
	for (int i = 0; i < m_aPlayerDoubleMissiles->size(); i++) m_pScene->addObject(l_playerDoubleMissiles[i]);
	auto l_droneMissiles = m_pDroneMissiles->activeAddresses(nullptr);
	for (int i = 0; i < m_pDroneMissiles->size(); i++) m_pScene->addObject(l_droneMissiles[i]);
	auto l_invaderMissiles = m_pInvaderMissiles->activeAddresses(nullptr);
	for (int i = 0; i < m_pInvaderMissiles->size(); i++) m_pScene->addObject(l_invaderMissiles[i]);
	auto l_seekerMissiles = m_pSeekerMissiles->activeAddresses(nullptr);
	for (int i = 0; i < m_pSeekerMissiles->size(); i++) m_pScene->addObject(l_seekerMissiles[i]);	
}

//Load the game events
void NovaCorps::loadEvents()
{
	//GameOver Sequence
	m_aWaves[0] = new EventSequence();

	m_aWaves[0]->addEvent(std::chrono::duration<float>(1.f), new Event([=](Event* self)
	{
		//std::cout << "GO1" << std::endl;
		return true;
	}));
	m_aWaves[0]->addEvent(std::chrono::duration<float>(5.f), new Event([=](Event* self)
	{
		//std::cout << "Going to menu" << std::endl;
		m_eGameMode = GameMode::end;

		return true;
	}));




	//Menu Sequence
	m_aWaves[1] = new EventSequence();

	//Play the music
	m_aWaves[1]->addEvent(std::chrono::duration<float>(0.f), new Event([=](Event* self)
	{
		m_sTitleMusic.setLoop(true);
		m_sTitleMusic.play();
		return true;
	}));

	//Slow down stars
	m_aWaves[1]->addEvent(std::chrono::duration<float>(0.25f), new Event([=](Event* self)
	{
		if (m_pStars->lifeTime() < 5.f)  m_pStars->scaleSpeed(0.01f);
		if (m_pStars2->lifeTime() < 5.f)  m_pStars2->scaleSpeed(0.01f);
		if (m_pStars3->lifeTime() < 5.f)  m_pStars3->scaleSpeed(0.01f);
		if(m_pStars->lifeTime() > 5.f && m_pStars2->lifeTime() > 5.f && m_pStars3->lifeTime() > 5.f)
		{
			m_aWaves[1]->stop();
			return true;
		}
		return false;
	}));




	//Tutorial sequence
	m_aWaves[2] = new EventSequence();

	//Title disappears
	m_aWaves[2]->addEvent(std::chrono::duration<float>(01.5f), new Event([=](Event* self) {
		//std::cout << "Starting Game!" << std::endl;
		m_sTitleMusic.stop();
		m_sBackgroundMusic.setLoop(true);
		m_sBackgroundMusic.play();
		m_pTitleCard->active(false);
		m_pPlayButton->active(false);
		return true;
	}));

	//Player starts coming in
	m_aWaves[2]->addEvent(std::chrono::duration<float>(02.0f), new Event([=](Event* self) {
		m_pPlayer->active(true);
		m_pPlayer->position(sf::Vector2f(960.f, 1120.f));
		m_pPlayer->velocity(sf::Vector2f(0.f, -85.f));
		m_sSoundManager2.setBuffer(m_sPlayerAppearSound);
		m_sSoundManager2.play();
		return true;
	}));

	//Player stops and move prompt appears
	m_aWaves[2]->addEvent(std::chrono::duration<float>(03.5f), new Event([=](Event* self) {
		if (m_pPlayer->position().y <= 950.f)
		{
			m_pPlayer->velocity(sf::Vector2f(0.f, 0.f));
			m_pPlayer->position(sf::Vector2f(960.f, 950.f));
			m_pMovePrompt->rectPosition(sf::FloatRect(0.f, 0.f, 0.5f, 0.6f), m_pRenderWindow);
			m_pMovePrompt->active(true);
			m_eGameMode = GameMode::playing;
			return true;
		}
		return false;
	}));

	//Wait for player to have moved
	m_aWaves[2]->addEvent(std::chrono::duration<float>(05.0f), new Event([=](Event* self) {
		return (m_pPlayer->position().x < 950.f || m_pPlayer->position().x > 970.f);
	}));

	//Move prompt disappears and shoot prompt appears
	m_aWaves[2]->addEvent(std::chrono::duration<float>(06.0f), new Event([=](Event* self) {
		m_pMovePrompt->active(false);
		m_pShootPrompt->active(true);
		return true;
	}));

	//Wait for player to have shot then make shoot prompt dissapear
	m_aWaves[2]->addEvent(std::chrono::duration<float>(8.f), new Event([=](Event* self) {
		if (m_aPlayerStandardMissiles->activeCount() > 0)
		{
			m_pShootPrompt->active(false);
			m_aWaves[2]->stop();
			m_iRound = 3;
			m_aWaves[3]->start();
			return true;
		}
		return false;
	}));


	//Round 1 sequence
	m_aWaves[3] = new EventSequence();

	//First alien
	m_aWaves[3]->addEvent(std::chrono::duration<float>(3.f), new Event([=](Event* self) {
		auto newInvader = m_pDrones->getNext();
		//std::cout << "New Alien #1! " << newInvader << std::endl;
		if (newInvader != nullptr)
		{
			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			newInvader->active(true);
			return true;
		}
		return false;
	}));

	//Second alien
	m_aWaves[3]->addEvent(std::chrono::duration<float>(6.f), new Event([=](Event* self) {
		auto newInvader = m_pInvaders->getNext();
		//std::cout << "New Alien #2! " << newInvader << std::endl;
		if (newInvader != nullptr)
		{
			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			newInvader->active(true);
			return true;
		}
		return false;
	}));

	//Third alien
	m_aWaves[3]->addEvent(std::chrono::duration<float>(9.0f), new Event([=](Event* self) {
		auto newInvader = m_pSeekers->getNext();
		//std::cout << "New Alien #3 " << newInvader << std::endl;
		if (newInvader != nullptr)
		{
			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			newInvader->active(true);
			return true;
		}
		return false;
	}));

	//Move on to next round
	m_aWaves[3]->addEvent(std::chrono::duration<float>(12.5f), new Event([=](Event* self) {
		//std::cout << "Starting the real challenge" << std::endl;
		nextRound();
		return true;
	}));

	//Round 2 sequence
	m_aWaves[4] = new EventSequence();

	m_aWaves[4]->addEvent(std::chrono::duration<float>(0.1f), new Event([=](Event* self) {
		//std::cout << "Starting second round" << std::endl;
		return true;
	}));

	//Drone Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[4]->addEvent(std::chrono::duration<float>(1+(i*0.3f)), new Event([=](Event* self) {

			auto newInvader = m_pDrones->getNext();
			if (newInvader != nullptr)
			{
				m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
				m_sSoundManager2.play();
				newInvader->position(sf::Vector2f(70.f, -100.f));
				newInvader->velocity(sf::Vector2f(500.f, 200.f));
				newInvader->active(true);
				return true;
			}
			return false;
		}));
	}

	//Invader Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[4]->addEvent(std::chrono::duration<float>(5.5f + (i*0.3f)), new Event([=](Event* self) {

			auto newInvader = m_pInvaders->getNext();
			if (newInvader != nullptr)
			{
				m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
				m_sSoundManager2.play();
				newInvader->position(sf::Vector2f(1850.f, -100.f));
				newInvader->velocity(sf::Vector2f(-500.f, 200.f));
				newInvader->active(true);
				return true;
			}
			return false;
		}));
	}

	//Seeker Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[4]->addEvent(std::chrono::duration<float>(11.f + (i*0.3f)), new Event([=](Event* self) {

			auto newInvader = m_pSeekers->getNext();
			if (newInvader != nullptr)
			{
				m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
				m_sSoundManager2.play();
				newInvader->position(sf::Vector2f(70.f, -100.f));
				newInvader->velocity(sf::Vector2f(500.f, 200.f));
				newInvader->active(true);
				return true;
			}
			return false;
		}));
	}

	//Move on to next round
	m_aWaves[4]->addEvent(std::chrono::duration<float>(18.0f), new Event([=](Event* self) {
		//std::cout << "Finished second round, moving on" << std::endl;
		nextRound();
		return true;
	}));

	//Round 3 sequence
	m_aWaves[5] = new EventSequence();

	m_aWaves[5]->addEvent(std::chrono::duration<float>(0.1f), new Event([=](Event* self) {
		//std::cout << "Starting third round" << std::endl;
		return true;
	}));

	//Drone Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[5]->addEvent(std::chrono::duration<float>(1+(i*0.4f)), new Event([=](Event* self) {

			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			auto newInvader1 = m_pDrones->getNext();
			auto newInvader2 = m_pDrones->getNext();
			if (newInvader1 != nullptr)
			{
				newInvader1->position(sf::Vector2f(1850.f, -100.f));
				newInvader1->velocity(sf::Vector2f(-500.f, 200.f));
				newInvader1->active(true);
			}
			if (newInvader2 != nullptr)
			{
				newInvader2->position(sf::Vector2f(70.f, -100.f));
				newInvader2->velocity(sf::Vector2f(500.f, 200.f));
				newInvader2->active(true);
			}
			return true;
		}));
	}

	//Invader Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[5]->addEvent(std::chrono::duration<float>(6.f + (i*0.35f)), new Event([=](Event* self) {

			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			auto newInvader1 = m_pInvaders->getNext();
			auto newInvader2 = m_pInvaders->getNext();
			if (newInvader1 != nullptr)
			{
				newInvader1->position(sf::Vector2f(1850.f, -100.f));
				newInvader1->velocity(sf::Vector2f(-500.f, 150.f));
				newInvader1->active(true);
			}
			if (newInvader2 != nullptr)
			{
				newInvader2->position(sf::Vector2f(70.f, -100.f));
				newInvader2->velocity(sf::Vector2f(500.f, 150.f));
				newInvader2->active(true);
			}
			return true;
		}));
	}

	//Seeker Swarm
	for (int i = 0; i < 10; i++)
	{
		m_aWaves[5]->addEvent(std::chrono::duration<float>(11.f + (i*0.3f)), new Event([=](Event* self) {

			m_sSoundManager2.setBuffer(m_sInvaderAppearSound);
			m_sSoundManager2.play();
			auto newInvader1 = m_pSeekers->getNext();
			auto newInvader2 = m_pSeekers->getNext();
			if (newInvader1 != nullptr)
			{
				newInvader1->position(sf::Vector2f(1850.f, -100.f));
				newInvader1->velocity(sf::Vector2f(-500.f, 100.f));
				newInvader1->active(true);
			}
			if (newInvader2 != nullptr)
			{
				newInvader2->position(sf::Vector2f(70.f, -100.f));
				newInvader2->velocity(sf::Vector2f(500.f, 100.f));
				newInvader2->active(true);
			}
			return true;
		}));
	}

	//Move on to next round
	m_aWaves[5]->addEvent(std::chrono::duration<float>(20.0f), new Event([=](Event* self) {
		//std::cout << "Looping back around" << std::endl;
		m_aWaves[5]->stop();
		m_iRound = 4;
		m_aWaves[4]->start();
		return true;
	}));
}

//Update objects
void NovaCorps::update()
{
	//Prep for missile checks
	int l_numberAliens = 0;
	int l_numMissiles = 0;
	Drone** l_activeDrones = nullptr;
	Invader** l_activeInvaders = nullptr;
	Seeker** l_activeSeekers = nullptr;
	PlayerMissileStandard** l_playerStandardMissiles = nullptr;
	PlayerMissileStandard* l_playerStandardMissile = nullptr;
	PlayerMissileStandard** l_playerDoubleMissiles = nullptr;
	PlayerMissileStandard* l_playerDoubleMissile = nullptr;
	InvaderMissile** l_droneMissiles = nullptr;
	InvaderMissile* l_droneMissile = nullptr;
	InvaderMissile** l_invaderMissiles = nullptr;
	InvaderMissile* l_invaderMissile = nullptr;
	InvaderMissile** l_seekerMissiles = nullptr;
	InvaderMissile* l_seekerMissile = nullptr;

	//Code to run while program is running
	while (m_pRenderWindow->isOpen())
	{
		//Rather than the later objects in the vector being updated last and therefore moving further / on a different sync,
		//update all objects to move the same distance (relative to their velocity) at the same time:
		m_fUpdateDeltaTime = std::chrono::duration<float>(std::chrono::system_clock::now() - m_tLastUpdate).count();

		//Throttle frame rate to 1000 maximum, otherwise it literally goes into the millions 
		//That would cause delta time to have weird floating point errors, and make the game crawl at minimum speed
		if (m_fUpdateDeltaTime > 0.001f)
		{
			
			//Check collisions
			switch (m_eGameMode)
			{
			case GameMode::settings:

				//Update Stars
				m_pStars->update(m_fUpdateDeltaTime);
				m_pStars2->update(m_fUpdateDeltaTime);
				m_pStars3->update(m_fUpdateDeltaTime);

				//Update graphics
				m_pMovePromptAnimation->update(m_fUpdateDeltaTime);
				m_pShootPromptAnimation->update(m_fUpdateDeltaTime);
				m_pBackButtonAnimation->update(m_fUpdateDeltaTime);
				break;

				//When in the menu
				case GameMode::menu:

					//Update Stars
					m_pStars->update(m_fUpdateDeltaTime);
					m_pStars2->update(m_fUpdateDeltaTime);
					m_pStars3->update(m_fUpdateDeltaTime);

					//Update anims
					m_pPlayPromptAnimation->update(m_fUpdateDeltaTime);
					m_pPlayButtonAnimation->update(m_fUpdateDeltaTime);
					m_pControlsButtonAnimation->update(m_fUpdateDeltaTime);
					m_pSettingsButtonAnimation->update(m_fUpdateDeltaTime);
					m_pQuitButtonAnimation->update(m_fUpdateDeltaTime);

					if (m_pPlayer->active())
					{
						m_pPlayer->update(m_fUpdateDeltaTime);
						m_pPlayer->physicsUpdate(m_fUpdateDeltaTime);
						m_pPlayerRunningAnimation->update(m_fUpdateDeltaTime);
					}

					break;

				//When playing the game
				case GameMode::playing:
					
					//Update Scene
					m_pScene->update(m_fUpdateDeltaTime);

					//Update Stars
					//m_pStars->update(m_fUpdateDeltaTime);
					m_pStars2->update(m_fUpdateDeltaTime);
					m_pStars3->update(m_fUpdateDeltaTime);

					//Update prompts in tutorial
					if (m_iRound == 2)
					{
						m_pMovePromptAnimation->update(m_fUpdateDeltaTime);
						m_pShootPromptAnimation->update(m_fUpdateDeltaTime);
					}

					//Update anims
					m_pPlayerRunningAnimation->update(m_fUpdateDeltaTime);
					m_pPlayerLeftAnimation->update(m_fUpdateDeltaTime);
					m_pPlayerRightAnimation->update(m_fUpdateDeltaTime);
					m_pPlayerMissileStandardAnimation->update(m_fUpdateDeltaTime);
					m_pPlayerMissileDoubleAnimation->update(m_fUpdateDeltaTime);

					m_pDroneRunningAnimation->update(m_fUpdateDeltaTime);
					m_pDroneDieAnimation->update(m_fUpdateDeltaTime);
					m_pDroneMissileAnimation->update(m_fUpdateDeltaTime);

					m_pInvaderRunningAnimation->update(m_fUpdateDeltaTime);
					m_pInvaderDieAnimation->update(m_fUpdateDeltaTime);
					m_pInvaderMissileAnimation->update(m_fUpdateDeltaTime);

					m_pSeekerRunningAnimation->update(m_fUpdateDeltaTime);
					m_pSeekerDieAnimation->update(m_fUpdateDeltaTime);
					m_pSeekerMissileAnimation->update(m_fUpdateDeltaTime);

					//Kill aliens and release any inactive missiles
					l_playerStandardMissiles = m_aPlayerStandardMissiles->activeAddresses(&l_numMissiles);
					for (l_numMissiles--; l_numMissiles > -1; l_numMissiles--)
					{
						if (!l_playerStandardMissiles[l_numMissiles]->active())
						{
							m_aPlayerStandardMissiles->release(l_playerStandardMissiles[l_numMissiles]);
						}
						else
						{
							//std::cout << "Missile Alive" << std::endl;
							l_activeDrones = m_pDrones->activeAddresses(&l_numberAliens);
							if (l_activeDrones != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerStandardMissiles[l_numMissiles]->checkCollision(l_activeDrones[l_numberAliens]))
									{
										l_playerStandardMissiles[l_numMissiles]->detonate(l_activeDrones[l_numberAliens]);
									}
								}
							}
							l_activeInvaders = m_pInvaders->activeAddresses(&l_numberAliens);
							if (l_activeInvaders != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerStandardMissiles[l_numMissiles]->checkCollision(l_activeInvaders[l_numberAliens]))
									{
										l_playerStandardMissiles[l_numMissiles]->detonate(l_activeInvaders[l_numberAliens]);
									}
								}
							}
							l_activeSeekers = m_pSeekers->activeAddresses(&l_numberAliens);
							if (l_activeSeekers != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerStandardMissiles[l_numMissiles]->checkCollision(l_activeSeekers[l_numberAliens]))
									{
										l_playerStandardMissiles[l_numMissiles]->detonate(l_activeSeekers[l_numberAliens]);
									}
								}
							}
						}
					}

					l_playerDoubleMissiles = m_aPlayerDoubleMissiles->activeAddresses(&l_numMissiles);
					for (l_numMissiles--; l_numMissiles > -1; l_numMissiles--)
					{
						if (!l_playerDoubleMissiles[l_numMissiles]->active())
						{
							m_aPlayerDoubleMissiles->release(l_playerDoubleMissiles[l_numMissiles]);
						}
						else
						{
							//std::cout << "Missile Alive" << std::endl;
							l_activeDrones = m_pDrones->activeAddresses(&l_numberAliens);
							if (l_activeDrones != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerDoubleMissiles[l_numMissiles]->checkCollision(l_activeDrones[l_numberAliens]))
									{
										l_playerDoubleMissiles[l_numMissiles]->detonate(l_activeDrones[l_numberAliens]);
									}
								}
							}
							l_activeInvaders = m_pInvaders->activeAddresses(&l_numberAliens);
							if (l_activeInvaders != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerDoubleMissiles[l_numMissiles]->checkCollision(l_activeInvaders[l_numberAliens]))
									{
										l_playerDoubleMissiles[l_numMissiles]->detonate(l_activeInvaders[l_numberAliens]);
									}
								}
							}
							l_activeSeekers = m_pSeekers->activeAddresses(&l_numberAliens);
							if (l_activeSeekers != nullptr)
							{
								for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
								{
									if (l_playerDoubleMissiles[l_numMissiles]->checkCollision(l_activeSeekers[l_numberAliens]))
									{
										l_playerDoubleMissiles[l_numMissiles]->detonate(l_activeSeekers[l_numberAliens]);
									}
								}
							}
						}
					}

					l_droneMissiles = m_pDroneMissiles->activeAddresses(&l_numMissiles);
					for (l_numMissiles--; l_numMissiles > -1; l_numMissiles--)
					{
						if (!l_droneMissiles[l_numMissiles]->active())
						{
							m_pDroneMissiles->release(l_droneMissiles[l_numMissiles]);
						}
					}
					l_invaderMissiles = m_pInvaderMissiles->activeAddresses(&l_numMissiles);
					for (l_numMissiles--; l_numMissiles > -1; l_numMissiles--)
					{
						if (!l_invaderMissiles[l_numMissiles]->active())
						{
							m_pInvaderMissiles->release(l_invaderMissiles[l_numMissiles]);
						}
					}
					l_seekerMissiles = m_pSeekerMissiles->activeAddresses(&l_numMissiles);
					for (l_numMissiles--; l_numMissiles > -1; l_numMissiles--)
					{
						if (!l_seekerMissiles[l_numMissiles]->active())
						{
							m_pSeekerMissiles->release(l_seekerMissiles[l_numMissiles]);
						}
					}

					//Check drones for collisions and firing
					l_activeDrones = m_pDrones->activeAddresses(&l_numberAliens);
					if (l_activeDrones != nullptr ) //Safety check. Alternative: if (l_numberAliens > 0)
					{
						for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
						{
							if (l_activeDrones[l_numberAliens]->active() && m_pPlayer->checkCollision(l_activeDrones[l_numberAliens]))
							{
								m_pPlayer->health(m_pPlayer->health() - 1);
								l_activeDrones[l_numberAliens]->active(false);

								//l_activeDrones[l_numberAliens]->velocity(sf::Vector2f(-l_activeDrones[l_numberAliens]->velocity().x, -l_activeDrones[l_numberAliens]->velocity().y));

								m_vShakeFactor = sf::Vector2f(r::andom(25.f, 200.f), r::andom(25.f, 200.f));
								m_bShakeCam = true;
							}

							//Make the alien attempt to fire
							if (l_activeDrones[l_numberAliens]->fire())
							{
								l_droneMissile = m_pDroneMissiles->getNext();
							
								if (l_droneMissile != nullptr)
								{
									//position it and set its variables as needed
									//l_missile->creator(l_activeDrones[i]);
									l_droneMissile->position(l_activeDrones[l_numberAliens]->position() + l_activeDrones[l_numberAliens]->fireFromOffset());
									l_droneMissile->velocity(l_activeDrones[l_numberAliens]->fireDirection());

									//Play sound
									m_sSoundManager3.setBuffer(m_sEnemyFireSound);
									m_sSoundManager3.play();

									//Fire the missile
									l_droneMissile->fire();
								}
							}

						}
					}

					//Check invaders for collisions and firing
					l_activeInvaders = m_pInvaders->activeAddresses(&l_numberAliens);
					if (l_activeInvaders != nullptr) //Safety check. Alternative: if (l_numberAliens > 0)
					{
						for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
						{
							if (l_activeInvaders[l_numberAliens]->active() && m_pPlayer->checkCollision(l_activeInvaders[l_numberAliens]))
							{
								m_pPlayer->health(m_pPlayer->health() - 1);
								l_activeDrones[l_numberAliens]->active(false);

								//l_activeInvaders[l_numberAliens]->velocity(sf::Vector2f(-l_activeInvaders[l_numberAliens]->velocity().x, -l_activeInvaders[l_numberAliens]->velocity().y));

								m_vShakeFactor = sf::Vector2f(r::andom(25.f, 200.f), r::andom(25.f, 200.f));
								m_bShakeCam = true;
							}

							//Make the alien attempt to fire
							if (l_activeInvaders[l_numberAliens]->fire())
							{
								l_invaderMissile = m_pInvaderMissiles->getNext();

								if (l_invaderMissile != nullptr)
								{
									//position it and set its variables as needed
									//l_missile->creator(l_activeDrones[i]);
									l_invaderMissile->position(l_activeInvaders[l_numberAliens]->position() + l_activeInvaders[l_numberAliens]->fireFromOffset());
									l_invaderMissile->velocity(l_activeInvaders[l_numberAliens]->fireDirection());

									//Play sound
									m_sSoundManager3.setBuffer(m_sEnemyFireSound);
									m_sSoundManager3.play();

									//Fire the missile
									l_invaderMissile->fire();
								}
							}

						}
					}

					//Check seekers for collisions and firing
					l_activeSeekers = m_pSeekers->activeAddresses(&l_numberAliens);
					if (l_activeSeekers != nullptr) //Safety check. Alternative: if (l_numberAliens > 0)
					{
						for (l_numberAliens--; l_numberAliens > -1; l_numberAliens--)
						{
							if (l_activeSeekers[l_numberAliens]->active() && m_pPlayer->checkCollision(l_activeSeekers[l_numberAliens]))
							{

								m_pPlayer->health(m_pPlayer->health() - 1);
								l_activeDrones[l_numberAliens]->active(false);

								//l_activeSeekers[l_numberAliens]->velocity(sf::Vector2f(-l_activeSeekers[l_numberAliens]->velocity().x, -l_activeSeekers[l_numberAliens]->velocity().y));

								m_vShakeFactor = sf::Vector2f(r::andom(25.f, 200.f), r::andom(25.f, 200.f));
								m_bShakeCam = true;
							}

							//Make the alien attempt to fire
							if (l_activeSeekers[l_numberAliens]->fire())
							{
								l_seekerMissile = m_pSeekerMissiles->getNext();

								if (l_seekerMissile != nullptr)
								{
									//position it and set its variables as needed
									//l_missile->creator(l_activeDrones[i]);
									l_seekerMissile->position(l_activeSeekers[l_numberAliens]->position() + l_activeSeekers[l_numberAliens]->fireFromOffset());
									l_seekerMissile->velocity(l_activeSeekers[l_numberAliens]->fireDirection());

									//Play sound
									m_sSoundManager3.setBuffer(m_sEnemyFireSound);
									m_sSoundManager3.play();

									//Fire the missile
									l_seekerMissile->fire();
								}
							}
						}
					}
					
					break;

				//When on the game over screen
				case GameMode::gameOver:
					//std::cout << "Game over" << std::endl;

					//Update anims
					m_pPlayerDieAnimation->update(m_fUpdateDeltaTime);
					m_pGameOverAnimation->update(m_fUpdateDeltaTime);

					break;

				//When quitting out
				case GameMode::end:

					break;

				default:
					break;
			}

			//Reset last update
			m_tLastUpdate = std::chrono::system_clock::now();

			//Increment update cycles this second
			m_iUpdatesThisSecond++;
		}
	}
}

//Do logic such as input
void NovaCorps::logic()
{
	//Code to run while program is running
	while (m_pRenderWindow->isOpen())
	{

		//Update wave EventSequence
		if (m_iRound > -1) m_aWaves[m_iRound]->update();


		switch (m_eGameMode)
		{
		case GameMode::settings:
			if (m_eButton == Button::back && (m_eLastKey == sf::Keyboard::Key::Space || m_eLastKey == sf::Keyboard::Key::Enter))
			{
				menu();
			}
			break;

		//When in the menu
		case GameMode::menu:

			//What to do for button press
			if (m_eLastKey != sf::Keyboard::Key::Unknown)
			{
				switch (m_eButton)
				{
					case Button::play:
						m_pPlayButtonAnimation->texture("Assets/Images/UI/MenuButtons/playButton0.png");
						m_pPlayButtonAnimState0->texture("Assets/Images/UI/MenuButtons/playButton0.png");
						m_pPlayButtonAnimState1->texture("Assets/Images/UI/MenuButtons/playButton0.png");
						if (m_eLastKey == sf::Keyboard::Key::W || m_eLastKey == sf::Keyboard::Key::Up)
						{
							m_eButton = Button::quit;
							m_pPlayPrompt->active(false);
						}
						if (m_eLastKey == sf::Keyboard::Key::S || m_eLastKey == sf::Keyboard::Key::Down) 
						{
							m_eButton = Button::controls;
							m_pPlayPrompt->active(false);
						}
						if (m_pQuitButton->active() && (m_eLastKey == sf::Keyboard::Key::Space || m_eLastKey == sf::Keyboard::Key::Enter))
						{
							m_pControlsButton->active(false);
							m_pSettingsButton->active(false);
							m_pQuitButton->active(false);
							m_pPlayPrompt->active(false);
							m_sSoundManager.setBuffer(m_sStartSound);
							m_sSoundManager.play();
							m_aWaves[1]->stop();
							m_iRound = 2;
							m_aWaves[2]->start();
						}
						break;

					case Button::controls:
						m_pControlsButtonAnimation->texture("Assets/Images/UI/MenuButtons/controlsButton0.png");
						m_pControlsButtonAnimState0->texture("Assets/Images/UI/MenuButtons/controlsButton0.png");
						m_pControlsButtonAnimState1->texture("Assets/Images/UI/MenuButtons/controlsButton0.png");
						if (m_eLastKey == sf::Keyboard::Key::W || m_eLastKey == sf::Keyboard::Key::Up) m_eButton = Button::play;
						if (m_eLastKey == sf::Keyboard::Key::S || m_eLastKey == sf::Keyboard::Key::Down) m_eButton = Button::settings;
						/*if (m_pQuitButton->active() && (m_eLastKey == sf::Keyboard::Key::Space || m_eLastKey == sf::Keyboard::Key::Enter))
						{
							m_eButton = Button::back;
							m_eGameMode = GameMode::settings;
						}*/
						break;
					case Button::settings:
						m_pSettingsButtonAnimation->texture("Assets/Images/UI/MenuButtons/settingsButton0.png");
						m_pSettingsButtonAnimState0->texture("Assets/Images/UI/MenuButtons/settingsButton0.png");
						m_pSettingsButtonAnimState1->texture("Assets/Images/UI/MenuButtons/settingsButton0.png");
						if (m_eLastKey == sf::Keyboard::Key::W || m_eLastKey == sf::Keyboard::Key::Up) m_eButton = Button::controls;
						if (m_eLastKey == sf::Keyboard::Key::S || m_eLastKey == sf::Keyboard::Key::Down) m_eButton = Button::quit;
						break;
					case Button::quit:
						m_pQuitButtonAnimation->texture("Assets/Images/UI/MenuButtons/quitButton0.png");
						m_pQuitButtonAnimState0->texture("Assets/Images/UI/MenuButtons/quitButton0.png");
						m_pQuitButtonAnimState1->texture("Assets/Images/UI/MenuButtons/quitButton0.png");
						if (m_eLastKey == sf::Keyboard::Key::W || m_eLastKey == sf::Keyboard::Key::Up) m_eButton = Button::settings;
						if (m_eLastKey == sf::Keyboard::Key::S || m_eLastKey == sf::Keyboard::Key::Down) m_eButton = Button::play;
						if (m_pQuitButton->active() && (m_eLastKey == sf::Keyboard::Key::Space || m_eLastKey == sf::Keyboard::Key::Enter))
						{
							m_eGameMode = GameMode::end;
						}
						break;
				}

				switch (m_eButton)
				{
				case Button::play:
					m_pPlayButtonAnimation->texture("Assets/Images/UI/MenuButtons/playButton0Selected.png");
					m_pPlayButtonAnimState0->texture("Assets/Images/UI/MenuButtons/playButton0Selected.png");
					m_pPlayButtonAnimState1->texture("Assets/Images/UI/MenuButtons/playButton1Selected.png");
					break;
				case Button::controls:
					m_pControlsButtonAnimation->texture("Assets/Images/UI/MenuButtons/controlsButton0Selected.png");
					m_pControlsButtonAnimState0->texture("Assets/Images/UI/MenuButtons/controlsButton0Selected.png");
					m_pControlsButtonAnimState1->texture("Assets/Images/UI/MenuButtons/controlsButton1Selected.png");
					break;
				case Button::settings:
					m_pSettingsButtonAnimation->texture("Assets/Images/UI/MenuButtons/settingsButton0Selected.png");
					m_pSettingsButtonAnimState0->texture("Assets/Images/UI/MenuButtons/settingsButton0Selected.png");
					m_pSettingsButtonAnimState1->texture("Assets/Images/UI/MenuButtons/settingsButton1Selected.png");
					break;
				case Button::quit:
					m_pQuitButtonAnimation->texture("Assets/Images/UI/MenuButtons/quitButton0Selected.png");
					m_pQuitButtonAnimState0->texture("Assets/Images/UI/MenuButtons/quitButton0Selected.png");
					m_pQuitButtonAnimState1->texture("Assets/Images/UI/MenuButtons/quitButton1Selected.png");
					break;
				}
			}

			break;

			//When playing the game
		case GameMode::playing:

			//Move left
			if (m_pPlayer->position().x > 50.f && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)))
			{
				//If left key is pressed set velocity as appropriate
				m_pPlayer->velocity(sf::Vector2f(-750.f, 0.f));
				m_pPlayer->animation(m_pPlayerLeftAnimation);
			}
			else if (m_pPlayer->position().x < 1870.f && (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
			{
				//If Right key is pressed set velocity as appropriate
				m_pPlayer->velocity(sf::Vector2f(750.f, 0.f));
				m_pPlayer->animation(m_pPlayerRightAnimation);
			}
			else
			{
				//If neither key is pressed set velocity as 0
				m_pPlayer->velocity(sf::Vector2f(0.f, 0.f));
				m_pPlayer->animation(m_pPlayerRunningAnimation);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && m_pPlayer->missile() == PlayerMissile::standard) m_pPlayer->missile(PlayerMissile::doublePower);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && m_pPlayer->missile() == PlayerMissile::doublePower) m_pPlayer->missile(PlayerMissile::standard);

			//Shoot
			if (!m_pMovePrompt->active() && m_pPlayer->fire() && (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
			{
				//fire off
				Missile* l_missile;

				switch (m_pPlayer->missile())
				{
				case PlayerMissile::standard:
					l_missile = m_aPlayerStandardMissiles->getNext();
					break;

				case PlayerMissile::doublePower:
					//std::cout << "Double Fire";
					l_missile = m_aPlayerDoubleMissiles->getNext();
					break;
				default:
					l_missile = nullptr;
					break;
				}

				if (l_missile != nullptr)
				{
					//std::cout << " Worked";
					l_missile->position(m_pPlayer->position() + m_pPlayer->fireFromOffset());
					l_missile->velocity(m_pPlayer->fireDirection());

					//Play sound
					m_sSoundManager.setBuffer(m_sPlayerFireSound);
					m_sSoundManager.play();

					//Fire the missile
					l_missile->active(true);
					l_missile->fire();
				}
				//std::cout << std::endl;
			}

			//Remove lives if player health is below 0
			/*if (m_pPlayer->health() <= 0.f)
			{
				//Subtract a life
				m_pPlayer->lives(m_pPlayer->lives() - 1);
				*/
				if (m_pPlayer->health() <= 0)
				{
					//End game
					gameOver();
				}
				/*else
				{
					//TODO: Sequence of restoring the player
					m_pPlayer->health(1);
				}*/
			//}

			break;

			//When on the game over screen
		case GameMode::gameOver:


			break;

			//When quitting out
		case GameMode::end:
			m_pRenderWindow->close();
			break;

		default:


			break;
		}

		//Reset the key
		if (m_eLastKey != sf::Keyboard::Key::Unknown) m_eLastKey = sf::Keyboard::Key::Unknown;

		//Update logic cycles this second
		m_iLogicThisSecond++;
	}
}

//Render objects and screen elements/UI
void NovaCorps::render()
{
	//Setup an event
	sf::Event event;

	//Code to run while program is running
	while (m_pRenderWindow->isOpen() && m_eGameMode != GameMode::end)
	{
		//Run through window events
		while (m_pRenderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) m_pRenderWindow->close();
			if (event.type == sf::Event::EventType::KeyPressed) m_eLastKey = event.key.code;
		}

		//TODO: pre-object render logic
		m_pRenderWindow->clear();

		switch (m_eGameMode)
		{
			//When in the menu
		case GameMode::settings:
			//std::cout << "settings" << std::endl;
			//Render stars
			m_pCamera->render(*m_pStars);
			m_pCamera->render(*m_pStars2);
			m_pCamera->render(*m_pStars3);

			m_pCamera->render(*m_pTitleCard);
			m_pCamera->render(*m_pBackButton);
			m_pCamera->render(*m_pMovePrompt);
			m_pCamera->render(*m_pShootPrompt);

			break;

		case GameMode::menu:

			//Render stars
			m_pCamera->render(*m_pStars);
			m_pCamera->render(*m_pStars2);
			m_pCamera->render(*m_pStars3);

			//Render menu stuff --not in scene objects, these don't take up CPU time when playing
			if (m_pTitleCard->active()) m_pCamera->render(*m_pTitleCard);
			if (m_pPlayPrompt->active()) m_pCamera->render(*m_pPlayPrompt);
			if (m_pPlayButton->active()) m_pCamera->render(*m_pPlayButton);
			if (m_pControlsButton->active()) m_pCamera->render(*m_pControlsButton);
			if (m_pSettingsButton->active()) m_pCamera->render(*m_pSettingsButton);
			if (m_pQuitButton->active()) m_pCamera->render(*m_pQuitButton);

			//Render player, as that's needed for when it's flying in
			if (m_pPlayer->active()) m_pCamera->render(*m_pPlayer);

			//TODO: post-object render logic
			m_pRenderWindow->display();
			break;

			//When playing the game
		case GameMode::playing:

			//Render stars
			//m_pCamera->render(*m_pStars);
			m_pCamera->render(*m_pStars2);
			m_pCamera->render(*m_pStars3);
			
			//Render the scene
			m_pScene->render();

			m_cPointsText.setString("Score: ");
			m_cHealthText.setString("Lives: " + std::to_string(m_pPlayer->health()));
			m_cRoundText.setString("Round: " + std::to_string(m_iRound));
			m_pRenderWindow->draw(m_cPointsText);
			m_pRenderWindow->draw(m_cHealthText);
			m_pRenderWindow->draw(m_cRoundText);

			//TODO: post-object render logic
			m_pRenderWindow->display();
			break;

			//When on the game over screen
		case GameMode::gameOver:

			//Render stars
			m_pCamera->render(*m_pStars2);
			m_pCamera->render(*m_pStars3);

			//Render the scene
			m_pScene->render();

			//Render the GameOver
			m_pCamera->render(*m_pTitleCard);

			//TODO: post-object render logic
			m_pRenderWindow->display();
			break;

			//When quitting out
		case GameMode::end:

			break;

		default:
			break;
		}




		//FPS
		/*m_iFramesThisSecond++;
		const std::chrono::duration<float> l_diff = std::chrono::system_clock::now() - m_tLastSecond;
		if (l_diff.count() >= 1.f)
		{
			std::cout << "\nFrames Per Second, this second:" << m_iFramesThisSecond << "\nUpdates Per Second, this second:" << m_iUpdatesThisSecond << "\nLogic Cycles Per Second, this second:" << m_iLogicThisSecond << std::endl;
			m_tLastSecond = std::chrono::system_clock::now();
			m_iFramesThisSecond = 0;
			m_iUpdatesThisSecond = 0;
			m_iLogicThisSecond = 0;
		}*/
	}
}

//Initialises and sets the game running
void NovaCorps::run()
{
	//Setup the game
	setup();
	
	//Let's not repeat
	m_pRenderWindow->setKeyRepeatEnabled(false);

	//Run the update in its own thread
	std::thread l_updateThread(&NovaCorps::update, this);

	//Run the logic in its own thread
	std::thread l_logicThread(&NovaCorps::logic, this);

	//Run the render in this thread because that's where textures and stuff exist - loops
	render();

	//Code only enters here when window is closed
	
	//Yield for the threads then close
	l_updateThread.join();
	l_logicThread.join();

	//std::cout << "Game over... somehow?" << std::endl;
}

//Setup game for play
void NovaCorps::setup()
{
	//Set game to menu
	m_eGameMode = GameMode::menu;

	//Reset the player lives
	m_pPlayer->health(m_pPlayer->lives());
	m_pPlayer->active(false);

	//Start title wave
	m_iRound = 1;
	m_aWaves[1]->start();

	//Set update time to be right now
	m_tLastUpdate = std::chrono::system_clock::now();
}

//Open the menu
void NovaCorps::menu()
{
	//Tell the rest of the game what's going on
	m_eGameMode = GameMode::menu;

	m_pMovePrompt->rectPosition(sf::FloatRect(0.f, 0.f, 0.5f, 0.5f), m_pRenderWindow);

	//Set the current round to 0, so the menu startup sequence is played
	m_aWaves[m_iRound]->stop();
	m_iRound = 0;
	m_aWaves[0]->start();

	//Play title music
	m_sSoundManager.setBuffer(m_sStartSound);
	m_sSoundManager.play();
}

//How to move to the next round
void NovaCorps::nextRound()
{
	//Stop this event sequence, resets the sequence
	m_aWaves[m_iRound]->stop();

	//Increment the round counter
	m_iRound++;

	//Add another life to the player if round is a multiple of 5
	m_pPlayer->health(m_pPlayer->health() + 1);

	//Give the player some points
	m_pPlayer->points(m_pPlayer->points() + 1000);

	//Start the next wave EventSequence
	m_aWaves[m_iRound]->start();
}

//What to do on a gameover
void NovaCorps::gameOver()
{

	//Set mode to gameOver TODO: move to top when above TODO is done
	m_eGameMode = GameMode::gameOver;

	//Stop current round and start the GameOver sequence
	m_aWaves[m_iRound]->stop();
	m_iRound = 0;
	m_aWaves[0]->start(); //TODO: enable when figured out

	//Set Player animation
	m_pPlayer->animation(m_pPlayerDieAnimation);

	//Play gameover sound
	m_sSoundManager.setBuffer(m_sGameOverSound);
	m_sSoundManager.play();

	//Display gameover card
	m_pTitleCard->animation(m_pGameOverAnimation);
	m_pTitleCard->rectPosition(sf::FloatRect(1920.f / 2.f, 1080.f / 2.f, 0.f, 0.f), m_pRenderWindow);
	m_pTitleCard->active(true);

	//Neutralise Player velocity
	m_pPlayer->velocity(sf::Vector2f(0.f, 0.f));

	//TODO: Reset all aliens

}