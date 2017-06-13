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
class Matrix2
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2();

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		xx - yy: All used for various points on the Matrix2
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2(float xx, float yx, float xy, float yy);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix2();

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
	// Multiplies a Vector2 by a Matrix2
	//
	// Parameters:
	//		rhs: The Vector2 that is being used in equation
	// Return:
	//		Returns the solution as a Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Multiplies a Matrix2 by another Matrix2
	//
	// Parameters:
	//		rhs: A Matrix2 that is being used in equation
	// Return:
	//		Returns the solution as a Matrix2
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 operator*(const Matrix2& rhs);
	
	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a Matrix2
	//
	// Return:
	//		Returns the solution as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Determinant();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a Matrix2
	//
	// Return:
	//		Returns the inverse as a Matrix2
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 Inverse();

	//--------------------------------------------------------------------------------------
	// Checks if the Matrix2 is an Identity Matrix
	//
	// Return:
	//		Returns if the Matrix2 is an Identity Matrix as a bool (either true or false)
	//--------------------------------------------------------------------------------------
	MATH_DLL bool isIdentity();

	//--------------------------------------------------------------------------------------
	// Transposes a Matrix2 (switches the columns and rows of each position)
	//--------------------------------------------------------------------------------------
	MATH_DLL void Transpose();

	//--------------------------------------------------------------------------------------
	// Allows for rotation in a 2d game
	//
	// Parameters:
	//		a: Refers to the angle (in radians)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotate(const float a);

	//--------------------------------------------------------------------------------------
	// Allows for rotation in a 2d game
	//
	// Parameters:
	//		a: Refers to the angle (in degrees)
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateDeg(const float deg);

	//--------------------------------------------------------------------------------------
	// Sets the scale of a game
	//
	// Parameters:
	//		x: Refers to the x value of a Vector
	//		y: Refers to the y value of a Vector
	//--------------------------------------------------------------------------------------
	MATH_DLL void setScale(const float x, const float y);

	//--------------------------------------------------------------------------------------
	// Allows the scale to be accessed
	//
	// Return:
	//		Returns the scale as a Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 getScale();

	//--------------------------------------------------------------------------------------
	// Overloads the sub-script operator to allow use for a Matrix2
	//
	// Parameters:
	//		rhs: Indicates one of the intergers in a Vector2
	// Return:
	//		Returns a Vector2 which will be the value in the sub-script operator
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the cast operator to allow use for Matrix2 values
	//
	// Return:
	//		Returns the address of the top left coordinate of the Matrix2
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	// Defines the 2x2 matrix as a float
	float m[2][2];
};

