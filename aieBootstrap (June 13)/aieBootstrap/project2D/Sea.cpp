#include "Sea.h"
#include "CollisionManager.h"

Sea::Sea(Vector2 pos)
{
	m_pTexture = new Texture("./textures/Water.png");

	Matrix3 changePos;
	changePos.setPos(pos);

	SetType(SEA);

	localTransform = localTransform * changePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);
}

Sea::~Sea()
{
	delete m_pTexture;
}

void Sea::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}