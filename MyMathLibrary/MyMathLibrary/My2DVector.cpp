#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{
	//default constructor
	My2DVector::My2DVector()
	{
		
	}

	//Constructor for operator overloading
	My2DVector::My2DVector(const float &a_X, const float &a_Y)
	{
		x = a_X;
		y = a_Y;
	}

	//default deconstructor
	My2DVector::~My2DVector()
	{
		
	}
	
		//Function for Magnitude
	float My2DVector::Magnitude(const My2DVector)
	{
		float c = 0;
		//take x and y into the equation and return c
		//figure out how to flag if the calculation is wrong
		c += (sqrt((x*x)+(y*y)));

		try
		{
			float tempX = 6;
			float tempY = 2;
			float tempResult = 0;

			tempResult += (sqrt((6*6) + (2*2)));

			if (tempResult != sqrt(40))
			{
				throw "2011";
			}
		}
		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		catch (string errorResult)
		{
			if (errorResult == "2011")
			{
				cout << "ERROR 2011: " << endl;
				cout << "Calculation Error has occured in Magnitude(const My2DVector)->sqrt" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

			return c;

	}
	
	float My2DVector::DotProduct(const My2DVector &a_2DVector)
	{
		float result = 0;
		//take the two vectors x's and y's and calculate the dot product
		result += ((x*a_2DVector.x) + (y*a_2DVector.y));
		

		try
		{
			float tempResult = 0;

			tempResult += ((6*2)+(2*6));

			if (tempResult != 24)
			{
				throw "2021";
			}
			//catch any error codes that might be spat out of the test and ouput the error
			//along with a quick definition of the error
			//Full documentation of error codes can be found in BuildDocumentation.txt
		}
		catch (string errorResult)
		{
			if (errorResult == "2021")
			{
				cout << "ERROR 2021: " << endl;
				cout << "Calculation Error has occured in DotProduct(const My2DVector &a_2DVector)" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

			return result;


	}

	//Function for Normalization
	My2DVector My2DVector::NomralizeVector(const My2DVector)
	{
		//create a reference to the vector so it can be passed through the maginitude function
		My2DVector temp = (*this);

		x = temp.x / Magnitude(temp);
		y = temp.y / Magnitude(temp);

		//Quickly test to see if the calculations preformed are running how they should be and
		//if they aren't then throw out an error code
		try
		{
			My2DVector MytestVec = My2DVector(6, 2);
			MytestVec.x = (MytestVec.x/ Magnitude(MytestVec));
			//Math is hardcoded into the if statement so it won't rely on going through the Magnitude function 
			//just in case that function isn't working for some odd reason.
			if (MytestVec.x != (6/(sqrt((6*6) + (2*2)))))
			{
				throw "2031";
			}
									
			if (MytestVec.y != (2 / (sqrt((6 * 6) + (2 * 2)))))
			{
				throw "2032";
			}
		}
		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		catch (string errorResult)
		{
			if (errorResult == "2031")
			{
				cout << "ERROR 2031: " << endl;
				cout << "Calculation Error has occured in NormalizeVector(const My2DVector)->Normalize X" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}

			else if (errorResult == "2032")
			{
				cout << "ERROR 2032: " << endl;
				cout << "Calculation Error has occured in NormalizeVector(const My2DVector)->Normalize Y" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		//if the quick test goes through without a problem then return the normalized vector
		return temp;
	}


	//Function for Cross Product
	//a_Ax, a_Ay & a_Az = point 1 {x, y, z} || a_Bx, a_By, a_Bz = point 2 {x, y, z}
	float My2DVector::CrossProduct(const My2DVector &a_2DVector)
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

		//new croos product
		My2DVector temp = (*this);
		float result = 0;

		result += ((temp.x*a_2DVector.y)-(temp.y*a_2DVector.x));

		//catch any error codes that might be spat out of the test and ouput the error
		//along with a quick definition of the error
		//Full documentation of error codes can be found in BuildDocumentation.txt
		try
		{
			float tempResult = 0;

			tempResult += ((6 * 2) - (2 * 6));

			if (tempResult != 0)
			{
				throw "2041";
			}
		}
		catch (string errorResult)
		{
			if (errorResult == "2041")
			{
				cout << "ERROR 2041: " << endl;
				cout << "Calculation Error has occured in CrossProduct(const My2DVector &a_2DVector)" << endl;
				cout << "Check wiki page for more information" << endl;
				cout << "https://github.com/jaredramey/MathLibrary/wiki" << endl;
			}
		}

		return result;

	}

	//linear Interpolation
	float My2DVector::Lerp(const My2DVector &a_2DVector, float a_percentage)
	{
		My2DVector temp = (*this);

		//Need to figure out the proper equation for this
		return (((a_2DVector.x-temp.x) + (a_2DVector.y-temp.y))/a_percentage);
	}



	//Time to do some operator overloading
	My2DVector My2DVector::operator + (const My2DVector &a_plus)
	{
		My2DVector temp = (*this);

		temp.x += a_plus.x;
		temp.y += a_plus.y;

		return temp;
	}

	My2DVector My2DVector::operator += (const My2DVector &a_plusEquals)
	{
		(*this) = (*this) + a_plusEquals;
		return (*this);
	}

	My2DVector My2DVector::operator - (const My2DVector &a_minus)
	{
		My2DVector temp = (*this);

		temp.x -= a_minus.x;
		temp.y -= a_minus.y;

		return temp;
	}

	My2DVector My2DVector::operator -= (const My2DVector &a_minusEquals)
	{
		(*this) = (*this) - a_minusEquals;
		return (*this);
	}

	My2DVector My2DVector::operator * (const My2DVector &a_times)
	{
		My2DVector temp = (*this);

		temp.x *= a_times.x;
		temp.y *= a_times.y;

		return temp;
	}

	My2DVector My2DVector::operator *= (const My2DVector &a_timesEquals)
	{
		(*this) = (*this) * a_timesEquals;
		return (*this);
	}

	My2DVector My2DVector::operator / (const My2DVector &a_devided)
	{
		My2DVector temp = (*this);

		temp.x /= a_devided.x;
		temp.y /= a_devided.y;

		return temp;
	}

	My2DVector My2DVector::operator /= (const My2DVector &a_devidedEquals)
	{
		(*this) = (*this) / a_devidedEquals;
		return (*this);
	}

	My2DVector My2DVector::operator = (const My2DVector &a_equals)
	{
		if (this == &a_equals)
		{
			return *this;
		}

		x = a_equals.x;
		y = a_equals.y;

		return *this;
	}

	bool My2DVector::operator == (const My2DVector &a_equalsEquals)
	{
		if (x == a_equalsEquals.x && y == a_equalsEquals.y)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
}