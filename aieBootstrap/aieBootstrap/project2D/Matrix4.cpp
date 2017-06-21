#include "Matrix4.h"
#include "VectorCast.h"
#include <math.h>

// Defines pi for use in cpp file
#define PI 3.14159265359

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Matrix4::Matrix4()
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		xx - tw: All used for various points on the Matrix4
//--------------------------------------------------------------------------------------
Matrix4::Matrix4(float xx, float yx, float zx, float tx, float xy, float yy, float zy, float ty, float xz, float yz, float zz, float tz, float xw, float yw, float zw, float tw)
{
	m[0][0] = xx;
	m[0][1] = yx;
	m[0][2] = zx;
	m[0][3] = tx;
	m[1][0] = xy;
	m[1][1] = yy;
	m[1][2] = zy;
	m[1][3] = ty;
	m[2][0] = xz;
	m[2][1] = yz;
	m[2][2] = zz;
	m[2][3] = tz;
	m[3][0] = xw;
	m[3][1] = yw;
	m[3][2] = zw;
	m[3][3] = tw;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Matrix4::~Matrix4()
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
float Matrix4::DegToRad(float deg)
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
float Matrix4::RadToDeg(float rad)
{
	float deg;
	deg = (PI / rad) * 180;
	return deg;
}

//--------------------------------------------------------------------------------------
// Multiplies a Vector4 by a Matrix4
//
// Parameters:
//		rhs: The Vector4 that is being used in equation
// Return:
//		Returns the solution as a Vector4
//--------------------------------------------------------------------------------------
Vector4 Matrix4::operator*(const Vector4 & rhs)
{
	Vector4 result;
	result.x = m[0][0] * rhs.x + m[1][0] * rhs.y + m[2][0] * rhs.z + m[3][0] * rhs.w;
	result.y = m[0][1] * rhs.x + m[1][1] * rhs.y + m[2][1] * rhs.z + m[3][1] * rhs.w;
	result.z = m[0][2] * rhs.x + m[1][2] * rhs.y + m[2][2] * rhs.z + m[3][2] * rhs.w;
	result.w = m[0][3] * rhs.x + m[1][3] * rhs.y + m[2][3] * rhs.z + m[3][3] * rhs.w;
	return result;
}

//--------------------------------------------------------------------------------------
// Multiplies a Matrix4 by another Matrix4
//
// Parameters:
//		rhs: A Matrix4 that is being used in equation
// Return:
//		Returns the solution as a Matrix4
//--------------------------------------------------------------------------------------
Matrix4 Matrix4::operator*(const Matrix4 & rhs)
{
	Matrix4 result;
	// Col 1
	result.m[0][0] = m[0][0] * rhs.m[0][0] + m[1][0] * rhs.m[0][1] + m[2][0] * rhs.m[0][2] + m[3][0] * rhs.m[0][3];
	result.m[0][1] = m[0][1] * rhs.m[0][0] + m[1][1] * rhs.m[0][1] + m[2][1] * rhs.m[0][2] + m[3][1] * rhs.m[0][3];
	result.m[0][2] = m[0][2] * rhs.m[0][0] + m[1][2] * rhs.m[0][1] + m[2][2] * rhs.m[0][2] + m[3][2] * rhs.m[0][3];
	result.m[0][3] = m[0][3] * rhs.m[0][0] + m[1][3] * rhs.m[0][1] + m[2][3] * rhs.m[0][2] + m[3][3] * rhs.m[0][3];

	// Col 2
	result.m[1][0] = m[0][0] * rhs.m[1][0] + m[1][0] * rhs.m[1][1] + m[2][0] * rhs.m[1][2] + m[3][0] * rhs.m[1][3];
	result.m[1][1] = m[0][1] * rhs.m[1][0] + m[1][1] * rhs.m[1][1] + m[2][1] * rhs.m[1][2] + m[3][1] * rhs.m[1][3];
	result.m[1][2] = m[0][2] * rhs.m[1][0] + m[1][2] * rhs.m[1][1] + m[2][2] * rhs.m[1][2] + m[3][2] * rhs.m[1][3];
	result.m[1][3] = m[0][3] * rhs.m[1][0] + m[1][3] * rhs.m[1][1] + m[2][3] * rhs.m[1][2] + m[3][3] * rhs.m[1][3];

	// Col 3
	result.m[2][0] = m[0][0] * rhs.m[2][0] + m[1][0] * rhs.m[2][1] + m[2][0] * rhs.m[2][2] + m[3][0] * rhs.m[2][3];
	result.m[2][1] = m[0][1] * rhs.m[2][0] + m[1][1] * rhs.m[2][1] + m[2][1] * rhs.m[2][2] + m[3][1] * rhs.m[2][3];
	result.m[2][2] = m[0][2] * rhs.m[2][0] + m[1][2] * rhs.m[2][1] + m[2][2] * rhs.m[2][2] + m[3][2] * rhs.m[2][3];
	result.m[2][3] = m[0][3] * rhs.m[2][0] + m[1][3] * rhs.m[2][1] + m[2][3] * rhs.m[2][2] + m[3][3] * rhs.m[2][3];

	// Col 4
	result.m[3][0] = m[0][0] * rhs.m[3][0] + m[1][0] * rhs.m[3][1] + m[2][0] * rhs.m[3][2] + m[3][0] * rhs.m[3][3];
	result.m[3][1] = m[0][1] * rhs.m[3][0] + m[1][1] * rhs.m[3][1] + m[2][1] * rhs.m[3][2] + m[3][1] * rhs.m[3][3];
	result.m[3][2] = m[0][2] * rhs.m[3][0] + m[1][2] * rhs.m[3][1] + m[2][2] * rhs.m[3][2] + m[3][2] * rhs.m[3][3];
	result.m[3][3] = m[0][3] * rhs.m[3][0] + m[1][3] * rhs.m[3][1] + m[2][3] * rhs.m[3][2] + m[3][3] * rhs.m[3][3];
	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a Matrix4
//
// Return:
//		Returns the solution as a float
//--------------------------------------------------------------------------------------
float Matrix4::Determinant()
{
	float a = m[0][0]; float b = m[1][0]; float c = m[2][0]; float d = m[3][0];
	float e = m[0][1]; float f = m[1][1]; float g = m[2][1]; float h = m[3][1];
	float i = m[0][2]; float j = m[1][2]; float k = m[2][2]; float l = m[3][2];
	float z = m[0][3]; float n = m[1][3]; float o = m[2][3]; float p = m[3][3];

	float res1 = a * (f * k * p - f * l * o - g * j * p + g * l * n + h * j * o - h * k * n);
	float res2 = b * (e * k * p - e * l * o - g * i * p + g * l * z + h * i * o - h * k * z);
	float res3 = c * (e * j * p - e * l * n - f * i * p + f * l * z + h * i * n - h * j * z);
	float res4 = d * (e * j * o - e * k * n - f * i * o + f * k * z + g * i * n - g * j * z);

	return res1 - res2 + res3 - res4;
}

//--------------------------------------------------------------------------------------
// Checks if the Matrix4 is an Identity Matrix
//
// Return:
//		Returns if the Matrix4 is an Identity Matrix as a bool (either true or false)
//--------------------------------------------------------------------------------------
bool Matrix4::isIdentity()
{
	int count = 0;

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (i == j && m[i][j] == 1)
				++count;
			else if (i != j && m[i][j] == 0)
				++count;
		}
	}

	if (count == 16)
		return true;

	return false;
}

