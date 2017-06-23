#pragma once
class Player
{
public:
	//--------------------------------------------------------------------------------------
	// Function made to return any instance to any class
	//
	// Return:
	//		Returns the static instance
	//--------------------------------------------------------------------------------------
	static Player* Instance();

	//--------------------------------------------------------------------------------------
	// Acts as our constuctor and creates a "new" instance
	//--------------------------------------------------------------------------------------
	static void create() { m_instance = new Player(); }

	//--------------------------------------------------------------------------------------
	// Acts as our destructor and deletes the instance to prevent memory leaks
	//--------------------------------------------------------------------------------------
	static void destroy() { delete m_instance; }

	//--------------------------------------------------------------------------------------
	// Used to get the colour of the car and sets the colour
	//
	// Parameters:
	//		colour: Checks what colour it is (true = red, false = blue)
	//--------------------------------------------------------------------------------------
	void setColour(bool colour);

	//--------------------------------------------------------------------------------------
	// Allows the colour to be gotten in other classes
	//
	// Return:
	//		Returns the colour of the car (true = red, false = blue)
	//--------------------------------------------------------------------------------------
	bool getColour();

	//--------------------------------------------------------------------------------------
	// Used to check if the car has finished and sets it
	//
	// Parameters:
	//		fin: A bool that states if the car has finished
	//--------------------------------------------------------------------------------------
	void setFinish(bool fin);

	//--------------------------------------------------------------------------------------
	// Allows other classes to check if the car has finished
	//
	// Return:
	//		Returns if the car has finished or not
	//--------------------------------------------------------------------------------------
	bool getFinish();

private:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	Player();

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	~Player();

	// Makes a static instance with the type being a singleton pointer
	static Player* m_instance;

	bool bColour;
	bool bFin;
};

