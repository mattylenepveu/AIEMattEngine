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
class Vector3
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3();

	//--------------------------------------------------------------------------------------
	// An additional Constructor.
	//
	// Parameters:
	//		x: Uses "this" keyword to define the x value of a Vector3
	//		y: Uses "this" keyword to define the y value of a Vector3
	//		z: Uses "this" keyword to define the z value of a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Default Destructor.
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector3();
	
	//--------------------------------------------------------------------------------------
	// Overloads the double equals operator for use for Vector3's.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in if statement
	// Return:
	//		Returns a boolean (either true or false) whether the first Vector3 is equal to
	//		the second Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator==(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the not equals operator for use for Vector3's.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in if statement
	// Return:
	//		Returns a boolean (either true or false) whether the first Vector3 is not equal
	//		to the second Vector3.
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator!=(const Vector3& rhs);
	
	//--------------------------------------------------------------------------------------
	// Overloads the plus symbol to add two Vector3's together.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's when added.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator+(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the minus symbol to subtract two Vector3's together.
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's when subtracted.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the multiply symbol to multiply two Vector3's together.
	//
	// Parameters:
	//		rhs: Indicates a float value used in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's when multiplied.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator*(const float rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the division symbol to divide two Vector3's together.
	//
	// Parameters:
	//		rhs: Indicates a float value used in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's when divided.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator/(const float rhs);
	
	//--------------------------------------------------------------------------------------
	// Finds the dot product of two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a float which is the answer to the equation
	//--------------------------------------------------------------------------------------
	MATH_DLL float Dot(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Finds the cross product of two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 which is the result to the equation
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Cross(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the negative symbol of any value in a Vector3
	//
	// Return:
	//		Returns a Vector3 to display a Vector2 with the negative symbol
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-();
	
	//--------------------------------------------------------------------------------------
	// Finds the magnitude of a Vector3
	//
	// Return:
	//		Returns a float which is the result of the Vector3's magnitude
	//--------------------------------------------------------------------------------------
	MATH_DLL float Magnitude();

	//--------------------------------------------------------------------------------------
	// Finds the magnitude of a Vector3 with answer being squared
	//
	// Return:
	//		Returns a float which is the result of the Vector3's magnitude squared
	//--------------------------------------------------------------------------------------
	MATH_DLL float sqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises the magnitude of a Vector3 (received when called on)
	//--------------------------------------------------------------------------------------
	MATH_DLL void Normalise();

	//--------------------------------------------------------------------------------------
	// Normalises the magnitude of a Vector3 (received via Parameters)
	//
	// Parameters:
	//		data: Indicates the Vector3 being normalised
	// Return:
	//		Returns a Vector2 which is the normalised Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL static Vector3 StaticNormalise(Vector3 data);
	
	//--------------------------------------------------------------------------------------
	// Overloads the plus-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator+=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the minus-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's when added.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator-=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the multiply-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator*=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the divide-equals symbol
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in equation
	// Return:
	//		Returns a Vector3 to display the result of the two Vector3's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator/=(const Vector3& rhs);
	
	//--------------------------------------------------------------------------------------
	// Finds the minimum values in two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a Vector3 to display the result of the minimum Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 min(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Finds the maximum values in two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a Vector3 to display the result of the maximum Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 max(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Limits the space between two Vectors
	//
	// Parameters:
	//		max: Indicates the maximum vector
	//      min: Indicates the minimum vector 
	// Return:
	//		Returns a Vector3 to display the minimum Vector3 (where clamping begins)
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 clamp(Vector3 max, Vector3 min);
	
	//--------------------------------------------------------------------------------------
	// Overloads the greater than symbol to allow use for two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector3 is greater than
	//		the other Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the less than symbol to allow use for two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector3 is less than
	//		the other Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the greater than or equal to symbol to allow use for two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector3 is greater than
	//		or equal to the other Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator>=(const Vector3& rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the less than or equal to symbol to allow use for two Vector3's
	//
	// Parameters:
	//		rhs: Indicates the second of two Vectors for use in function
	// Return:
	//		Returns a boolean (either true or false) to display if a Vector3 is less than or
	//		equal to the other Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator<=(const Vector3& rhs);
	
	//--------------------------------------------------------------------------------------
	// Overloads the sub-script operator to allow use for a Vector3
	//
	// Parameters:
	//		rhs: Indicates one of the intergers in a Vector3
	// Return:
	//		Returns a float which will be the value in the sub-script operator
	//--------------------------------------------------------------------------------------
	MATH_DLL float& operator[](const int rhs);

	//--------------------------------------------------------------------------------------
	// Overloads the cast operator to allow use for Vector3 values
	//
	// Return:
	//		Returns the address of x
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();
	
	//--------------------------------------------------------------------------------------
	// Calculates the normal of line between two Vector3's
	//
	// Parameters:
	//		pos: Indicates the position of one of the Vector3's
	// Return:
	//		Returns a Vector3 which is the position of the normal
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 CalcNorm(Vector3 pos);


	//--------------------------------------------------------------------------------------
	// Calculates the distance between two Vector3's
	//
	// Parameters:
	//		pos1: Indicates the position of one of the Vector3's
	//		pos2: Indicates the position of the other Vector3
	// Return:
	//		Returns the distance between the two Vector3's as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float CalcDist(Vector3 pos1, Vector3 pos2);
	
	//--------------------------------------------------------------------------------------
	// Calculates any position between two Vector3's
	//
	// Parameters:
	//		a: Indicates the position of one of the Vector3's
	//		b: Indicates the position of the other Vector3
	//		t: Indicates a percentage between the two Vector3's
	// Return:
	//		Returns a Vector3 which is a position between the two Vector3's
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Lerp(Vector3 a, Vector3 b, float t);

	//--------------------------------------------------------------------------------------
	// Calculates two midpoints between three Vector3's and lerps between those midpoints
	//
	// Parameters:
	//		a: Indicates the position of one of the Vector3's
	//		b: Indicates the position of one of the other Vector3's
	//		c: Indicates the position of the third Vector3
	//		t: Indicates a percentage between the two midpoints
	// Return:
	//		Returns a Vector3 which is the lerp between the two midpoints
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 QuadraticBezier(Vector3 a, Vector3 b, Vector3 c, float t);

	//--------------------------------------------------------------------------------------
	// Calculates a curve between two control points
	//
	// Parameters:
	//		point0: Indicates one of the control points
	//		tangent0: Indicates the tangent of point0
	//		point1: Indicates the other control point
	//		tangent1: Indicates the tangent of point1
	// Return:
	//		Returns a Vector3 which is the hermite curve
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 HermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t);

	//--------------------------------------------------------------------------------------
	// Following 27 functions define x, y and z as either x, y or z
	//
	// Return:
	//		All functions returns a Vector3 of the swizzle
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 xxx();
	MATH_DLL Vector3 yxx();
	MATH_DLL Vector3 yyx();
	MATH_DLL Vector3 yyy();
	MATH_DLL Vector3 xyx();
	MATH_DLL Vector3 xyy();
	MATH_DLL Vector3 yxy();
	MATH_DLL Vector3 zxx();
	MATH_DLL Vector3 zzx();
	MATH_DLL Vector3 zzz();
	MATH_DLL Vector3 zxz();
	MATH_DLL Vector3 xxz();
	MATH_DLL Vector3 xzz();
	MATH_DLL Vector3 zyy();
	MATH_DLL Vector3 zzy();
	MATH_DLL Vector3 zyz();
	MATH_DLL Vector3 yzy();
	MATH_DLL Vector3 yyz();
	MATH_DLL Vector3 yzz();
	MATH_DLL Vector3 xzy();
	MATH_DLL Vector3 yxz();
	MATH_DLL Vector3 yzx();
	MATH_DLL Vector3 zyx();
	MATH_DLL Vector3 zxy();
	MATH_DLL Vector3 xxy();
	MATH_DLL Vector3 xzx();

	// Defines x, y and z as floats
	float x;
	float y;
	float z;
};
//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector3's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector3 used in the equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when multiplied.
//--------------------------------------------------------------------------------------
MATH_DLL Vector3 operator*(float lhs, const Vector3 rhs);

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector3's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector3 value used in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when divided.
//--------------------------------------------------------------------------------------
MATH_DLL Vector3 operator/(float lhs, const Vector3 rhs);