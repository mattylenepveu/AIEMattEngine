#pragma once
#include "State.h"
#include "Car.h"
#include "Road.h"
#include "Grass.h"
#include "Human.h"
#include "Flag.h"
#include "Sea.h"

// Defines the array size for road, grass and both ocean dimensions
#define TRACK 20
#define FIELD 55
#define OCEANX 55
#define OCEANY 10

// Inherits from state class
class Game : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Game();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Game();

	//--------------------------------------------------------------------------------------
	// Runs when the state is first pushed back
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	void OnEnter(StateMachine* pStateMachine);

	//--------------------------------------------------------------------------------------
	// Updates the state when it is running
	//
	// Paramaters:
	//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
	//		pStateMachine: Is used to access the state machine
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Draws the state when it is pushed on the stack
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
	//--------------------------------------------------------------------------------------
	void OnDraw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Runs when the state is being exited
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	void OnExit(StateMachine* pStateMachine);

private:
	float m_cameraX, m_cameraY;
	float m_timer;
	bool fin;

	Car* m_pCar;
	Road* m_pRoad[TRACK];
	Grass* m_pGrass[FIELD][FIELD];
	Human* m_pHuman;
	Flag* m_pFlag;
	Sea* m_pSea[OCEANY][OCEANX];
};