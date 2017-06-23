#include "Credits.h"
#include "StateMachine.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Credits::Credits()
{
	// Creates a "new" font
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Credits::~Credits()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Credits::OnEnter(StateMachine* pStateMachine)
{
	fTimer = 0.0f;
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Credits::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Updates timer based on real time
	fTimer += deltaTime;

	// Checks if timer is 8.0f or greater
	if (fTimer >= 8.0f)
	{
		// If it is, then reset stack and go back to title screen state
		pStateMachine->Reset();
		pStateMachine->PushState(1);
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Credits::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws the "You Win!!!" text
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "You Win!!!", 555, 390);

	// Draws the second line of text
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Thanks for playing this amazing simulation!", 265, 314);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Credits::OnExit(StateMachine* pStateMachine) {}
