#include "Road.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Parameters:
//		pos: Takes in a position which is set in Game.cpp
//--------------------------------------------------------------------------------------
Road::Road(Vector2 pos)
{
	// Creates a "new" texture
	texture = new Texture("./textures/Roadway.png");

	// Sets its position upon whats being passed through
	Matrix3 changePos;
	changePos.setPos(pos);

	// Updates its position upon startup
	localTransform = localTransform * changePos;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Road::~Road()
{
	delete texture;
}

//--------------------------------------------------------------------------------------
// Draws the road for use in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the road to be drawn
//--------------------------------------------------------------------------------------
void Road::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}