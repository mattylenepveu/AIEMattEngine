#pragma once
#include "Renderer2d.h"
#include "DynamicArray.h"
#include "State.h"
#include "Stack.h"
using namespace aie;

class StateMachine
{
public:
	StateMachine();
	~StateMachine();

	void Update(float fDeltaTime, Renderer2D* m_2dRenderer);
	void Draw(Renderer2D* m_2dRenderer);
	void PushState(int nStateIndex);
	void AddState(int nStateIndex, State* pState);
	void PopState();
	void Reset();
	void SetBackground(bool onoff);

private:
	DynamicArray<State*> m_StateList;
	Stack<State*> m_CurrentStack;

	bool bBackUpdate;
};

// State Machine: Made set background function (returns a bool)