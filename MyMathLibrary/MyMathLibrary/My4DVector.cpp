#include "MyMathLibrary.h"

using namespace std;

namespace MyMathLibrary
{
	My4DVector::My4DVector()
	{
		
	}

	My4DVector::My4DVector(float a_x, float a_y, float a_z, float a_w)
	{
		x = a_x;
		y = a_y;
		z = a_z;
		w = a_w;
	}

	My4DVector::~My4DVector()
	{
		
	}

	//Credit for this style of construction from a hex value to Jeffrey M. Johnson
	//https://github.com/JeffreyMJohnson
	My4DVector My4DVector::ConstructFromHex(unsigned int a_hex)
	{
		My4DVector result;

		unsigned int mask = 0x000000FF;
		unsigned int color = a_hex;

		result.w = color & mask;
		color = color >> 8;
		result.z = color & mask;
		color = color >> 8;
		result.y = color & mask;
		color = color >> 8;
		result.x = color & mask;
		return result;
	
	}

	//Function to normalize a 4D Vector
	My4DVector My4DVector::Normalize4D(const My4DVector)
	{
		My4DVector temp = (*this);
		
		x = temp.x / (sqrt((temp.x * temp.x) + (temp.y * temp.y) + (temp.z * temp.z) + (temp.w * temp.w)));
		y = temp.y / (sqrt((temp.x * temp.x) + (temp.y * temp.y) + (temp.z * temp.z) + (temp.w * temp.w)));
		z = temp.z / (sqrt((temp.x * temp.x) + (temp.y * temp.y) + (temp.z * temp.z) + (temp.w * temp.w)));
		w = temp.w / (sqrt((temp.x * temp.x) + (temp.y * temp.y) + (temp.z * temp.z) + (temp.w * temp.w)));

		return temp;

	}
}