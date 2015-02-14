#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{
	My3DVector::My3DVector()
	{

	}

	//Constructor for operator overloading
	My3DVector::My3DVector(const float &a_X, const float &a_Y, const float &a_Z)
	{
		x = a_X;
		y = a_Y;
		z = a_Z;
	}

	My3DVector::~My3DVector()
	{

	}

	//Function for Magnitude
	float My3DVector::Magnitude(const My3DVector)
	{
		float c = 0;
		//take x and y into the equation and return c
		//figure out how to flag if the calculation is wrong
		c += (sqrt((x*x) + (y*y) + (z*z)));

		try
		{
			float tempResult = 0;

			tempResult += (sqrt((6 * 6) + (2 * 2) + (5*5)));

			if (tempResult != sqrt(65))
			{
				//throw "3011";
			}
		}
		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		catch (string errorResult)
		{
			if (errorResult == "3011")
			{
				cout << "ERROR 2011: " << endl;
				cout << "Calculation Error has occured in Magnitude(const My3DVector)->sqrt" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		return c;

	}

	float My3DVector::DotProduct(const My3DVector &a_3DVector)
	{
		float result = 0;
		//take the two vectors x's and y's and calculate the dot product
		result += ((x*a_3DVector.x) + (y*a_3DVector.y) + (z*a_3DVector.z));


		try
		{
			float tempResult = 0;

			tempResult += ((6 * 2) + (2 * 6) + (5 * 5));

			if (tempResult != 49)
			{
				//throw "3021";
			}
			//catch any error codes that might be spat out of the test and ouput the error
			//along with a quick definition of the error
			//Full documentation of error codes can be found in BuildDocumentation.txt
		}
		catch (string errorResult)
		{
			if (errorResult == "3021")
			{
				cout << "ERROR 3021: " << endl;
				cout << "Calculation Error has occured in DotProduct(const My3DVector &a_3DVector)" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		return result;


	}

	//Function for Normalization
	My3DVector My3DVector::NomralizeVector(const My3DVector)
	{
		//create a reference to the vector so it can be passed through the maginitude function
		My3DVector temp = (*this);

		x = temp.x / Magnitude(temp);
		y = temp.y / Magnitude(temp);
		z = temp.z / Magnitude(temp);

		//Quickly test to see if the calculations preformed are running how they should be and
		//if they aren't then throw out an error code
		try
		{
			My3DVector MytestVec = My3DVector(6, 2, 5);
			MytestVec.x = (MytestVec.x / Magnitude(MytestVec));
			MytestVec.y = (MytestVec.y / Magnitude(MytestVec));
			MytestVec.z = (MytestVec.z / Magnitude(MytestVec));
			//Math is hardcoded into the if statement so it won't rely on going through the Magnitude function 
			//just in case that function isn't working for some odd reason.
			if (MytestVec.x != (6 / (sqrt((6 * 6) + (2 * 2) + (5 * 5)))))
			{
				//throw "3031";
			}

			if (MytestVec.y != (2 / (sqrt((6 * 6) + (2 * 2) + (5 * 5)))))
			{
				//throw "3032";
			}

			if (MytestVec.z != (5 / (sqrt((6 * 6) + (2 * 2) + (5 * 5)))))
			{
				//throw "3033";
			}
		}
		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		catch (string errorResult)
		{
			if (errorResult == "3031")
			{
				cout << "ERROR 3031: " << endl;
				cout << "Calculation Error has occured in NormalizeVector(const My3DVector)->Normalize X" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}

			else if (errorResult == "3032")
			{
				cout << "ERROR 3032: " << endl;
				cout << "Calculation Error has occured in NormalizeVector(const My3DVector)->Normalize Y" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}

			else if (errorResult == "3033")
			{
				cout << "ERROR 3033: " << endl;
				cout << "Calculation Error has occured in NormalizeVector(const My3DVector)->Normalize Z" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		//if the quick test goes through without a problem then return the normalized vector
		return temp;
	}


	//Function for Cross Product
	//a_Ax, a_Ay & a_Az = point 1 {x, y, z} || a_Bx, a_By, a_Bz = point 2 {x, y, z}
	float My3DVector::CrossProduct(const My3DVector &a_3DVector)
	{
		//Original cross product
		/*float resultX = 0;
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
		}*/

		//new cross product
		My3DVector temp = (*this);

		
		float result = ((y*a_3DVector.z) + (z*a_3DVector.x) + (x*a_3DVector.y) - (x*a_3DVector.z) - (z*a_3DVector.y) - (y*a_3DVector.x));

		try
		{
			float tempResultX = 0;
			float tempResultY = 0;
			float tempResultZ = 0;

			float tempX = 6;
			float tempY = 2;
			float tempZ = 5;

			float tempX2 = 6;
			float tempY2 = 2;
			float tempZ2 = 5;

			tempResultX += ((tempY * tempZ2) - (tempZ * tempY2));
			tempResultY += ((tempZ * tempX2) - (tempX * tempZ2));
			tempResultZ += ((tempX * tempY2) - (tempY * tempX2));

			if (tempResultX != 0)
			{
				//throw "3041";
			}

			if (tempResultY != 0)
			{
				//throw "3042";
			}

			if (tempResultZ != 0)
			{
				//throw "3043";
			}
		}
		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		catch (string errorResult)
		{
			if (errorResult == "3041")
			{
				cout << "ERROR 3041: " << endl;
				cout << "Calculation Error has occured in CrossProduct(const My3DVector &a_3DVector)->x" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}

			else if (errorResult == "3042")
			{
				cout << "ERROR 3042: " << endl;
				cout << "Calculation Error has occured in CrossProduct(const My3DVector &a_3DVector)->y" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}

			else if (errorResult == "3043")
			{
				cout << "ERROR 3043: " << endl;
				cout << "Calculation Error has occured in CrossProduct(const My3DVector &a_3DVector)->z" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		return result;

	}


	vector<float> My3DVector::GetVect()
	{
		vector<float> NewVect =
		{
			{ x, y, z }
		};

		return NewVect;

	}


	//Time to do some operator overloading
	My3DVector My3DVector::operator + (const My3DVector &a_plus)
	{
		My3DVector temp = (*this);

		temp.x + a_plus.x;
		temp.y + a_plus.y;
		temp.z + a_plus.z;

		return temp;
	}

	My3DVector My3DVector::operator += (const My3DVector &a_plusEquals)
	{
		My3DVector temp = (*this);

		temp.x += a_plusEquals.x;
		temp.y += a_plusEquals.y;
		temp.z += a_plusEquals.z;

		return temp;
	}

	My3DVector My3DVector::operator - (const My3DVector &a_minus)
	{
		My3DVector temp = (*this);

		temp.x - a_minus.x;
		temp.y - a_minus.y;
		temp.z - a_minus.z;

		return temp;
	}

	My3DVector My3DVector::operator -= (const My3DVector &a_minusEquals)
	{
		My3DVector temp = (*this);

		temp.x -= a_minusEquals.x;
		temp.y -= a_minusEquals.y;
		temp.z -= a_minusEquals.z;

		return temp;
	}

	My3DVector My3DVector::operator * (const My3DVector &a_times)
	{
		My3DVector temp = (*this);

		temp.x * a_times.x;
		temp.y * a_times.y;
		temp.z * a_times.z;

		return temp;
	}

	My3DVector My3DVector::operator *= (const My3DVector &a_timesEquals)
	{
		My3DVector temp = (*this);

		temp.x * a_timesEquals.x;
		temp.y * a_timesEquals.y;
		temp.z * a_timesEquals.z;

		return temp;
	}

	My3DVector My3DVector::operator / (const My3DVector &a_devided)
	{
		My3DVector temp = (*this);

		temp.x / a_devided.x;
		temp.y / a_devided.y;
		temp.z / a_devided.z;

		return temp;
	}

	My3DVector My3DVector::operator /= (const My3DVector &a_devidedEquals)
	{
		My3DVector temp = (*this);

		temp.x /= a_devidedEquals.x;
		temp.y /= a_devidedEquals.y;
		temp.z /= a_devidedEquals.z;

		return temp;
	}

	My3DVector My3DVector::operator = (const My3DVector &a_equals)
	{
		if (this == &a_equals)
		{
			return *this;
		}

		x = a_equals.x;
		y = a_equals.y;
		z = a_equals.z;

		return *this;
	}

	bool My3DVector::operator == (const My3DVector &a_equalsEquals)
	{
		if (x == a_equalsEquals.x && y == a_equalsEquals.y && z == a_equalsEquals.z)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}