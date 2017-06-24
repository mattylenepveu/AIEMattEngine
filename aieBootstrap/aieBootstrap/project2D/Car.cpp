#include "Car.h"
#include "Texture.h"
#include "Input.h"
#include "Vector2.h"
#include "Application2D.h"
#include "CollisionManager.h"
#include "Player.h"
#include <crtdbg.h>
using namespace aie;

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Car::Car()
{
	// Defines both the red and blue car
	textureA = new Texture("./textures/RedCar.png");
	_ASSERT(textureA);
	textureB = new Texture("./textures/BlueCar.png");
	_ASSERT(textureB);

	// Sets the starting position of the car
	Matrix3 changePos;
	changePos.setPos(-60, 0);

	// Transforms its state per frame
	localTransform = localTransform * changePos;
	UpdateTransform();

	// Sets its type to be a Car (for collision)
	SetType(CAR);

	// Adds car to the collision list
	CollisionManager::GetInstance()->AddObject(this);

	// Sets default values for variables
	mass = 2.0f;
	drag = 1.0f;
	rotSpeed = 3.14f;
	speed = 800.0f;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Car::~Car()
{
	// Deletes both textures
	delete textureA;
	delete textureB;
}

//--------------------------------------------------------------------------------------
// Sets the colour of the car that will be used in game
//--------------------------------------------------------------------------------------
void Car::setColour()
{
	// Gets the colour the player has chosen
	colour = Player::Instance()->getColour();

	// If the colour variable is true, make the car red
	if (colour)
		textureCurrent = textureA;

	// Otherwise, make the car blue
	else
		textureCurrent = textureB;
}

//--------------------------------------------------------------------------------------
// Updates the car per frame in game
//
// Paramaters:
//		deltaTime: Keeps track of real time, used for movement
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Car::Update(float deltaTime, Renderer2D* m_2dRenderer)
{
	// Gets input so player can control car
	Input* input = Input::getInstance();

	// Sets default values for local variables
	float rot = 0;
	direction = Vector2(0, 0);

	// Tests any collision between car and other objects per frame
	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	// Moves the car based on the "wasd" keys
	if (input->isKeyDown(INPUT_KEY_W))
		direction = Vector2(0, 1);

	if (input->isKeyDown(INPUT_KEY_S))
		direction = Vector2(0, -0.5f);

	if (input->isKeyDown(INPUT_KEY_A))
		rot = (rotSpeed * deltaTime) / 1.5;

	if (input->isKeyDown(INPUT_KEY_D))
		rot = (-rotSpeed * deltaTime) / 1.5;

	// Equations used for movement
	Vector2 forceSum = direction * speed;
	Vector2 acceleration = forceSum / mass;
	Vector2 dampening = -(velocity * drag);
	velocity += (acceleration + dampening) * deltaTime;
	position = velocity * deltaTime;

	Matrix3 changeRot;
	Matrix3 changePos;

	changeRot.setRotateZ(rot);

	// Checks if car has collided with the sea
	if (collide && collide->GetType() == SEA)
	{
		// Resets its position and speed if car hits the sea
		velocity.x = 0;
		velocity.y = 0;
		localTransform.setPos(-60, 0);
	}

	// If there is no collision between sea and car, then allow car to move
	else
		changePos.setPos(position);

	// Check if car has collided with the flag
	if (collide && collide->GetType() == FLAG)
	{
		// If so, change its position back to default and set finish instance to be true
		velocity.x = 0;
		velocity.y = 0;
		localTransform.setPos(-60, 0);
		Player::Instance()->setFinish(true);
	}
	// If no collision between car and flag, set finish instance to be false
	else
		Player::Instance()->setFinish(false);

	// Transforms its position
	localTransform = localTransform * changeRot;
	localTransform = localTransform * changePos;

	UpdateTransform();

	// Sets camera so the car is always centred on screen
	m_2dRenderer->setCameraPos(globalTransform.m[2][0] - 640, globalTransform.m[2][1] - 360);
}

//--------------------------------------------------------------------------------------
// Draws the car for use in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the car to be drawn
//--------------------------------------------------------------------------------------
void Car::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(textureCurrent, globalTransform);
}

