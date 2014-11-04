//MyMathLibrary.h
//By: Jared Ramey || Started: 11/4/14

namespace MyMathLibrary
{
	class MyMathFunctions
	{
	public:
	//All functions for 2D & 3D Dimensional Vectors
		//Function for Dot Product
		float DotProduct(float a_Ax, float a_Ay, float a_Bx, float a_By);
		//Function for Normalization

		//Function for Cross Product
		float CrossProduct(string a_returnType, float a_Ax, float a_Ay, float a_Az, float a_Bx, float a_By, float a_Bz);
		//Function for Magnitude
		float Magnitude(float a_A, float a_B);
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
		int DegreeRadianConversion(int a_type, float a_numToConvert);
		//Function for Testing Scalar Value for Power of Two

		//Function for Bitwise Operations

	};
}