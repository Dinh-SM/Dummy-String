#include "gtest/gtest.h"
#include "OurString.cpp"
#include <iostream>

TEST(GTestTests, FirstTest) {
	OurString string;
	EXPECT_EQ(string.c_str(),"Hello World");
}