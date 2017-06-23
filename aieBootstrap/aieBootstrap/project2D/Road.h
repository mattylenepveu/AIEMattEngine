#pragma once
#include "Vector2.h"
#include "Entity.h"
#include "Texture.h"
#include "Renderer2D.h"
using namespace aie;

// Inherits from Entity class
class Road : public Entity
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//
	// Parameters:
	//		pos: Takes in a position which is set in Game.cpp
	//--------------------------------------------------------------------------------------
	Road(Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Road();

	//--------------------------------------------------------------------------------------
	// Draws the road for use in game
	//
	// Parameters:
	//		m_2dRenderer: Accesses the renderer class to allow the road to be drawn
	//--------------------------------------------------------------------------------------
	void Draw(Renderer2D* m_2dRenderer);

private:
	Texture* texture;
};

