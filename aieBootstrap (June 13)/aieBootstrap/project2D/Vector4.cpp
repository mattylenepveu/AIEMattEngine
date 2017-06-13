#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include <math.h>

//--------------------------------------------------------------------------------------
// Default Constructor.
//--------------------------------------------------------------------------------------
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

//--------------------------------------------------------------------------------------
// An additional Constructor.
//
// Parameters:
//		x: Uses "this" keyword to define the x value of a Vector4
//		y: Uses "this" keyword to define the y value of a Vector4
//		z: Uses "this" keyword to define the z value of a Vector4
//		w: Uses "this" keyword to define the z value of a Vector4
//--------------------------------------------------------------------------------------
Vector4::Vector4(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

//--------------------------------------------------------------------------------------
// Default Destructor.
//--------------------------------------------------------------------------------------
Vector4::~Vector4()
{
	// Emptry as nothing needs to be deleted
}

//--------------------------------------------------------------------------------------
// Overloads the double equals operator for use for Vector4's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector4 is equal to
//		the second Vector4.
//--------------------------------------------------------------------------------------
bool Vector4::operator==(const Vector4 & rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the not equals operator for use for Vector4's.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in if statement
// Return:
//		Returns a boolean (either true or false) whether the first Vector4 is not equal
//		to the second Vector4.
//--------------------------------------------------------------------------------------
bool Vector4::operator!=(const Vector4 & rhs)
{
	return (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the plus symbol to add two Vector4's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when added.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator+(const Vector4& rhs)
{
	Vector4 result;
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the minus symbol to subtract two Vector4's together.
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when subtracted.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-(const Vector4 & rhs)
{
	Vector4 result;
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector4's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when multiplied.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator*(const float rhs)
{
	Vector4 result;
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector4's together.
//
// Parameters:
//		rhs: Indicates a float value used in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when divided.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator/(const float rhs)
{
	Vector4 result;
	result.x = x / rhs;
	result.y = y / rhs;
	result.z = z / rhs;
	result.w = w / rhs;
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the dot product of two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a float which is the answer to the equation
//--------------------------------------------------------------------------------------
float Vector4::Dot(Vector4 rhs)
{
	float result;
	result = x * rhs.x + y * rhs.y + z * rhs.z + w * rhs.w;
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the cross product of two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 which is the result to the equation
//--------------------------------------------------------------------------------------
Vector4 Vector4::Cross(Vector4 rhs)
{
	Vector4 result;
	result.x = y * rhs.z - z * rhs.y;
	result.y = z * rhs.x - x * rhs.z;
	result.z = x * rhs.y - y * rhs.x;
	result.w = 0;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the negative symbol of any value in a Vector4
//
// Return:
//		Returns a Vector4 to display a Vector2 with the negative symbol
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-()
{
	Vector4 result;
	result.x = -x;
	result.y = -y;
	result.z = -z;
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector4
//
// Return:
//		Returns a float which is the result of the Vector4's magnitude
//--------------------------------------------------------------------------------------
float Vector4::Magnitude()
{
	float result;
	result = sqrtf(x * x + y * y + z * z);
	return result;
}

//--------------------------------------------------------------------------------------
// Finds the magnitude of a Vector4 with answer being squared
//
// Return:
//		Returns a float which is the result of the Vector4's magnitude squared
//--------------------------------------------------------------------------------------
float Vector4::sqrMagnitude()
{
	float result;
	result = x * x + y * y + z * z;
	return result;
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector4 (received when called on)
//--------------------------------------------------------------------------------------
void Vector4::Normalise()
{
	float mag = Magnitude();
	if (mag != 0)
	{
		x = x / mag;
		y = y / mag;
		z = z / mag;
	}
}

//--------------------------------------------------------------------------------------
// Normalises the magnitude of a Vector4 (received via Parameters)
//
// Parameters:
//		data: Indicates the Vector4 being normalised
// Return:
//		Returns a Vector4 which is the normalised Vector4
//--------------------------------------------------------------------------------------
Vector4 Vector4::StaticNormalise(Vector4 data)
{
	Vector4 result;
	float mag = data.Magnitude();
	if (mag != 0)
	{
		result.x = data.x / mag;
		result.y = data.y / mag;
		result.z = data.z / mag;
		return result;
	}
}

//--------------------------------------------------------------------------------------
// Overloads the plus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator+=(const Vector4 & rhs)
{
	x += rhs.x;
	y += rhs.y;
	z += rhs.z;
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the minus-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when added.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator-=(const Vector4 & rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	z -= rhs.z;
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator*=(const Vector4 & rhs)
{
	x *= rhs.x;
	y *= rhs.y;
	z *= rhs.z;
	return *this;
}

//--------------------------------------------------------------------------------------
// Overloads the divide-equals symbol
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator/=(const Vector4 & rhs)
{
	x /= rhs.x;
	y /= rhs.y;
	z /= rhs.z;
	return *this;
}

//--------------------------------------------------------------------------------------
// Finds the minimum values in two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector4 to display the result of the minimum Vector4
//--------------------------------------------------------------------------------------
Vector4 Vector4::min(Vector4 rhs)
{
	Vector4 result;
	if (x < rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z < rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	if (w < rhs.w)
		result.w = w;
	else
		result.w = rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Finds the maximum values in two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a Vector4 to display the result of the maximum Vector4
//--------------------------------------------------------------------------------------
Vector4 Vector4::max(Vector4 rhs)
{
	Vector4 result;
	if (x > rhs.x)
		result.x = x;
	else
		result.x = rhs.x;

	if (y > rhs.y)
		result.y = y;
	else
		result.y = rhs.y;

	if (z > rhs.z)
		result.z = z;
	else
		result.z = rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Limits the space between two Vectors
//
// Parameters:
//		max: Indicates the maximum vector
//      min: Indicates the minimum vector 
// Return:
//		Returns a Vector4 to display the minimum Vector4 (where clamping begins)
//--------------------------------------------------------------------------------------
Vector4 Vector4::clamp(Vector4 max, Vector4 min)
{
	Vector4 result;
	result = this->max(max);
	result = result.min(min);
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the greater than symbol to allow use for two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector4 is greater than
//		the other Vector4
//--------------------------------------------------------------------------------------
bool Vector4::operator>(const Vector4 & rhs)
{
	return (x > rhs.x && y > rhs.y && z > rhs.z && w > rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the less than symbol to allow use for two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector4 is less than
//		the other Vector4
//--------------------------------------------------------------------------------------
bool Vector4::operator<(const Vector4 & rhs)
{
	return (x < rhs.x && y < rhs.y && z < rhs.z && w < rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the greater than or equal to symbol to allow use for two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector4 is greater than
//		or equal to the other Vector4
//--------------------------------------------------------------------------------------
bool Vector4::operator>=(const Vector4 & rhs)
{
	return (x >= rhs.x && y >= rhs.y && z >= rhs.z && w >= rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the less than or equal to symbol to allow use for two Vector4's
//
// Parameters:
//		rhs: Indicates the second of two Vectors for use in function
// Return:
//		Returns a boolean (either true or false) to display if a Vector4 is less than or
//		equal to the other Vector4
//--------------------------------------------------------------------------------------
bool Vector4::operator<=(const Vector4 & rhs)
{
	return (x <= rhs.x && y <= rhs.y && z <= rhs.z && w <= rhs.w);
}

//--------------------------------------------------------------------------------------
// Overloads the sub-script operator to allow use for a Vector4
//
// Parameters:
//		rhs: Indicates one of the intergers in a Vector4
// Return:
//		Returns a float which will be the value in the sub-script operator
//--------------------------------------------------------------------------------------
float & Vector4::operator[](const int rhs)
{
	if (rhs == 0)
		return x;
	else if (rhs == 1)
		return y;
	else if (rhs == 2)
		return z;
	else if (rhs == 3)
		return w;
	else
		return x;
}

//--------------------------------------------------------------------------------------
// Overloads the cast operator to allow use for Vector4 values
//
// Return:
//		Returns the address of x
//--------------------------------------------------------------------------------------
Vector4::operator float*()
{
	return &x;
}

//--------------------------------------------------------------------------------------
// Calculates the normal of line between two Vector4's
//
// Parameters:
//		pos: Indicates the position of one of the Vector4's
// Return:
//		Returns a Vector4 which is the position of the normal
//--------------------------------------------------------------------------------------
Vector4 Vector4::CalcNorm(Vector4 pos)
{
	Vector4 vec1;
	Vector4 vec2;

	vec1.x = pos.x - x;
	vec1.y = pos.y - y;
	vec1.z = pos.z - z;

	vec2.x = pos.x - x;
	vec2.y = pos.y - y;
	vec2.z = pos.z - z;

	Vector4 res = vec1.Cross(vec2);
	res.Normalise();
	return res;
}

//--------------------------------------------------------------------------------------
// Calculates the distance between two Vector4's
//
// Parameters:
//		pos1: Indicates the position of one of the Vector4's
//		pos2: Indicates the position of the other Vector4
// Return:
//		Returns the distance between the two Vector4's as a float
//--------------------------------------------------------------------------------------
float Vector4::CalcDist(Vector4 pos1, Vector4 pos2)
{
	Vector4 dist = pos1 - pos2;
	return dist.Magnitude();
}

//--------------------------------------------------------------------------------------
// Calculates any position between two Vector4's
//
// Parameters:
//		a: Indicates the position of one of the Vector4's
//		b: Indicates the position of the other Vector4
//		t: Indicates a percentage between the two Vector4's
// Return:
//		Returns a Vector4 which is a position between the two Vector4's
//--------------------------------------------------------------------------------------
Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float t)
{
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Calculates two midpoints between three Vector4's and lerps between those midpoints
//
// Parameters:
//		a: Indicates the position of one of the Vector4's
//		b: Indicates the position of one of the other Vector4's
//		c: Indicates the position of the third Vector4
//		t: Indicates a percentage between the two midpoints
// Return:
//		Returns a Vector4 which is the lerp between the two midpoints
//--------------------------------------------------------------------------------------
Vector4 Vector4::QuadraticBezier(Vector4 a, Vector4 b, Vector4 c, float t)
{
	Vector4 mid1 = Lerp(a, b, t);
	Vector4 mid2 = Lerp(b, c, t);

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
//		Returns a Vector4 which is the hermite curve
//--------------------------------------------------------------------------------------
Vector4 Vector4::HermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t)
{
	float tsq = t * t;
	float tcub = tsq * t;

	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//--------------------------------------------------------------------------------------
// Following 255 functions define x, y, z and w as either x, y, z or w
//
// Return:
//		All functions returns a Vector4 of the swizzle
//--------------------------------------------------------------------------------------
Vector4 Vector4::wwww()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wwwx()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wwwy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wwwz()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wwxw()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wwxx() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wwxy()
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wwxz() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wwyw() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wwyx() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wwyy() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wwyz() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wwzw() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wwzx() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wwzy() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wwzz() 
{
	Vector4 result;
	result.x = w;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wxww() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wxwx()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wxwy() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wxwz() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wxxw()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wxxx() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wxxy() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wxxz() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wxyw() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wxyx() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wxyy() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wxyz() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wxzw()
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wxzx() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wxzy() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wxzz() 
{
	Vector4 result;
	result.x = w;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wyww() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wywx() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wywy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wywz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wyxw() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wyxx() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wyxy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wyxz() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wyyw() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wyyx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wyyy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wyyz()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wyzw()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wyzx()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wyzy()
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wyzz() 
{
	Vector4 result;
	result.x = w;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wzww() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wzwx()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wzwy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wzwz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wzxw()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wzxx() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wzxy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wzxz()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wzyw() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wzyx() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wzyy()
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wzyz() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wzzw() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wzzx() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wzzy() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wzzz() 
{
	Vector4 result;
	result.x = w;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xwww() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xwwx() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xwwy() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xwwz() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xwxw() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xwxx() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xwxy() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xwxz()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xwyw() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xwyx()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xwyy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xwyz() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xwzw()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xwzx() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xwzy()
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xwzz() 
{
	Vector4 result;
	result.x = x;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xxww()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xxwx()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xxwy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xxwz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xxxw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xxxx() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xxxy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xxxz() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xxyw() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xxyx() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xxyy() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xxyz() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xxzw()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xxzx() 
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xxzy()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xxzz()
{
	Vector4 result;
	result.x = x;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xyww()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xywx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xywy()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xywz() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xyxw()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xyxx() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xyxy() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xyxz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xyyw() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xyyx() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xyyy() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xyyz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xyzx()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xyzy() 
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xyzz()
{
	Vector4 result;
	result.x = x;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xzww()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xzwx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xzwy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xzwz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xzxw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xzxx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xzxy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xzxz()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xzyw()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xzyx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xzyy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xzyz() 
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xzzw() 
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xzzx()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xzzy()
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xzzz() 
{
	Vector4 result;
	result.x = x;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::ywww() 
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::ywwx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::ywwy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::ywwz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::ywxw() 
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::ywxx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::ywxy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::ywxz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::ywyw() 
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::ywyx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::ywyy()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::ywyz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::ywzw() 
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::ywzx()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::ywzy() 
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::ywzz()
{
	Vector4 result;
	result.x = y;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yxww()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yxwx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yxwy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yxwz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yxxw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yxxx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yxxy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::yxxz() 
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yxyw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yxyx() 
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yxyy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yxyz()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yxzw()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yxzx()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yxzy()
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yxzz() 
{
	Vector4 result;
	result.x = y;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yyww() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yywx() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yywy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yywz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yyxw() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yyxx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yyxy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::yyxz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yyyw() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yyyx() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yyyy()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yyyz()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yyzw()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yyzx()
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yyzy() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yyzz() 
{
	Vector4 result;
	result.x = y;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yzww()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yzwx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yzwy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yzwz() 
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yzxw() 
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yzxx() 
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yzxy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yzxz() 
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yzyw()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yzyx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yzyy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yzyz()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yzzw()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yzzx()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yzzy()
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yzzz() 
{
	Vector4 result;
	result.x = y;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zwww() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zwwx() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zwwy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zwwz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;	
}

Vector4 Vector4::zwxw() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zwxx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zwxy() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zwxz() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zwyw() 
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zwyx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zwyy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zwyz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zwzw()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zwzx()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zwzy()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zwzz()
{
	Vector4 result;
	result.x = z;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zxww()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zxwx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zxwy() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zxwz() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zxxw() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zxxx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zxxy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zxxz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zxyw()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zxyx() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zxyy()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zxyz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zxzw() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zxzx()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zxzy() 
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zxzz()
{
	Vector4 result;
	result.x = z;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zyww() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zywx() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zywy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zywz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zyxw()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zyxx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zyxy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zyxz()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zyyw()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zyyx()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zyyy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zyyz() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zyzw() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zyzx() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zyzy()
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zyzz() 
{
	Vector4 result;
	result.x = z;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zzww()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zzwx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zzwy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zzwz() 
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zzxw()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zzxx() 
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zzxy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zzxz()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zzyw()
{	
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zzyx() 
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zzyy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zzyz()
{	
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zzzw() 
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zzzx()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zzzy()
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zzzz() 
{
	Vector4 result;
	result.x = z;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the multiply symbol to multiply two Vector4's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector4 used in the equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when multiplied.
//--------------------------------------------------------------------------------------
Vector4 operator*(float lhs, const Vector4 rhs)
{
	Vector4 result;
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = 0;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloads the division symbol to divide two Vector4's together.
//
// Parameters:
//		lhs: Indicates the float value used in equation
//		rhs: Indicates a Vector4 value used in equation
// Return:
//		Returns a Vector4 to display the result of the two Vector4's when divided.
//--------------------------------------------------------------------------------------
Vector4 operator/(float lhs, const Vector4 rhs)
{
	Vector4 result;
	result.x = lhs / rhs.x;
	result.y = lhs / rhs.y;
	result.z = lhs / rhs.z;
	result.w = 0;
	return result;
}