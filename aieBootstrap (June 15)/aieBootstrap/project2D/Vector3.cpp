#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Vector3::Vector3()
{
	// Sets x, y and z to zero as default
	x = 0;
	y = 0;
	z = 0;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		x: Uses "this" keyword to define the x value of a Vector3
//		y: Uses "this" keyword to define the y value of a Vector3
//		z: Uses "this" keyword to define the z value of a Vector3
//--------------------------------------------------------------------------------------
Vector3::Vector3(float x, float y, float z)
{
	// Indicates "this" x, y and z in a Vector3
	this->x = x;
	this->y = y;
	this->z = z;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Vector3::~Vector3()
{
	// Empty as we don't need to delete anything
}

//--------------------------------------------------------------------------------------
// Overloads the double equals operator for use for Vector3's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector3 is equal to
//		the second Vector3.
//--------------------------------------------------------------------------------------
bool Vector3::operator==(const Vector3& rhs)
{
	// Return value used
	return (x == rhs.x && y == rhs.y && z == rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the not equals operator for use for Vector3's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector3 is not equal
//		to the second Vector3.
//--------------------------------------------------------------------------------------
bool Vector3::operator!=(const Vector3& rhs)
{
	// Return value used
	return (x != rhs.x && y != rhs.y && z != rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the plus symbol to add two Vector3's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when added.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator+(const Vector3& rhs)
{
	// Makes a new Vector3 where the result is stored
	Vector3 result;

	// Adds both Vector3's x's, y's and z's together
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the minus symbol to subtract two Vector3's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when subtracted.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-(const Vector3 & rhs)
{
	// Makes a new Vector3 where the result is stored
	Vector3 result;

	// Subtracts both Vector3's x's, y's and z's by the other
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector3's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when multiplied.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator*(const float rhs)
{
	// Makes a new Vector3 where the result is stored
	Vector3 result;

	// Multiplies both Vector3's x's, y's and z's together
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector3's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when divided.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator/(const float rhs)
{
	// Makes a new Vector3 where the result is stored
	Vector3 result;

	// Divides both Vector3's x's, y's and z's by the other
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the dot product of two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a float which is the answer to the equation
//--------------------------------------------------------------------------------------
float Vector3::Dot(Vector3 rhs)
{
	// Makes a new float where result is stored
	float result;

	// Calculates the dot product and stores in result variable
	result = x * rhs.x + y * rhs.y + z * rhs.z;

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the cross product of two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 which is the result to the equation
//--------------------------------------------------------------------------------------
Vector3 Vector3::Cross(Vector3 rhs)
{
	// Makes a new Vector3 where result is stored 
	Vector3 result;

	// Calculates the cross produvt and stores in result's x, y and z
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;

	// Returns the Vector3's result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the negative symbol of any value in a Vector3
//
// Return:
//		Returns a Vector3 to display a Vector2 with the negative symbol
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-()
{
	// Makes a new Vector3 where the result is stored
	Vector3 result;

	// Makes x, y and z as a negative value
	result.x = -x;
	result.y = -y;
	result.z = -z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector3
//
// Return:
//		Returns a float which is the result of the Vector3's magnitude
//--------------------------------------------------------------------------------------
float Vector3::Magnitude()
{
	// Makes a new float variable where result is stored
	float result;

	// Does calculation for magnitude and stores in the result
	result = sqrtf(x * x + y * y + z * z);

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector3 with answer being squared
//
// Return:
//		Returns a float which is the result of the Vector3's magnitude squared
//--------------------------------------------------------------------------------------
float Vector3::sqrMagnitude()
{
	// Makes a new float where the result is stored
	float result;

	// Does calculation without square root and stores in result variable
	result = x * x + y * y + z * z;

	// Returns the float result
	return result;
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector3 (received when called on)
//--------------------------------------------------------------------------------------
void Vector3::Normalise()
{
	// Gets the magnitude and stores in a float variable
	float mag = Magnitude();

	// Checks if denominator is not zero (as that breaks the compiler)
	if (mag != 0)
	{
		// Normalises the Vector3
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector3 (received via Parameters)
//
// Parameters:
//		data: Indicates the Vector3 being normalised
// Return:
//		Returns a Vector2 which is the normalised Vector3
//--------------------------------------------------------------------------------------
Vector3 Vector3::StaticNormalise(Vector3 data)
{
	// Makes a new variable where the result is stored
	Vector3 result;

	// Gets the magnitude and stores in a float variable
	float mag = data.Magnitude();

	// Checks if denominator is not zero (as that breaks the compiler)
	if (mag != 0)
	{
		// Normalises the Vector3
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;

		// Returns the Vector3 result
		return result;
	}
}

//--------------------------------------------------------------------------------------
// Overloads the plus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator+=(const Vector3 & rhs)
{
	// Does the plus-equals calculations on x, y and z
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;

	// Returns "this" Vector3 result of plus-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the minus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when added.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator-=(const Vector3 & rhs)
{
	// Does the minus-equals calculations on x, y and z
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;

	// Returns "this" Vector3 result of minus-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator*=(const Vector3 & rhs)
{
	// Does the multiply-equals calculations on x, y and z
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;

	// Returns "this" Vector3 of multiply-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the divide-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator/=(const Vector3 & rhs)
{
	// Does the divide-equals calculations on x, y and z
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;

	// Returns "this" Vector3 of divide-equals
	return *this;
}

//--------------------------------------------------------------------------------------
// Finds the minimum values in two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector3 to display the result of the minimum Vector3
//--------------------------------------------------------------------------------------
Vector3 Vector3::min(Vector3 rhs)
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Checks if left Vector's x is less than right's x
	if (x < rhs.x)
		// If so, result's x = left x
		result.x = x;
	else
		// Else, result's x = right x
		result.x = rhs.x;

	// Checks if left Vector's y is less than right's y
	if (y < rhs.y)
		// If so, result's y = left y
		result.y = y;
	else
		// Else, result's y = right y
		result.y = rhs.y;

	// Checks if left Vector's x is greater than right's x
	if (z < rhs.z)
		// If so, result's z = left z
		result.z = z;
	else
		// Else, result's z = right z
		result.z = rhs.z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the maximum values in two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector3 to display the result of the maximum Vector3
//--------------------------------------------------------------------------------------
Vector3 Vector3::max(Vector3 rhs)
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Checks if left Vector's x is greater than right's x
	if (x > rhs.x)
		// If so, result's x = left x
		result.x = x;
	else
		// Else, result's x = right x
		result.x = rhs.x;

	// Checks if left Vector's y is greater than right's y
	if (y > rhs.y)
		// If so, result's y = left y
		result.y = y;
	else
		// Else, result's y = right y
		result.y = rhs.y;

	// Checks if left Vector's z is greater than right's z
	if (z > rhs.z)
		// If so, result's z = left z
		result.z = z;
	else
		// Else, result's z = right z
		result.z = rhs.z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Limits the space between two Vectors
//
// Parameters:
//		max: Indicates the maximum vector
//      min: Indicates the minimum vector 
// Return:
//		Returns a Vector3 to display the minimum Vector3 (where clamping begins)
//--------------------------------------------------------------------------------------
Vector3 Vector3::clamp(Vector3 max, Vector3 min)
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Calculates the clamping and stores in result variable
	result = this->max(max);
	result = result.min(min);

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the greater than symbol to allow use for two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector3 is greater than
//		the other Vector3
//--------------------------------------------------------------------------------------
bool Vector3::operator>(const Vector3 & rhs)
{
	// Return value used
	return (x > rhs.x && y > rhs.y && z > rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the less than symbol to allow use for two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector3 is less than
//		the other Vector3
//--------------------------------------------------------------------------------------
bool Vector3::operator<(const Vector3 & rhs)
{
	// Return value used
	return (x < rhs.x && y < rhs.y && z < rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the greater than or equal to symbol to allow use for two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector3 is greater than
//		or equal to the other Vector3
//--------------------------------------------------------------------------------------
bool Vector3::operator>=(const Vector3 & rhs)
{
	// Return value used
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the less than or equal to symbol to allow use for two Vector3's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector3 is less than or
//		equal to the other Vector3
//--------------------------------------------------------------------------------------
bool Vector3::operator<=(const Vector3 & rhs)
{
	// Return value used
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z);
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Vector3
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector3
// Return:
//		Returns a float which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
float & Vector3::operator[](const int rhs)
{
	// Checks if rhs int is 0, 1, 2 or anything else
	if (rhs == 0)
		// If rhs is 0, returns x
		return x;
	else if (rhs == 1)
		// If rhs is 1, returns y
		return y;
	else if (rhs == 2)
		// If rhs is 2, returns z
		return z;
	else
		// Returns x if rhs is anything else
		return x;
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Vector3 values
//
// Return:
//		Returns the address of x
//--------------------------------------------------------------------------------------
Vector3::operator float*()
{
	// Return value is used
	return &x;
}

//--------------------------------------------------------------------------------------
// Calculates the normal of line between two Vector3's
//
// Parameters:
//		pos: Indicates the position of one of the Vector3's
// Return:
//		Returns a Vector3 which is the position of the normal
//--------------------------------------------------------------------------------------
Vector3 Vector3::CalcNorm(Vector3 pos)
{
	// Makes two new vectors for each end of the line
	Vector3 vec1;
	Vector3 vec2;

	// Calculates both positions of both ends of line
	vec1.x = pos.x - x;
	vec1.y = pos.y - y;
	vec1.z = pos.z - z;

	vec2.x = pos.x - x;
	vec2.y = pos.y - y;
	vec2.z = pos.z - z;

	// Calculates result via cross product call and stores result in local Vector3
	Vector3 res = vec1.Cross(vec2);

	// Calls normalise function to normalise result
	res.Normalise();

	// Returns the normalised Vector3 result
	return res;
}

//--------------------------------------------------------------------------------------
// Calculates the distance between two Vector3's
//
// Parameters:
//		pos1: Indicates the position of one of the Vector3's
//		pos2: Indicates the position of the other Vector3
// Return:
//		Returns the distance between the two Vector3's as a float
//--------------------------------------------------------------------------------------
float Vector3::CalcDist(Vector3 pos1, Vector3 pos2)
{
	// Distance equation is used and stored in local Vector3
	Vector3 dist = pos1 - pos2;

	// Returns the magnitude of the Vector3's distance
	return dist.Magnitude();
}

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
Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float t)
{
	// Returns the lerp equation
	return (a + b) * t;
}

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
Vector3 Vector3::QuadraticBezier(Vector3 a, Vector3 b, Vector3 c, float t)
{
	// Calculates both midpoints between both lines
	Vector3 mid1 = Lerp(a, b, t);
	Vector3 mid2 = Lerp(b, c, t);

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
//		Returns a Vector3 which is the hermite curve
//--------------------------------------------------------------------------------------
Vector3 Vector3::HermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t)
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
// Following 26 functions define x, y and z as either x, y or z
//
// Return:
//		All functions returns a Vector3 of the swizzle
//--------------------------------------------------------------------------------------
Vector3 Vector3::xxx()
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Defines results x, y and z all as old Vector3's x
	result.x = x;
	result.y = x;
	result.z = x;

	// Returns the Vector3's result
	return result;

	// Other 25 functions work in same way but with different values
}

Vector3 Vector3::yxx()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::yyx()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::yyy()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::xyx()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::xyy()
{
	Vector3 result;
	result.x = x;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::yxy()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::zxx()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::zzx()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = x;
	return result;
}

Vector3 Vector3::zzz()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = z;
	return result;
}

Vector3 Vector3::zxz()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::xxz()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::xzz()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = z;
	return result;
}

Vector3 Vector3::zyy()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::zzy()
{
	Vector3 result;
	result.x = z;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::zyz()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = z;
	return result;
}
Vector3 Vector3::yzy()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::yyz()
{
	Vector3 result;
	result.x = y;
	result.y = y;
	result.z = z;
	return result;
}

Vector3 Vector3::yzz()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = z;
	return result;
}

Vector3 Vector3::xzy()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::yxz()
{
	Vector3 result;
	result.x = y;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::yzx()
{
	Vector3 result;
	result.x = y;
	result.y = z;
	result.z = x;
	return result;
}

Vector3 Vector3::zyx()
{
	Vector3 result;
	result.x = z;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::zxy()
{
	Vector3 result;
	result.x = z;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::xxy()
{
	Vector3 result;
	result.x = x;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::xzx()
{
	Vector3 result;
	result.x = x;
	result.y = z;
	result.z = x;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector3's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector3 used in the equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when multiplied.
//--------------------------------------------------------------------------------------
Vector3 operator*(float lhs, const Vector3 rhs)
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Multiplies the left float by the Vector3's x, y and z
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	// Returns the Vector3 result
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector3's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector3 value used in equation
// Return:
//		Returns a Vector3 to display the result of the two Vector3's when divided.
//--------------------------------------------------------------------------------------
Vector3 operator/(float lhs, const Vector3 rhs)
{
	// Makes a new Vector3 where result is stored
	Vector3 result;

	// Divides the left float by the Vector3's x, y and z
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;

	// Returns the Vector3 result
	return result;
}