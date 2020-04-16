#include "gtest/gtest.h"
#include "OurString.cpp"

//Student A

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

// G-Test that tests the c_str() method
TEST(GTestTests, CStrTest) {
	OurString string;
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}

// G-Test that tests the size() method
TEST(GTestTests, SizeTest) {
	OurString string;
	long unsigned int val = 11;
	EXPECT_EQ(string.size(), val);
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






//----------------------
// Student B
//----------------------


// Test of constructor OurString::OurString(const char* s)
// Comparison of an expected return with the cstring constructor and a know char[]
TEST(GTestTests, ConstructorCStringTest) {
	OurString string("Hello World");
	const char* c_string = string.c_str();
	EXPECT_STREQ(c_string, "Hello World");
}


//Test of method string.length() 
// Comparison of an expected return with the default constructor
TEST(GTestTests, LengthTest) {
    OurString string;
	long unsigned int val = 11;
    EXPECT_EQ(string.length(), val);   
}


//Test of method string.max_size() 
// Comparison of an expected return with the default constructor
TEST(GTestTests, MaxSizeTest) {
	OurString string;
	long unsigned int val = 100;
	EXPECT_EQ(string.max_size(), val);
}	


//Test of method string.resize(n,c) 
// Test of an expected length after beign resized

TEST(GTestTests, ResizeTest) {
	OurString string;
	string.resize(5,' ');
	long unsigned int val = 5;
	EXPECT_EQ(string.length(), val); //test de la taille attendue
	EXPECT_STREQ(string.c_str(), "Hello");//Test du raccourci de string
	OurString string2;
	string2.resize(16,'!');
	EXPECT_STREQ(string2.c_str(), "Hello World!!!!!");//test rallongement de la chaine;
}
   
//Test of OurString::operator=(const OurString &string)
// Test of an expected length after a new assignation
TEST(GTestTests, OpeEgString){
	OurString string; // len(string.string_) == 11
	char c[] = "Hello ! "; // len(c) == 8
	OurString string2(c);
	long unsigned int val = 8;
	EXPECT_EQ(string2.length(), val);
	string2 = string;
	val = 11;
	EXPECT_EQ(string2.length(), val);
}

//Test of OurString::operator+(char c)
// Test of an expected string after the addition of a single char
TEST(GTestTests, OpePLUSSingCHAR){
	OurString string;
	//OurString truc(string + 'f'); // NE MARCHE PAS CAR (string+'f') est de type Objet et le constructeur prend pour arg(chaine de char) !
	string = string +'!';
	EXPECT_STREQ(string.c_str(), "Hello World!"); 
}