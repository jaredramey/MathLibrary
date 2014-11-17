//MyMathLibrary.cpp
#include "MyMathLibrary.h"
#include <stdexcept>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

namespace MyMathLibrary
{
	//All functions for 2D & 3D Dimensional Vectors
	//Function for Dot Product
		//a_Ax & a_Ay = point 1 {x, y} || a_Bx & a_By = point 2 {x, y}
	float MyMathFunctions::DotProduct(float a_Ax, float a_Ay, float a_Bx, float a_By)
	{
		float result = 0;
		result += ((a_Ax*a_Bx) + (a_Ay*a_By));
		if (result != 0)
		{
			return result;
		}

		else
		{
			cout << "ERROR 002" << endl;
			cout << "THE FUNCTION HAS ENCOUNTERED AN UNKOWN ISSUE" << endl;
			system("pause");
			return result;
		}
	}
	//Function for Normalization
	float MyMathFunctions::NomralizeVector(string a_returnType, float a_x, float a_y, float a_length)
	{
		float resultX = 0;
		float resultY = 0;

		if (a_returnType == "x" || a_returnType == "X")
		{
			resultX += (a_x/a_length);
			return resultX;
		}

		else if (a_returnType == "y" || a_returnType == "Y")
		{
			resultY += (a_y/a_length);
			return resultY;
		}

		else
		{
			cout << "ERROR 004: " << endl;
			cout << "RETURN TYPE NOT RECOGNIZED" << endl;
			system("pause");
			return 0;
		}
	}
	//Function for Cross Product
		//a_Ax, a_Ay & a_Az = point 1 {x, y, z} || a_Bx, a_By, a_Bz = point 2 {x, y, z}
	float MyMathFunctions::CrossProduct(string a_returnType, float a_Ax, float a_Ay, float a_Az, float a_Bx, float a_By, float a_Bz)
	{
		float resultX = 0;
		float resultY = 0;
		float resultZ = 0;

		if (a_returnType == "x" || a_returnType == "X")
		{
			resultX += (((a_Ay*a_Bz) - (a_Az*a_By)));
			return resultX;
		}
		
		else if (a_returnType == "y" || a_returnType == "Y")
		{
			resultY += (((a_Az*a_Bx) - (a_Ax*a_Bz)));
			return resultY;
		}

		else if (a_returnType == "z" || a_returnType == "Z")
		{
			resultZ += (((a_Ax*a_By) - (a_Ay*a_Bx)));
			return resultZ;
		}
		
		else
		{
			cout << "ERROR 003: " << endl;
			cout << "RETURN TYPE NOT RECOGNIZED" << endl;
			system("pause");
			return 0;
		}
		
	}
	//Function for Magnitude
	float MyMathFunctions::Magnitude(float a_A, float a_B)
	{
		float c = 0;
		c += (sqrt((a_A*a_A)+(a_B*a_B)));

		if (c != 0)
		{
			return c;
		}

		else
		{
			cout << "ERROR 005: " << endl;
			cout << "CALCULATION HAS RETURNED NULL" << endl;
			system("pause");
			return 0;
		}
	}
	//Function for Operator Overloading

	//Function for Linear Interpolation


	//All functions for 3x3 & 4x4 Matrix's
	//Function for Orthographic Projection Creation

	//Function for Scale
	vector<vector<float>> MyMathFunctions::Scale2DVector(float a_xChange, float a_yChange, vector<vector<float>>& someMatrix)
	{
		float changeMatrix[3][3] =
		{
			{ a_xChange, 0, 0 },
			{ 0, a_yChange, 0 },
			{ 0, 0, 1 }
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));


