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

void StateMachine::Draw(Renderer2D* m_2dRenderer)
{
	if (m_CurrentStack.Size() <= 0)
		return;

	if (bBackUpdate)
		m_CurrentStack.SecondLast()->OnDraw(m_2dRenderer);

	m_CurrentStack.Top()->OnDraw(m_2dRenderer);
}

void StateMachine::PushState(int nStateIndex)
{
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.Push(m_StateList[nStateIndex]);

	m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	_ASSERT(pState);
	m_StateList.Insert(nStateIndex, pState);
}

void StateMachine::PopState()
{
	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.Pop();

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::Reset()
{
	while (m_CurrentStack.Size() > 0)
	{
		m_CurrentStack.Pop();
	}
}

void StateMachine::SetBackground(bool onoff)
{
	bBackUpdate = onoff;
}