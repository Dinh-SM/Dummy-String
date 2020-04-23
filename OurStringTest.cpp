#include "gtest/gtest.h"
#include "OurString.cpp"

//Student A

// G-Test that tests the dummy default constructor
// TEST(GTestTests, DummyConstructorTest) {
//	 OurString string;
//	 const char* c_string = string.c_str();
//	 EXPECT_STREQ(c_string, "Hello World");
// };

// G-Test that tests the default constructor
TEST(GTestTests, ConstructorTest) {
	OurString string;
	EXPECT_STREQ(string.c_str(), "");
};

// G-Test that tests the copy constructor
TEST(GTestTests, CopyConstructorTest) {
	OurString string("Hello World");
	OurString string1(string);
	EXPECT_STREQ(string.c_str(), string1.c_str());

	OurString string2("");
	OurString string3(string2);
	EXPECT_STREQ(string2.c_str(), string3.c_str());
};

// G-Test that tests the c_str() method
TEST(GTestTests, CStrTest) {
	OurString string("Hello World");
	EXPECT_STREQ(string.c_str(), "Hello World");
};

// G-Test that tests the size() method
TEST(GTestTests, SizeTest) {
	OurString string("Hello World");
	size_t expected_size = 11;
	EXPECT_EQ(string.size(), expected_size);
};

// G-Test that tests the clear() method
TEST(GTestTests, ClearTest) {
	OurString string("Hello World");
	string.clear();
	EXPECT_STREQ(string.c_str(), "");
	size_t expected_size = 0;
	EXPECT_EQ(string.size(), expected_size);
};

// G-Test that tests the assignement operator with a char
TEST(GTestTests, EqualCharTest) {
	OurString string("Hello World"); 
	string = 'z';
	EXPECT_STREQ(string.c_str(), "z");

	string = '\0';
	EXPECT_STREQ(string.c_str(), "");
};

// G-Test that tests the concatenation operator with a c string
TEST(GTestTests, PlusCStringTest) {
	OurString string("Hello World");
	OurString string1("Hello World");
	string = string + string1.c_str();
	EXPECT_STREQ(string.c_str(), "Hello WorldHello World");

	OurString string2("");
	string = string + string2.c_str();
	EXPECT_STREQ(string.c_str(), "Hello WorldHello World");

	OurString string3(NULL);
	string = string + string3.c_str() + string2.c_str();
	EXPECT_STREQ(string.c_str(), "Hello WorldHello World");

	//test of an exceeding of the capacity limitation on string which is 100 
	OurString string4("0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");
	//string4.length() == 100
	OurString string5("2");
	string4 = string4 + string5.c_str();
	EXPECT_STREQ(string4.c_str(), "0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");
};


// Student B

// Test of constructor OurString::OurString(const char* s)
// Comparison of an expected return with the cstring constructor and a know char[]
TEST(GTestTests, ConstructorCStringTest) {
	OurString string("Hello World");
	EXPECT_STREQ(string.c_str(), "Hello World");
};

//Test of method string.length() 
// Comparison of an expected return with the default constructor
TEST(GTestTests, LengthTest) {
    OurString string("Hello World");
	size_t expected_length = 11;
    EXPECT_EQ(string.length(), expected_length);   
};

//Test of method string.max_size() 
// Comparison of an expected return with the default constructor
TEST(GTestTests, MaxSizeTest) {
	OurString string("Hello World");
	size_t expected_max_size = 100;
	EXPECT_EQ(string.max_size(), expected_max_size);
};

//Test of method string.resize(n,c) 
// Test of an expected length after beign resized
TEST(GTestTests, ResizeTest) {
	OurString string("Hello World");
	string.resize(5,' ');
	size_t expected_length = 5;
	EXPECT_EQ(string.length(), expected_length); //test of expected length
	EXPECT_STREQ(string.c_str(), "Hello");//Test of shortening the string

	OurString string2("Hello World");
	string2.resize(16,'!');
	expected_length = 16;
	EXPECT_EQ(string2.length(), expected_length); //test of expected length
	EXPECT_STREQ(string2.c_str(), "Hello World!!!!!");//Test of extending the string

	//test of an exceeding of the capacity limitation on string which is 100 
	OurString string4("0");
	string4.resize(101, '$');
	EXPECT_STREQ(string4.c_str(), "0");

};
   
//Test of OurString::operator=(const OurString &string)
// Test of an expected length after a new assignation
TEST(GTestTests, EqualOurStringTest){
	OurString string("Hello World"); // len(string.string_) == 11
	OurString string2("Hello ! "); // len(c) == 8
	size_t expected_length = 8;
	EXPECT_EQ(string2.length(), expected_length);

	string2 = string;
	expected_length = 11;
	EXPECT_EQ(string2.length(), expected_length);

	EXPECT_STREQ(string2.c_str(), string.c_str());

	//test of an exceeding of the capacity limitation on string which is 100 
	OurString string4("0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");
	//string4.length() == 100
	OurString string5("2");
	string4 = string4 + string5.c_str();
	EXPECT_STREQ(string4.c_str(), "0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");

};

//Test of OurString::operator+(char c)
// Test of an expected string after the addition of a single char
TEST(GTestTests, PlusCharTest){
	OurString string("Hello World");
	string = string + '!';
	EXPECT_STREQ(string.c_str(), "Hello World!"); 

	//test of an exceeding of the capacity limitation on string which is 100 
	OurString string4("0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");
	//string4.length() == 100
	OurString string5("2");
	string4 = string4 + string5.c_str();
	EXPECT_STREQ(string4.c_str(), "0101011011010101101101010110110101011011010101101101010110110101011011010101101101010110110101011011");

};