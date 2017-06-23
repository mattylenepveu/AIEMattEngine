#include "Human.h"
#include "CollisionManager.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Human::Human()
{
	// Creates two "new" textures for alive and dead human
	m_pTextureA = new Texture("./textures/Person.png");
	m_pTextureB = new Texture("./textures/Blood.png");

	// Sets the current texture to be the alive human
	m_pCurrent = m_pTextureA;

	// Sets the humans position
	Matrix3 changePos;
	changePos.setPos(60, 2500);

	// Sets its type to be a human
	SetType(HUMAN);

	// Updates the position of the human upon startup
	localTransform = localTransform * changePos;
	UpdateTransform();

	// Gets added to collision manager
	CollisionManager::GetInstance()->AddObject(this);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Human::~Human()
{
	delete m_pTextureA;
	delete m_pTextureB;
}

//--------------------------------------------------------------------------------------
// Updates the human per frame in game
//
// Paramaters:
//		deltaTime: Keeps track of real time, used for movement
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Human::Update(float deltaTime, Renderer2D* m_2dRenderer)
{
	// Checks for collision between other objects in the list
	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	// Checks if it has collided and the human is alive
	if (collide && m_pCurrent == m_pTextureA)
	{
		// If so, change its texture to be dead
		m_pCurrent = m_pTextureB;
	}
}

//--------------------------------------------------------------------------------------
// Draws the human for use in game
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the human to be drawn
//--------------------------------------------------------------------------------------
void Human::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pCurrent, globalTransform);
}
