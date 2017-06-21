#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Sea : public Entity
{
public:
	Sea(Vector2 pos);
	~Sea();

	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* m_pTexture;

	float fTimer;
};

