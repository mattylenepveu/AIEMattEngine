#include "Game.h"
#include "CollisionManager.h"
#include "Player.h"
#include "StateMachine.h"
#include "Input.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Game::Game()
{
	// Creates the collision manager
	CollisionManager::Create();

	// Creates the "new" ocean
	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			Vector2 pos;
			pos.x = j * 120 - 3000;
			pos.y = i * 120 - 1700;
			m_pSea[i][j] = new Sea(pos);
			_ASSERT(m_pSea[i][j]);
		}
	}

	// Creates the "new" grass
	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			Vector2 pos;
			pos.x = j * 120 - 3000;
			pos.y = i * 120 - 500;
			m_pGrass[i][j] = new Grass(pos);
			_ASSERT(m_pGrass[i][j]);
		}
	}

	// Creates the "new" road
	for (int i = 0; i < TRACK; ++i)
	{
		Vector2 pos;
		pos.x = 0;
		pos.y = i * 256 - 433;
		m_pRoad[i] = new Road(pos);
		_ASSERT(m_pRoad[i]);
	}

	// Creates a "new" flag
	m_pFlag = new Flag();
	_ASSERT(m_pFlag);

	// Creates a "new" human
	m_pHuman = new Human();
	_ASSERT(m_pHuman);

	// Creates a "new" car
	m_pCar = new Car();
	_ASSERT(m_pCar);

	// Sets default values to variables
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Game::~Game()
{
	// Deletes the ocean
	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			delete m_pSea[i][j];
		}
	}

	// Deletes the grass
	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			delete m_pGrass[i][j];
		}
	}

	// Deletes the road
	for (int i = 0; i < TRACK; ++i)
	{
		delete m_pRoad[i];
	}

	// Deletes the flag, car and human
	delete m_pFlag;
	delete m_pCar;
	delete m_pHuman;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Game::OnEnter(StateMachine* pStateMachine)
{
	// Sets the colour of the car
	m_pCar->setColour();
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Game::OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Allows for users to input keys
	Input* input = Input::getInstance();

	// Checks if the "enter" key was pressed
	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		// If so, then change to the pause state
		pStateMachine->SetBackground(true);
		pStateMachine->PushState(5);
	}

	// Updates the timer based on real time
	m_timer += fDeltaTime;

	// Calls update functions for the car and human
	m_pCar->Update(fDeltaTime, m_2dRenderer);
	m_pHuman->Update(fDeltaTime, m_2dRenderer);

	// Catches whether or not the car has finished
	fin = Player::Instance()->getFinish();

	// If the car has finished, then reset camera position and go to credits
	if (fin)
	{
		m_2dRenderer->setCameraPos(0, 0);
		pStateMachine->PushState(6);
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Game::OnDraw(Renderer2D* m_2dRenderer)
{
	// draws the ocean
	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			m_pSea[i][j]->Draw(m_2dRenderer);
		}
	}

	// draws the grass
	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			m_pGrass[i][j]->Draw(m_2dRenderer);
		}
	}

	// draws the road
	for (int i = 0; i < TRACK; ++i)
	{
		m_pRoad[i]->Draw(m_2dRenderer);
	}

	// draws the finish line
	m_pFlag->Draw(m_2dRenderer);

	// draws the person
	m_pHuman->Draw(m_2dRenderer);

	// draws car
	m_pCar->Draw(m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Game::OnExit(StateMachine* pStateMachine) {}