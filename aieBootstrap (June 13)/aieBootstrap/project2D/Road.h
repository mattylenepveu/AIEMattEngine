#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Road : public Entity
{
public:
	Road(Vector2 pos);
	~Road();

	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
};

