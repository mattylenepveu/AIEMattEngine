#include "Application2D.h"
#include <crtdbg.h>

//--------------------------------------------------------------------------------------
// Runs the game
//
// Return:
//		Returns an int.
//--------------------------------------------------------------------------------------
int main() 
{
	// Creates a "new" application2D
	Application2D* app = new Application2D();
	_ASSERT(app);

	// Calls the run function to load program
	app->run("AIE", 1280, 720, false);

	// Deletes app to prevent memory leaks
	delete app;

	return 0;
}