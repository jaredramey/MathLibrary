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
		//Function for Linear Interpolation
			//Algorithm credit to http://en.wikipedia.org/wiki/Linear_interpolation
		float LinearInterpolation(float v0, float v1, float t);

	//All functions for 3x3 & 4x4 Matrix's
		//Function for Orthographic Projection Creation
		std::vector<std::vector<float>> OrthographicProj(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far, std::vector<std::vector<float>>& someVector);

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
		//Function for Normalization

		//Function for Construction from Hexadecimal Color Value


	//All functions for common math Functionality
		//Function for Linear Interpolation for Scalar Values

		//Function for Conversion Between degrees and Radians
		int DegreeRadianConversion(int a_type, float a_numToConvert);
		//Function for Testing Scalar Value for Power of Two

		//Function for Bitwise Operations

	};

	class My2DVector
	{
	public:
		My2DVector();

		//Constructor to make a 2D vector from scratch or from a vector<(float||int)>
		My2DVector(const float &a_X, const float &a_Y);

		~My2DVector();

		//take in a 2d vector and return it's magnitude
		float Magnitude(const My2DVector);

		float DotProduct(const My2DVector &a_2Dvector);

		//Function for Normalization
		My2DVector NomralizeVector(const My2DVector);

		//Function for Cross Product
		float CrossProduct(const My2DVector &a_2Dvector);
		

		
		float x;
		float y;


		//Time to declare some operator overloading
		My2DVector operator + (const My2DVector &a_plus);
		My2DVector operator += (const My2DVector &a_plusEquals);

		My2DVector operator - (const My2DVector &a_minus);
		My2DVector operator -= (const My2DVector &a_minusEquals);

		My2DVector operator * (const My2DVector &a_times);
		My2DVector operator *= (const My2DVector &a_timesEquals);

		My2DVector operator / (const My2DVector &a_devided);
		My2DVector operator /= (const My2DVector &a_devidedEquals);

		My2DVector operator = (const My2DVector &a_equals);
		bool operator == (const My2DVector &a_equalsEquals);
	};

	class My3DVector
	{
	public:
		My3DVector();

		//Constructor to make a 3D vector from scratch for operator Overloading
		My3DVector(const float &a_X, const float &a_Y, const float &a_Z);

		~My3DVector();

		//take in a 2d vector and return it's magnitude
		float Magnitude(const My3DVector);

		float DotProduct(const My3DVector &a_3Dvector);

		//Function for Normalization
		My3DVector NomralizeVector(const My3DVector);

		//Function for Cross Product
		My3DVector CrossProduct(const My3DVector &a_3DVector);

		float x;
		float y;
		float z;


		//Time to declare some operator overloading
		My3DVector operator + (const My3DVector &a_plus);
		My3DVector operator += (const My3DVector &a_plusEquals);

		My3DVector operator - (const My3DVector &a_minus);
		My3DVector operator -= (const My3DVector &a_minusEquals);

		My3DVector operator * (const My3DVector &a_times);
		My3DVector operator *= (const My3DVector &a_timesEquals);

		My3DVector operator / (const My3DVector &a_devided);
		My3DVector operator /= (const My3DVector &a_devidedEquals);

		My3DVector operator = (const My3DVector &a_equals);
		bool operator == (const My3DVector &a_equalsEquals);
	};
}
