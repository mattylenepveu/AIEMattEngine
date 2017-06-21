#include "Menu.h"
#include "Input.h"
#include "StateMachine.h"

Menu::Menu()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pLogo = pTextureManager->LoadResource("./textures/GameLogo.png");
	m_font = new Font("./font/consolas.ttf", 32);
}

Menu::~Menu()
{
	delete m_font;
}

void Menu::OnEnter(StateMachine* pStateMachine)
{
	fAlpha = 1.0f;
}

void Menu::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	if (input->isKeyDown(INPUT_KEY_ENTER))
	{
		pStateMachine->PushState(2);
	}
}

void Menu::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, fAlpha);
	m_2dRenderer->drawSprite(m_pLogo, 640, 420);

	m_2dRenderer->drawText(m_font, "Press Enter to Play!", 400, 200);
}

void Menu::OnExit(StateMachine* pStateMachine)
{
	fAlpha = 0.0f;
}