		return someMatrix;
	}

	//Function for Rotation
	vector<vector<float>> MyMathFunctions::Rotate2DVector(vector<vector<float>>& someMatrix, float a_degreeChange)
	{
		float changeMatrix[3][3] =
		{
			{ (cos(a_degreeChange)), (sin(a_degreeChange)), 0 },
			{ (asin(a_degreeChange)), (cos(a_degreeChange)), 0 },
			{ 0, 0, 1 }
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));

		return someMatrix;
	}

	//Function for Transform Point

	//Function for Transform Vector
	vector<vector<float>> MyMathFunctions::Transform2DVector(vector<vector<float>>& someMatrix, float a_xChange, float a_yChange)
	{
		//Matrix for translating a 2D vector
		float changeMatrix[3][3] = 
		{
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ a_xChange, a_yChange, 1 } 
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * changeMatrix[1][0]) + (someMatrix[0][1] * changeMatrix[1][1]) + (someMatrix[0][2] * changeMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * changeMatrix[2][0]) + (someMatrix[0][1] * changeMatrix[2][1]) + (someMatrix[0][2] * changeMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * changeMatrix[0][0]) + (someMatrix[1][1] * changeMatrix[0][1]) + (someMatrix[1][2] * changeMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * changeMatrix[1][0]) + (someMatrix[1][1] * changeMatrix[1][1]) + (someMatrix[1][2] * changeMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * changeMatrix[2][0]) + (someMatrix[1][1] * changeMatrix[2][1]) + (someMatrix[1][2] * changeMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * changeMatrix[0][0]) + (someMatrix[2][1] * changeMatrix[0][1]) + (someMatrix[2][2] * changeMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * changeMatrix[1][0]) + (someMatrix[2][1] * changeMatrix[1][1]) + (someMatrix[2][2] * changeMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * changeMatrix[2][0]) + (someMatrix[2][1] * changeMatrix[2][1]) + (someMatrix[2][2] * changeMatrix[2][2]));

		return someMatrix;
	}

	//Function for Matrix Multiplication in between a vector and matrix
	vector<float> MyMathFunctions::My2DMatrixMultiplication(vector<float>& someVector, vector<vector<float>>& someMatrix)
	{

		someVector[0] = ((someVector[0] * someMatrix[0][0]) + (someVector[0] * someMatrix[0][1]) + (someVector[0] * someMatrix[0][2]));
		someVector[1] = ((someVector[1] * someMatrix[1][0]) + (someVector[1] * someMatrix[1][1]) + (someVector[1] * someMatrix[1][2]));
		someVector[2] = ((someVector[2] * someMatrix[2][0]) + (someVector[2] * someMatrix[2][1]) + (someVector[2] * someMatrix[2][2]));

		return someVector;
	}

	//function for matrix multiplication between two matricies
	vector<vector<float>> MyMathFunctions::MyMatrixMultiplication(vector<vector<float>>& someMatrix, vector<vector<float>>& someOtherMatrix)
	{

		someMatrix[0][0] = ((someMatrix[0][0] * someOtherMatrix[0][0]) + (someMatrix[0][1] * someOtherMatrix[0][1]) + (someMatrix[0][2] * someOtherMatrix[0][2]));
		someMatrix[0][1] = ((someMatrix[0][0] * someOtherMatrix[1][0]) + (someMatrix[0][1] * someOtherMatrix[1][1]) + (someMatrix[0][2] * someOtherMatrix[1][2]));
		someMatrix[0][2] = ((someMatrix[0][0] * someOtherMatrix[2][0]) + (someMatrix[0][1] * someOtherMatrix[2][1]) + (someMatrix[0][2] * someOtherMatrix[2][2]));
		someMatrix[1][0] = ((someMatrix[1][0] * someOtherMatrix[0][0]) + (someMatrix[1][1] * someOtherMatrix[0][1]) + (someMatrix[1][2] * someOtherMatrix[0][2]));
		someMatrix[1][1] = ((someMatrix[1][0] * someOtherMatrix[1][0]) + (someMatrix[1][1] * someOtherMatrix[1][1]) + (someMatrix[1][2] * someOtherMatrix[1][2]));
		someMatrix[1][2] = ((someMatrix[1][0] * someOtherMatrix[2][0]) + (someMatrix[1][1] * someOtherMatrix[2][1]) + (someMatrix[1][2] * someOtherMatrix[2][2]));
		someMatrix[2][0] = ((someMatrix[2][0] * someOtherMatrix[0][0]) + (someMatrix[2][1] * someOtherMatrix[0][1]) + (someMatrix[2][2] * someOtherMatrix[0][2]));
		someMatrix[2][1] = ((someMatrix[2][0] * someOtherMatrix[1][0]) + (someMatrix[2][1] * someOtherMatrix[1][1]) + (someMatrix[2][2] * someOtherMatrix[1][2]));
		someMatrix[2][2] = ((someMatrix[2][0] * someOtherMatrix[2][0]) + (someMatrix[2][1] * someOtherMatrix[2][1]) + (someMatrix[2][2] * someOtherMatrix[2][2]));

		return someMatrix;
	}


	//All functions for Vector 4
	//Function for Normilization

	//Function for Construction from Hexadecimal Color Value


	//All functions for common math Functionality
	//Function for Linear Interpolation for Scalar Values

	//Function for Conversion Between degrees and Radians
		//If 0 is returned then something went wrong with conversion
		//a_type: 1 = Degrees -> Radians || 2 = Radians -> Degrees
	int MyMathFunctions::DegreeRadianConversion(int a_type, float a_numToConvert)
	{
		int result = 0;

		if (a_type == 1)
		{
			result = ((a_numToConvert/180)*3.14);
			return result;
		}

		else if (a_type == 2)
		{
			result = ((a_numToConvert/3.14)*180);
			return result;
		}

		else
		{
			cout << "ERROR 001: " << endl;
			cout << "CONVERSION TYPE NOT RECOGNIZED" << endl;
			system("pause");
			return result;
		}
	}
	//Function for Testing Scalar Value for Power of Two

	//Function for Bitwise Operations

}