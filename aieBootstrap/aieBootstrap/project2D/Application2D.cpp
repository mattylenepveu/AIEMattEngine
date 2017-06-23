#include "Application2D.h"
#include "Input.h"
#include "ResourceManager.h"
#include "Splash.h"
#include "Menu.h"
#include "ChooseCar.h"
#include "Loading.h"
#include "Game.h"
#include "Pause.h"
#include "Credits.h"
#include "Player.h"
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Application2D::Application2D() {}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Application2D::~Application2D() {}

//--------------------------------------------------------------------------------------
// Acts as our constructor and creates the renderer and state machine
//
// Return:
//		A bool returns true upon startup
//--------------------------------------------------------------------------------------
bool Application2D::startup() 
{
	// Creates the singleton for use in game
	Player::create();

	// Creates the resource manager and uses it for textures
	ResourceManager<Texture>::Create();

	// Makes a "new" renderer
	m_2dRenderer = new Renderer2D();
	
	// Makes a "new" state machine
	m_pStateMachine = new StateMachine();

	// Creates "new" states
	m_pStateMachine->AddState(0, new Splash());
	m_pStateMachine->AddState(1, new Menu());
	m_pStateMachine->AddState(2, new ChooseCar());
	m_pStateMachine->AddState(3, new Loading());
	m_pStateMachine->AddState(4, new Game());
	m_pStateMachine->AddState(5, new Pause());
	m_pStateMachine->AddState(6, new Credits());

	// Starts on the first state when it boots up
	m_pStateMachine->PushState(0);

	return true;
}

//--------------------------------------------------------------------------------------
// Acts as our destructor and deletes the renderer and state machine
//--------------------------------------------------------------------------------------
void Application2D::shutdown() 
{
	// Destroys the singleton
	Player::destroy();

	// Destroys the resource manager
	ResourceManager<Texture>::Destroy();

	// Deletes the renderer and state machine
	delete m_2dRenderer;
	delete m_pStateMachine;
}

//--------------------------------------------------------------------------------------
// Updates the state machine and the renderer by frame
//
// Parameters:
//		deltaTime: A float the keeps track of real time
//--------------------------------------------------------------------------------------
void Application2D::update(float deltaTime)
{
	// input example
	Input* input = Input::getInstance();

	// Updates the state machine by frame
	m_pStateMachine->Update(deltaTime, m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// Draws the state machine and renderer to work in game
//--------------------------------------------------------------------------------------
void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draws states
	m_pStateMachine->Draw(m_2dRenderer);

	// done drawing sprites
	m_2dRenderer->end();
}