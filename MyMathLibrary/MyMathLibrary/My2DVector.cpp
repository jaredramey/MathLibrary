#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{
	My2DVector::My2DVector()
	{
		
	}

	//Constructor for operator overloading
	My2DVector::My2DVector(const float &a_X, const float &a_Y)
	{
		x = a_X;
		y = a_Y;
	}

	My2DVector::~My2DVector()
	{
		
	}

	float My2DVector::DotProduct(const My2DVector &a_2DVector)
	{
		float result = 0;
		result += ((x*a_2DVector.x) + (y*a_2DVector.y));

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
	My2DVector My2DVector::NomralizeVector(const My2DVector &a_2Dvector, float a_length)
	{
		My2DVector temp = (*this);

		x = temp.x / a_length;
		y = temp.y / a_length;

		return temp;

		/*if (a_returnType == "x" || a_returnType == "X")
		{
			resultX += (a_x / a_length);
			return resultX;
		}

		else if (a_returnType == "y" || a_returnType == "Y")
		{
			resultY += (a_y / a_length);
			return resultY;
		}

		else
		{
			cout << "ERROR 004: " << endl;
			cout << "RETURN TYPE NOT RECOGNIZED" << endl;
			system("pause");
			return 0;
		}*/
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