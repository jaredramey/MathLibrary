//MyBasicMath.cpp
#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{

	//Function for Linear Interpolation
	//Algorithm credit to http://en.wikipedia.org/wiki/Linear_interpolation
	float MyBasicMath::LinearInterpolation(float v0, float v1, float t)
	{
		return (1 - t)*v0 + t*v1;
	}

	//Function for Conversion Between degrees and Radians
	//If 0 is returned then something went wrong with conversion
	//a_type: 1 = Degrees -> Radians || 2 = Radians -> Degrees
	int MyBasicMath::DegreeRadianConversion(int a_type, float a_numToConvert)
	{
		int result = 0;

		if (a_type == 1)
		{
			result = ((a_numToConvert / 180)*3.14);
			return result;
		}

		else if (a_type == 2)
		{
			result = ((a_numToConvert / 3.14) * 180);
			return result;
		}
	}
	//Function for Testing Scalar Value for Power of Two
	bool MyBasicMath::IsPowerOfTwo(unsigned int num)
	{
		while (((num % 2) == 0) && num > 1)
		{
			num /= 2;
		}

		if (num == 0)
		{
			return true;
		}

		else
		{
			return false;
		}
	}

}