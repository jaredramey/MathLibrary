//MyMatrix3x3.cpp
#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{
	MyMatrix3x3::MyMatrix3x3()
	{

	}

	MyMatrix3x3::MyMatrix3x3(vector<vector<float>>& a_matrix)
	{
		zeroZero = a_matrix[0][0];
		zeroOne = a_matrix[0][1];
		zeroTwo = a_matrix[0][2];
		oneZero = a_matrix[1][0];
		oneOne = a_matrix[1][1];
		oneTwo = a_matrix[1][2];
		twoZero = a_matrix[2][0];
		twoOne = a_matrix[2][1];
		twoTwo = a_matrix[2][2];
	}

	MyMatrix3x3::~MyMatrix3x3()
	{

	}



	//Function for Scaling a [3]x[3] matrix
	MyMatrix3x3 MyMatrix3x3::Scale3x3Matrix(float a_xChange, float a_yChange, MyMatrix3x3& someMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ a_xChange, 0, 0 },
			{ 0, a_yChange, 0 },
			{ 0, 0, 1 }
		};

		MyMatrix3x3 testMatrix = MyMatrix3x3(changeMatrix);

		My3x3MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));*/


		return someMatrix;
	}

	//Function for Rotating a [3]x[3] matrix
	MyMatrix3x3 MyMatrix3x3::Rotate3x3MatrixZ(MyMatrix3x3& someMatrix, float a_degreeChange)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(a_degreeChange)), (sin(a_degreeChange)), 0 },
			{ (asin(a_degreeChange)), (cos(a_degreeChange)), 0 },
			{ 0, 0, 1 }
		};

		MyMatrix3x3 testMatrix = MyMatrix3x3(changeMatrix);

		My3x3MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));*/

		return someMatrix;
	}

	MyMatrix3x3 MyMatrix3x3::Rotate3x3MatrixY(MyMatrix3x3& someMatrix, float a_degreeChange)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(a_degreeChange)), 0, (sin(a_degreeChange)) },
			{ 0, 1, 0 },
			{ (asin(a_degreeChange)), 0, (cos(a_degreeChange)) }
		};

		MyMatrix3x3 testMatrix = MyMatrix3x3(changeMatrix);

		My3x3MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));*/

		return someMatrix;
	}

	MyMatrix3x3 MyMatrix3x3::Rotate3x3MatrixX(MyMatrix3x3& someMatrix, float a_degreeChange)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0 },
			{ 0, (cos(a_degreeChange)), (asin(a_degreeChange)) },
			{ 0, (sin(a_degreeChange)), (cos(a_degreeChange)) }

		};

		MyMatrix3x3 testMatrix = MyMatrix3x3(changeMatrix);

		My3x3MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));*/

		return someMatrix;
	}

	//Function for Transforming a [3]x[3] matrix
	MyMatrix3x3 MyMatrix3x3::Transform3x3Matrix(MyMatrix3x3& someMatrix, float a_xChange, float a_yChange)
	{
		//Matrix for translating a 2D vector
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ a_xChange, a_yChange, 1 }
		};

		MyMatrix3x3 testMatrix = MyMatrix3x3(changeMatrix);

		My3x3MatrixMultiplication(someMatrix, testMatrix);

		/*someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));*/

		return someMatrix;
	}

	//function for matrix multiplication between two [3]x[3] matricies
	MyMatrix3x3 MyMatrix3x3::My3x3MatrixMultiplication(MyMatrix3x3 someMatrix, MyMatrix3x3 someOtherMatrix)
	{
		//New Multiplication																																			/*First Row*/
		zeroZero = ((someMatrix.zeroZero*someOtherMatrix.zeroZero) + (someMatrix.zeroOne*someOtherMatrix.oneZero) + (someMatrix.zeroTwo*someOtherMatrix.twoZero));	//	{x, x, x}
		zeroOne = ((someMatrix.zeroZero*someOtherMatrix.oneZero) + (someMatrix.zeroOne*someOtherMatrix.oneOne) + (someMatrix.zeroTwo*someOtherMatrix.twoOne));		//	{O, O, O}
		zeroTwo = ((someMatrix.zeroZero*someOtherMatrix.twoZero) + (someMatrix.zeroOne*someOtherMatrix.oneTwo) + (someMatrix.zeroTwo*someOtherMatrix.twoTwo));		//	{O, O, O}
																																											/*Second Row*/
		oneZero = ((someMatrix.oneZero*someOtherMatrix.zeroZero) + (someMatrix.oneOne*someOtherMatrix.zeroOne) + (someMatrix.oneTwo*someOtherMatrix.zeroTwo));		//		{O, O, O}
		oneOne = ((someMatrix.oneZero*someOtherMatrix.oneZero) + (someMatrix.oneOne*someOtherMatrix.oneOne) + (someMatrix.oneTwo*someOtherMatrix.oneTwo));			//		{x, x, x}
		oneTwo = ((someMatrix.oneZero*someOtherMatrix.twoZero) + (someMatrix.oneOne*someMatrix.twoOne) + (someMatrix.oneTwo*someOtherMatrix.twoTwo));				//		{O, O, O}
																																												/*Third Row*/
		twoZero = ((someMatrix.twoZero*someOtherMatrix.zeroZero) + (someMatrix.twoOne*someOtherMatrix.zeroOne) + (someMatrix.twoTwo*someOtherMatrix.zeroTwo));		//			{O, O, O}
		twoOne = ((someMatrix.twoZero*someOtherMatrix.oneZero) + (someMatrix.twoOne*someOtherMatrix.oneOne) + (someMatrix.twoTwo*someOtherMatrix.oneTwo));			//			{O, O, O}
		twoTwo = ((someMatrix.twoZero*someOtherMatrix.twoZero) + (someMatrix.twoOne*someOtherMatrix.twoOne) + (someMatrix.twoTwo*someOtherMatrix.twoTwo));			//			{x, x, x}

		//Old Multiplication (changed on 12/9/14)
		/*someMatrix.zeroZero = ((someMatrix.zeroZero * someOtherMatrix.zeroZero) + (someMatrix.zeroOne * someOtherMatrix.zeroOne) + (someMatrix.zeroTwo * someOtherMatrix.zeroTwo));
		someMatrix.zeroOne = ((someMatrix.zeroZero * someOtherMatrix.oneZero) + (someMatrix.zeroOne * someOtherMatrix.oneOne) + (someMatrix.zeroTwo * someOtherMatrix.oneTwo));
		someMatrix.zeroTwo = ((someMatrix.zeroZero * someOtherMatrix.twoZero) + (someMatrix.zeroOne * someOtherMatrix.twoOne) + (someMatrix.zeroTwo * someOtherMatrix.twoTwo));
		someMatrix.oneZero = ((someMatrix.zeroZero * someOtherMatrix.zeroZero) + (someMatrix.oneOne * someOtherMatrix.zeroOne) + (someMatrix.oneTwo * someOtherMatrix.zeroTwo));
		someMatrix.oneOne = ((someMatrix.oneZero * someOtherMatrix.oneZero) + (someMatrix.oneOne * someOtherMatrix.oneOne) + (someMatrix.oneTwo * someOtherMatrix.oneTwo));
		someMatrix.oneTwo = ((someMatrix.oneZero * someOtherMatrix.twoZero) + (someMatrix.oneOne * someOtherMatrix.twoOne) + (someMatrix.oneTwo * someOtherMatrix.twoTwo));
		someMatrix.twoZero = ((someMatrix.oneZero * someOtherMatrix.zeroZero) + (someMatrix.twoOne * someOtherMatrix.zeroOne) + (someMatrix.twoTwo * someOtherMatrix.zeroTwo));
		someMatrix.twoOne = ((someMatrix.twoZero * someOtherMatrix.oneZero) + (someMatrix.twoOne * someOtherMatrix.oneOne) + (someMatrix.twoTwo * someOtherMatrix.oneTwo));
		someMatrix.twoTwo = ((someMatrix.twoZero * someOtherMatrix.twoZero) + (someMatrix.twoOne * someOtherMatrix.twoOne) + (someMatrix.twoTwo * someOtherMatrix.twoTwo));*/

		return someMatrix;
	}

	//Function for Matrix Multiplication in between a vector [3]x[1] and matrix [3]x[3]
	std::vector<float> MyMatrix3x3::My2DMatrixMultiplication(std::vector<float>& someVector, MyMatrix3x3& someMatrix)
	{

		someVector[0] = ((someVector[0] * someMatrix.zeroZero) + (someVector[0] * someMatrix.zeroOne) + (someVector[0] * someMatrix.zeroTwo));
		someVector[1] = ((someVector[1] * someMatrix.oneZero) + (someVector[1] * someMatrix.oneOne) + (someVector[1] * someMatrix.oneTwo));
		someVector[2] = ((someVector[2] * someMatrix.twoZero) + (someVector[2] * someMatrix.twoOne) + (someVector[2] * someMatrix.twoTwo));

		return someVector;
	}

	vector<vector<float>> MyMatrix3x3::GetMatrix()
	{
		vector<vector<float>> NewVect = 
		{
			{zeroZero, oneZero, twoZero},
			{zeroOne, oneOne, twoOne},
			{zeroTwo, oneTwo, twoTwo}
		};

		return NewVect;
	}

}