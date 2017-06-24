#include "ChooseCar.h"
#include "Input.h"
#include "StateMachine.h"
#include "Player.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
ChooseCar::ChooseCar()
{
	// Accesses the resource manager to define new textures
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Makes the background, two boxes and two cars for display
	m_pBackground = pTextureManager->LoadResource("./textures/BackgroundCol.png");
	m_pBox = pTextureManager->LoadResource("./textures/Box.png");
	m_pRed = pTextureManager->LoadResource("./textures/RedCar.png");
	m_pBlue = pTextureManager->LoadResource("./textures/BlueCar.png");

	// Creates a "new" font for use in state
	m_font = new Font("./font/consolas_bold.ttf", 32);
	_ASSERT(m_font);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
ChooseCar::~ChooseCar()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void ChooseCar::OnEnter(StateMachine* pStateMachine)
{
	// Defines variables by default
	nNotRed = 0;
	nNotBlue = 1;
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void ChooseCar::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Allows for user input
	Input* input = Input::getInstance();
	
	// When the "D" key is pressed, highlight blue car
	if (input->wasKeyPressed(INPUT_KEY_D))
	{
		nNotRed = 1;
		nNotBlue = 0;
	}

	// When the "A" key is pressed, highlight red car
	if (input->wasKeyPressed(INPUT_KEY_A))
	{
		nNotRed = 0;
		nNotBlue = 1;
	}

	// If "escape" key is pressed, go back a state
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
		pStateMachine->PopState();

	// Checks if "enter" key is pressed
	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		// Checks for the car chosen
		if (nNotRed == 0)
			// Runs if player chose the red car
			Player::Instance()->setColour(true);
		else
			// Runs if the player chose the blue car
			Player::Instance()->setColour(false);
		
		// Pushes the state onto state 3 if "enter" is pressed
		pStateMachine->PushState(3);
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void ChooseCar::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws background
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBackground, 640, 360);

	// Draws text
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawText(m_font, "Choose Your Vehicle!", 470, 580);

	// Draws left box
	m_2dRenderer->setRenderColour(1, 1, nNotRed, 1);
	m_2dRenderer->drawSprite(m_pBox, 430, 300);

	// Draws right box
	m_2dRenderer->setRenderColour(1, 1, nNotBlue, 1);
	m_2dRenderer->drawSprite(m_pBox, 850, 300);
	
	// Draws red car
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pRed, 430, 300);

	// Draws blue car
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBlue, 850, 300);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void ChooseCar::OnExit(StateMachine* pStateMachine) {}