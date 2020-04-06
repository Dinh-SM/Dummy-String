#include "gtest/gtest.h"
#include "OurString.cpp"

TEST(GTestTests, ConstructorTest) {
	OurString string;
	bool check = true;
	char* c_string = string.c_str();
	char hello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r','l', 'd', '\0'};
	short i = 0;
	while(c_string[i] != '\0' && hello[i] != '\0' && i < 100){
		if (c_string[i] != hello[i])
		{
			check = false;
		}
		i++;
	}
	EXPECT_TRUE(check);
}

TEST(GTestTests, CopyConstructorTest) {
	OurString string;
	string.clear();
	OurString string1(string);
	EXPECT_EQ(string1.size(), 0);
}

TEST(GTestTests, SizeTest) {
	OurString string;
	EXPECT_EQ(string.size(), 11);
}

TEST(GTestTests, ClearTest) {
	OurString string;
	string.clear();
	EXPECT_EQ(string.size(), 0);
}

TEST(GTestTests, EqualCharTest) {
	OurString string;
	string = 'z';
	EXPECT_EQ(string.size(), 1);
}

TEST(GTestTests, PlusCStringTest) {
	OurString string;
	OurString string1;
	string = string + string1.c_str();
	EXPECT_EQ(string.size(), 22);
}