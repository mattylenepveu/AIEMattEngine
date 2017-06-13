#include "Matrix2.h"
#include <math.h>

// Defines pi for use in cpp file
#define PI 3.14159265359

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Matrix2::Matrix2()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		xx - yy: All used for various points on the Matrix2
//--------------------------------------------------------------------------------------
Matrix2::Matrix2(float xx, float yx, float xy, float yy)
{
	m[0][0] = xx;
	m[0][1] = yx;
	m[1][0] = xy;
	m[1][1] = yy;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Matrix2::~Matrix2()
{
	// Empty as we don't need to delete anything
}

//--------------------------------------------------------------------------------------
// Transfers results from degrees to radians
//
// Parameters:
//		deg: The angle that is being passed through (in degrees)
// Return:
//		Returns the angle in radians as a float value
//--------------------------------------------------------------------------------------
float Matrix2::DegToRad(float deg)
{
	float rad;
	rad = (deg / PI) * 180;
	return rad;
}

//--------------------------------------------------------------------------------------
// Transfers results to degrees from radians
//
// Parameters:
//		rad: The angle that is being passed through (in radians)
// Return:
//		Returns the angle in degrees as a float value
//--------------------------------------------------------------------------------------
float Matrix2::RadToDeg(float rad)
{
	float deg;
	deg = (PI / rad) * 180;
	return deg;
}

//--------------------------------------------------------------------------------------
// Multiplies a Vector2 by a Matrix2
//
// Parameters:
//		rhs: The Vector2 that is being used in equation
// Return:
//		Returns the solution as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Matrix2::operator*(const Vector2 & rhs)
{
	Vector2 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y;
	return result;
}

//--------------------------------------------------------------------------------------
// Multiplies a Matrix2 by another Matrix2
//
// Parameters:
//		rhs: A Matrix2 that is being used in equation
// Return:
//		Returns the solution as a Matrix2
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::operator*(const Matrix2 & rhs)
{
	Matrix2 result;

	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[0][1] * rhs.m[1][0];
	result.m[0][1] = m[0][0] * rhs.m[0][1] + m[0][1] * rhs.m[1][1];

	result.m[1][0] = m[1][0] * rhs.m[0][0] + m[1][1] * rhs.m[1][0];
	result.m[1][1] = m[1][0] * rhs.m[0][1] + m[1][1] * rhs.m[1][1];
	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a Matrix2
//
// Return:
//		Returns the solution as a float
//--------------------------------------------------------------------------------------
float Matrix2::Determinant()
{
	float res1 = m[0][0] * m[1][1];
	float res2 = m[1][0] * m[0][1];

	return res1 - res2;
}

//--------------------------------------------------------------------------------------
// Calculates the inverse of a Matrix2
//
// Return:
//		Returns the inverse as a Matrix2
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::Inverse()
{
	float inverseDet = 1 / Determinant();
	Matrix2 result;
	
	result.m[0][0] = inverseDet * m[0][0];
	result.m[0][1] = inverseDet * m[0][1] * -1;
	result.m[1][0] = inverseDet * m[1][0] * -1;
	result.m[1][1] = inverseDet * m[1][1];

	return result;
}

//--------------------------------------------------------------------------------------
// Checks if the Matrix2 is an Identity Matrix
//
// Return:
//		Returns if the Matrix2 is an Identity Matrix as a bool (either true or false)
//--------------------------------------------------------------------------------------
bool Matrix2::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}

	if (count == 4)
		return true;

	return false;
}

//--------------------------------------------------------------------------------------
// Transposes a Matrix2 (switches the columns and rows of each position)
//--------------------------------------------------------------------------------------
void Matrix2::Transpose()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			m[i][j] = m[j][i];
		}
	}
}

//--------------------------------------------------------------------------------------
// Allows for rotation in a 2d game
//
// Parameters:
//		a: Refers to the angle (in radians)
//--------------------------------------------------------------------------------------
void Matrix2::setRotate(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Allows for rotation in a 2d game
//
// Parameters:
//		a: Refers to the angle (in degrees)
//--------------------------------------------------------------------------------------
void Matrix2::setRotateDeg(const float deg)
{
	float rad;
	rad = DegToRad(deg);
	setRotate(rad);
}

//--------------------------------------------------------------------------------------
// Sets the scale of a game
//
// Parameters:
//		x: Refers to the x value of a Vector
//		y: Refers to the y value of a Vector
//--------------------------------------------------------------------------------------
void Matrix2::setScale(const float x, const float y)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[1][0] = 0;
	m[1][1] = y;
}

//--------------------------------------------------------------------------------------
// Allows the scale to be accessed
//
// Return:
//		Returns the scale as a Vector2
//--------------------------------------------------------------------------------------
Vector2 Matrix2::getScale()
{
	Vector2 res;

	Vector2 xcol(m[0][0], m[0][1]);
	Vector2 ycol(m[1][0], m[1][1]);

	res.x = xcol.Magnitude();
	res.y = ycol.Magnitude();

	return res;
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Matrix2
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector2
// Return:
//		Returns a Vector2 which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
Vector2& Matrix2::operator[](const int rhs)
{
	return *(Vector2*)m[rhs];
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Matrix2 values
//
// Return:
//		Returns the address of the top left coordinate of the Matrix2
//--------------------------------------------------------------------------------------
Matrix2::operator float*()
{
	return &m[0][0];
}
