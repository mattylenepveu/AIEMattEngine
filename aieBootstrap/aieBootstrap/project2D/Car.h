#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

// Inherits from Entity class
class Car : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Car();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Car();

	//--------------------------------------------------------------------------------------
	// Sets the colour of the car that will be used in game
	//--------------------------------------------------------------------------------------
	void setColour();

	//--------------------------------------------------------------------------------------
	// Updates the car per frame in game
	//
	// Paramaters:
	//		deltaTime: Keeps track of real time, used for movement
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime, Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Draws the car for use in game
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the car to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	// Three textures used, two for both car textures and the other for the texture being used
	Texture* textureA;
	Texture* textureB;
	Texture* textureCurrent;

	Vector2 velocity;
	Vector2 direction;
	Vector2 position;

	float rotSpeed;
	float speed;
	float mass;
	float drag;
	bool colour;
};

