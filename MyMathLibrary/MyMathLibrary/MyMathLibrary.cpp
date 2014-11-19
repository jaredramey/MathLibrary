//MyMathLibrary.cpp
#include "MyMathLibrary.h"
#include <stdexcept>

using namespace std;

namespace MyMathLibrary
{
	//All functions for 2D & 3D Dimensional Vectors
	//Function for Dot Product
		//a_Ax & a_Ay = point 1 {x, y} || a_Bx & a_By = point 2 {x, y}
	

	

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
		//Refer to each class for it's operator overloads

	//Function for Linear Interpolation
		//Algorythm credit to http://en.wikipedia.org/wiki/Linear_interpolation
	float MyMathFunctions::LinearInterpolation(float v0, float v1, float t)
	{
		return (1-t)*v0 + t*v1;
	}

	//All functions for 3x3 & 4x4 Matrix's
	//Function for Orthographic Projection Creation
	std::vector<std::vector<float>> MyMathFunctions::OrthographicProj(float a_left, float a_right, float a_top, float a_bottom, float a_near, float a_far, std::vector<std::vector<float>>& someMatrix)
	{																							//||=============================================||
		std::vector<std::vector<float>> changeMatrix =											//||-------The Matrix in column row major -------||
		{																						//||=============================================||
			{ (2 / (a_right - a_left)), 0, 0, (((a_right + a_left) / (a_right - a_left))*-1) }, //  |(2 / (a_right - a_left)), 0, 0, 0|
			{ 0, (2 / (a_top - a_bottom)), 0, (((a_top + a_bottom) / (a_top - a_bottom))*-1) }, //  |0, (2 / (a_top - a_bottom)), 0, 0|
			{ 0, 0, (-1 / (a_far - a_near)), (a_near / (a_far - a_near)) },                     //  |0, 0, (-1 / (a_far - a_near)), 0 |
			{0, 0, 0, 1 }                                                                       //  |(((a_right + a_left) / (a_right - a_left))*-1), (((a_top + a_bottom) / (a_top - a_bottom))*-1), (a_near / (a_far - a_near))|
		};

		//multiply with already made multiplication function and then return the result
		return My4x4MatrixMultiplication(someMatrix, changeMatrix);

	}

	//Function for Scaling a [3]x[3] matrix
	std::vector<std::vector<float>> MyMathFunctions::Scale3x3Matrix(float a_xChange, float a_yChange, std::vector<std::vector<float>>& someMatrix)
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

	//function for Scaling a [4]x[4] matrix
	std::vector<std::vector<float>> MyMathFunctions::Scale4x4Matrix(float a_xChange, float a_yChange, float a_zChange , std::vector<std::vector<float>>& someMatrix)
	{
		float changeMatrix[4][4] =
		{
			{ a_xChange, 0, 0, 0 },
			{ 0, a_yChange, 0, 0 },
			{ 0, 0, a_zChange, 0 },
			{0, 0, 0, 1}
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
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
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));


