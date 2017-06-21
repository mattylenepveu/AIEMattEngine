#include "Bubble.h"

Bubble::Bubble()
{
	texture = new Texture("./textures/CarBubble.png");
}

Bubble::~Bubble()
{
	delete texture;
}

void Bubble::Update(float deltaTime, Renderer2D* m_2dRenderer)
{

}

void Bubble::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}