#include "Human.h"
#include "CollisionManager.h"

Human::Human()
{
	m_pTextureA = new Texture("./textures/Person.png");
	m_pTextureB = new Texture("./textures/Blood.png");
	m_pCurrent = m_pTextureA;

	Matrix3 changePos;
	changePos.setPos(60, 2500);

	localTransform = localTransform * changePos;
	UpdateTransform();

	CollisionManager::GetInstance()->AddObject(this);
}

Human::~Human()
{
	delete m_pTextureA;
	delete m_pTextureB;
}

void Human::Update(float deltaTime, Renderer2D* m_2dRenderer)
{
	Entity* collide = CollisionManager::GetInstance()->TestBoxCollision(this);

	if (collide && m_pCurrent == m_pTextureA)
	{
		m_pCurrent = m_pTextureB;
	}
}

void Human::Draw(Renderer2D* m_2dRenderer)
{
	m_2dRenderer->drawSpriteTransformed3x3(m_pCurrent, globalTransform);
}
