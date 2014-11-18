//MyMathLibrary.h
//By: Jared Ramey || Started: 11/4/14
//#ifdef _MYMATHLIBRARY_H_
//#define _MYMATHLIBRARY_H_

#include <string>
#include <iostream>
#include <math.h>
#include <vector>

namespace MyMathLibrary
{
	class MyMathFunctions
	{
	public:
	/*but you're not using any Vectors here. you can have a DotProduct function by itself (I would make it a static function
	so you don't instantiate a Math library object to use it however) but normrmally it would be a function of a Vector class
	that you would call with another Vector to have the dot product returned.
	
	e.g.
	class Vector2
	{
		float DotProduct(const Vector2& rhs);
	};
	
	use:
		void main()
		{
			Vector2 v1(1,1);
			Vector2 v2 (2,2);
			float dotProduct = v1.DotProduct(v2);
		}
	
	This should get you on the right path. If you have question or prefer me to shut the fuck up feel free to ask / let me know.
	jefjohms@gmail.com
	jeffrey.johnson@students.aie.edu.au
	*/
		//All functions for 2D & 3D Dimensional Vectors
		//Function for Dot Product
		float DotProduct(float a_Ax, float a_Ay, float a_Bx, float a_By);
		//Function for Normalization
		float NomralizeVector(std::string a_returnType, float a_x, float a_y, float a_length);
		//Function for Cross Product
		float CrossProduct(std::string a_returnType, float a_Ax, float a_Ay, float a_Az, float a_Bx, float a_By, float a_Bz);
		//Function for Magnitude
		float Magnitude(float a_A, float a_B);
		//Function for Operator Overloading

		//Function for Linear Interpolation
			//Algorythm credit to http://en.wikipedia.org/wiki/Linear_interpolation
		float LinearInterpolation(float v0, float v1, float t);

	//All functions for 3x3 & 4x4 Matrix's
		//Function for Orthographic Projection Creation


		//Function for Scaling a [3]x[3] matrix
		std::vector<std::vector<float>> Scale3x3Matrix(float a_xChange, float a_yChange, std::vector<std::vector<float>>& someVector);

		//Function for scaling a [4]x[4] matrix
		std::vector<std::vector<float>> Scale4x4Matrix(float a_xChange, float a_yChange, float a_zChange, std::vector<std::vector<float>>& someVector);

		//Function for Rotating a [3]x[3] matrix
		std::vector<std::vector<float>> Rotate3x3Matrix(std::vector<std::vector<float>>& someVector, float a_degreeChange);

		//Function for Rotating a [4]x[4] matrix
		std::vector<std::vector<float>> Rotate4x4Matrix(std::vector<std::vector<float>>& someVector, float a_degreeChange);

		//Function for Transforming a [3]x[3] matrix
		std::vector<std::vector<float>> Transform3x3Matrix(std::vector<std::vector<float>>& someVector, float a_xChange, float a_yChange);

		//Function for transforming a [4]x[4] matrix
		std::vector<std::vector<float>> Transform4x4Matrix(std::vector<std::vector<float>>& someVector, float a_xChange, float a_yChange, float a_zChange);

		//Function for Matrix Multiplication in between a vector [3]x[1] and matrix [3]x[3]
		std::vector<float> My2DMatrixMultiplication(std::vector<float>& someVector, std::vector<std::vector<float>>& someOtherVector);

		//function for matrix multiplication between two [3]x[3] matricies
		std::vector<std::vector<float>> My3x3MatrixMultiplication(std::vector<std::vector<float>>& someVector, std::vector<std::vector<float>>& someOtherVector);

		//Function for matrix multiplication between two [4]x[4] matricies
		std::vector<std::vector<float>> My4x4MatrixMultiplication(std::vector<std::vector<float>>& someVector, std::vector<std::vector<float>>& someOtherVector);

	//All functions for Vector 4
		//Function for Normilization

		//Function for Construction from Hexadecimal Color Value


	//All functions for common math Functionality
		//Function for Linear Interpolation for Scalar Values

		//Function for Conversion Between degrees and Radians
		int DegreeRadianConversion(int a_type, float a_numToConvert);
		//Function for Testing Scalar Value for Power of Two

		//Function for Bitwise Operations

	};
}
