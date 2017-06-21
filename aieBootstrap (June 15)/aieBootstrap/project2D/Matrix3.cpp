#include "Matrix3.h"
#include <math.h>

// Defines pi for use in cpp file
#define PI 3.14159265359

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Matrix3::Matrix3()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		xx - zz: All used for various points on the Matrix3
//--------------------------------------------------------------------------------------
Matrix3::Matrix3(float xx, float xy, float xz, float yx, float yy, float yz, float zx, float zy, float zz)
{
	m[0][0] = xx;
	m[0][1] = xy;
	m[0][2] = xz;

	m[1][0] = yx;
	m[1][1] = yy;
	m[1][2] = yz;
	
	m[2][0] = zx;
	m[2][1] = zy;
	m[2][2] = zz;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Matrix3::~Matrix3()
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
float Matrix3::DegToRad(float deg)
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
float Matrix3::RadToDeg(float rad)
{
	float deg;
	deg = (PI / rad) * 180;
	return deg;
}

//--------------------------------------------------------------------------------------
// Multiplies a Vector3 by a Matrix3
//
// Parameters:
//		rhs: The Vector3 that is being used in equation
// Return:
//		Returns the solution as a Vector3
//--------------------------------------------------------------------------------------
Vector3 Matrix3::operator*(const Vector3 & rhs)
{
	Vector3 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y + m[2][0] * rhs.z;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y + m[2][1] * rhs.z;
	result.z = m[0][2] * rhs.x + m[1][2] * rhs.y + m[2][2] * rhs.z;
	return result;
}

//--------------------------------------------------------------------------------------
// Multiplies a Matrix3 by another Matrix3
//
// Parameters:
//		rhs: A Matrix3 that is being used in equation
// Return:
//		Returns the solution as a Matrix3
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::operator*(const Matrix3 & rhs)
{
	Matrix3 result;
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[1][0] * rhs.m[0][1] + m[2][0] * rhs.m[0][2];
	result.m[0][1] = m[0][1] * rhs.m[0][0] + m[1][1] * rhs.m[0][1] + m[2][1] * rhs.m[0][2];
	result.m[0][2] = m[0][2] * rhs.m[0][0] + m[1][2] * rhs.m[0][1] + m[2][2] * rhs.m[0][2];

	result.m[1][0] = m[0][0] * rhs.m[1][0] + m[1][0] * rhs.m[1][1] + m[2][0] * rhs.m[1][2];
	result.m[1][1] = m[0][1] * rhs.m[1][0] + m[1][1] * rhs.m[1][1] + m[2][1] * rhs.m[1][2];
	result.m[1][2] = m[0][2] * rhs.m[1][0] + m[1][2] * rhs.m[1][1] + m[2][2] * rhs.m[1][2];

	result.m[2][0] = m[0][0] * rhs.m[2][0] + m[1][0] * rhs.m[2][1] + m[2][0] * rhs.m[2][2];
	result.m[2][1] = m[0][1] * rhs.m[2][0] + m[1][1] * rhs.m[2][1] + m[2][1] * rhs.m[2][2];
	result.m[2][2] = m[0][2] * rhs.m[2][0] + m[1][2] * rhs.m[2][1] + m[2][2] * rhs.m[2][2];
	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a Matrix3
//
// Return:
//		Returns the solution as a float
//--------------------------------------------------------------------------------------
float Matrix3::Determinant()
{
	float res1 = m[0][0] * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2]));
	float res2 = m[1][0] * ((m[0][1] * m[2][2]) - (m[2][1] * m[0][2]));
	float res3 = m[2][0] * ((m[0][1] * m[1][2]) - (m[1][1] * m[0][2]));

	return res1 - res2 + res3;
}

//--------------------------------------------------------------------------------------
// Calculates the inverse of a Matrix3
//
// Return:
//		Returns the inverse as a Matrix3
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::Inverse()
{
	float inverseDet = 1 / Determinant();
	Matrix3 result;

	result.m[0][0] = inverseDet * ((m[1][1] * m[2][2]) - (m[2][1] * m[1][2]));
	result.m[0][1] = inverseDet * -1 * ((m[1][0] * m[2][2]) - (m[1][2] * m[2][0]));
	result.m[0][2] = inverseDet * ((m[1][0] * m[2][1]) - (m[2][0] * m[1][1]));
					
	result.m[1][0] = inverseDet * -1 * ((m[0][1] * m[2][2]) - (m[0][2] * m[2][1]));
	result.m[1][1] = inverseDet * ((m[0][0] * m[2][2]) - (m[0][2] * m[2][0]));
	result.m[1][2] = inverseDet * -1 * ((m[0][0] * m[2][1]) - (m[2][0] * m[0][1]));
					
	result.m[2][0] = inverseDet * ((m[0][1] * m[1][2]) - (m[0][2] * m[1][1]));
	result.m[2][1] = inverseDet * -1 * ((m[0][0] * m[1][2]) - (m[1][0] * m[0][2]));
	result.m[2][2] = inverseDet * ((m[0][0] * m[1][1]) - (m[1][0] * m[0][1]));

	return result;
}

