//MyMatrix4x4.cpp
#include "MyMathFuncs.h"
#include <stdexcept>

using namespace std;

namespace DLLMath
{
	MyMatrix4x4::MyMatrix4x4()
	{

	}

	MyMatrix4x4::MyMatrix4x4(vector<vector<float>>& a_matrix)
	{
		zeroZero = a_matrix[0][0];
		zeroOne = a_matrix[0][1];
		zeroTwo = a_matrix[0][2];
		zeroThree = a_matrix[0][3];
		oneZero = a_matrix[1][0];
		oneOne = a_matrix[1][1];
		oneTwo = a_matrix[1][2];
		oneThree = a_matrix[1][3];
		twoZero = a_matrix[2][0];
		twoOne = a_matrix[2][1];
		twoTwo = a_matrix[2][2];
		twoThree = a_matrix[2][3];
		threeZero = a_matrix[3][0];
		threeOne = a_matrix[3][1];
		threeTwo = a_matrix[3][2];
		threeThree = a_matrix[3][3];
	}

	MyMatrix4x4::~MyMatrix4x4()
	{

	}


	//All functions for 3x3 & 4x4 Matrix's
	//Function for Orthographic Projection Creation
	MyMatrix4x4 MyMatrix4x4::OrthographicProj(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far, MyMatrix4x4& someMatrix)
	{																																				//||=============================================||
		vector<vector<float>> changeMatrix =																										//||-------The Matrix in column row major -------||
		{																																			//||=============================================||
			{ (2 / (a_right - a_left)), 0, 0, 0 },																									//  |(2 / (a_right - a_left)), 0, 0, 0|
			{ 0, (2 / (a_top - a_bottom)), 0, 0 },																									//  |0, (2 / (a_top - a_bottom)), 0, 0|
			{ 0, 0, (-1 / (a_far - a_near)), 0 },																									//  |0, 0, (-1 / (a_far - a_near)), 0 |
			{ (((a_right + a_left) / (a_right - a_left))*-1), (((a_top + a_bottom) / (a_top - a_bottom))*-1), (a_near / (a_far - a_near)), 1 }      //  |(((a_right + a_left) / (a_right - a_left))*-1), (((a_top + a_bottom) / (a_top - a_bottom))*-1), (a_near / (a_far - a_near)), 1|
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);

		//multiply with already made multiplication function and then return the result
		return someMatrix;

	}



