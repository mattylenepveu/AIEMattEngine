#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Vector2::Vector2()
{
	// Sets both x and y to 0 as default
	x = 0;
	y = 0;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		x: Uses "this" keyword to define the x value of a Vector2
//		y: Uses "this" keyword to define the y value of a Vector2
//--------------------------------------------------------------------------------------
Vector2::Vector2(float x, float y)
{
	// Indicates "this" x and y in a Vector2
	this->x = x;
	this->y = y;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Vector2::~Vector2()
{
	// Empty as we don't need to delete anything
}

//--------------------------------------------------------------------------------------
// Overloads the double equals operator for use for Vector2's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector2 is equal to
//		the second Vector2.
//--------------------------------------------------------------------------------------
bool Vector2::operator==(const Vector2 & rhs)
{
	// Return value used
	return (x == rhs.x && y == rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the not equals operator for use for Vector2's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector2 is not equal
//		to the second Vector2.
//--------------------------------------------------------------------------------------
bool Vector2::operator!=(const Vector2 & rhs)
{
	// Return value used
	return (x != rhs.x && y != rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the plus symbol to add two Vector2's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when added.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator+(const Vector2& rhs)
{
	// Makes a new Vector2 where the result is stored
	Vector2 result;

	// Adds both Vector2's x's and y's together
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the minus symbol to subtract two Vector2's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when subtracted.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-(const Vector2& rhs)
{
	// Makes a new Vector2 where the result is stored
	Vector2 result;

	// Subtracts both Vector2's x's and y's together
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector2's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when multiplied.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator*(const float rhs)
{
	// Makes a new Vector2 where the result is stored
	Vector2 result;

	// Multiplies both x and y by a float
	result.x = x * rhs;
	result.y = y * rhs;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector2's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when divided.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator/(const float rhs)
{
	// Makes a new Vector2 where the result is stored
	Vector2 result;

	// Divides both x and y by a float
	result.x = x / rhs;
	result.y = y / rhs;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the dot product of two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a float which is the answer to the equation
//--------------------------------------------------------------------------------------
float Vector2::Dot(Vector2 rhs)
{
	// Makes a new float where result will be stored
	float result;
	
	// Calculates the dot product
	result = x * rhs.x + y * rhs.y;

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the negative symbol of any value in a Vector2
//
// Return:
//		Returns a Vector2 to display a Vector2 with the negative symbol
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-()
{
	// Makes a new Vector2 where the result will be stored
	Vector2 result;

	// Makes both x and y in a Vector2 negative
	result.x = -x;
	result.y = -y;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector2
//
// Return:
//		Returns a float which is the result of the Vector2's magnitude
//--------------------------------------------------------------------------------------
float Vector2::Magnitude()
{
	// Makes a new float where the result will be stored
	float result;

	// Calculates the magnitude
	result = sqrtf(x * x + y * y);

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector2 with answer being squared
//
// Return:
//		Returns a float which is the result of the Vector2's magnitude squared
//--------------------------------------------------------------------------------------
float Vector2::sqrMagnitude()
{
	// Makes a new float where the result will be stored
	float result;

	// Calculates the result without the square root
	result = x * x + y * y;

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector2 (received when called on)
//--------------------------------------------------------------------------------------
void Vector2::Normalise()
{
	// Calls on magnitude function
	float mag = Magnitude();

	// Checks if denominator is not zero (as that breaks the compiler)
	if (mag != 0)
	{
		// Normalises the Vector2
		x = x / mag;
		y = y / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector2 (received via Parameters)
//
// Parameters:
//		data: Indicates the Vector2 being normalised
// Return:
//		Returns a Vector2 which is the normalised Vector2
//--------------------------------------------------------------------------------------
Vector2 Vector2::StaticNormalise(Vector2 data)
{
	// Makes a new Vector2 where the result will be stored
	Vector2 result;

	// Calls on magnitude function
	float mag = data.Magnitude();

	// Checks if denominator is not zero (as that breaks the compiler)
	if (mag != 0)
	{
		// Normalises the Vector2
		result.x = data.x / mag;
		result.y = data.y / mag;

		// Returns the normalised Vector2
		return result;
	}
}

//--------------------------------------------------------------------------------------
// Overloads the plus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator+=(const Vector2 & rhs)
{
	// Does the plus-equals calculations for both x and y
	x += rhs.x;
	y += rhs.y;

	// Returns "this" Vector2 result of plus-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the minus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when added.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator-=(const Vector2 & rhs)
{
	// Does the minus-equals calculations for both x and y
	x -= rhs.x;
	y -= rhs.y;

	// Returns "this" Vector2 result of minus-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator*=(const Vector2 & rhs)
{
	// Does the multiply-equals calculations for both x and y
	x *= rhs.x;
	y *= rhs.y;

	// Returns "this" Vector2 result of multiply-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the divide-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator/=(const Vector2 & rhs)
{
	// Does the divide-equals calculations for both x and y
	x /= rhs.x;
	y /= rhs.y;

	// Returns "this" Vector2 result of divide-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Finds the minimum values in two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector2 to display the result of the minimum Vector2
//--------------------------------------------------------------------------------------
Vector2 Vector2::min(Vector2 rhs)
{
	// Makes a new Vector2 to store result
	Vector2 result;

	// Checks if left Vector2's x  is less than the rights x
	if (x < rhs.x)
		// If so, make the min x get the left Vector2's x
		result.x = x;
	else
		// Else, make the min x get the right Vector2's x
		result.x = rhs.x;

	// Checks if left Vector2's y is less than the rights y
	if (y < rhs.y)
		// If so, make the min y get the left Vector2's y
		result.y = y;
	else
		// Else, make the min y get the right Vector2's y
		result.y = rhs.y;

	// Returns the Vector2 result with min x and y
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the maximum values in two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector2 to display the result of the maximum Vector2
//--------------------------------------------------------------------------------------
Vector2 Vector2::max(Vector2 rhs)
{
	// Makes a new Vector2 to store result
	Vector2 result;

	// Checks if left Vector2's x  is greater than the rights x
	if (x > rhs.x)
		// If so, make the max x get the left Vector2's x
		result.x = x;
	else
		// Else, make the max x get the right Vector2's x
		result.x = rhs.x;

	// Checks if left Vector2's y is less than the rights y
	if (y > rhs.y)
		// If so, make the max y get the left Vector2's y
		result.y = y;
	else
		// Else, make the max y get the right Vector2's y
		result.y = rhs.y;

	// Returns the Vector2 result with max x and y
	return result;
}

//--------------------------------------------------------------------------------------
// Limits the space between two Vectors
//
// Parameters:
//		max: Indicates the maximum vector
//      min: Indicates the minimum vector 
// Return:
//		Returns a Vector2 to display the minimum Vector2 (where clamping begins)
//--------------------------------------------------------------------------------------
Vector2 Vector2::clamp(Vector2 max, Vector2 min)
{
	Vector2 result;
	result = this->max(min);
	result = result.min(max);
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the greater than symbol to allow use for two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector2 is greater than
//		the other Vector2
//--------------------------------------------------------------------------------------
bool Vector2::operator>(const Vector2 & rhs)
{
	// Returns value used
	return (x > rhs.x && y > rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the less than symbol to allow use for two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector2 is less than
//		the other Vector2
//--------------------------------------------------------------------------------------
bool Vector2::operator<(const Vector2 & rhs)
{
	// Returns value used
	return (x < rhs.x && y < rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the greater than or equal to symbol to allow use for two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector2 is greater than
//		or equal to the other Vector2
//--------------------------------------------------------------------------------------
bool Vector2::operator>=(const Vector2 & rhs)
{
	// Returns value used
	return (x >= rhs.x && y >= rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the less than or equal to symbol to allow use for two Vector2's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector2 is less than or
//		equal to the other Vector2
//--------------------------------------------------------------------------------------
bool Vector2::operator<=(const Vector2 & rhs)
{
	// Returns value used
	return (x <= rhs.x && y <= rhs.y);
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Vector2
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector2
// Return:
//		Returns a float which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
float& Vector2::operator[](const int rhs)
{
	// Checks if the rhs int is 0 or 1 or anything else
	if (rhs == 0)
		// Returns x if rhs int is 0 
		return x;
	else if (rhs == 1)
		// Returns y if rhs int is 1 
		return y;
	else
		// Returns x if rhs is anything else
		return x;
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Vector2 values
//
// Return:
//		Returns the address of x
//--------------------------------------------------------------------------------------
Vector2::operator float*()
{
	// Return value used
	return &x;
}

//--------------------------------------------------------------------------------------
// Calculates the normal of line between two Vector2's
//
// Parameters:
//		pos: Indicates the position of one of the Vector2's
// Return:
//		Returns a Vector2 which is the position of the normal
//--------------------------------------------------------------------------------------
Vector2 Vector2::CalcNorm(Vector2 pos)
{
	// Makes two new Vector2's, one for the result and other for use in equations
	Vector2 vec;
	Vector2 res;

	// Calculates the distance then normalises it
	vec.x = pos.x - x;
	vec.y = pos.y - y;
	vec.Normalise();

	// Gets the result by making the y value a negative
	res.x = vec.y;
	res.y = -vec.x;

	// Returns the Vector2 result
	return res;
}

//--------------------------------------------------------------------------------------
// Calculates the distance between two Vector2's
//
// Parameters:
//		pos1: Indicates the position of one of the Vector2's
//		pos2: Indicates the position of the other Vector2
// Return:
//		Returns the distance between the two Vector2's as a float
//--------------------------------------------------------------------------------------
float Vector2::CalcDist(Vector2 pos1, Vector2 pos2)
{
	// Calculates distance and makes a new Vector2 to store it in
	Vector2 dist = pos1 - pos2;

	// Returns the magnitude of the distance
	return dist.Magnitude();
}

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
Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
{
	// Returns lerp equation
	return (a + b) * t;
}

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
Vector2 Vector2::QuadraticBezier(Vector2 a, Vector2 b, Vector2 c, float t)
{
	// Calculates both midpoints between both lines
	Vector2 mid1 = Lerp(a, b, t);
	Vector2 mid2 = Lerp(b, c, t);

	// Returns lerp between two midpoints
	return Lerp(mid1, mid2, t);
}

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
Vector2 Vector2::HermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t)
{
	// Makes two new float variables, one for t squared and other is t cubed
	float tsq = t * t;
	float tcub = tsq * t;

	// Makes four new float variables to store equations in
	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;
	
	// Returns the final equation to calculate Hermite Curve
	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//--------------------------------------------------------------------------------------
// Following three functions define x and y as either both x, both y or one y and one x
//
// Return:
//		All functions returns a Vector2 of the swizzle
//--------------------------------------------------------------------------------------
Vector2 Vector2::xx()
{
	// Makes a new Vector2 to store result in
	Vector2 result;

	// Defines the result x as x
	result.x = x;

	// Defines the result y as x
	result.y = x;

	// Returns the Vector2 result
	return result;

	// Other 2 functions work in same way but with different values
}

Vector2 Vector2::yx()
{
	Vector2 result;
	result.x = y;
	result.y = x;
	return result;
}

Vector2 Vector2::yy()
{
	Vector2 result;
	result.x = y;
	result.y = y;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector2's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector2 used in the equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when multiplied.
//--------------------------------------------------------------------------------------
Vector2 operator*(float lhs, const Vector2 rhs)
{
	// Makes a new Vector2 to store result in
	Vector2 result;

	// Multiplies the left float by the Vector2's x and y
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	// Returns the Vector2 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector2's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector2 value used in equation
// Return:
//		Returns a Vector2 to display the result of the two Vector2's when divided.
//--------------------------------------------------------------------------------------
Vector2 operator/(float lhs, const Vector2 rhs)
{
	// Makes a new Vector2 to store result in
	Vector2 result;

	// Divides the left float by the Vector2's x and y
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;

	// Returns the Vector2 result
	return result;
}