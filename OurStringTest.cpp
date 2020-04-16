#include "gtest/gtest.h"
#include "OurString.cpp"
#include<iostream>

// G-Test that tests the default constructor
TEST(GTestTests, ConstructorTest) {
	OurString string;
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}

// G-Test that tests the copy constructor
TEST(GTestTests, CopyConstructorTest) {
	OurString string;
	OurString string1(string);
	const char* c_string = string1.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}

// G-Test that tests the size() method
TEST(GTestTests, SizeTest) {
	OurString string;
	EXPECT_EQ(string.size(), 11);
}

// G-Test that tests the clear() method
TEST(GTestTests, ClearTest) {
	OurString string;
	string.clear();
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "");
}

// G-Test that tests the assignement operator with a char
TEST(GTestTests, EqualCharTest) {
	OurString string;
	string = 'z';
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "z");
}

// G-Test that tests the concatenation operator with a c string
TEST(GTestTests, PlusCStringTest) {
	OurString string;
	OurString string1;
	string = string + string1.c_str();
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello WorldHello World");
}