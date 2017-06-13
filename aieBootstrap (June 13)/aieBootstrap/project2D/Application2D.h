#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Audio.h"
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

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Texture*		m_shipTexture;
	aie::Font*			m_font;
	aie::Audio*			m_audio;

	float m_cameraX, m_cameraY;
	float m_timer;

	Car* m_pCar;
	Road* m_pRoad[TRACK];
	Grass* m_pGrass[FIELD][FIELD];
	Human* m_pHuman;
	Flag* m_pFlag;
	Sea* m_pSea[OCEANY][OCEANX];
};