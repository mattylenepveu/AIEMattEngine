#include "Game.h"
#include "CollisionManager.h"

Game::Game()
{
	CollisionManager::Create();

	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			Vector2 pos;
			pos.x = j * 120 - 3000;
			pos.y = i * 120 - 1700;
			m_pSea[i][j] = new Sea(pos);
		}
	}

	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			Vector2 pos;
			pos.x = j * 120 - 3000;
			pos.y = i * 120 - 500;
			m_pGrass[i][j] = new Grass(pos);
		}
	}

	for (int i = 0; i < TRACK; ++i)
	{
		Vector2 pos;
		pos.x = 0;
		pos.y = i * 256 - 433;
		m_pRoad[i] = new Road(pos);
	}

	m_pFlag = new Flag();

	m_pHuman = new Human();

	m_pCar = new Car();

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
}

Game::~Game()
{
	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			delete m_pSea[i][j];
		}
	}

	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			delete m_pGrass[i][j];
		}
	}

	for (int i = 0; i < TRACK; ++i)
	{
		delete m_pRoad[i];
	}

	delete m_pFlag;
	delete m_pCar;
	delete m_pHuman;
}

void Game::OnEnter(StateMachine* pStateMachine)
{

}

void Game::OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	m_timer += fDeltaTime;

	m_pCar->Update(fDeltaTime, m_2dRenderer);
	m_pHuman->Update(fDeltaTime, m_2dRenderer);
}

void Game::OnDraw(Renderer2D* m_2dRenderer)
{
	// draws the ocean
	for (int i = 0; i < OCEANY; ++i)
	{
		for (int j = 0; j < OCEANX; ++j)
		{
			m_pSea[i][j]->Draw(m_2dRenderer);
		}
	}

	// draws the grass
	for (int i = 0; i < FIELD; ++i)
	{
		for (int j = 0; j < FIELD; ++j)
		{
			m_pGrass[i][j]->Draw(m_2dRenderer);
		}
	}

	// draws the road
	for (int i = 0; i < TRACK; ++i)
	{
		m_pRoad[i]->Draw(m_2dRenderer);
	}

	// draws the finish line
	m_pFlag->Draw(m_2dRenderer);

	// draws the person
	m_pHuman->Draw(m_2dRenderer);

	// draws car
	m_pCar->Draw(m_2dRenderer);
}

void Game::OnExit(StateMachine* pStateMachine)
{

}