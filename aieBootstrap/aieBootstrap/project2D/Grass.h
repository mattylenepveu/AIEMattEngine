#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

// Inherits from Entity class
class Grass : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Parameters:
	//		pos: Takes in a position which is set in Game.cpp
	//--------------------------------------------------------------------------------------
	Grass(Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Grass();

	//--------------------------------------------------------------------------------------
	// Draws the grass in game
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the grass to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
};

