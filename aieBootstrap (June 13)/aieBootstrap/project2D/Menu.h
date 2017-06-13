#pragma once
#include "State.h"

class Menu : public State
{
public:
	Menu();
	virtual ~Menu();

	void OnEnter();
	void OnUpdate(float fDeltaTime);
	// void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};

