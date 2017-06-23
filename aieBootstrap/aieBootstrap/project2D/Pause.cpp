#include "Pause.h"
#include "StateMachine.h"
#include "Input.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Pause::Pause()
{
	// Creates a "new" font
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Pause::~Pause()
{
	// Deletes the font
	delete m_font;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Pause::OnEnter(StateMachine* pStateMachine) {}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Pause::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Allows user input
	Input* input = Input::getInstance();

	// Checks if escape key is pressed
	if (input->wasKeyPressed(INPUT_KEY_ESCAPE))
	{
		// Sets the two running states to be false
		pStateMachine->SetBackground(false);

		// Resets camera position
		m_2dRenderer->setCameraPos(0, 0);

		// Resets the state machine
		pStateMachine->Reset();

		// Starts the title screen state
		pStateMachine->PushState(1);
	}

	if (input->wasKeyPressed(INPUT_KEY_ENTER))
	{
		pStateMachine->SetBackground(false);
		pStateMachine->PopState();
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Pause::OnDraw(Renderer2D* m_2dRenderer)
{
	// Creates two local floats
	float xPos;
	float yPos;

	// Sets the camera position based on where the player is
	m_2dRenderer->getCameraPos(xPos, yPos);

	// Draws a slightly faded box over the game
	m_2dRenderer->setRenderColour(0, 0, 0, 0.75);
	m_2dRenderer->drawBox(xPos + 640, yPos + 360, 1280, 720);

	// Places text in centre of the screen
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Pause.", xPos + 590, yPos + 360);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Pause::OnExit(StateMachine* pStateMachine) {}