#include "Splash.h"
#include "StateMachine.h"

Splash::Splash()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pPic = pTextureManager->LoadResource("./textures/Me.png");
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

Splash::~Splash()
{
	delete m_font;
}

void Splash::OnEnter(StateMachine* pStateMachine)
{
	fTimer = 0.0f;
	fAlpha = 0.0f;
}

void Splash::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	fTimer += deltaTime;
	fAlpha += deltaTime;

	if (fAlpha >= 1.0f)
		fAlpha = 1.0f;

	if (fTimer >= 5.0f)
		pStateMachine->PushState(1);
}

void Splash::OnDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->setRenderColour(1, 1, 1, fAlpha);
	m_2dRenderer->drawSprite(m_pPic, 640, 420);
	
	m_2dRenderer->drawText(m_font, "Matthew Le Nepveu Productions", 380, 170);
}

void Splash::OnExit(StateMachine* pStateMachine) 
{
	fTimer = 0.0f;
}