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
TEST(GTestTests, LengthTest) {
    OurString string;
    EXPECT_EQ(string.length(), 11);
}
TEST(GTestTests, Max_SizeTest) {
	OurString string;
	EXPECT_EQ(string.max_size(), 100);
}	
TEST(GTestTests, ResizeTest) {
	OurString string;
	string.resize(5,' ');
	EXPECT_EQ(string.length(), 5); //test la taille attendue
	EXPECT_STREQ(string.string_ , "Hello");//Test du raccourci de string
	OurString string2;
	string2.resize(16,'!');
	EXPECT_STREQ(string2.string_, "Hello World!!!!!");//test rallongement de la chaine;
}
   
TEST(GTestTests, Ope_Eg_String){
	OurString string; // len(string.string_) == 11
	char c[] = "Hello ! "; // len(c) == 8
	OurString string2(c);
	EXPECT_EQ(string2.length(), 8);
	string2 = string;
	EXPECT_EQ(string2.length(), 11);
}

TEST(GTestTests, Ope_PLUS_SingCHAR){
	OurString string;
	//OurString truc(string + 'f'); // NE MARCHE PAS CAR (string+'f') est de type Objet et le constructeur prend pour arg(chaine de char) !
	string = string +'!';
	EXPECT_STREQ(string.string_, "Hello World!"); 
}		