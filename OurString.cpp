#include "OurString.h"

// Student A
OurString::OurString(OurString &string)
{

};

char* OurString::c_str()
{

};

size_t OurString::size()
{

};

void OurString::clear()
{

};

OurString OurString::operator=(char c)
{

};

OurString OurString::operator+(const string&, const char* s)
{

};


// Student B
OurString::OurString(char &string)
{

	if(string) //si non null ?
	{
		int i = 0;
		while(string[i] != '\0')
		{
			string[i] = string_[i];
			i++;
		}	
		string_[i]='\0';
	}

};

size_t OurString::length()
{
	size_t length_z;
	length_z = 0;
	int i = 0;
	while(string_[i]!='\0')
	{
		length_z += 1;
		i++;
	}
	return length_z;

};

size_t OurString::max_size()
{

};

void OurString::resize(size_t n, char c)
{

};

OurString OurString::operator=(const string&)
{

};

OurString OurString::operator+(const string&, char c)
{

};