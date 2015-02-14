#ifdef DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif#include <string>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;namespace DLLMath{	class MyBasicMath
	{
	public:
		//All functions for common math Functionality

		//Function for Linear Interpolation
		//Algorithm credit to http://en.wikipedia.org/wiki/Linear_interpolation
		DLLEXPORT float LinearInterpolation(float v0, float v1, float t);

		//Function for Conversion Between degrees and Radians
		DLLEXPORT float DegreeRadianConversion(int a_type, float a_numToConvert);

		//Function for Testing Scalar Value for Power of Two
		DLLEXPORT bool IsPowerOfTwo(unsigned int num);
	};

	class MyMatrix3x3
	{
	public:
		DLLEXPORT MyMatrix3x3();

		//take in a multidimensional Vector in order to create a new 4x4 matrix
		DLLEXPORT MyMatrix3x3(vector<vector<float>>& a_matrix);

		DLLEXPORT ~MyMatrix3x3();


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
		DLLEXPORT MyMatrix3x3 Scale3x3Matrix(float a_xChange, float a_yChange, MyMatrix3x3& someVector);

		//Function for Rotating a [3]x[3] matrix
		DLLEXPORT MyMatrix3x3 Rotate3x3MatrixZ(MyMatrix3x3& someVector, float a_degreeChange);

		DLLEXPORT MyMatrix3x3 Rotate3x3MatrixY(MyMatrix3x3& someVector, float a_degreeChange);

		DLLEXPORT MyMatrix3x3 Rotate3x3MatrixX(MyMatrix3x3& someVector, float a_degreeChange);

		//Function for Transforming a [3]x[3] matrix
		DLLEXPORT MyMatrix3x3 Transform3x3Matrix(MyMatrix3x3& someVector, float a_xChange, float a_yChange);

		//function for matrix multiplication between two [3]x[3] matricies
		DLLEXPORT MyMatrix3x3 My3x3MatrixMultiplication(MyMatrix3x3 someVector, MyMatrix3x3 someOtherVector);

		//Function for Matrix Multiplication in between a vector [3]x[1] and matrix [3]x[3]
		DLLEXPORT std::vector<float> My2DMatrixMultiplication(std::vector<float>& someVector, MyMatrix3x3& someMatrix);

		DLLEXPORT vector<vector<float>> GetMatrix();
	};

	class MyMatrix4x4
	{
	public:
		DLLEXPORT MyMatrix4x4();

		//take in a multidimensional array in order to create a new 4x4 matrix
		DLLEXPORT MyMatrix4x4(std::vector<std::vector<float>>& a_matrix);

		DLLEXPORT ~MyMatrix4x4();


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

		//All functions for 3x3 & 4x4 Matrix's
		//Function for Orthographic Projection Creation
		DLLEXPORT MyMatrix4x4 OrthographicProj(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far, MyMatrix4x4& someVector);

		//Function for scaling a [4]x[4] matrix
		DLLEXPORT MyMatrix4x4 Scale4x4Matrix(float a_xChange, float a_yChange, float a_zChange, MyMatrix4x4& someVector);


		//Function for Rotating a [4]x[4] matrix
		DLLEXPORT MyMatrix4x4 Rotate4x4MatrixZ(MyMatrix4x4& someVector, float a_degreeChange);

		DLLEXPORT MyMatrix4x4 Rotate4x4MatrixY(MyMatrix4x4& someVector, float a_degreeChange);

		DLLEXPORT MyMatrix4x4 Rotate4x4MatrixX(MyMatrix4x4& someVector, float a_degreeChange);



		//Function for transforming a [4]x[4] matrix
		DLLEXPORT MyMatrix4x4 Transform4x4Matrix(MyMatrix4x4& someVector, float a_xChange, float a_yChange, float a_zChange);


		//Function for matrix multiplication between two [4]x[4] matricies
		DLLEXPORT MyMatrix4x4 My4x4MatrixMultiplication(MyMatrix4x4 someVector, MyMatrix4x4 someOtherVector);

		DLLEXPORT vector<vector<float>> GetMatrix();

	};

	class My2DVector
	{
	public:
		DLLEXPORT My2DVector();

		//Constructor to make a 2D vector from scratch or from a vector<(float||int)>
		DLLEXPORT My2DVector(const float &a_X, const float &a_Y);

		DLLEXPORT ~My2DVector();

		//take in a 2d vector and return it's magnitude
		DLLEXPORT float Magnitude(const My2DVector);

		DLLEXPORT float DotProduct(const My2DVector &a_2Dvector);

		//Function for Normalization
		DLLEXPORT My2DVector NomralizeVector(const My2DVector);

		//Function for Cross Product
		DLLEXPORT float CrossProduct(const My2DVector &a_2Dvector);

		//function for Linear Interloping
		DLLEXPORT float Lerp(const My2DVector &a_2DVector, float percentage);


		float x;
		float y;

		DLLEXPORT vector<float> GetVect();

		//Time to declare some operator overloading
		DLLEXPORT My2DVector operator + (const My2DVector &a_plus);
		DLLEXPORT My2DVector operator += (const My2DVector &a_plusEquals);

		DLLEXPORT My2DVector operator - (const My2DVector &a_minus);
		DLLEXPORT My2DVector operator -= (const My2DVector &a_minusEquals);

		DLLEXPORT My2DVector operator * (const My2DVector &a_times);
		DLLEXPORT My2DVector operator *= (const My2DVector &a_timesEquals);

		DLLEXPORT My2DVector operator / (const My2DVector &a_devided);
		DLLEXPORT My2DVector operator /= (const My2DVector &a_devidedEquals);

		DLLEXPORT My2DVector operator = (const My2DVector &a_equals);
		DLLEXPORT bool operator == (const My2DVector &a_equalsEquals);
	};

	class My3DVector
	{
	public:
		DLLEXPORT My3DVector();

		//Constructor to make a 3D vector from scratch for operator Overloading
		DLLEXPORT My3DVector(const float &a_X, const float &a_Y, const float &a_Z);

		DLLEXPORT ~My3DVector();

		//take in a 2d vector and return it's magnitude
		DLLEXPORT float Magnitude(const My3DVector);

		DLLEXPORT float DotProduct(const My3DVector &a_3Dvector);

		//Function for Normalization
		DLLEXPORT My3DVector NomralizeVector(const My3DVector);

		//Function for Cross Product
		DLLEXPORT float CrossProduct(const My3DVector &a_3DVector);

		float x;
		float y;
		float z;

		DLLEXPORT vector<float> GetVect();

		//Time to declare some operator overloading
		DLLEXPORT My3DVector operator + (const My3DVector &a_plus);
		DLLEXPORT My3DVector operator += (const My3DVector &a_plusEquals);

		DLLEXPORT My3DVector operator - (const My3DVector &a_minus);
		DLLEXPORT My3DVector operator -= (const My3DVector &a_minusEquals);

		DLLEXPORT My3DVector operator * (const My3DVector &a_times);
		DLLEXPORT My3DVector operator *= (const My3DVector &a_timesEquals);

		DLLEXPORT My3DVector operator / (const My3DVector &a_devided);
		DLLEXPORT My3DVector operator /= (const My3DVector &a_devidedEquals);

		DLLEXPORT My3DVector operator = (const My3DVector &a_equals);
		DLLEXPORT bool operator == (const My3DVector &a_equalsEquals);
	};

	class My4DVector
	{
	public:

		DLLEXPORT My4DVector();

		DLLEXPORT My4DVector(float x, float y, float z, float w);

		DLLEXPORT ~My4DVector();

		float x;
		float y;
		float z;
		float w;

		//Function for Construction from Hexadecimal Color Value
		//Credit for this style of construction from a hex value to Jeffrey M. Johnson
		//https://github.com/JeffreyMJohnson
		DLLEXPORT My4DVector ConstructFromHex(const unsigned int a_hex);

		//Function for Normalization
		DLLEXPORT My4DVector Normalize4D(const My4DVector);

		DLLEXPORT vector<float> GetVect();

		DLLEXPORT bool operator == (const My4DVector &a_equalsEquals);


	};}