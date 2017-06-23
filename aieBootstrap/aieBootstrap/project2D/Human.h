#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

// Inherits from Entity class
class Human : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Human();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Human();

	//--------------------------------------------------------------------------------------
	// Updates the human per frame in game
	//
	// Paramaters:
	//		deltaTime: Keeps track of real time, used for movement
	//		m_2dRenderer: Is used for access to the renderer class
	//--------------------------------------------------------------------------------------
	void Update(float deltaTime, Renderer2D* m_2dRenderer);

	//--------------------------------------------------------------------------------------
	// Draws the human for use in game
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the human to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	// Three textures used, two for alive and dead state and other used for whhich state to be drawn
	Texture* m_pTextureA;
	Texture* m_pTextureB;
	Texture* m_pCurrent;

	float fTimer;
};

