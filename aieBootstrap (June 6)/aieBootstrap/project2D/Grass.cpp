#include "Grass.h"

Grass::Grass(Vector2 pos)
{
	texture = new Texture("./textures/Grass.png");

	Matrix3 changePos;
	changePos.setPos(pos);

	localTransform = localTransform * changePos;
	UpdateTransform();
}

Grass::~Grass()
{
}

void Grass::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}