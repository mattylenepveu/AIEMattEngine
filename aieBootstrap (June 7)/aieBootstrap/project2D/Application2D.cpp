#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CollisionManager.h"

using namespace aie;

Application2D::Application2D() 
{
}

Application2D::~Application2D() 
{
}

bool Application2D::startup() 
{
	CollisionManager::Create();

	m_2dRenderer = new Renderer2D();

	// m_shipTexture = new Texture("./textures/ship.png");

	m_font = new Font("./font/consolas.ttf", 32);

	// m_audio = new Audio("./audio/powerup.wav");

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

	return true;
}

void Application2D::shutdown() 
{
	// delete m_audio;
	delete m_font;
	// delete m_shipTexture;
	delete m_2dRenderer;

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

void Application2D::update(float deltaTime) 
{
	m_timer += deltaTime;

	// input example
	Input* input = Input::getInstance();

	// use arrow keys to move camera
	/*if (input->isKeyDown(INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;*/

	// example of audio
	// if (input->wasKeyPressed(INPUT_KEY_SPACE))
		// m_audio->play();

	// exit the application
	if (input->isKeyDown(INPUT_KEY_ESCAPE))
		quit();

	m_pCar->Update(deltaTime, m_2dRenderer);
	m_pHuman->Update(deltaTime, m_2dRenderer);
}

void Application2D::draw() 
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	//m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

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

	// demonstrate spinning sprite
	// m_2dRenderer->setUVRect(0,0,1,1);
	// m_2dRenderer->drawSprite(m_shipTexture, 600, 400, 0, 0, m_timer, 1);

	// draw a thin line
	// m_2dRenderer->drawLine(300, 300, 500, 400, 2, 1);

	// draw a moving purple circle
	// m_2dRenderer->setRenderColour(1, 0, 1, 1);
	// m_2dRenderer->drawCircle(sin(m_timer) * 100 + 600, 150, 50);

	// draw a rotating red box
	// m_2dRenderer->setRenderColour(1, 0, 0, 1);
	// m_2dRenderer->drawBox(600, 500, 60, 20, m_timer);

	// draw a slightly rotated sprite with no texture, coloured yellow
	// m_2dRenderer->setRenderColour(1, 1, 0, 1);
	// m_2dRenderer->drawSprite(nullptr, 400, 400, 50, 50, 3.14159f * 0.25f, 1);
	
	// output some text, uses the last used colour
	// char fps[32];
	// sprintf_s(fps, 32, "FPS: %i", getFPS());
	// m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	// m_2dRenderer->drawText(m_font, "Press Space for sound!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}