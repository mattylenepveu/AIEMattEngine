#include "Splash.h"


Splash::Splash()
{
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	m_pPic = pTextureManager->LoadResource("./textures/Me.png");
}

Splash::~Splash()
{
}

void Splash::onEnter()
{
	fTimer = 
}

void Splash::onUpdate(float deltaTime)
{

}

void Splash::onDraw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSprite(m_pPic, 0, 0);
}

void Splash::onExit()
{

}