	//function for Scaling a [4]x[4] matrix
	MyMatrix4x4 MyMatrix4x4::Scale4x4Matrix(float a_xChange, float a_yChange, float a_zChange, MyMatrix4x4& someMatrix)
	{
		vector<vector<float>> changeMatrix =
		{
			{ a_xChange, 0, 0, 0 },
			{ 0, a_yChange, 0, 0 },
			{ 0, 0, a_zChange, 0 },
			{ 0, 0, 0, 1 }
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]) + (someMatrix[0][3] * changeMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]) + (someMatrix[0][3] * changeMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * changeMatrix[3][0]) + (someMatrix[0][1] * changeMatrix[3][1]) + (someMatrix[0][2] * changeMatrix[3][2]) + (someMatrix[0][3] * changeMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]) + (someMatrix[1][3] * changeMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]) + (someMatrix[1][3] * changeMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]) + (someMatrix[1][3] * changeMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * changeMatrix[3][0]) + (someMatrix[1][1] * changeMatrix[3][1]) + (someMatrix[1][2] * changeMatrix[3][2]) + (someMatrix[1][3] * changeMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]) + (someMatrix[2][3] * changeMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]) + (someMatrix[2][3] * changeMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]) + (someMatrix[2][3] * changeMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * changeMatrix[3][0]) + (someMatrix[2][1] * changeMatrix[3][1]) + (someMatrix[2][2] * changeMatrix[3][2]) + (someMatrix[2][3] * changeMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * changeMatrix[0][0]) + (someMatrix[3][1] * changeMatrix[0][1]) + (someMatrix[3][2] * changeMatrix[0][2]) + (someMatrix[3][3] * changeMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * changeMatrix[1][0]) + (someMatrix[3][1] * changeMatrix[1][1]) + (someMatrix[3][2] * changeMatrix[1][2]) + (someMatrix[3][3] * changeMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * changeMatrix[2][0]) + (someMatrix[3][1] * changeMatrix[2][1]) + (someMatrix[3][2] * changeMatrix[2][2]) + (someMatrix[3][3] * changeMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));*/


		return someMatrix;
	}



	//Function for Rotating a [4]x[4] matrix
	MyMatrix4x4 MyMatrix4x4::Rotate4x4MatrixZ(MyMatrix4x4& someMatrix, float a_degreeChange)
	{
		vector<vector<float>> changeMatrix =
		{
			{ (cos(a_degreeChange)), (sin(a_degreeChange)), 0, 0 },
			{ (asin(a_degreeChange)), (cos(a_degreeChange)), 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]) + (someMatrix[0][3] * changeMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]) + (someMatrix[0][3] * changeMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * changeMatrix[3][0]) + (someMatrix[0][1] * changeMatrix[3][1]) + (someMatrix[0][2] * changeMatrix[3][2]) + (someMatrix[0][3] * changeMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]) + (someMatrix[1][3] * changeMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]) + (someMatrix[1][3] * changeMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]) + (someMatrix[1][3] * changeMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * changeMatrix[3][0]) + (someMatrix[1][1] * changeMatrix[3][1]) + (someMatrix[1][2] * changeMatrix[3][2]) + (someMatrix[1][3] * changeMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]) + (someMatrix[2][3] * changeMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]) + (someMatrix[2][3] * changeMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]) + (someMatrix[2][3] * changeMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * changeMatrix[3][0]) + (someMatrix[2][1] * changeMatrix[3][1]) + (someMatrix[2][2] * changeMatrix[3][2]) + (someMatrix[2][3] * changeMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * changeMatrix[0][0]) + (someMatrix[3][1] * changeMatrix[0][1]) + (someMatrix[3][2] * changeMatrix[0][2]) + (someMatrix[3][3] * changeMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * changeMatrix[1][0]) + (someMatrix[3][1] * changeMatrix[1][1]) + (someMatrix[3][2] * changeMatrix[1][2]) + (someMatrix[3][3] * changeMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * changeMatrix[2][0]) + (someMatrix[3][1] * changeMatrix[2][1]) + (someMatrix[3][2] * changeMatrix[2][2]) + (someMatrix[3][3] * changeMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));*/

		return someMatrix;
	}

	MyMatrix4x4 MyMatrix4x4::Rotate4x4MatrixY(MyMatrix4x4& someMatrix, float a_degreeChange)
	{
		vector<vector<float>> changeMatrix =
		{
			{ (cos(a_degreeChange)), 0, (asin(a_degreeChange)), 0 },
			{ 0, 1, 0, 0 },
			{ (sin(a_degreeChange)), 0, (cos(a_degreeChange)), 0 },
			{ 0, 0, 0, 1 }
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]) + (someMatrix[0][3] * changeMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]) + (someMatrix[0][3] * changeMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * changeMatrix[3][0]) + (someMatrix[0][1] * changeMatrix[3][1]) + (someMatrix[0][2] * changeMatrix[3][2]) + (someMatrix[0][3] * changeMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]) + (someMatrix[1][3] * changeMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]) + (someMatrix[1][3] * changeMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]) + (someMatrix[1][3] * changeMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * changeMatrix[3][0]) + (someMatrix[1][1] * changeMatrix[3][1]) + (someMatrix[1][2] * changeMatrix[3][2]) + (someMatrix[1][3] * changeMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]) + (someMatrix[2][3] * changeMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]) + (someMatrix[2][3] * changeMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]) + (someMatrix[2][3] * changeMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * changeMatrix[3][0]) + (someMatrix[2][1] * changeMatrix[3][1]) + (someMatrix[2][2] * changeMatrix[3][2]) + (someMatrix[2][3] * changeMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * changeMatrix[0][0]) + (someMatrix[3][1] * changeMatrix[0][1]) + (someMatrix[3][2] * changeMatrix[0][2]) + (someMatrix[3][3] * changeMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * changeMatrix[1][0]) + (someMatrix[3][1] * changeMatrix[1][1]) + (someMatrix[3][2] * changeMatrix[1][2]) + (someMatrix[3][3] * changeMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * changeMatrix[2][0]) + (someMatrix[3][1] * changeMatrix[2][1]) + (someMatrix[3][2] * changeMatrix[2][2]) + (someMatrix[3][3] * changeMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));*/

		return someMatrix;
	}

	MyMatrix4x4 MyMatrix4x4::Rotate4x4MatrixX(MyMatrix4x4& someMatrix, float a_degreeChange)
	{
		vector<vector<float>> changeMatrix =
		{
			{ 1, 0, 0, 0 },
			{ 0, (cos(a_degreeChange)), (asin(a_degreeChange)), 0 },
			{ 0, (sin(a_degreeChange)), (cos(a_degreeChange)), 0 },
			{ 0, 0, 0, 1 }
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]) + (someMatrix[0][3] * changeMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]) + (someMatrix[0][3] * changeMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * changeMatrix[3][0]) + (someMatrix[0][1] * changeMatrix[3][1]) + (someMatrix[0][2] * changeMatrix[3][2]) + (someMatrix[0][3] * changeMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]) + (someMatrix[1][3] * changeMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]) + (someMatrix[1][3] * changeMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]) + (someMatrix[1][3] * changeMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * changeMatrix[3][0]) + (someMatrix[1][1] * changeMatrix[3][1]) + (someMatrix[1][2] * changeMatrix[3][2]) + (someMatrix[1][3] * changeMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]) + (someMatrix[2][3] * changeMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]) + (someMatrix[2][3] * changeMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]) + (someMatrix[2][3] * changeMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * changeMatrix[3][0]) + (someMatrix[2][1] * changeMatrix[3][1]) + (someMatrix[2][2] * changeMatrix[3][2]) + (someMatrix[2][3] * changeMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * changeMatrix[0][0]) + (someMatrix[3][1] * changeMatrix[0][1]) + (someMatrix[3][2] * changeMatrix[0][2]) + (someMatrix[3][3] * changeMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * changeMatrix[1][0]) + (someMatrix[3][1] * changeMatrix[1][1]) + (someMatrix[3][2] * changeMatrix[1][2]) + (someMatrix[3][3] * changeMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * changeMatrix[2][0]) + (someMatrix[3][1] * changeMatrix[2][1]) + (someMatrix[3][2] * changeMatrix[2][2]) + (someMatrix[3][3] * changeMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));*/

		return someMatrix;
	}

	//Function for Transform Point



	//Function for Transforming a [4]x[4] matrix
	MyMatrix4x4 MyMatrix4x4::Transform4x4Matrix(MyMatrix4x4& someMatrix, float a_xChange, float a_yChange, float a_zChange)
	{
		vector<vector<float>> changeMatrix =
		{
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ a_xChange, a_yChange, a_zChange, 1 }
		};

		MyMatrix4x4 testMatrix = MyMatrix4x4(changeMatrix);

		My4x4MatrixMultiplication(someMatrix, testMatrix);


		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]) + (someMatrix[0][3] * changeMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]) + (someMatrix[0][3] * changeMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * changeMatrix[3][0]) + (someMatrix[0][1] * changeMatrix[3][1]) + (someMatrix[0][2] * changeMatrix[3][2]) + (someMatrix[0][3] * changeMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]) + (someMatrix[1][3] * changeMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]) + (someMatrix[1][3] * changeMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]) + (someMatrix[1][3] * changeMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * changeMatrix[3][0]) + (someMatrix[1][1] * changeMatrix[3][1]) + (someMatrix[1][2] * changeMatrix[3][2]) + (someMatrix[1][3] * changeMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]) + (someMatrix[2][3] * changeMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]) + (someMatrix[2][3] * changeMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]) + (someMatrix[2][3] * changeMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * changeMatrix[3][0]) + (someMatrix[2][1] * changeMatrix[3][1]) + (someMatrix[2][2] * changeMatrix[3][2]) + (someMatrix[2][3] * changeMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * changeMatrix[0][0]) + (someMatrix[3][1] * changeMatrix[0][1]) + (someMatrix[3][2] * changeMatrix[0][2]) + (someMatrix[3][3] * changeMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * changeMatrix[1][0]) + (someMatrix[3][1] * changeMatrix[1][1]) + (someMatrix[3][2] * changeMatrix[1][2]) + (someMatrix[3][3] * changeMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * changeMatrix[2][0]) + (someMatrix[3][1] * changeMatrix[2][1]) + (someMatrix[3][2] * changeMatrix[2][2]) + (someMatrix[3][3] * changeMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));*/


		return someMatrix;
	}



	//Function for matrix multiplication between two [4]x[4] matricies
	MyMatrix4x4 MyMatrix4x4::My4x4MatrixMultiplication(MyMatrix4x4 someMatrix, MyMatrix4x4 someOtherMatrix)
	{
		//New Multiplication
		zeroZero = ((someMatrix.zeroZero*someOtherMatrix.zeroZero) + (someMatrix.zeroOne*someOtherMatrix.oneZero) + (someMatrix.zeroTwo*someOtherMatrix.twoZero) + (someMatrix.zeroThree*someOtherMatrix.threeZero));		//	{x, x, x, x}
		zeroOne = ((someMatrix.zeroZero*someOtherMatrix.zeroOne) + (someMatrix.zeroOne*someOtherMatrix.oneOne) + (someMatrix.zeroTwo*someOtherMatrix.twoOne) + (someMatrix.zeroThree*someOtherMatrix.threeOne));			//	{O, O, O, O}
		zeroTwo = ((someMatrix.zeroZero*someOtherMatrix.zeroTwo) + (someMatrix.zeroOne*someOtherMatrix.oneTwo) + (someMatrix.zeroTwo*someOtherMatrix.twoTwo) + (someMatrix.zeroThree*someOtherMatrix.threeTwo));			//	{O, O, O, O}
		zeroThree = ((someMatrix.zeroZero*someOtherMatrix.zeroThree) + (someMatrix.zeroOne*someOtherMatrix.oneThree) + (someMatrix.zeroTwo*someOtherMatrix.twoThree) + (someMatrix.zeroThree*someOtherMatrix.threeThree));	//	{O, O, O, O}
		/*Second Row*/
		oneZero = ((someMatrix.oneZero*someOtherMatrix.oneZero) + (someMatrix.oneOne*someOtherMatrix.zeroOne) + (someMatrix.oneTwo*someOtherMatrix.twoZero) + (someMatrix.oneThree*someOtherMatrix.threeZero));		//		{O, O, O, O}
		oneOne = ((someMatrix.oneZero*someOtherMatrix.oneOne) + (someMatrix.oneOne*someOtherMatrix.oneOne) + (someMatrix.oneTwo*someOtherMatrix.oneTwo) + (someMatrix.oneThree*someOtherMatrix.threeOne));				//		{x, x, x, x}
		oneTwo = ((someMatrix.oneZero*someOtherMatrix.oneTwo) + (someMatrix.oneOne*someMatrix.twoOne) + (someMatrix.oneTwo*someOtherMatrix.twoTwo) + (someMatrix.oneThree*someOtherMatrix.threeTwo));					//		{O, O, O, O}
		oneThree = (someMatrix.oneZero*someOtherMatrix.oneThree) + (someMatrix.zeroOne*someOtherMatrix.threeOne) + (someMatrix.zeroTwo*someOtherMatrix.threeTwo) + (someMatrix.zeroThree*someOtherMatrix.threeThree);	//      {O, O, O, O}
		/*Third Row*/
		twoZero = ((someMatrix.twoZero*someOtherMatrix.twoZero) + (someMatrix.twoOne*someOtherMatrix.zeroOne) + (someMatrix.twoTwo*someOtherMatrix.zeroTwo) + (someMatrix.twoThree*someOtherMatrix.threeZero));		//		{O, O, O, O}
		twoOne = ((someMatrix.twoZero*someOtherMatrix.twoOne) + (someMatrix.twoOne*someOtherMatrix.oneOne) + (someMatrix.twoTwo*someOtherMatrix.oneTwo) + (someMatrix.twoThree*someOtherMatrix.threeOne));				//		{O, O, O, O}
		twoTwo = ((someMatrix.twoZero*someOtherMatrix.twoTwo) + (someMatrix.twoOne*someOtherMatrix.twoOne) + (someMatrix.twoTwo*someOtherMatrix.twoTwo) + (someMatrix.twoThree*someOtherMatrix.threeTwo));				//		{x, x, x, x}
		twoThree = ((someMatrix.twoZero*someOtherMatrix.twoThree) + (someMatrix.twoOne*someOtherMatrix.threeOne) + (someMatrix.threeTwo*someOtherMatrix.twoTwo) + (someMatrix.twoThree*someOtherMatrix.threeThree));	//		{O, O, O, O}
		/*Fourth Row*/
		threeZero = ((someMatrix.threeZero*someOtherMatrix.threeZero) + (someMatrix.threeOne*someOtherMatrix.zeroOne) + (someMatrix.threeTwo*someOtherMatrix.zeroTwo) + (someMatrix.threeThree*someOtherMatrix.zeroThree));
		threeOne = ((someMatrix.threeZero*someOtherMatrix.threeOne) + (someMatrix.threeOne*someOtherMatrix.oneOne) + (someMatrix.threeTwo*someOtherMatrix.oneTwo) + (someMatrix.threeThree*someOtherMatrix.oneThree));
		threeTwo = ((someMatrix.threeZero*someOtherMatrix.threeTwo) + (someMatrix.threeOne*someOtherMatrix.twoOne) + (someMatrix.threeTwo*someOtherMatrix.twoTwo) + (someMatrix.threeThree*someOtherMatrix.twoThree));
		threeThree = ((someMatrix.threeZero*someOtherMatrix.threeThree) + (someMatrix.threeOne*someOtherMatrix.threeOne) + (someMatrix.threeTwo*someOtherMatrix.threeTwo) + (someMatrix.threeThree*someOtherMatrix.threeThree));


		//Old Multiplication (changed on 12/9/14)
		/*someMatrix.zeroZero = ((someMatrix.zeroZero * someOtherMatrix.zeroZero) + (someMatrix.zeroOne * someOtherMatrix.zeroOne) + (someMatrix.zeroTwo * someOtherMatrix.zeroTwo) + (someMatrix.zeroThree * someOtherMatrix.zeroThree));
		someMatrix.zeroOne = ((someMatrix.zeroZero * someOtherMatrix.oneZero) + (someMatrix.zeroOne * someOtherMatrix.oneOne) + (someMatrix.zeroTwo * someOtherMatrix.oneTwo) + (someMatrix.zeroThree * someOtherMatrix.oneThree));
		someMatrix.zeroTwo = ((someMatrix.zeroZero * someOtherMatrix.twoZero) + (someMatrix.zeroOne * someOtherMatrix.twoOne) + (someMatrix.zeroTwo * someOtherMatrix.twoTwo) + (someMatrix.zeroThree * someOtherMatrix.twoThree));
		someMatrix.zeroThree = ((someMatrix.zeroZero * someOtherMatrix.threeZero) + (someMatrix.zeroOne * someOtherMatrix.threeOne) + (someMatrix.zeroTwo * someOtherMatrix.threeTwo) + (someMatrix.zeroThree * someOtherMatrix.threeThree));
		someMatrix.oneZero = ((someMatrix.zeroZero * someOtherMatrix.zeroZero) + (someMatrix.oneOne * someOtherMatrix.zeroOne) + (someMatrix.oneTwo * someOtherMatrix.zeroTwo) + (someMatrix.oneThree * someOtherMatrix.zeroThree));
		someMatrix.oneOne = ((someMatrix.oneZero * someOtherMatrix.oneZero) + (someMatrix.oneOne * someOtherMatrix.oneOne) + (someMatrix.oneTwo * someOtherMatrix.oneTwo) + (someMatrix.oneThree * someOtherMatrix.oneThree));
		someMatrix.oneTwo = ((someMatrix.oneZero * someOtherMatrix.twoZero) + (someMatrix.oneOne * someOtherMatrix.twoOne) + (someMatrix.oneTwo * someOtherMatrix.twoTwo) + (someMatrix.oneThree * someOtherMatrix.twoThree));
		someMatrix.oneThree = ((someMatrix.oneZero * someOtherMatrix.threeZero) + (someMatrix.oneOne * someOtherMatrix.threeOne) + (someMatrix.oneTwo * someOtherMatrix.threeTwo) + (someMatrix.oneThree * someOtherMatrix.threeThree));
		someMatrix.twoZero = ((someMatrix.oneZero * someOtherMatrix.zeroZero) + (someMatrix.twoOne * someOtherMatrix.zeroOne) + (someMatrix.twoTwo * someOtherMatrix.zeroTwo) + (someMatrix.twoThree * someOtherMatrix.zeroThree));
		someMatrix.twoOne = ((someMatrix.twoZero * someOtherMatrix.oneZero) + (someMatrix.twoOne * someOtherMatrix.oneOne) + (someMatrix.twoTwo * someOtherMatrix.oneTwo) + (someMatrix.twoThree * someOtherMatrix.oneThree));
		someMatrix.twoTwo = ((someMatrix.twoZero * someOtherMatrix.twoZero) + (someMatrix.twoOne * someOtherMatrix.twoOne) + (someMatrix.twoTwo * someOtherMatrix.twoTwo) + (someMatrix.twoThree * someOtherMatrix.twoThree));
		someMatrix.twoThree = ((someMatrix.twoZero * someOtherMatrix.threeZero) + (someMatrix.twoOne * someOtherMatrix.threeOne) + (someMatrix.twoTwo * someOtherMatrix.threeTwo) + (someMatrix.twoThree * someOtherMatrix.threeThree));
		someMatrix.threeZero = ((someMatrix.threeZero * someOtherMatrix.zeroZero) + (someMatrix.threeOne * someOtherMatrix.zeroOne) + (someMatrix.threeTwo * someOtherMatrix.zeroTwo) + (someMatrix.threeThree * someOtherMatrix.zeroThree));
		someMatrix.threeOne = ((someMatrix.threeZero * someOtherMatrix.oneZero) + (someMatrix.threeOne * someOtherMatrix.oneOne) + (someMatrix.threeTwo * someOtherMatrix.oneTwo) + (someMatrix.threeThree * someOtherMatrix.oneThree));
		someMatrix.threeTwo = ((someMatrix.threeZero * someOtherMatrix.twoZero) + (someMatrix.threeOne * someOtherMatrix.twoOne) + (someMatrix.threeTwo * someOtherMatrix.twoTwo) + (someMatrix.threeThree * someOtherMatrix.twoThree));
		someMatrix.threeThree = ((someMatrix.threeZero * someOtherMatrix.threeZero) + (someMatrix.threeOne * someOtherMatrix.threeOne) + (someMatrix.threeTwo * someOtherMatrix.threeTwo) + (someMatrix.threeThree * someOtherMatrix.threeThree));*/

		return someMatrix;

	}


	vector<vector<float>> MyMatrix4x4::GetMatrix()
	{
		vector<vector<float>> NewVect =
		{
			{ zeroZero, oneZero, twoZero, threeZero },
			{ zeroOne, oneOne, twoOne, threeOne },
			{ zeroTwo, oneTwo, twoTwo, threeTwo },
			{ zeroThree, oneThree, twoThree, threeThree }
		};

		return NewVect;
	}


}