#include "Loading.h"
#include "StateMachine.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Loading::Loading()
{
	// Adds the texture to the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Creates a new loading bar via loading it in the resource manager
	m_pBar = pTextureManager->LoadResource("./textures/LoadingBarEmpty.png");

	// Creates a "new" font
	m_font = new Font("./font/consolas_bold.ttf", 32);
	_ASSERT(m_font);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Loading::~Loading()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Loading::OnEnter(StateMachine* pStateMachine)
{
	// Sets default values
	fTimer = 0.0f;
	nWidth = 0;
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Loading::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Updates timer based on real time
	fTimer += deltaTime;

	// Changes width on green square based on time
	if (fTimer >= 1.5f)
		nWidth = 60;

	if (fTimer >= 3.5f)
		nWidth = 170;

	if (fTimer >= 6.5f)
		nWidth = 320;

	if (fTimer >= 7.9f)
		nWidth = 377;

	if (fTimer >= 8.5f)
		pStateMachine->PushState(4);
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Loading::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws the loading bar
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBar, 640, 360);

	// Draws the text
	m_2dRenderer->setRenderColour(0, 1, 0, 1);
	m_2dRenderer->drawText(m_font, "Loading...", 434, 450);

	// Checks if timer is greater than 1.5f
	if (fTimer >= 1.5f)
	{
		// If so, draw a green square with width varying over time
		m_2dRenderer->setRenderColour(0, 1, 0, 1);
		m_2dRenderer->drawSprite(nullptr, 452, 360, nWidth, 94, 0, 0, 0);
	}
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Loading::OnExit(StateMachine* pStateMachine) {}