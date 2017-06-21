#pragma once
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Bubble : public Entity
{
public:
	Bubble();
	~Bubble();

	void Update(float deltaTime, Renderer2D* m_2dRenderer);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
};

