#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

class Car : public Entity
{
public:
	Car();
	~Car();

	void Update(float deltaTime, Renderer2D* m_2dRenderer);
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
	Vector2 velocity;
	Vector2 direction;
	Vector2 position;

	float rotSpeed;
	float speed;
	float mass;
	float drag;
};

