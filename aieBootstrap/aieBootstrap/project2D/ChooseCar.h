#pragma once
#include "State.h"
#include "Renderer2D.h"
#include "Texture.h"
#include "ResourceManager.h"
#include "Font.h"
using namespace aie;

class ChooseCar : public State
{
public:
	ChooseCar();
	~ChooseCar();

	void OnEnter(StateMachine* pStateMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pStateMachine);

private:
	Texture* m_pBackground;
	Texture* m_pBox;
	Texture* m_pRed;
	Texture* m_pBlue;
	Font* m_font;

	int nNotRed;
	int nNotBlue;
};