//--------------------------------------------------------------------------------------
// Transposes a Matrix4 (switches the columns and rows of each position)
//--------------------------------------------------------------------------------------
void Matrix4::Transpose()
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
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
void Matrix4::setRotateX(const float a)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = cosf(a);
	m[1][2] = sinf(a);
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = -sinf(a);
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the y axis
//
// Parameters:
//		a: Refers to the angle (in radians)
//--------------------------------------------------------------------------------------
void Matrix4::setRotateY(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = 0;
	m[0][2] = -sinf(a);
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = sinf(a);
	m[2][1] = 0;
	m[2][2] = cosf(a);
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the z axis
//
// Parameters:
//		a: Refers to the angle (in radians)
//--------------------------------------------------------------------------------------
void Matrix4::setRotateZ(const float a)
{
	m[0][0] = cosf(a);
	m[0][1] = sinf(a);
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = -sinf(a);
	m[1][1] = cosf(a);
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Allows for rotation in game on the x axis
//
// Parameters:
//		a: Refers to the angle (in degrees)
//--------------------------------------------------------------------------------------
void Matrix4::setRotateXDeg(const float deg)
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
void Matrix4::setRotateYDeg(const float deg)
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
void Matrix4::setRotateZDeg(const float deg)
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
//		z: Position on the z axis
//--------------------------------------------------------------------------------------
void Matrix4::setPos(const float x, const float y, const float z)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = x;
	m[3][1] = y;
	m[3][2] = z;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Sets the position of an object in a game
//
// Parameters:
//		rhs: Refers to the position as a Vector3
//--------------------------------------------------------------------------------------
void Matrix4::setPos(const Vector3& rhs)
{
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = rhs.x;
	m[3][1] = rhs.y;
	m[3][2] = rhs.z;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Allows the position to be accessed
//
// Return:
//		Returns the position as a Vector4
//--------------------------------------------------------------------------------------
Vector4 Matrix4::getPos()
{
	Vector4 res;

	res.x = m[3][0];
	res.y = m[3][1];
	res.z = m[3][2];

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
void Matrix4::setScale(const float x, const float y, const float z)
{
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Allows the scale to be accessed
//
// Return:
//		Returns the scale as a Vector4
//--------------------------------------------------------------------------------------
Vector4 Matrix4::getScale()
{
	Vector4 res;

	Vector4 xcol(m[0][0], m[0][1], m[0][2], m[0][3]);
	Vector4 ycol(m[1][0], m[1][1], m[1][2], m[1][3]);
	Vector4 zcol(m[2][0], m[2][1], m[2][2], m[2][3]);

	res.x = xcol.Magnitude();
	res.y = ycol.Magnitude();
	res.z = zcol.Magnitude();

	return res;
}

//--------------------------------------------------------------------------------------
// Allows for a player or object to look at something
//
// Parameters:
//		from: Refers to the players position
//		target: Refers to the position of the object the players trying to look at
//		up: Refers to the line above the player
//--------------------------------------------------------------------------------------
void Matrix4::LookAt(Vector3 from, const Vector3 target, const Vector3 up)
{
	Vector3 zaxis = from - target;
	zaxis.Normalise();

	Vector3 xaxis = zaxis.Cross(up);
	xaxis.Normalise();

	Vector3 yaxis = xaxis.Cross(zaxis);
	yaxis.Normalise();

	(*this)[0] = CastTo<Vector4>(xaxis);
	(*this)[1] = CastTo<Vector4>(yaxis);
	(*this)[2] = CastTo<Vector4>(zaxis);
	(*this)[3] = CastTo<Vector4>(from);

	m[3][3] = 1;
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Matrix4
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector4
// Return:
//		Returns a Vector4 which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
Vector4 & Matrix4::operator[](const int rhs)
{
	return *(Vector4*)m[rhs];
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Matrix4 values
//
// Return:
//		Returns the address of the top left coordinate of the Matrix4
//--------------------------------------------------------------------------------------
Matrix4::operator float*()
{
	return &m[0][0];
}
