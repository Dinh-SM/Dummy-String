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
	if((c_string != NULL) && (c_string[0] != '\0')){
		strcpy(string_, c_string);
	}else{
		strcpy(string_, "");
	};

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
	};

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
	char new_string[100];
	strcpy(new_string, string_);

	if((s != NULL) && (s[0] != '\0')){
		
		short base_size = size();
		short i = base_size;
		while(s[i-base_size] != '\0' && size() < 99){
			new_string[i] = s[i-base_size];
			i++;
		};
		new_string[i] = s[i-base_size];

	}

	OurString new_our_string(new_string);

	return new_our_string;
}

//-------------------------------------------------------------
// Student B

// Constructor that initializes an OurString object from a c-string passed as argument
// Copies the null-terminated character sequence (C-string) pointed by s.
OurString::OurString(const char* s)
{
	if ((s != NULL) && (s[0] != '\0')) //if s non null and it's first character isn't the null terminator
	{
		int i = 0;
		while(s[i] != '\0')
		{
			string_[i] = s[i];
			i++;
		}	
		string_[i]='\0';
	}
	else
	{
        strcpy(string_, "");
    };
};


// Method that returns the size/length of the content in an unsigned integral type size_t
size_t OurString::length() const
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

// Method that returns the maximum length the string can reach in an unsigned integral type size_t
size_t OurString::max_size() const
{
	return 100;

};




void OurString::resize(size_t n, char c)
/* Method that resizes the string to a length of n characters.

If n is smaller than the current string length, the current value is shortened to its first n character, removing the characters beyond the nth.

If n is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of n. If c is specified, the new elements are initialized as copies of c, otherwise, they are value-initialized characters (null characters).
*/

{

	if (OurString::length() < n)
	{
		size_t i = OurString::length();
		while(i < n)
		{		
			string_[i] = c;
			i++;
		}		
		string_[i] = '\0'	;
	}
	else
	{
		size_t i = n;
		string_[i] = '\0';

	}

};




// Operator of assignement: takes the OurString &string as new content and return a new one
OurString& OurString::operator=(const OurString &string) 
{
	
	strcpy(string_,string.string_); //string_ =/= string.string_ !!
	return *this;

};


// Operator of concatenation: concatenate the content of our string object with a single character
OurString OurString::operator+(char c)

{
	char newc[100];
	int len = length();

	strcpy(newc, string_);
	
	if (len < 100 )
	{
		newc[len] = c;
		newc[len+1] = '\0';
	};

	OurString news;

	strcpy(news.string_, newc);
	return news; //renvoie objet OurString news

};

