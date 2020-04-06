OurStringTest.cpp
#include "gtest/gtest.h"
#include "OurString.cpp"
#include <iostream>

TEST(GTestTests, FirstTest) {
	OurString string;
	bool check = true;
	char* c_string = string.c_str();
	char hello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r','l', 'd', '\0'};
	short i = 0;
	while(c_string[i] != '\0' && hello[i] != '\0'){
		if (c_string[i] != hello[i])
		{
			check = false;
		}
		i++;
	}
	EXPECT_TRUE(check);
}