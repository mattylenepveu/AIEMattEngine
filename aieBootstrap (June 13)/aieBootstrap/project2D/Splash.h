#pragma once
#include "Renderer2D.h"
#include "State.h"
#include "Texture.h"
#include "ResourceManager.h"
using namespace aie;

class Splash : public State
{
public:
	Splash();
	~Splash();

	void onEnter();
	void onUpdate(float deltaTime);
	void onDraw(Renderer2D* m_2dRenderer);
	void onExit();

private:
	Texture* m_pPic;

	float fTimer;
	float fAlpha;
};

