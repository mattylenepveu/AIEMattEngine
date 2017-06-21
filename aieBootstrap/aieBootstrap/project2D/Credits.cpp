#include "Credits.h"
#include "StateMachine.h"

Credits::Credits()
{
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

Credits::~Credits()
{
	delete m_font;
}

void Credits::OnEnter(StateMachine* pStateMachine)
{
	fTimer = 0.0f;
}

void Credits::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	fTimer += deltaTime;

	if (fTimer >= 8.0f)
	{
		pStateMachine->Reset();
		pStateMachine->PushState(1);
	}
}

void Credits::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "You Win!!!", 555, 390);

	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Thanks for playing this amazing simulation!", 265, 314);
}

void Credits::OnExit(StateMachine* pStateMachine)
{

}