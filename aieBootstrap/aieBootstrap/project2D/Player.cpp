#include "Player.h"

Player* Player::m_instance = nullptr;

Player::Player()
{
}

Player::~Player()
{
}

Player* Player::Instance()
{
	return m_instance;
}

void Player::setColour(bool colour)
{
	bColour = colour;
}

bool Player::getColour()
{
	return bColour;
}

void Player::setFinish(bool fin)
{
	bFin = fin;
}

bool Player::getFinish()
{
	return bFin;
}