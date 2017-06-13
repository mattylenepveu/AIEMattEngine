#include "Car.h"
#include "Texture.h"
#include "Input.h"
#include "Vector2.h"
#include "Application2D.h"
#include "CollisionManager.h"
using namespace aie;

Car::Car()
{
	texture = new Texture("./textures/BlueCar.png");

	Matrix3 changePos;
	changePos.setPos(-60, 0);

	localTransform = localTransform * changePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);

	mass = 2.0f;
	drag = 1.0f;
	rotSpeed = 3.14f;
	speed = 800.0f;
}

Car::~Car()
{
	delete texture;
}

void Car::Update(float deltaTime, Renderer2D* m_2dRenderer)
{
	Input* input = Input::getInstance();

	float rot = 0;

	direction = Vector2(0, 0);

	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	if (input->isKeyDown(INPUT_KEY_W))
		direction = Vector2(0, 1);

	if (input->isKeyDown(INPUT_KEY_S))
		direction = Vector2(0, -0.5f);

	if (input->isKeyDown(INPUT_KEY_A))
		rot = (rotSpeed * deltaTime) / 1.5;

	if (input->isKeyDown(INPUT_KEY_D))
		rot = (-rotSpeed * deltaTime) / 1.5;

	Vector2 forceSum = direction * speed;
	Vector2 acceleration = forceSum / mass;
	Vector2 dampening = -(velocity * drag);
	velocity += (acceleration + dampening) * deltaTime;
	position = velocity * deltaTime;

	Matrix3 changeRot;
	Matrix3 changePos;

	changeRot.setRotateZ(rot);

	if (collide && collide->GetType() == SEA)
	{
		localTransform.setPos(-60, 0);
	}
	else
	{
		changePos.setPos(position);
	}

	localTransform = localTransform * changeRot;
	localTransform = localTransform * changePos;

	UpdateTransform();

	m_2dRenderer->setCameraPos(globalTransform.m[2][0] - 640, globalTransform.m[2][1] - 360);
}

void Car::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}