//--------------------------------------------------------------------------------------
// Checks if the Matrix3 is an Identity Matrix
//
// Return:
//		Returns if the Matrix3 is an Identity Matrix as a bool (either true or false)
//--------------------------------------------------------------------------------------
bool Matrix3::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}

	if (count == 9)
		return true;

	return false;
}

//--------------------------------------------------------------------------------------
// Transposes a Matrix3 (switches the columns and rows of each position)
//--------------------------------------------------------------------------------------
void Matrix3::Transpose()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m[i][j] = m[j][i];
		}
	}
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the x axis
//
// Parameters:
//		a: Refers to the angle (in radians)
//--------------------------------------------------------------------------------------
void Matrix3::setRotateX(const float a)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = cosf(a);
	m[1][2] = sinf(a);
	m[2][0] = 0;
	m[2][1] = -sinf(a);
	m[2][2] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the y axis
//
// Parameters:
//		a: Refers to the angle (in radians)
//----------------------------------------------------------------------------------
void Matrix3::setRotateY(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = 0;
	m[0][2] = -sinf(a);
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = sinf(a);
	m[2][1] = 0;
	m[2][2] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the z axis
//
// Parameters:
//		a: Refers to the angle (in radians)
//--------------------------------------------------------------------------------------
void Matrix3::setRotateZ(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[0][2] = 0;
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the x axis
//
// Parameters:
//		a: Refers to the angle (in degrees)
//--------------------------------------------------------------------------------------
void Matrix3::setRotateXDeg(const float deg)
{
	float rad;
	rad = DegToRad(deg);
	setRotateX(rad);
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the y axis
//
// Parameters:
//		a: Refers to the angle (in degrees)
//--------------------------------------------------------------------------------------
void Matrix3::setRotateYDeg(const float deg)
{
	float rad;
	rad = DegToRad(deg);
	setRotateY(rad);
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the z axis
//
// Parameters:
//		a: Refers to the angle (in degrees)
//--------------------------------------------------------------------------------------
void Matrix3::setRotateZDeg(const float deg)
{
	float rad;
	rad = DegToRad(deg);
	setRotateZ(rad);
}

//--------------------------------------------------------------------------------------
// Sets the position of an object in a game
//
// Parameters:
//		x: Position on the x axis
//		y: Position on the y axis
//--------------------------------------------------------------------------------------
void Matrix3::setPos(const float x, const float y)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = x;
	m[2][1] = y;
	m[2][2] = 1;
}

//--------------------------------------------------------------------------------------
// Sets the position of an object in a game
//
// Parameters:
//		rhs: Refers to the position as a Vector2
//--------------------------------------------------------------------------------------
void Matrix3::setPos(const Vector2& rhs)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[2][0] = rhs.x;
	m[2][1] = rhs.y;
	m[2][2] = 1;
}

//--------------------------------------------------------------------------------------
// Allows the position to be accessed
//
// Return:
//		Returns the position as a Vector3
//--------------------------------------------------------------------------------------
Vector3 Matrix3::getPos()
{
	Vector3 res;

	res.x = m[2][0];
	res.y = m[2][1];

	return res;
}

//--------------------------------------------------------------------------------------
// Sets the scale of a game
//
// Parameters:
//		x: Refers to the x value of a Vector
//		y: Refers to the y value of a Vector
//		z: Refers to the z value of a Vector
//--------------------------------------------------------------------------------------
void Matrix3::setScale(const float x, const float y, const float z)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
}

//--------------------------------------------------------------------------------------
// Allows the scale to be accessed
//
// Return:
//		Returns the scale as a Vector3
//--------------------------------------------------------------------------------------
Vector3 Matrix3::getScale()
{
	Vector3 res;

	Vector3 xcol(m[0][0], m[0][1], m[0][2]);
	Vector3 ycol(m[1][0], m[1][1], m[1][2]);
	Vector3 zcol(m[2][0], m[2][1], m[2][2]);

	res.x = xcol.Magnitude();
	res.y = ycol.Magnitude();
	res.z = zcol.Magnitude();

	return res;
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Matrix3
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector3
// Return:
//		Returns a Vector3 which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
Vector3& Matrix3::operator[](const int rhs)
{
	return *(Vector3*)m[rhs];
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Matrix4 values
//
// Return:
//		Returns the address of the top left coordinate of the Matrix4
//--------------------------------------------------------------------------------------
Matrix3::operator float*()
{
	return &m[0][0];
}
