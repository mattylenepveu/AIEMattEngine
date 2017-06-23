#include "Player.h"

Player* Player::m_instance = nullptr;

Player::Player() {}

Player::~Player() {}

//--------------------------------------------------------------------------------------
// Function made to return any instance to any class
//
// Return:
//		Returns the static instance
//--------------------------------------------------------------------------------------
Player* Player::Instance()
{
	return m_instance;
}

//--------------------------------------------------------------------------------------
// Used to get the colour of the car and sets the colour
//
// Parameters:
//		colour: Checks what colour it is (true = red, false = blue)
//--------------------------------------------------------------------------------------
void Player::setColour(bool colour)
{
	bColour = colour;
}

//--------------------------------------------------------------------------------------
// Allows the colour to be gotten in other classes
//
// Return:
//		Returns the colour of the car (true = red, false = blue)
//--------------------------------------------------------------------------------------
bool Player::getColour()
{
	return bColour;
}

//--------------------------------------------------------------------------------------
// Used to check if the car has finished and sets it
//
// Parameters:
//		fin: A bool that states if the car has finished
//--------------------------------------------------------------------------------------
void Player::setFinish(bool fin)
{
	bFin = fin;
}

//--------------------------------------------------------------------------------------
// Allows other classes to check if the car has finished
//
// Return:
//		Returns if the car has finished or not
//--------------------------------------------------------------------------------------
bool Player::getFinish()
{
	return bFin;
}