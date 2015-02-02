#include "stdafx.h"
#include <iostream>

#include "MyMathLibrary.h"
#include "gtest\gtest.h"

using namespace std;

MyMathLibrary::MyBasicMath BasicMath;
MyMathLibrary::My2DVector Vector2D;
MyMathLibrary::My3DVector Vector3D;
MyMathLibrary::My4DVector Vector4D;
MyMathLibrary::MyMatrix3x3 Matrix3;
MyMathLibrary::MyMatrix4x4 Matrix4;

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

TEST(Basic_Math_Test, Expected_Result)
{
	EXPECT_EQ(BasicMath.DegreeRadianConversion(1, 30), 0);
}

TEST(Vector2_test, Magnitude)
{
	MyMathLibrary::My2DVector NewVector2 = MyMathLibrary::My2DVector::My2DVector(2, 1);
	EXPECT_FLOAT_EQ(Vector2D.Magnitude(NewVector2), 2.23);
}

TEST
{
	
}

int main(int argc, char** argv)
{
	MyMathLibrary::My2DVector NewVector2 = MyMathLibrary::My2DVector::My2DVector(2, 1);

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke

	
	return 0;
}

