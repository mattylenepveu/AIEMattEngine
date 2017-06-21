#include "StateMachine.h"
#include <crtdbg.h>

StateMachine::StateMachine()
{
	bBackUpdate = false;
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

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
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_CurrentStack.Size() > 0)
		m_CurrentStack.Top()->OnExit(this);

	m_CurrentStack.Push(m_StateList[nStateIndex]);

	m_CurrentStack.Top()->OnEnter(this);
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
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