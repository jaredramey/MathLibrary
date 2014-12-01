#include "stdafx.h"
#include <iostream>

#include "MyMathLibrary.h"
#include "gtest\gtest.h"

using namespace MyMathLibrary;

TEST(sample_test_case, sample_test)
{
	EXPECT_EQ(1, 1);
}

int main(int argc, char** argv)
{
	float test1 = 5;
	float test2 = 3;

	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	std::getchar(); // keep console window open until Return keystroke

	
	return 0;
}

