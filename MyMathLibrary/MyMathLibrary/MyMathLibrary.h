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
	class MyBasicMath
	{
	public:
		//All functions for common math Functionality
		//Function for Linear Interpolation for Scalar Values

		//Function for Conversion Between degrees and Radians
		int DegreeRadianConversion(int a_type, float a_numToConvert);
		//Function for Testing Scalar Value for Power of Two

		//Function for Bitwise Operations


	};

	class MyMatrix3x3
	{
	public:
		MyMatrix3x3();

		//take in a multidimensional array in order to create a new 4x4 matrix
		MyMatrix3x3(std::vector<std::vector<float>>& a_matrix);

		~MyMatrix3x3();


		float zeroZero;
		float zeroOne;
		float zeroTwo;
		float oneZero;
		float oneOne;
		float oneTwo;
		float twoZero;
		float twoOne;
		float twoTwo;


		//Function for Scaling a [3]x[3] matrix
		MyMatrix3x3 Scale3x3Matrix(float a_xChange, float a_yChange, MyMatrix3x3& someVector);

		//Function for Rotating a [3]x[3] matrix
		MyMatrix3x3 Rotate3x3MatrixZ(MyMatrix3x3& someVector, float a_degreeChange);

		MyMatrix3x3 Rotate3x3MatrixY(MyMatrix3x3& someVector, float a_degreeChange);

		MyMatrix3x3 Rotate3x3MatrixX(MyMatrix3x3& someVector, float a_degreeChange);

		//Function for Transforming a [3]x[3] matrix
		MyMatrix3x3 Transform3x3Matrix(MyMatrix3x3& someVector, float a_xChange, float a_yChange);

		//function for matrix multiplication between two [3]x[3] matricies
		MyMatrix3x3 My3x3MatrixMultiplication(MyMatrix3x3& someVector, MyMatrix3x3& someOtherVector);

		//Function for Matrix Multiplication in between a vector [3]x[1] and matrix [3]x[3]
		std::vector<float> My2DMatrixMultiplication(std::vector<float>& someVector, MyMatrix3x3& someMatrix);
	};

	class MyMatrix4x4
	{
	public:
		MyMatrix4x4();

		//take in a multidimensional array in order to create a new 4x4 matrix
		MyMatrix4x4(std::vector<std::vector<float>>& a_matrix);

		~MyMatrix4x4();


		float zeroZero;
		float zeroOne;
		float zeroTwo;
		float zeroThree;
		float oneZero;
		float oneOne;
		float oneTwo;
		float oneThree;
		float twoZero;
		float twoOne;
		float twoTwo;
		float twoThree;
		float threeZero;
		float threeOne;
		float threeTwo;
		float threeThree;



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
		MyMatrix4x4 OrthographicProj(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far, MyMatrix4x4& someVector);

		//Function for scaling a [4]x[4] matrix
		MyMatrix4x4 Scale4x4Matrix(float a_xChange, float a_yChange, float a_zChange, MyMatrix4x4& someVector);

		
		//Function for Rotating a [4]x[4] matrix
		MyMatrix4x4 Rotate4x4MatrixZ(MyMatrix4x4& someVector, float a_degreeChange);

		MyMatrix4x4 Rotate4x4MatrixY(MyMatrix4x4& someVector, float a_degreeChange);

		MyMatrix4x4 Rotate4x4MatrixX(MyMatrix4x4& someVector, float a_degreeChange);

		

		//Function for transforming a [4]x[4] matrix
		MyMatrix4x4 Transform4x4Matrix(MyMatrix4x4& someVector, float a_xChange, float a_yChange, float a_zChange);
		

		//Function for matrix multiplication between two [4]x[4] matricies
		MyMatrix4x4 My4x4MatrixMultiplication(MyMatrix4x4& someVector, MyMatrix4x4& someOtherVector);

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

		//function for Linear Interloping
		float Lerp(const My2DVector &a_2DVector, float percentage);

		
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

	class My4DVector
	{
	public:

		My4DVector();

		My4DVector(float x, float y, float z, float w);

		~My4DVector();

		float x;
		float y;
		float z;
		float w;

		//Function for Construction from Hexadecimal Color Value
		//Credit for this style of construction from a hex value to Jeffrey M. Johnson
		//https://github.com/JeffreyMJohnson
		My4DVector ConstructFromHex(const unsigned int a_hex);

		//Function for Normalization
		My4DVector Normalize4D(const My4DVector);


	};
}
