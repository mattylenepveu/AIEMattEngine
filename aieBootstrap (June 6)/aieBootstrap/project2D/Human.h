#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Human : public Entity
{
public:
	Human();
	~Human();

	void Update(float deltaTime, Renderer2D* m_2dRenderer);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* m_pTextureA;
	Texture* m_pTextureB;
	Texture* m_pCurrent;
};

