  /// <summary>
/// Vector 3 class
/// Kevin McCoy
/// </summary>
#include "MyVector3.h"
#include <string.h>
#define PI           3.14159265358979323846

/// <summary>
/// Defautl constructor set all 3 values to zero
/// </summary>
MyVector3::MyVector3() :
	x{ 0.0 },
	y{ 0.0 },
	z{ 0.0 }
{
}

MyVector3::MyVector3(double t_x, double t_y, double t_z) :
	x{ t_x },
	y{ t_y },
	z{ t_z }
{
}

MyVector3::MyVector3(sf::Vector3i t_sfVector):
	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) },
	z{ static_cast<double>(t_sfVector.z) }
{
}

MyVector3::MyVector3(sf::Vector3f t_sfVector):
	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) },
	z{ static_cast<double>(t_sfVector.z) }
{
}

MyVector3::MyVector3(sf::Vector2i t_sfVector):
	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) },
	z{ 0.0 }
{
}

MyVector3::MyVector3(sf::Vector2u t_sfVector) :
	x{ static_cast<double>(t_sfVector.x) },
	y{ static_cast<double>(t_sfVector.y) },
	z{ 0.0 }
{
}

/// <summary>
/// default destructor
/// nothing to release because we only have
/// primitive type data
/// </summary>
MyVector3::~MyVector3()
{
}

#pragma region methods

double MyVector3::lengthSquared() const
{
	const double result = ((x * x) + (y * y) + (z * z));
	return result;
}


MyVector3 MyVector3::unit() const
{
	double length = sqrt((x*x) + (y*y) + (z*z));

	return MyVector3(x / length, y / length, z / length);
}


void MyVector3::normalise()
{
	double length = sqrt((x * x) + (y * y) + (z * z));
	x = x / length;
	y = y / length;
	z = z / length;
}



double MyVector3::angleBetween(MyVector3 t_other) const
{
	double top = dot(t_other);
	double bottom = length() * t_other.length();
	double angleRadians;

	if (bottom != 0)
	{
		double answer = top / bottom;
		if (answer > 1) answer = 1;
		if (answer < -1) answer = -1;
		angleRadians = std::acos(answer);
		double angleBetween = acos(top / bottom) * 180 / PI;
		return angleBetween;
	}

	return 0.0;
}


double MyVector3::dot(MyVector3 t_other) const
{
	double const dotProduct = ((x * t_other.x) + (y * t_other.y) + (z * t_other.z));

	return dotProduct;
}

MyVector3 MyVector3::projection(const MyVector3 t_other) const
{
	double lenghtSq = lengthSquared();
	double dotProduct = dot(t_other);
	double scale{ 1.0 };
	if (lenghtSq != 0);
	{
		scale = dotProduct / lenghtSq;
	}

	return this->operator*(scale);
}

MyVector3 MyVector3::rejection(const MyVector3 t_other) const
{
	return MyVector3(t_other) - projection(t_other);
}

MyVector3 MyVector3::crossProduct(const MyVector3 t_other) const
{
	const double newX = y * t_other.z + z * t_other.y;
	const double newY = x * t_other.y + z * t_other.x;
	const double newZ = x * t_other.y + y * t_other.x;
	return MyVector3{ newX, newY, newZ };
}

/// <summary>
/// 
/// </summary>
/// <returns>the vector as a string surrounded by square brackets and seperated by commas</returns>
std::string MyVector3::toString()
{
	const std::string output = "[" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "]";
	return output;	
}

#pragma endregion
#pragma region operators


MyVector3 MyVector3::operator + (const MyVector3 t_right) const
{
	return MyVector3(x + t_right.x, y + t_right.y, z + t_right.z);
}



MyVector3 MyVector3::operator - (const MyVector3 t_right) const
{
	return MyVector3(x - t_right.x, y - t_right.y, z - t_right.z);
}


MyVector3 MyVector3::operator / (const double t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor , z / t_divisor);
}


MyVector3 MyVector3::operator / (const float t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}


MyVector3 MyVector3::operator / (const int t_divisor) const
{
	return MyVector3(x / t_divisor, y / t_divisor, z / t_divisor);
}


MyVector3 MyVector3::operator += (const MyVector3 t_right)
{
	x += t_right.x;
	y += t_right.y;
	z += t_right.z;
	return MyVector3(x, y, z);
}


MyVector3 MyVector3::operator -= (const MyVector3 t_right)
{
	x -= t_right.x;
	y -= t_right.y;
	z -= t_right.z;
	return MyVector3(x, y, z);
}

double MyVector3::length() const
{
	const double answer = std::sqrt(x * x + y * y + z * z);
	return answer;
}


MyVector3 MyVector3::operator-()
{
	return MyVector3(x * -1, y * -1, z * -1);
}


bool MyVector3::operator==(const MyVector3 t_right) const
{
	const bool answer{ x == t_right.x && y == t_right.y && z == t_right.z};
	return answer;
}


bool MyVector3::operator!=(const MyVector3 t_right) const
{
	const bool result{ x != t_right.x || y != t_right.y || z != t_right.z};
	return result;
}

MyVector3 MyVector3::operator * (const double t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}


MyVector3 MyVector3::operator * (const float t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}


MyVector3 MyVector3::operator * (const int t_scalar) const
{
	return MyVector3(x * t_scalar, y * t_scalar, z * t_scalar);
}

void MyVector3::reverseX()
{
	x = -x;
}

void MyVector3::reverseY()
{
	y = -y;
}

#pragma endregion


