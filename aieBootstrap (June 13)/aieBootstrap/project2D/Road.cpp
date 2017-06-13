#include "Road.h"

Road::Road(Vector2 pos)
{
	texture = new Texture("./textures/Roadway.png");

	Matrix3 changePos;
	changePos.setPos(pos);

	localTransform = localTransform * changePos;
	UpdateTransform();
}

Road::~Road()
{
	delete texture;
}

void Road::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}