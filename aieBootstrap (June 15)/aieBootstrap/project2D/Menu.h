#pragma once
#include "State.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

class Menu : public State
{
public:
	Menu();
	~Menu();

	void OnEnter(StateMachine* pStateMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pStateMachine);

private:
	Texture* m_pLogo;
	Font* m_font;

	float fAlpha;
};