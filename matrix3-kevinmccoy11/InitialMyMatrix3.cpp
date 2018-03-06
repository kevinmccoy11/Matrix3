/// <summary>
/// Matrix 3 class
/// Kevin McCoy
/// </summary>
#include "InitialMyMatrix3.h"
#include <string.h>
#define PI           3.14159265358979323846

MyMatrix3::MyMatrix3() :
	a11{ 0.0 },
	a12{ 0.0 },
	a13{ 0.0 },
	a21{ 0.0 },
	a22{ 0.0 },
	a23{ 0.0 },
	a31{ 0.0 },
	a32{ 0.0 },
	a33{ 0.0 }
{
}

MyMatrix3::MyMatrix3(double t_a11, double t_a12, double t_a13, double t_a21, double t_a22, double t_a23, double t_a31, double t_a32, double t_a33) :
	a11{ t_a11 },
	a12{ t_a12 },
	a13{ t_a13 },
	a21{ t_a21 },
	a22{ t_a22 },
	a23{ t_a23 },
	a31{ t_a31 },
	a32{ t_a32 },
	a33{ t_a33 }
{
}

MyMatrix3::MyMatrix3(MyVector3 t_row1, MyVector3 t_row2, MyVector3 t_row3)
{
	t_row1 = { a11,a12,a13 };
	t_row2 = { a21,a22,a23 };
	t_row3 = { a31,a32,a33 };
}

MyMatrix3::~MyMatrix3()
{
}

std::string MyMatrix3::toString() const
{
	const std::string output1 = "(" + std::to_string(a11) + "," + std::to_string(a12) + "," + std::to_string(a13) + ";";
	const std::string output2= std::to_string(a21) + "," + std::to_string(a22) + "," + std::to_string(a23) + ";";
	const std::string output3 = std::to_string(a31) + "," + std::to_string(a32) + "," + std::to_string(a33) + ")";

	const std::string outputFinal = output1 + output2 + output3;
	return outputFinal;
}

bool MyMatrix3::operator==(const MyMatrix3 t_other) const
{
	const bool answer{ a11 == t_other.a11 && a12 == t_other.a12 && a13 == t_other.a13 &&
					   a21 == t_other.a21 && a22 == t_other.a22 && a23 == t_other.a23 &&
					   a31 == t_other.a31 && a32 == t_other.a32 && a33 == t_other.a33 };
	return answer;
}

bool MyMatrix3::operator!=(const MyMatrix3 t_other) const
{
	const bool answer{ a11 != t_other.a11 || a12 != t_other.a12 || a13 != t_other.a13 ||
					   a21 != t_other.a21 || a22 != t_other.a22 || a23 != t_other.a23 ||
					   a31 != t_other.a31 || a32 != t_other.a32 || a33 != t_other.a33 };
	return answer;
}

MyMatrix3 MyMatrix3::operator+(const MyMatrix3 t_other) const
{
	return MyMatrix3(a11 + t_other.a11, a12 + t_other.a12, a13 + t_other.a13, 
					 a21 + t_other.a21, a22 + t_other.a22, a23 + t_other.a23,
					 a31 + t_other.a31, a32 + t_other.a32, a33 + t_other.a33);
}

MyMatrix3 MyMatrix3::operator-(const MyMatrix3 t_other) const
{
	return MyMatrix3(a11 - t_other.a11, a12 - t_other.a12, a13 - t_other.a13,
					 a21 - t_other.a21, a22 - t_other.a22, a23 - t_other.a23,
					 a31 - t_other.a31, a32 - t_other.a32, a33 - t_other.a33);
}

MyMatrix3 MyMatrix3::operator*(const MyMatrix3 t_other) const
{
	return MyMatrix3(a11 * t_other.a11 + a12 * t_other.a21 + a13 * t_other.a31, a11 * t_other.a12 + a12 * t_other.a22 + a13 * t_other.a32, a11 * t_other.a13 + a12 * t_other.a23 + a13 * t_other.a33,
					 a21 * t_other.a11 + a22 * t_other.a22 + a23 * t_other.a32, a21 * t_other.a12 + a22 * t_other.a22 + a23 * t_other.a32, a21 * t_other.a13 + a22 * t_other.a23 + a23 * t_other.a33,
					 a31 * t_other.a13 + a32 * t_other.a23 + a33 * t_other.a33, a31 * t_other.a12 + a32 * t_other.a22 + a33 * t_other.a32, a31 * t_other.a13 + a32 * t_other.a23 + a33 * t_other.a33);
}

