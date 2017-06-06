#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Grass : public Entity
{
public:
	Grass(Vector2 pos);
	~Grass();

	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
};

