//MyBasicMath.cpp
#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{

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


	//Function for Bitwise Operations
}