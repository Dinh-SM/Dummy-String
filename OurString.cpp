#include "OurString.h"

OurString::OurString()
{
	char string[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r','l', 'd', '\0'};
	short i = 0;
	while(string[i] != '\0' && i < 100){
		string_[i] = string[i];
		i++;
	};
	string_[i] = string[i];
};

// Student A
OurString::OurString(OurString &string)
{
	char* c_string = string.c_str();
	short i = 0;
	while(c_string[i] != '\0' && i < 100){
		string_[i] = c_string[i];
		i++;
	};
	string_[i] = c_string[i];
};

char* OurString::c_str()
{
	return string_;
};

size_t OurString::size()
{
	short i = 0;
	while(string_[i] != '\0'){
		i++;
	}
	return i;
};

void OurString::clear()
{
	memset(string_, 0, sizeof(string_));
};

OurString OurString::operator=(char c)
{
	string_[0] = c;
	string_[1] = '\0';
};

OurString OurString::operator+(const char* s)
{
	short base_size = size();
	short i = base_size;
	while(s[i-base_size] != '\0' && size() < 100){
		string_[i] = s[i-base_size];
		i++;
	};
	string_[i] = s[i-base_size];
};

// Student B
OurString::OurString(const char* s)
{
	;
};

size_t OurString::length()
{
	;
};

size_t OurString::max_size()
{
	;
};

void OurString::resize(size_t n, char c)
{
	;
};

OurString OurString::operator=(const OurString &string)
{
	;
};

OurString OurString::operator+(char c)
{
	;
};