MyVector3 MyMatrix3::operator*(const MyVector3 t_vector) const
{
	return MyVector3(a11 * t_vector.x + a12 * t_vector.y + a13 * t_vector.z,
					 a21 * t_vector.x + a22 * t_vector.y + a23 * t_vector.z,
					 a31 * t_vector.x + a32 * t_vector.y + a33 * t_vector.z);
}

MyMatrix3 MyMatrix3::operator*(const double t_scale) const
{
	return MyMatrix3(a11 * t_scale, a12 * t_scale, a13 * t_scale,
					 a21 * t_scale, a22 * t_scale, a23 * t_scale,
					 a31 * t_scale, a32 * t_scale, a33 * t_scale);
}

MyMatrix3 MyMatrix3::transpose() const
{
	return MyMatrix3(a11, a21, a31,
					 a12, a22, a32,
					 a13, a23, a33);
}

double MyMatrix3::determinant() const
{
	double det1 = a11 * ((a22 * a33) - (a32 * a23));
	double det2 = a21 * ((a33 * a12) - (a32 * a13));
	double det3 = a31 * ((a23 * a12) - (a22 * a13));

	double determinant = det1 - det2 + det3;

	return determinant;
}

MyMatrix3 MyMatrix3::inverse(MyMatrix3 &t_matrix) const
{
	MyMatrix3 newMatrix{ ((a33 * a22) - (a32 * a23)), ((a32 * a13) - (a33 * a12)), ((a23 * a12) - (a22 * a13)),
						 ((a31 * a23) - (a33 * a21)), ((a33 * a11) - (a31 * a13)), ((a21 * a13) - (a23 * a11)),
						 ((a32 * a21) - (a31 * a22)), ((a31 * a12) - (a32 * a11)), ((a22 * a11) - (a21 * a12)) };

	MyMatrix3 myInverse = newMatrix * t_matrix.determinant();

	return myInverse;
}

MyVector3 MyMatrix3::row(const int t_row) const
{
	MyVector3 myRow{ 0.0, 0.0, 0.0 };

	if (t_row == 1)
	{
		myRow = { a11, a12, a13 };
	}
	else if (t_row == 2)
	{
		myRow = { a21, a22, a23 };
	}
	else if (t_row == 3)
	{
		myRow = { a31, a32, a33 };
	}


	return myRow;
}

MyVector3 MyMatrix3::column(const int t_column) const
{
	MyVector3 myColumn{ 0.0, 0.0, 0.0 };

	if (t_column == 1)
	{
		myColumn = { a11, a21, a31 };
	}
	else if (t_column == 2)
	{
		myColumn = { a12, a22, a32 };
	}
	else if (t_column == 3)
	{
		myColumn = { a13, a23, a33 };
	}


	return myColumn;
}

MyMatrix3 MyMatrix3::rotationZ(const double t_angleRadians)
{
	double new11 = cos(t_angleRadians);
	double new12 = sin(t_angleRadians);
	double new13 = 0.0;

	double new21 = -sin(t_angleRadians);
	double new22 = cos(t_angleRadians);
	double new23 = 0.0;

	double new31 = 0.0;
	double new32 = 0.0;
	double new33 = 1.0;


	return MyMatrix3(new11, new12, new13,
					 new21, new22, new23,
					 new31, new32, new33);
}

MyMatrix3 MyMatrix3::rotationY(const double t_angleRadians)
{
	double new11 = 1.0;
	double new12 = 0.0;
	double new13 = 0.0;

	double new21 = 0.0;
	double new22 = cos(t_angleRadians);
	double new23 = sin(t_angleRadians);

	double new31 = 0.0;
	double new32 = -sin(t_angleRadians);
	double new33 = cos(t_angleRadians);


	return MyMatrix3(new11, new12, new13,
					 new21, new22, new23,
					 new31, new32, new33);
}

MyMatrix3 MyMatrix3::rotationX(const double t_angleRadians)
{
	double new11 = cos(t_angleRadians);
	double new12 = 0.0;
	double new13 = -sin(t_angleRadians);

	double new21 = 0.0;
	double new22 = 1.0;
	double new23 = 0.0;

	double new31 = sin(t_angleRadians);
	double new32 = 0.0;
	double new33 = cos(t_angleRadians);


	return MyMatrix3(new11, new12, new13,
					 new21, new22, new23,
			 		 new31, new32, new33);

}

MyMatrix3 MyMatrix3::translation(const MyVector3 t_displacement)
{
	return MyMatrix3();
}

MyMatrix3 MyMatrix3::scale(const double t_scalingfactor)
{
	return MyMatrix3();
}
