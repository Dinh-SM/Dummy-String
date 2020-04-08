#include "gtest/gtest.h"
#include "OurString.cpp"

TEST(GTestTests, ConstructorTest) {
	OurString string;
	char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}

TEST(GTestTests, CopyConstructorTest) {
	OurString string;
	OurString string1(string);
	char* c_string = string1.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}

TEST(GTestTests, SizeTest) {
	OurString string;
	EXPECT_EQ(string.size(), 11);
}

TEST(GTestTests, ClearTest) {
	OurString string;
	string.clear();
	char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "");
}

TEST(GTestTests, EqualCharTest) {
	OurString string;
	string = 'z';
	char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "z");
}

TEST(GTestTests, PlusCStringTest) {
	OurString string;
	OurString string1;
	string = string + string1.c_str();
	char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello WorldHello World");
}