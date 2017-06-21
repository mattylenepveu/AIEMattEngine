#include "ChooseCar.h"
#include "Input.h"
#include "StateMachine.h"
#include "Player.h"

ChooseCar::ChooseCar()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pBackground = pTextureManager->LoadResource("./textures/BackgroundCol.png");
	m_pBox = pTextureManager->LoadResource("./textures/Box.png");
	m_pRed = pTextureManager->LoadResource("./textures/RedCar.png");
	m_pBlue = pTextureManager->LoadResource("./textures/BlueCar.png");
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

ChooseCar::~ChooseCar()
{
	delete m_font;
}

void ChooseCar::OnEnter(StateMachine* pStateMachine)
{
	nNotRed = 0;
	nNotBlue = 1;
}

void ChooseCar::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	if (input->wasKeyPressed(INPUT_KEY_D))
	{
		nNotRed = 1;
		nNotBlue = 0;
	}

	if (input->wasKeyPressed(INPUT_KEY_A))
	{
		nNotRed = 0;
		nNotBlue = 1;
	}

	if (input->wasKeyPressed(INPUT_KEY_BACKSPACE))
		pStateMachine->PopState();

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		if (nNotRed == 0)
			Player::Instance()->setColour(true);
		else
			Player::Instance()->setColour(false);
		
		pStateMachine->PushState(3);
	}
}

void ChooseCar::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBackground, 640, 360);

	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawText(m_font, "Choose Your Vehicle!", 470, 580);

	m_2dRenderer->setRenderColour(1, 1, nNotRed, 1);
	m_2dRenderer->drawSprite(m_pBox, 430, 300);

	m_2dRenderer->setRenderColour(1, 1, nNotBlue, 1);
	m_2dRenderer->drawSprite(m_pBox, 850, 300);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pRed, 430, 300);

	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBlue, 850, 300);
}

void ChooseCar::OnExit(StateMachine* pStateMachine)
{

}
