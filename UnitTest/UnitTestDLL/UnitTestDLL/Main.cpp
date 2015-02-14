#include <iostream>

#include "gtest\gtest.h"
#include "MyMathFuncs.h"


DLLMath::MyBasicMath BasicMath;
DLLMath::My2DVector Vector2D;
DLLMath::My3DVector Vector3D;
DLLMath::My4DVector Vector4D;

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

TEST(Basic_Math_Test, Expected_Result)
{
	EXPECT_FLOAT_EQ(0, BasicMath.DegreeRadianConversion(1, 30));
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke
}

TEST(Vector2_test, Magnitude)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(2, 1);
	float numCheck = NewVector2.Magnitude(NewVector2);
	EXPECT_FLOAT_EQ(NewVector2.Magnitude(NewVector2), 2.236068);
}

TEST(Vector2_Test, Dot_Product)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	EXPECT_FLOAT_EQ(NewVector2.DotProduct(OtherNewVector2), 41);
}

TEST(Vector2_Test, Normalize)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector2 = DLLMath::My2DVector::My2DVector(4, 5);

	NewVector2.NomralizeVector(NewVector2);
	ResultVector2.NomralizeVector(ResultVector2);

	vector<float> MyVect = NewVector2.GetVect();
	vector<float> MyOtherVect = ResultVector2.GetVect();

	float num1 = MyVect[0];
	float num2 = MyVect[1];
	float num3 = MyOtherVect[0];
	float num4 = MyOtherVect[1];

	EXPECT_FLOAT_EQ(0.62469506, num1);
	EXPECT_FLOAT_EQ(0.99228531, num2);
	EXPECT_FLOAT_EQ(0.62469506, num3);
	EXPECT_FLOAT_EQ(0.99228531, num4);

	/*
	-
	- Need to figure out a way to test this or see if it's just like how we have to test our matrix functions on paper
	-
	*/
}

TEST(Vector2_Test, Cross_Product)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	EXPECT_FLOAT_EQ(NewVector2.CrossProduct(OtherNewVector2), 0);
}

TEST(Vector2_Test, Linear_Interpolation)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	EXPECT_FLOAT_EQ(NewVector2.Lerp(OtherNewVector2, .5), 0);
}

