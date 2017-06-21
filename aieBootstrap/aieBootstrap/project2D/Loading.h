#pragma once
#include "Renderer2D.h"
#include "State.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

class Loading : public State
{
public:
	Loading();
	~Loading();

	void OnEnter(StateMachine* pStateMachine);
	void OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pStateMachine);

private:
	Texture* m_pBar;
	Font* m_font;

	float fTimer;
	int nWidth;
};

