#include "Pause.h"
#include "StateMachine.h"
#include "Input.h"

Pause::Pause()
{
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

Pause::~Pause()
{
	delete m_font;
}

void Pause::OnEnter(StateMachine* pStateMachine)
{

}

void Pause::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		pStateMachine->SetBackground(false);
		m_2dRenderer->setCameraPos(0, 0);
		pStateMachine->Reset();
		pStateMachine->PushState(1);
	}

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		pStateMachine->SetBackground(false);
		pStateMachine->PopState();
	}
}

void Pause::OnDraw(Renderer2D* m_2dRenderer)
{
	float xPos;
	float yPos;
	m_2dRenderer->getCameraPos(xPos, yPos);

	m_2dRenderer->setRenderColour(0, 0, 0, 0.75);
	m_2dRenderer->drawBox(xPos + 640, yPos + 360, 1280, 720);

	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Pause.", xPos + 590, yPos + 360);
}

void Pause::OnExit(StateMachine* pStateMachine)
{

}