#include "Loading.h"
#include "StateMachine.h"

Loading::Loading()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pBar = pTextureManager->LoadResource("./textures/LoadingBarEmpty.png");
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

Loading::~Loading()
{
	delete m_font;
}

void Loading::OnEnter(StateMachine* pStateMachine)
{
	fTimer = 0.0f;
	nWidth = 0;
}

void Loading::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	fTimer += deltaTime;

	if (fTimer >= 1.5f)
		nWidth = 60;

	if (fTimer >= 3.5f)
		nWidth = 170;

	if (fTimer >= 6.5f)
		nWidth = 320;

	if (fTimer >= 7.9f)
		nWidth = 377;

	if (fTimer >= 8.5f)
		pStateMachine->PushState(4);
}

void Loading::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBar, 640, 360);

	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Loading...", 434, 450);

	if (fTimer >= 1.5)
	{
		m_2dRenderer->setRenderColour(0, 1, 0, 1);
		m_2dRenderer->drawSprite(nullptr, 452, 360, nWidth, 94, 0, 0, 0);
	}
}

void Loading::OnExit(StateMachine* pStateMachine)
{

}