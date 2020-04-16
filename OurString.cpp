#include "OurString.h"

// Default constructor that initializes an OurString object
// with "Hello World" as content
OurString::OurString()
{
	strcpy(string_, "Hello World");
};

// Student A

// Copy constructor that takes another OurString object and
// initialize a new OurString object with the same content
OurString::OurString(OurString &string)
{
	const char* c_string = string.c_str();
	strcpy(string_, c_string);
};

// Method that returns the content as a c string (array of char)
const char* OurString::c_str() const
{
	return string_;
};

// Method that returns the size/length of the content
size_t OurString::size() const
{
	short i = 0;
	while(string_[i] != '\0'){
		i++;
	}
	return i;
};

// Method that clears the content of the string (size = 0)
void OurString::clear()
{
	memset(string_, 0, sizeof(string_));
};

// Operator of assignement: takes the char c as new content
OurString& OurString::operator=(char c)
{
	string_[0] = c;
	string_[1] = '\0';
	return *this;
};

// Operator of concatenation: concatenate the content with the
// c string
OurString OurString::operator+(const char* s)
{
	short base_size = size();
	short i = base_size;
	while(s[i-base_size] != '\0' && size() < 99){
		string_[i] = s[i-base_size];
		i++;
	};
	string_[i] = s[i-base_size];
	return *this;
};

// Student B
OurString::OurString(const char* s)
{
	;
};

size_t OurString::length() const
{
	;
};

size_t OurString::max_size() const
{
	;
};

void OurString::resize(size_t n, char c)
{
	;
};

OurString& OurString::operator=(const OurString &string)
{
	;
};

OurString OurString::operator+(char c)
{
	;
};