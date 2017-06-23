#include "Menu.h"
#include "Input.h"
#include "StateMachine.h"

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Menu::Menu()
{
	// Adds textures to the resource manager
	ResourceManager<Texture>* pTextureManager = ResourceManager<Texture>::GetInstance();

	// Creates a new logo and background via loading them from resource manager
	m_pLogo = pTextureManager->LoadResource("./textures/GameLogo.png");
	m_pBackground = pTextureManager->LoadResource("./textures/BackgroundCol.png");

	// Creates a new font
	m_font = new Font("./font/consolas_bold.ttf", 32);
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Menu::~Menu()
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
void Menu::OnEnter(StateMachine* pStateMachine)
{
	// Sets the default values
	fAlpha = 1.0f;
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
void Menu::OnUpdate(float deltaTime, StateMachine* pStateMachine, Renderer2D* m_2dRenderer)
{
	// Allows user to input keys
	Input* input = Input::getInstance();

	// If "enter" key is pressed, then push to choose car screen
	if (input->wasKeyPressed(INPUT_KEY_ENTER))
		pStateMachine->PushState(2);

	// Updates timer variable based on real time
	fTimer += deltaTime;

	// If timer is greater than 3.0, then don't let text appear
	if (fTimer > 3.0f)
		fAlpha = 0.0f;

	// If timer is greater than 3.5, then let text appear and reset timer
	if (fTimer > 3.5f)
	{
		fAlpha = 1.0f;
		fTimer -= fTimer;
	}
}

//--------------------------------------------------------------------------------------
// Draws the state when it is pushed on the stack
//
// Parameters:
//		m_2dRenderer: Accesses the renderer class to allow the state to be drawn
//--------------------------------------------------------------------------------------
void Menu::OnDraw(Renderer2D* m_2dRenderer)
{
	// Draws the background
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pBackground, 640, 360);

	// Draws the logo
	m_2dRenderer->setRenderColour(1, 1, 1, 1);
	m_2dRenderer->drawSprite(m_pLogo, 640, 450);

	// Draws the first line of text
	m_2dRenderer->setRenderColour(1, 0, 0, fAlpha);
	m_2dRenderer->drawText(m_font, "Press Enter to Play!", 468, 190);

	// Draws the second line of text
	m_2dRenderer->setRenderColour(1, 0, 0, 1);
	m_2dRenderer->drawText(m_font, "(C) 2017 Matthew Le Nepveu Productions", 302, 120);
}

//--------------------------------------------------------------------------------------
// Runs when the state is being exited
//
// Paramaters:
//		pStateMachine: A pointer to the StateMachine for use in function
//--------------------------------------------------------------------------------------
void Menu::OnExit(StateMachine* pStateMachine)
{
	// Sets timer to 0.0 upon exiting state
	fAlpha = 0.0f;
}