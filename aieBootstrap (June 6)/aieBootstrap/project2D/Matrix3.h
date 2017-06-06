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
#include "Vector2.h"
#include "Vector3.h"
class Matrix3
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3();

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		xx - zz: All used for various points on the Matrix3
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3(float xx, float yx, float zx, float xy, float yy, float zy, float xz, float yz, float zz);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix3();

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
	// Multiplies a Vector3 by a Matrix3
	//
	// Parameters:
	//		rhs: The Vector3 that is being used in equation
	// Return:
	//		Returns the solution as a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator*(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Multiplies a Matrix3 by another Matrix3
	//
	// Parameters:
	//		rhs: A Matrix3 that is being used in equation
	// Return:
	//		Returns the solution as a Matrix3
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 operator*(const Matrix3& rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix3
	//
	// Return:
	//		Returns the solution as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Determinant();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a Matrix3
	//
	// Return:
	//		Returns the inverse as a Matrix3
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 Inverse();

	//--------------------------------------------------------------------------------------
	// Checks if the Matrix3 is an Identity Matrix
	//
	// Return:
	//		Returns if the Matrix3 is an Identity Matrix as a bool (either true or false)
	//--------------------------------------------------------------------------------------
	MATH_DLL bool isIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix3 (switches the columns and rows of each position)
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
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPos(const float x, const float y);

	//--------------------------------------------------------------------------------------
	// Sets the position of an object in a game
	//
	// Parameters:
	//		rhs: Refers to the position as a Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL void setPos(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Allows the position to be accessed
	//
	// Return:
	//		Returns the position as a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 getPos();

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
	//		Returns the scale as a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 getScale();

	//--------------------------------------------------------------------------------------
	// Overloads the sub-script operator to allow use for a Matrix3
	//
	// Parameters:
	//		rhs: Indicates one of the intergers in a Vector3
	// Return:
	//		Returns a Vector3 which will be the value in the sub-script operator
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the cast operator to allow use for Matrix4 values
	//
	// Return:
	//		Returns the address of the top left coordinate of the Matrix4
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	// Defines the 3x3 matrix as a float
	float m[3][3];
};