TEST(Vector2_Test, Operator_Plus)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator+(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator+(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Plus_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator+=(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator+=(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Minus)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator-(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator-(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Minus_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator-=(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator-=(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Times)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator*(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator*(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Times_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator*=(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator*=(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Devide)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator/(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator/(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Devide_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator/=(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator/=(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector ResultVector = NewVector2.operator=(OtherNewVector2);
	DLLMath::My2DVector Equals = NewVector2.operator=(OtherNewVector2);
	EXPECT_TRUE(ResultVector == Equals);
}

TEST(Vector2_Test, Operator_Equals_Equals)
{
	DLLMath::My2DVector NewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	DLLMath::My2DVector OtherNewVector2 = DLLMath::My2DVector::My2DVector(4, 5);
	EXPECT_TRUE(NewVector2 == OtherNewVector2);
}

TEST(Vector3_Test, Magnitude)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	EXPECT_FLOAT_EQ(NewVector3.Magnitude(NewVector3), 8.7749643873921220604063883074163);
}

TEST(Vector3_Test, Dot_Product)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	EXPECT_FLOAT_EQ(NewVector3.DotProduct(OtherNewVector3), 77);
}

TEST(Vector3_Test, Normalize)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	EXPECT_TRUE(NewVector3 == OtherNewVector3);
}

TEST(Vector3_Test, Cross_Product)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	NewVector3.NomralizeVector(NewVector3);

	vector<float> MyVec = NewVector3.GetVect();

	float num1 = MyVec[0];
	float num2 = MyVec[1];
	float num3 = MyVec[2];

	EXPECT_FLOAT_EQ(0.45584232, num1);
	EXPECT_FLOAT_EQ(0.6390968, num2);
	EXPECT_FLOAT_EQ(0.99154949, num3);

}

TEST(Vector3_Test, Operator_Plus)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator+(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator+(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Plus_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator+=(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator+=(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Minus)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator-(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator-(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Minus_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator-=(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator-=(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Times)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator*(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator*(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Times_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator*=(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator*=(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Devide)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator/(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator/(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Devide_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator/=(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator/=(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector ResultVector = NewVector3.operator=(OtherNewVector3);
	DLLMath::My3DVector EqualsVector = NewVector3.operator=(OtherNewVector3);
	EXPECT_TRUE(ResultVector == EqualsVector);
}

TEST(Vector3_Test, Operator_Equals_Equals)
{
	DLLMath::My3DVector NewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	DLLMath::My3DVector OtherNewVector3 = DLLMath::My3DVector::My3DVector(4, 5, 6);
	EXPECT_TRUE(NewVector3 == OtherNewVector3);
}

TEST(Vector4_test, Construction_From_Hex)
{
	DLLMath::My4DVector NewVector4 = DLLMath::My4DVector::My4DVector(0x00, 0x00, 0x00, 0x00);
	DLLMath::My4DVector OtherNewVector4 = Vector4D.ConstructFromHex(0x00000000);
	EXPECT_TRUE(NewVector4 == OtherNewVector4);
}

TEST(Vector4_Test, Normalize)
{
	DLLMath::My4DVector NewVector4 = DLLMath::My4DVector::My4DVector(23, 15, 1, 6);
	NewVector4.Normalize4D(NewVector4);

	vector<float> MyVec = NewVector4.GetVect();

	float num1 = MyVec[0];
	float num2 = MyVec[1];
	float num3 = MyVec[2];
	float num4 = MyVec[3];

	EXPECT_FLOAT_EQ(0.81778586, num1);
	EXPECT_FLOAT_EQ(0.53333861, num2);
	EXPECT_FLOAT_EQ(0.035555907, num3);
	EXPECT_FLOAT_EQ(0.21333544, num4);

}

TEST(Matrix3x1_Test, Multiplication)
{
	vector<float> MyVect = { 1, 1, 1 };
	vector<float> ResultVect = { 3, 3, 3 };
	vector<vector<float>> MyMatrix =
	{
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	DLLMath::MyMatrix3x3 NewMatrix = DLLMath::MyMatrix3x3::MyMatrix3x3(MyMatrix);
	vector<float> SumVect = NewMatrix.My2DMatrixMultiplication(MyVect, NewMatrix);


	EXPECT_TRUE(SumVect == ResultVect);
}

TEST(Matrix3x3_Test, Multiplication)
{
	vector<vector<float>> MyMatrix =
	{
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	vector<vector<float>> MyOtherMatrix =
	{
		{ 1, 1, 1 },
		{ 1, 1, 1 },
		{ 1, 1, 1 }
	};

	DLLMath::MyMatrix3x3 NewMatrix = DLLMath::MyMatrix3x3::MyMatrix3x3(MyMatrix);
	DLLMath::MyMatrix3x3 OtherNewMatrix = DLLMath::MyMatrix3x3::MyMatrix3x3(MyOtherMatrix);

	NewMatrix.My3x3MatrixMultiplication(NewMatrix, OtherNewMatrix);

	vector<vector<float>> ResultVect = NewMatrix.GetMatrix();

	float num0 = ResultVect[0][0];
	float num1 = ResultVect[0][1];
	float num2 = ResultVect[0][2];
	float num3 = ResultVect[1][0];
	float num4 = ResultVect[1][1];
	float num5 = ResultVect[1][2];
	float num6 = ResultVect[2][0];
	float num7 = ResultVect[2][1];
	float num8 = ResultVect[2][2];

	EXPECT_FLOAT_EQ(3, num0);
	EXPECT_FLOAT_EQ(3, num1);
	EXPECT_FLOAT_EQ(3, num2);
	EXPECT_FLOAT_EQ(3, num3);
	EXPECT_FLOAT_EQ(3, num4);
	EXPECT_FLOAT_EQ(3, num5);
	EXPECT_FLOAT_EQ(3, num6);
	EXPECT_FLOAT_EQ(3, num7);
	EXPECT_FLOAT_EQ(3, num8);

}

TEST(Matrix4x4_Test, Multiplication)
{
	vector<vector<float>> MyMatrix =
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 }
	};

	vector<vector<float>> MyOtherMatrix =
	{
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 },
		{ 1, 1, 1, 1 }
	};

	DLLMath::MyMatrix4x4 NewMatrix = DLLMath::MyMatrix4x4::MyMatrix4x4(MyMatrix);
	DLLMath::MyMatrix4x4 OtherNewMatrix = DLLMath::MyMatrix4x4::MyMatrix4x4(MyOtherMatrix);

	NewMatrix.My4x4MatrixMultiplication(NewMatrix, OtherNewMatrix);

	vector<vector<float>> ResultVect = NewMatrix.GetMatrix();

	float num0 = ResultVect[0][0];
	float num1 = ResultVect[0][1];
	float num2 = ResultVect[0][2];
	float num3 = ResultVect[0][3];
	float num4 = ResultVect[1][0];
	float num5 = ResultVect[1][1];
	float num6 = ResultVect[1][2];
	float num7 = ResultVect[1][3];
	float num8 = ResultVect[2][0];
	float num9 = ResultVect[2][1];
	float num10 = ResultVect[2][2];
	float num11 = ResultVect[2][3];
	float num12 = ResultVect[3][0];
	float num13 = ResultVect[3][1];
	float num14 = ResultVect[3][2];
	float num15 = ResultVect[2][3];

	EXPECT_FLOAT_EQ(4, num0);
	EXPECT_FLOAT_EQ(4, num1);
	EXPECT_FLOAT_EQ(4, num2);
	EXPECT_FLOAT_EQ(4, num3);
	EXPECT_FLOAT_EQ(4, num4);
	EXPECT_FLOAT_EQ(4, num5);
	EXPECT_FLOAT_EQ(4, num6);
	EXPECT_FLOAT_EQ(4, num7);
	EXPECT_FLOAT_EQ(4, num8);
	EXPECT_FLOAT_EQ(4, num9);
	EXPECT_FLOAT_EQ(4, num10);
	EXPECT_FLOAT_EQ(4, num11);
	EXPECT_FLOAT_EQ(4, num12);
	EXPECT_FLOAT_EQ(4, num13);
	EXPECT_FLOAT_EQ(4, num14);
	EXPECT_FLOAT_EQ(4, num15);
}