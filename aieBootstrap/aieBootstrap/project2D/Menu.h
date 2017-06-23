#pragma once
#include "State.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

// Inherits from state class
class Menu : public State
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Menu();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Menu();

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
	Texture* m_pLogo;
	Texture* m_pBackground;
	Font* m_font;

	float fAlpha;
	float fTimer;
};