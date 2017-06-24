#include "Splash.h"
#include "StateMachine.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Splash::Splash()
{
	// Manages the textures in the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Defines the picture from resource manager
	m_pPic = pTextureManager->LoadResource("./textures/Me.png");

	// Creates a "new" font
	m_font = new Font("./font/consolas_bold.ttf", 32);
	_ASSERT(m_font);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Splash::~Splash()
{
	delete m_font;
}

//--------------------------------------------------------------------------------------
// Runs when the state is first pushed back
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Splash::OnEnter(StateMachine* pStateMachine)
{
	// Defines default variables
	fTimer = 0.0f;
	fAlpha = 0.0f;
}

//--------------------------------------------------------------------------------------
// Updates the state when it is running
//
// Paramaters:
//		fDeltaTime: Keeps track of real time, used for movement and waiting periods
//		pStateMachine: Is used to access the state machine
//		m_2dRenderer: Is used for access to the renderer class
//--------------------------------------------------------------------------------------
void Splash::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Keeps updating timer via real time
	fTimer += deltaTime;

	// Allows variable to be used for a fade in
	fAlpha += deltaTime;

	// Does not let alpha become greater than one
	if (fAlpha >= 1.0f)
		fAlpha = 1.0f;

	// If timer is greater or equal to five, then move on to the menu
	if (fTimer >= 5.0f)
		pStateMachine->PushState(1);
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Splash::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws the image
	m_2dRenderer->setRenderColour(1, 1, 1, fAlpha);
	m_2dRenderer->drawSprite(m_pPic, 640, 420);
	
	// Draws the text below the image
	m_2dRenderer->drawText(m_font, "Matthew Le Nepveu Productions", 380, 170);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Splash::OnExit(StateMachine* pStateMachine) 
{
	// Resets timer to equal zero when state is exited
	fTimer = 0.0f;
}