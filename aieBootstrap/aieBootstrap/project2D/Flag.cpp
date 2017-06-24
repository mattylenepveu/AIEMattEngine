#include "Flag.h"
#include "CollisionManager.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Flag::Flag()
{
	// Creates a new texture
	m_pTexture = new Texture("./textures/Flag.png");
	_ASSERT(m_pTexture);

	// Sets the position of the flag
	Matrix3 changePos;
	changePos.setPos(0, 4431);

	// Updates its position upon starting program
	localTransform = localTransform * changePos;
	UpdateTransform();

	// Sets the type to be a flag
	SetType(FLAG);

	// Flag gets added to the collision manager
	CollisionManager::GetInstance()->AddObject(this);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Flag::~Flag()
{
	delete m_pTexture;
}

//--------------------------------------------------------------------------------------
// Draws the car for use in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the flag to be drawn
//--------------------------------------------------------------------------------------
void Flag::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pTexture, globalTransform);
}
