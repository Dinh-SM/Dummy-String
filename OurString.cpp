#include "OurString.h"

OurString::OurString()
{
	char string[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r','l', 'd', '\0'};
	short i = 0;
	while(string[i] != '\0'){
		string_[i] = string[i];
		i++;
	};
	string_[i] = string[i];
};

// Student A
OurString::OurString(OurString &string)
{
	;
};

char* OurString::c_str()
{
	return string_;
};

size_t OurString::size()
{
	;
};

void OurString::clear()
{
	;
};

OurString OurString::operator=(char c)
{
	;
};

OurString OurString::operator+(const char* s)
{
	;
};

// Student B
OurString::OurString(const char* s)
{
	if(s) //si non null ?
	{
		int i = 0;
		while(s[i] != '\0')
		{
			string_[i] = s[i];
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
	return 100;
};



void OurString::resize(size_t n, char c)
/* Resizes the string to a length of n characters.

If n is smaller than the current string length, the current value is shortened to its first n character, removing the characters beyond the nth.

If n is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of n. If c is specified, the new elements are initialized as copies of c, otherwise, they are value-initialized characters (null characters).
*/

{
	
	if (OurString::length() < n)
	{
		int i = OurString::length();
		while(i < n)
		{		
			string_[i] = c;
			i++;
		}		
		string_[i] = '\0'	;
	}
	else
	{
		int i = n;
		string_[i] = '\0';

	}

};





OurString OurString::operator=(const OurString &string)
{
	;
};

OurString OurString::operator+(char c)
{
	;
};










