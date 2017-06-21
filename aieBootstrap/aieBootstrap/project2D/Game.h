#pragma once
#include "State.h"
#include "Car.h"
#include "Road.h"
#include "Grass.h"
#include "Human.h"
#include "Flag.h"
#include "Sea.h"

#define TRACK 20
#define FIELD 55
#define OCEANX 55
#define OCEANY 10

class Game : public State
{
public:
	Game();
	~Game();

	void OnEnter(StateMachine* pStateMachine);
	void OnUpdate(float fDeltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer);
	void OnDraw(Renderer2D* m_2dRenderer);
	void OnExit(StateMachine* pStateMachine);

private:
	float m_cameraX, m_cameraY;
	float m_timer;
	bool fin;

	Car* m_pCar;
	Road* m_pRoad[TRACK];
	Grass* m_pGrass[FIELD][FIELD];
	Human* m_pHuman;
	Flag* m_pFlag;
	Sea* m_pSea[OCEANY][OCEANX];
};