		return someMatrix;
	}

	//Function for Rotating a [3]x[3] matrix
	std::vector<std::vector<float>> MyMathFunctions::Rotate3x3Matrix(std::vector<std::vector<float>>& someMatrix, float a_degreeChange)
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

	//Function for Rotating a [4]x[4] matrix
	std::vector<std::vector<float>> MyMathFunctions::Rotate4x4Matrix(std::vector<std::vector<float>>& someMatrix, float a_degreeChange)
	{
		float changeMatrix[4][4] =
		{
			{ (cos(a_degreeChange)), (sin(a_degreeChange)), 0, 0 },
			{ (asin(a_degreeChange)), (cos(a_degreeChange)), 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
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
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));

		return someMatrix;
	}

	//Function for Transform Point

	//Function for Transforming a [3]x[3] matrix
	std::vector<std::vector<float>> MyMathFunctions::Transform3x3Matrix(std::vector<std::vector<float>>& someMatrix, float a_xChange, float a_yChange)
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

	//Function for Transforming a [4]x[4] matrix
	std::vector<std::vector<float>> MyMathFunctions::Transform4x4Matrix(std::vector<std::vector<float>>& someMatrix, float a_xChange, float a_yChange, float a_zChange)
	{
		float changeMatrix[4][4] =
		{
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ a_xChange, a_yChange, a_zChange, 1 }
		};

		someMatrix[0][0] = ((someMatrix[0][0] * changeMatrix[0][0]) + (someMatrix[0][1] * changeMatrix[0][1]) + (someMatrix[0][2] * changeMatrix[0][2]) + (someMatrix[0][3] * changeMatrix[0][3]));
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
		someMatrix[3][3] = ((someMatrix[3][0] * changeMatrix[3][0]) + (someMatrix[3][1] * changeMatrix[3][1]) + (someMatrix[3][2] * changeMatrix[3][2]) + (someMatrix[3][3] * changeMatrix[3][3]));


		return someMatrix;
	}
	
	//Function for Matrix Multiplication in between a vector [3]x[1] and matrix [3]x[3]
	std::vector<float> MyMathFunctions::My2DMatrixMultiplication(std::vector<float>& someVector, std::vector<std::vector<float>>& someMatrix)
	{

		someVector[0] = ((someVector[0] * someMatrix[0][0]) + (someVector[0] * someMatrix[0][1]) + (someVector[0] * someMatrix[0][2]));
		someVector[1] = ((someVector[1] * someMatrix[1][0]) + (someVector[1] * someMatrix[1][1]) + (someVector[1] * someMatrix[1][2]));
		someVector[2] = ((someVector[2] * someMatrix[2][0]) + (someVector[2] * someMatrix[2][1]) + (someVector[2] * someMatrix[2][2]));

		return someVector;
	}

	//function for matrix multiplication between two [3]x[3] matricies
	std::vector<std::vector<float>> MyMathFunctions::My3x3MatrixMultiplication(std::vector<std::vector<float>>& someMatrix, std::vector<std::vector<float>>& someOtherMatrix)
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

	//Function for matrix multiplication between two [4]x[4] matricies
	std::vector<std::vector<float>> MyMathFunctions::My4x4MatrixMultiplication(std::vector<std::vector<float>>& someMatrix, std::vector<std::vector<float>>& someOtherMatrix)
	{
		someMatrix[0][0] = ((someMatrix[0][0] * someOtherMatrix[0][0]) + (someMatrix[0][1] * someOtherMatrix[0][1]) + (someMatrix[0][2] * someOtherMatrix[0][2]) + (someMatrix[0][3] * someOtherMatrix[0][3]));
		someMatrix[0][1] = ((someMatrix[0][0] * someOtherMatrix[1][0]) + (someMatrix[0][1] * someOtherMatrix[1][1]) + (someMatrix[0][2] * someOtherMatrix[1][2]) + (someMatrix[0][3] * someOtherMatrix[1][3]));
		someMatrix[0][2] = ((someMatrix[0][0] * someOtherMatrix[2][0]) + (someMatrix[0][1] * someOtherMatrix[2][1]) + (someMatrix[0][2] * someOtherMatrix[2][2]) + (someMatrix[0][3] * someOtherMatrix[2][3]));
		someMatrix[0][3] = ((someMatrix[0][0] * someOtherMatrix[3][0]) + (someMatrix[0][1] * someOtherMatrix[3][1]) + (someMatrix[0][2] * someOtherMatrix[3][2]) + (someMatrix[0][3] * someOtherMatrix[3][3]));
		someMatrix[1][0] = ((someMatrix[1][0] * someOtherMatrix[0][0]) + (someMatrix[1][1] * someOtherMatrix[0][1]) + (someMatrix[1][2] * someOtherMatrix[0][2]) + (someMatrix[1][3] * someOtherMatrix[0][3]));
		someMatrix[1][1] = ((someMatrix[1][0] * someOtherMatrix[1][0]) + (someMatrix[1][1] * someOtherMatrix[1][1]) + (someMatrix[1][2] * someOtherMatrix[1][2]) + (someMatrix[1][3] * someOtherMatrix[1][3]));
		someMatrix[1][2] = ((someMatrix[1][0] * someOtherMatrix[2][0]) + (someMatrix[1][1] * someOtherMatrix[2][1]) + (someMatrix[1][2] * someOtherMatrix[2][2]) + (someMatrix[1][3] * someOtherMatrix[2][3]));
		someMatrix[1][3] = ((someMatrix[1][0] * someOtherMatrix[3][0]) + (someMatrix[1][1] * someOtherMatrix[3][1]) + (someMatrix[1][2] * someOtherMatrix[3][2]) + (someMatrix[1][3] * someOtherMatrix[3][3]));
		someMatrix[2][0] = ((someMatrix[2][0] * someOtherMatrix[0][0]) + (someMatrix[2][1] * someOtherMatrix[0][1]) + (someMatrix[2][2] * someOtherMatrix[0][2]) + (someMatrix[2][3] * someOtherMatrix[0][3]));
		someMatrix[2][1] = ((someMatrix[2][0] * someOtherMatrix[1][0]) + (someMatrix[2][1] * someOtherMatrix[1][1]) + (someMatrix[2][2] * someOtherMatrix[1][2]) + (someMatrix[2][3] * someOtherMatrix[1][3]));
		someMatrix[2][2] = ((someMatrix[2][0] * someOtherMatrix[2][0]) + (someMatrix[2][1] * someOtherMatrix[2][1]) + (someMatrix[2][2] * someOtherMatrix[2][2]) + (someMatrix[2][3] * someOtherMatrix[2][3]));
		someMatrix[2][3] = ((someMatrix[2][0] * someOtherMatrix[3][0]) + (someMatrix[2][1] * someOtherMatrix[3][1]) + (someMatrix[2][2] * someOtherMatrix[3][2]) + (someMatrix[2][3] * someOtherMatrix[3][3]));
		someMatrix[3][0] = ((someMatrix[3][0] * someOtherMatrix[0][0]) + (someMatrix[3][1] * someOtherMatrix[0][1]) + (someMatrix[3][2] * someOtherMatrix[0][2]) + (someMatrix[3][3] * someOtherMatrix[0][3]));
		someMatrix[3][1] = ((someMatrix[3][0] * someOtherMatrix[1][0]) + (someMatrix[3][1] * someOtherMatrix[1][1]) + (someMatrix[3][2] * someOtherMatrix[1][2]) + (someMatrix[3][3] * someOtherMatrix[1][3]));
		someMatrix[3][2] = ((someMatrix[3][0] * someOtherMatrix[2][0]) + (someMatrix[3][1] * someOtherMatrix[2][1]) + (someMatrix[3][2] * someOtherMatrix[2][2]) + (someMatrix[3][3] * someOtherMatrix[2][3]));
		someMatrix[3][3] = ((someMatrix[3][0] * someOtherMatrix[3][0]) + (someMatrix[3][1] * someOtherMatrix[3][1]) + (someMatrix[3][2] * someOtherMatrix[3][2]) + (someMatrix[3][3] * someOtherMatrix[3][3]));

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