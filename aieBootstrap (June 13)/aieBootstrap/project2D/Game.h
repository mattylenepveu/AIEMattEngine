#pragma once
#include "State.h"
class Game : public State
{
public:
	Game();
	virtual ~Game();

	void OnEnter();
	void OnUpdate(float fDeltaTime);
 	// void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit();
};