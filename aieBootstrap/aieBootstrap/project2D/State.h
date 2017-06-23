#pragma once
#include "Renderer2D.h"
using namespace aie;

// Calls the State Machine class
class StateMachine;

class State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	State();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	virtual ~State();

	//--------------------------------------------------------------------------------------
	// Runs when the state is first pushed back (virtual for use in inherited classes)
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	virtual void OnEnter(StateMachine* pStateMachine) = 0;

	//--------------------------------------------------------------------------------------
	// Updates the state when it is running (virtual for use in inherited classes)
	//
	// Paramaters:
	//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
	//		pStateMachine: Is used to access the state machine
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	virtual void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer) = 0;

	//--------------------------------------------------------------------------------------
	// Draws the state when it is pushed on the stack (virtual for use in inherited classes)
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
	//--------------------------------------------------------------------------------------
	virtual void OnDraw(Renderer2D* m_2dRenderer) = 0;

	//--------------------------------------------------------------------------------------
	// Runs when the state is being exited (virtual for use in inherited classes)
	//
	// Paramaters:
	//		pStateMachine: A pointer to the StateMachine for use in function
	//--------------------------------------------------------------------------------------
	virtual void OnExit(StateMachine* pStateMachine) = 0;
};

