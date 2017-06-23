#pragma once
#include "Renderer2D.h"
#include "State.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

// Inherits from state class
class Pause : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Pause();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Pause();

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
	void OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);

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
	Font* m_font;
};

