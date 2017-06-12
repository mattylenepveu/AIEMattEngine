#pragma once

// Includes from Vector2 class
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// Struct used to define properties for collision
//--------------------------------------------------------------------------------------
struct Collider
{
	// Defines the radius as a float
	float rad;

	// Defines the top left and bottom right both as Vector2's
	Vector2 topLeft;
	Vector2 bottomRight;
};