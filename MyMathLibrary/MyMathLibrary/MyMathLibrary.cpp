//MyMathLibrary.cpp
#include "MyMathLibrary.h"
#include <stdexcept>
#include <iostream>

using namespace std;

namespace MyMathLibrary
{
	//All functions for 2D & 3D Dimensional Vectors
	//Function for Dot Product
		//a_Ax & a_Ay = point 1 {x, y} || a_Bx & a_By = point 2 {x, y}
	float MyMathLibrary::DotProduct(float a_Ax, float a_Ay, float a_Bx, float a_By)
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

	//Function for Cross Product
		//a_Ax, a_Ay & a_Az = point 1 {x, y, z} || a_Bx, a_By, a_Bz = point 2 {x, y, z}
	float MyMathLibrary::CrossProduct(string a_returnType,float a_Ax, float a_Ay, float a_Az, float a_Bx, float a_By, float a_Bz)
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
	float MyMathLibrary::Magnitude(float a_A, float a_B)
	{
		float c = 0;
		c += (sqrt((a_A*a_A)+(a_B*a_B)));

		return c;
	}
	//Function for Operator Overloading

	//Function for Linear Interpolation


	//All functions for 3x3 & 4x4 Matrix's
	//Function for Orthographic Projection Creation

	//Function for Scale

	//Function for Create Rotation

	//Function for Tranform Point

	//Function for Transform Vector

	//Function for Matrix Multiplication


	//All functions for Vector 4
	//Function for Normilization

	//Function for Contruction from Hexadecimal Color Value


	//All functions for common math Functionality
	//Function for Linear Interpolation for Scalar Values

	//Function for Conversion Between degrees and Radians
		//If 0 is returned then something went wrong with conversion
		//a_type: 1 = Degrees -> Radians || 2 = Radians -> Degrees
	int MyMathLibrary::DegreeRadianConversion(int a_type, float a_numToConvert)
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