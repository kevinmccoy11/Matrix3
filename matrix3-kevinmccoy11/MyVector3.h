#ifndef MYVECTOR3 
#define MYVECTOR3


/// <summary>
/// Kevin McCoy
/// 

#include <iostream>
#include <SFML/Graphics.hpp>


class MyVector3
{
public:
	double x;
	double y;
	double z;

	MyVector3();
	MyVector3(double t_x, double t_y, double t_z);
	MyVector3(sf::Vector3i t_vector);
	MyVector3(sf::Vector3f t_vector);
	MyVector3(sf::Vector2i t_sfVector);
	MyVector3(sf::Vector2u t_vector);
	~MyVector3();
	
	double lengthSquared() const;
	
	MyVector3 unit() const;
	
	void normalise();
	
	double angleBetween(MyVector3 t_other) const;
	
	double dot(MyVector3 t_other) const;
	
	MyVector3 projection(const MyVector3 t_other) const;
	
	MyVector3 rejection(const MyVector3 t_other) const;

	MyVector3 crossProduct(const MyVector3 t_other) const;
	
	std::string toString();

	MyVector3 operator+(const MyVector3 t_right) const;

	MyVector3 operator-(const MyVector3 t_right) const;

	MyVector3 operator/(const double t_divisor) const;

	MyVector3 operator/(const float t_divisor) const;

	MyVector3 operator/(const int t_divisor) const;

	MyVector3 operator+=(const MyVector3 t_right);

	MyVector3 operator-=(const MyVector3 t_right);

	double length() const;

	MyVector3 operator-();

	bool operator==(const MyVector3 t_right) const;

	bool operator!=(const MyVector3 t_right) const;

	MyVector3 operator*(const double t_scalar) const;

	MyVector3 operator*(const float t_scalar) const;

	MyVector3 operator*(const int t_scalar) const;

	void reverseX();

	void reverseY();


	//MyVector3(double x, double y, double z);
	//MyVector3(sf::Vector3f t_sfVector);
	//MyVector3(sf::Vector3i t_sfVector);
	//MyVector3(sf::Vector2i t_sfVector);
	//MyVector3(sf::Vector2u t_sfVector);
	//MyVector3(sf::Vector2f t_sfVector); 
	
	//bool operator == (const MyVector3 t_right) const;
	//bool operator != (const MyVector3 t_right) const;


	//MyVector3 operator +(const MyVector3 t_right) const;
	//MyVector3 operator -(const MyVector3 t_right) const;
	//MyVector3 operator *(const double t_scalar) const;
	//MyVector3 operator /(const double t_divisor) const;
	//MyVector3 operator +=(const MyVector3 t_right);
	//MyVector3 operator -=(const MyVector3 t_right);

	
	// negative of a vector 
	//MyVector3 operator -();
	

	//double length()const;
	//double lengthSquared()const;
	//double dot(const MyVector3 t_other) const;
	//MyVector3 crossProduct(const MyVector3 t_other)const;
	//double angleBetween(const MyVector3 t_other)const;
	//MyVector3 unit() const;
	//void normalise();
	//MyVector3 projection(const MyVector3 t_other)const;
	// projection of other onto the current vector so answer will parralell to current vector.
	//MyVector3 rejection(const MyVector3 t_other)const;


	operator sf::Vector2f() { return sf::Vector2f{ static_cast<float>(x), static_cast<float>(y) }; };
	//operator sf::Vector2i() { return sf::Vector2i{ }; };	
	//operator sf::Vector2u() { return sf::Vector2u{ }; };
	//operator sf::Vector3i() { return sf::Vector3i{ }; };
	//operator sf::Vector3f() { return sf::Vector3f{ }; };
	
};



#endif // !MYVECTOR3