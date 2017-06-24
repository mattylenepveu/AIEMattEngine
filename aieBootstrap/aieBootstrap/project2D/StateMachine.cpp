#include "StateMachine.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
StateMachine::StateMachine()
{
	// Sets variable to false by default
	bBackUpdate = false;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
StateMachine::~StateMachine()
{
	// Deletes everything on the statelist via a for loop
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

//--------------------------------------------------------------------------------------
// Calls the onUpdate function for the top state on the stack
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void StateMachine::Update(float fDeltaTime, Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	m_CurrentStack.Top()->OnUpdate(fDeltaTime, this, m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// Draws the state that is on top of the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	// Makes sure the stack size is not less than or equal to zero
	if (m_CurrentStack.Size() <= 0)
		return;

	// If in paused state, then render the second to top state on the stack
	if (bBackUpdate)
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);

	// Renders the top state on the stack
	m_CurrentStack.Top()->OnDraw(m_2dRenderer);
}

//--------------------------------------------------------------------------------------
// Pushes the state onto the next state on top of the stack
//
// Parameters:
//		nStateIndex: Refers to the state at the top of the stack
//--------------------------------------------------------------------------------------
void StateMachine::PushState(int nStateIndex)
{
	// Checks if the state index is greater than or equal to the state list size
	if (nStateIndex >= m_StateList.Size())
		return;

	// If the stack's size is greater than zero, then exit the current state on top
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);
	
	// Calls the push function in the stack class to push to the next top state
	m_CurrentStack.Push(m_StateList[nStateIndex]);

	// Enters the new state
	m_CurrentStack.Top()->OnEnter(this);
}

//--------------------------------------------------------------------------------------
// Allows a state to be added to the top of the stack
//
// Parameters:
//		nStateIndex: Refers to the top of the stack
//		pState: Calls the state to be added
//--------------------------------------------------------------------------------------
void StateMachine::AddState(int nStateIndex, State* pState)
{
	_ASSERT(pState);

	// Inserts a state into the stack
	m_StateList.Insert(nStateIndex, pState);
}

//--------------------------------------------------------------------------------------
// Pops the state off of the top of the stack back to the state previously top
//--------------------------------------------------------------------------------------
void StateMachine::PopState()
{
	// Exits the top state if the state list is greater than zero
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	// Pops the top state off of the top
	m_CurrentStack.Pop();

	// Enters the new top state if the state list is greater than zero 
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnEnter(this);
}

//--------------------------------------------------------------------------------------
// Resets the stack and erases all states on it
//--------------------------------------------------------------------------------------
void StateMachine::Reset()
{
	// Pops off all of the states from stack while the stack is greater than zero
	while (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Pop();
	}
}

//--------------------------------------------------------------------------------------
// Allows another state to run as well as the one on top
//
// Parameters:
//		onoff: Allows the second to top state to run if true
//--------------------------------------------------------------------------------------
void StateMachine::SetBackground(bool onoff)
{
	bBackUpdate = onoff;
}