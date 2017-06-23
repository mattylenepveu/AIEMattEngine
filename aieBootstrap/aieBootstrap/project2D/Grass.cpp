#include "Grass.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Parameters:
//		pos: Takes in a position which is set in Game.cpp
//--------------------------------------------------------------------------------------
Grass::Grass(Vector2 pos)
{
	// Creates a "new" texture
	texture = new Texture("./textures/Grass.png");

	// Sets the position of grass, based on whats being passed in
	Matrix3 changePos;
	changePos.setPos(pos);

	// Updates the position upon startup
	localTransform = localTransform * changePos;
	UpdateTransform();
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Grass::~Grass()
{
	delete texture;
}

//--------------------------------------------------------------------------------------
// Draws the grass in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the grass to be drawn
//--------------------------------------------------------------------------------------
void Grass::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(texture, globalTransform);
}