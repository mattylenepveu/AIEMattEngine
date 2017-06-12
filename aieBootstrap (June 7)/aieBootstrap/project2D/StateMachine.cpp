#include "StateMachine.h"
#include <crtdbg.h>

StateMachine::StateMachine()
{
	m_nCurrentState = -1;
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < m_StateList.Size(); ++i)
	{
		delete m_StateList[i];
	}
}

void StateMachine::Update(float fDeltaTime)
{
	if (m_StateList.Size() <= 0)
		return;

	m_StateList[m_nCurrentState]->OnUpdate(fDeltaTime);
}

//void StateMachine::Draw(Renderer2D* m_2dRenderer)
//{
//	if (m_StateList.Size() <= 0)
//		return;
//
//	m_StateList[m_nCurrentState]->OnDraw(m_2dRenderer);
//}

void StateMachine::SetState(int nStateIndex)
{
	_ASSERT(nStateIndex < m_StateList.Size());
	if (nStateIndex >= m_StateList.Size())
		return;

	if (m_nCurrentState >= 0)
		m_StateList[m_nCurrentState]->OnExit();

	m_nCurrentState = nStateIndex;

	m_StateList[m_nCurrentState]->OnEnter();
}

void StateMachine::AddState(int nStateIndex, State* pState)
{
	m_StateList.Insert(nStateIndex, pState);
}