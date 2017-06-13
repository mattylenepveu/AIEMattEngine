#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Flag : public Entity
{
public:
	Flag();
	~Flag();

	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* m_pTexture;
};

