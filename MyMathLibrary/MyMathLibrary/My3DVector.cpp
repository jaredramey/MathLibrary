#include "MyMathLibrary.h"

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

	//Time to do some operator overloading
	My3DVector My3DVector::operator + (const My3DVector &a_plus)
	{
		My3DVector temp = (*this);

		temp.x += a_plus.x;
		temp.y += a_plus.y;
		temp.z += a_plus.z;

		return temp;
	}

	My3DVector My3DVector::operator += (const My3DVector &a_plusEquals)
	{
		(*this) = (*this) + a_plusEquals;
		return (*this);
	}

	My3DVector My3DVector::operator - (const My3DVector &a_minus)
	{
		My3DVector temp = (*this);

		temp.x -= a_minus.x;
		temp.y -= a_minus.y;
		temp.z -= a_minus.z;

		return temp;
	}

	My3DVector My3DVector::operator -= (const My3DVector &a_minusEquals)
	{
		(*this) = (*this) - a_minusEquals;
		return (*this);
	}

	My3DVector My3DVector::operator * (const My3DVector &a_times)
	{
		My3DVector temp = (*this);

		temp.x *= a_times.x;
		temp.y *= a_times.y;
		temp.z *= a_times.z;

		return temp;
	}

	My3DVector My3DVector::operator *= (const My3DVector &a_timesEquals)
	{
		(*this) = (*this) * a_timesEquals;
		return (*this);
	}

	My3DVector My3DVector::operator / (const My3DVector &a_devided)
	{
		My3DVector temp = (*this);

		temp.x /= a_devided.x;
		temp.y /= a_devided.y;
		temp.z /= a_devided.z;

		return temp;
	}

	My3DVector My3DVector::operator /= (const My3DVector &a_devidedEquals)
	{
		(*this) = (*this) / a_devidedEquals;
		return (*this);
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