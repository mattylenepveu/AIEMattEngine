#include "Flag.h"
#include "CollisionManager.h"

Flag::Flag()
{
	m_pTexture = new Texture("./textures/Flag.png");

	Matrix3 changePos;
	changePos.setPos(0, 4431);

	localTransform = localTransform * changePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);
}

Flag::~Flag()
{
	delete m_pTexture;
}

void Flag::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}
