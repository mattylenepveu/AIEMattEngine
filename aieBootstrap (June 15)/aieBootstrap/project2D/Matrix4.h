// Checks to see if library is static, dll export or dll import
#ifdef STATIC_LIB
	#define	MATH_DLL
#else
	#ifdef DLL_EXPORT
		#define MATH_DLL __declspec(dllexport)
	#else
		#define MATH_DLL __declspec(dllimport)
	#endif
#endif

#pragma once
#include "Vector4.h"
#include "Vector3.h"
class Matrix4
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4();

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		xx - tw: All used for various points on the Matrix4
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4(float xx, float yx, float zx, float tx, float xy, float yy, float zy, float ty, float xz, float yz, float zz, float tz, float xw, float yw, float zw, float tw);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix4();

	//--------------------------------------------------------------------------------------
	// Transfers results from degrees to radians
	//
	// Parameters:
	//		deg: The angle that is being passed through (in degrees)
	// Return:
	//		Returns the angle in radians as a float value
	//--------------------------------------------------------------------------------------
	MATH_DLL float DegToRad(float deg);

	//--------------------------------------------------------------------------------------
	// Transfers results to degrees from radians
	//
	// Parameters:
	//		rad: The angle that is being passed through (in radians)
	// Return:
	//		Returns the angle in degrees as a float value
	//--------------------------------------------------------------------------------------
	MATH_DLL float RadToDeg(float rad);

	//--------------------------------------------------------------------------------------
	// Multiplies a Vector4 by a Matrix4
	//
	// Parameters:
	//		rhs: The Vector4 that is being used in equation
	// Return:
	//		Returns the solution as a Vector4
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator*(const Vector4& rhs);

	//--------------------------------------------------------------------------------------
	// Multiplies a Matrix4 by another Matrix4
	//
	// Parameters:
	//		rhs: A Matrix4 that is being used in equation
	// Return:
	//		Returns the solution as a Matrix4
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 operator*(const Matrix4& rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix4
	//
	// Return:
	//		Returns the solution as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Determinant();

	//--------------------------------------------------------------------------------------
	// Checks if the Matrix4 is an Identity Matrix
	//
	// Return:
	//		Returns if the Matrix4 is an Identity Matrix as a bool (either true or false)
	//--------------------------------------------------------------------------------------
	MATH_DLL bool isIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix4 (switches the columns and rows of each position)
	//--------------------------------------------------------------------------------------
	MATH_DLL void Transpose();

	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the x axis
	//
	// Parameters:
	//		a: Refers to the angle (in radians)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateX(const float a);

	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the y axis
	//
	// Parameters:
	//		a: Refers to the angle (in radians)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateY(const float a);

	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the z axis
	//
	// Parameters:
	//		a: Refers to the angle (in radians)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateZ(const float a);

	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the x axis
	//
	// Parameters:
	//		a: Refers to the angle (in degrees)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateXDeg(const float deg);

	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the y axis
	//
	// Parameters:
	//		a: Refers to the angle (in degrees)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateYDeg(const float deg);
	
	//--------------------------------------------------------------------------------------
	// Allows for rotation in game on the z axis
	//
	// Parameters:
	//		a: Refers to the angle (in degrees)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateZDeg(const float deg);

	//--------------------------------------------------------------------------------------
	// Sets the position of an object in a game
	//
	// Parameters:
	//		x: Position on the x axis
	//		y: Position on the y axis
	//		z: Position on the z axis
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPos(const float x, const float y, const float z);

	//--------------------------------------------------------------------------------------
	// Sets the position of an object in a game
	//
	// Parameters:
	//		rhs: Refers to the position as a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPos(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Allows the position to be accessed
	//
	// Return:
	//		Returns the position as a Vector4
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 getPos();

	//--------------------------------------------------------------------------------------
	// Sets the scale of a game
	//
	// Parameters:
	//		x: Refers to the x value of a Vector
	//		y: Refers to the y value of a Vector
	//		z: Refers to the z value of a Vector
	//--------------------------------------------------------------------------------------
	MATH_DLL void setScale(const float x, const float y, const float z);

	//--------------------------------------------------------------------------------------
	// Allows the scale to be accessed
	//
	// Return:
	//		Returns the scale as a Vector4
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 getScale();

	//--------------------------------------------------------------------------------------
	// Allows for a player or object to look at something
	//
	// Parameters:
	//		from: Refers to the players position
	//		target: Refers to the position of the object the players trying to look at
	//		up: Refers to the line above the player
	//--------------------------------------------------------------------------------------
	MATH_DLL void LookAt(Vector3 from, const Vector3 target, const Vector3 up);

	//--------------------------------------------------------------------------------------
	// Overloads the sub-script operator to allow use for a Matrix4
	//
	// Parameters:
	//		rhs: Indicates one of the intergers in a Vector4
	// Return:
	//		Returns a Vector4 which will be the value in the sub-script operator
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the cast operator to allow use for Matrix4 values
	//
	// Return:
	//		Returns the address of the top left coordinate of the Matrix4
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	// Defines the 4x4 matrix as a float
	float m[4][4];
};

