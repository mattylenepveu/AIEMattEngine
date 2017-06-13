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
class Vector2
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2();

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		x: Uses "this" keyword to define the x value of a Vector2
	//		y: Uses "this" keyword to define the y value of a Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2(float x, float y);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector2();

	//--------------------------------------------------------------------------------------
	// Overloads the double equals operator for use for Vector2's.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in if statement
	// Return:
	//		Returns a boolean (either true or false) whether the first Vector2 is equal to
	//		the second Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator==(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the not equals operator for use for Vector2's.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in if statement
	// Return:
	//		Returns a boolean (either true or false) whether the first Vector2 is not equal
	//		to the second Vector2.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator!=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the plus symbol to add two Vector2's together.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's when added.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator+(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the minus symbol to subtract two Vector2's together.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's when subtracted.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the multiply symbol to multiply two Vector2's together.
	//
	// Parameters:
	//		rhs: Indicates a float value used in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's when multiplied.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*(const float rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the division symbol to divide two Vector2's together.
	//
	// Parameters:
	//		rhs: Indicates a float value used in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's when divided.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator/(const float rhs);

	//--------------------------------------------------------------------------------------
	// Finds the dot product of two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a float which is the answer to the equation
	//--------------------------------------------------------------------------------------
	MATH_DLL float Dot(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the negative symbol of any value in a Vector2
	//
	// Return:
	//		Returns a Vector2 to display a Vector2 with the negative symbol
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-();

	//--------------------------------------------------------------------------------------
	// Finds the magnitude of a Vector2
	//
	// Return:
	//		Returns a float which is the result of the Vector2's magnitude
	//--------------------------------------------------------------------------------------
	MATH_DLL float Magnitude();

	//--------------------------------------------------------------------------------------
	// Finds the magnitude of a Vector2 with answer being squared
	//
	// Return:
	//		Returns a float which is the result of the Vector2's magnitude squared
	//--------------------------------------------------------------------------------------
	MATH_DLL float sqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises the magnitude of a Vector2 (received when called on)
	//--------------------------------------------------------------------------------------
	MATH_DLL void Normalise();

	//--------------------------------------------------------------------------------------
	// Normalises the magnitude of a Vector2 (received via Parameters)
	//
	// Parameters:
	//		data: Indicates the Vector2 being normalised
	// Return:
	//		Returns a Vector2 which is the normalised Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL static Vector2 StaticNormalise(Vector2 data);

	//--------------------------------------------------------------------------------------
	// Overloads the plus-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator+=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the minus-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's when added.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator-=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the multiply-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator*=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the divide-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector2 to display the result of the two Vector2's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator/=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Finds the minimum values in two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a Vector2 to display the result of the minimum Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 min(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Finds the maximum values in two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a Vector2 to display the result of the maximum Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 max(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Limits the space between two Vectors
	//
	// Parameters:
	//		max: Indicates the maximum vector
	//      min: Indicates the minimum vector 
	// Return:
	//		Returns a Vector2 to display the minimum Vector2 (where clamping begins)
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 clamp(Vector2 max, Vector2 min);

	//--------------------------------------------------------------------------------------
	// Overloads the greater than symbol to allow use for two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector2 is greater than
	//		the other Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the less than symbol to allow use for two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector2 is less than
	//		the other Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the greater than or equal to symbol to allow use for two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector2 is greater than
	//		or equal to the other Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the less than or equal to symbol to allow use for two Vector2's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector2 is less than or
	//		equal to the other Vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<=(const Vector2& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the sub-script operator to allow use for a Vector2
	//
	// Parameters:
	//		rhs: Indicates one of the intergers in a Vector2
	// Return:
	//		Returns a float which will be the value in the sub-script operator
	//--------------------------------------------------------------------------------------
	MATH_DLL float& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the cast operator to allow use for Vector2 values
	//
	// Return:
	//		Returns the address of x
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Calculates the normal of line between two Vector2's
	//
	// Parameters:
	//		pos: Indicates the position of one of the Vector2's
	// Return:
	//		Returns a Vector2 which is the position of the normal
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 CalcNorm(Vector2 pos);

	//--------------------------------------------------------------------------------------
	// Calculates the distance between two Vector2's
	//
	// Parameters:
	//		pos1: Indicates the position of one of the Vector2's
	//		pos2: Indicates the position of the other Vector2
	// Return:
	//		Returns the distance between the two Vector2's as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float CalcDist(Vector2 pos1, Vector2 pos2);

	//--------------------------------------------------------------------------------------
	// Calculates any position between two Vector2's
	//
	// Parameters:
	//		a: Indicates the position of one of the Vector2's
	//		b: Indicates the position of the other Vector2
	//		t: Indicates a percentage between the two Vector2's
	// Return:
	//		Returns a Vector2 which is a position between the two Vector2's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 Lerp(Vector2 a, Vector2 b, float t);

	//--------------------------------------------------------------------------------------
	// Calculates two midpoints between three Vector2's and lerps between those midpoints
	//
	// Parameters:
	//		a: Indicates the position of one of the Vector2's
	//		b: Indicates the position of one of the other Vector2's
	//		c: Indicates the position of the third Vector2
	//		t: Indicates a percentage between the two midpoints
	// Return:
	//		Returns a Vector2 which is the lerp between the two midpoints
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 QuadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t);

	//--------------------------------------------------------------------------------------
	// Calculates a curve between two control points
	//
	// Parameters:
	//		point0: Indicates one of the control points
	//		tangent0: Indicates the tangent of point0
	//		point1: Indicates the other control point
	//		tangent1: Indicates the tangent of point1
	// Return:
	//		Returns a Vector2 which is the hermite curve
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 HermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Following three functions define x and y as either both x, both y or one y and one x
	//
	// Return:
	//		All functions returns a Vector2 of the swizzle
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 xx();
	MATH_DLL Vector2 yx();
	MATH_DLL Vector2 yy();

	// Defines both x and y as a float
	float x;
	float y;
};
//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector2's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector2 used in the equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when multiplied.
//--------------------------------------------------------------------------------------
MATH_DLL Vector2 operator*(float lhs, const Vector2 rhs);

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector2's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector2 value used in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when divided.
//--------------------------------------------------------------------------------------
MATH_DLL Vector2 operator/(float lhs, const Vector2 rhs);