#pragma once
#include "Renderer2d.h"
#include "DynamicArray.h"
#include "State.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	StateMachine();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~StateMachine();

	//--------------------------------------------------------------------------------------
	// Calls the onUpdate function for the top state on the stack
	//
	// Paramaters:
	//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	void Update(float fDeltaTime, Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Draws the state that is on top of the stack
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Pushes the state onto the next state on top of the stack
	//
	// Parameters:
	//		nStateIndex: Refers to the state at the top of the stack
	//--------------------------------------------------------------------------------------
	void PushState(int nStateIndex);

	//--------------------------------------------------------------------------------------
	// Allows a state to be added to the top of the stack
	//
	// Parameters:
	//		nStateIndex: Refers to the top of the stack
	//		pState: Calls the state to be added
	//--------------------------------------------------------------------------------------
	void AddState(int nStateIndex, State* pState);

	//--------------------------------------------------------------------------------------
	// Pops the state off of the top of the stack back to the state previously top
	//--------------------------------------------------------------------------------------
	void PopState();

	//--------------------------------------------------------------------------------------
	// Resets the stack and erases all states on it
	//--------------------------------------------------------------------------------------
	void Reset();

	//--------------------------------------------------------------------------------------
	// Allows another state to run as well as the one on top
	//
	// Parameters:
	//		onoff: Allows the second to top state to run if true
	//--------------------------------------------------------------------------------------
	void SetBackground(bool onoff);

private:
	DynamicArray<State*> m_StateList;
	Stack<State*> m_CurrentStack;

	bool bBackUpdate;
};