#include "Sea.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//
// Parameters:
//		pos: Takes in a position which is set in Game.cpp
//--------------------------------------------------------------------------------------
Sea::Sea(Vector2 pos)
{
	// Creates a "new" texture
	m_pTexture = new Texture("./textures/Water.png");

	// Sets the position of the sea based on whats being passed in
	Matrix3 changePos;
	changePos.setPos(pos);

	// Sets the type as sea for collision
	SetType(SEA);

	// Updates the position upon startup
	localTransform = localTransform * changePos;
	UpdateTransform();

	// Gets added to the collision list
	CollisionManager::GetInstance()->AddObject(this);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Sea::~Sea()
{
	delete m_pTexture;
}

//--------------------------------------------------------------------------------------
// Draws the sea for use in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the sea to be drawn
//--------------------------------------------------------------------------------------
void Sea::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}