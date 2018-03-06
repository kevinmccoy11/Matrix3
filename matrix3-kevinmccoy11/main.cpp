/// <summary>
/// Empty Project for SFML[2.4.2]
/// 
/// 
/// @author Peter Lowe
/// @date May 21017
/// </summary>

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 


#include "InitialMyMatrix3.h"

/// <summary>
/// main enrtry point
/// </summary>
/// <returns>zero</returns>
int main()
{
	MyMatrix3 matrix1{ 2, 5, 6,
					   4, 2, 7,
					   7, 6, 2 };
	MyMatrix3 matrix2{ 1, 0, 0,
					   0, 1, 0,
					   0, 0, 1 };
	MyMatrix3 matrix3;

	matrix3 = matrix1 + matrix2;
	std::cout << MyMatrix3{ 3,5,6,4,3,7,7,6,3 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Addition ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1 - matrix2;
	std::cout << MyMatrix3{ 1,5,6,4,1,7,7,6,1 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Subtraction ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1 * matrix2;
	std::cout << MyMatrix3{ 2,5,6,4,2,7,7,6,2 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Multiplication by Matrix ------------------------" << std::endl;
	std::cout << std::endl;

	MyVector3 vector1{ 2,4,6 };
	MyVector3 vector2{};
	vector2 = matrix1 * vector1;
	std::cout << MyVector3{ 60,58,50 }.toString() << std::endl;
	std::cout << vector2.toString() << std::endl;
	std::cout << "Multiplication by Vector ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1 * 2;
	std::cout << MyMatrix3{ 4,10,12,8,4,14,14,12,4 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Multiplication by Scalar ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1.transpose();
	std::cout << MyMatrix3{ 2,4,7,5,2,6,6,7,2 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Transpose ------------------------" << std::endl;
	std::cout << std::endl;

	double determinant = matrix1.determinant();
	std::cout << "189" << std::endl;
	std::cout << determinant << std::endl;
	std::cout << "Determinant ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1 * matrix1.inverse(matrix1);
	std::cout << MyMatrix3{ 35721,0,0,0,-12663,35721,0,35721,0 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Inverse ------------------------" << std::endl;
	std::cout << std::endl;

	vector2 = matrix1.row(1);
	std::cout << MyVector3{ 2,5,6 }.toString() << std::endl;
	std::cout << vector2.toString() << std::endl;
	std::cout << "Row ------------------------" << std::endl;
	std::cout << std::endl;

	vector2 = matrix1.column(1);
	std::cout << MyVector3{ 3,4,7 }.toString() << std::endl;
	std::cout << vector2.toString() << std::endl;
	std::cout << "Column ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1.rotationZ(45);
	std::cout << MyMatrix3{0.5253220, -0.8509035, 0, 0.8509035, 0.5253220, 0, 0, 0, 1}.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Rotation Z ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1.rotationY(45);
	std::cout << MyMatrix3{ 0.5253220, 0, 0.8509035, 0, 1, 0,-0.8509035, 0, 0.5253220 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Rotation Y ------------------------" << std::endl;
	std::cout << std::endl;

	matrix3 = matrix1.rotationX(45);
	std::cout << MyMatrix3{ 1, 0, 0, 0, 0.5253220, -0.8509035, 0, 0.8509035, 0.5253220 }.toString() << std::endl;
	std::cout << matrix3.toString() << std::endl;
	std::cout << "Rotation X ------------------------" << std::endl;
	std::cout << std::endl;

	system("Pause");
	return 0;
}