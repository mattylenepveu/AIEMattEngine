#pragma once
#include "Renderer2D.h"
#include "State.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

class Splash : public State
{
public:
	Splash();
	~Splash();

	void OnEnter(StateMachine* pStateMachine);
	void OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pStateMachine);

private:
	Texture* m_pPic;
	Font* m_font;

	float fTimer;
	float fAlpha;
};

