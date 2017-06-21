#include "Menu.h"
#include "Input.h"
#include "StateMachine.h"

Menu::Menu()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pLogo = pTextureManager->LoadResource("./textures/GameLogo.png");
	m_pBackground = pTextureManager->LoadResource("./textures/BackgroundCol.png");
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

Menu::~Menu()
{
	delete m_font;
}

void Menu::OnEnter(StateMachine* pStateMachine)
{
	fAlpha = 1.0f;
	fTimer = 0.0f;
}

void Menu::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
		pStateMachine->PushState(2);

	fTimer += deltaTime;

	if (fTimer > 3.0f)
		fAlpha = 0.0f;

	if (fTimer > 3.5f)
	{
		fAlpha = 1.0f;
		fTimer -= fTimer;
	}
}

void Menu::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBackground, 640, 360);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pLogo, 640, 450);

	m_2dRenderer->setRenderColour(1, 0, 0, fAlpha);
	m_2dRenderer->drawText(m_font, "Press Enter to Play!", 468, 190);

	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawText(m_font, "(C) 2017 Matthew Le Nepveu Productions", 302, 120);
}

void Menu::OnExit(StateMachine* pStateMachine)
{
	fAlpha = 0.0f;
}