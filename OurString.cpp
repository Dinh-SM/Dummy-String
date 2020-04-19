#include "OurString.h"

// Default constructor that initializes an OurString object
// with "Hello World" as content
OurString::OurString()
{
	// Dummy default constructor: working
	//  string_ = new char[12]; 
	//  strcpy(string_, "Hello World");
	
	// True default constructor
	string_ = new char[1];
	string_[0] = '\0';
};

// Protected method that returns the size of a c string
size_t OurString::size_(const char* s) const
{
	short i = 0;
	while(s[i] != '\0')
	{
		i++;
	};

	return i;
};


// Student A

// Copy constructor that takes another OurString object and
// initialize a new OurString object with the same content
OurString::OurString(OurString &string)
{
	const char* c_string = string.c_str();
	if((c_string != NULL) && (c_string[0] != '\0'))
	{
		size_t new_size = size_(c_string);
		string_ = new char[new_size+1];
		strcpy(string_, c_string);
	}
	else
	{
		string_ = new char[1];
		string_[0] = '\0';
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
	while(string_[i] != '\0')
	{
		i++;
	};

	return i;
};

// Method that clears the content of the string (size = 0)
void OurString::clear()
{
	memset(string_, 0, sizeof(*string_));
};

// Operator of assignement: takes the char c as new content
OurString& OurString::operator=(char c)
{
	if(c != '\0')
	{
		string_ = new char[2];
		string_[0] = c;
		string_[1] = '\0';
	}
	else
	{
		string_ = new char[1];
		string_[0] = '\0';
	};

	return *this;
};

// Operator of concatenation: concatenate the content with the
// c string
OurString OurString::operator+(const char* s)
{
	if((s != NULL) && (s[0] != '\0') && size()+size_(s) <= 100)
	{
		size_t new_size = size()+size_(s);
		char new_string[new_size+1];
		strcpy(new_string, string_);
		
		short base_size = size();
		short i = 0;
		while(s[i] != '\0')
		{
			new_string[base_size+i] = s[i];
			i++;
		};
		new_string[base_size+i] = s[i];
		
		OurString new_our_string(new_string);
	
		return new_our_string;
	};
	
	OurString new_our_string(*this);
	
	return new_our_string;
}


// Student B

// Constructor that initializes an OurString object from a c-string passed as argument
// Copies the null-terminated character sequence (C-string) pointed by s.
OurString::OurString(const char* s)
{
	if ((s != NULL) && (s[0] != '\0')) //if s non null and it's first character isn't the null terminator
	{
		size_t new_size = size_(s);
		string_ = new char[new_size+1];
		strcpy(string_, s);
	}
	else
	{
		string_ = new char[1];
		string_[0] = '\0';
	};
};

// TODO: Destructor
//OurString::~OurString()
//{
	
//};

// Method that returns the size/length of the content in an unsigned integral type size_t
size_t OurString::length() const
{
	size_t len;
	len = 0;
	int i = 0;
	while(string_[i]!='\0')
	{
		len += 1;
		i++;
	}
	return len;
};

// Method that returns the maximum length the string can reach in an unsigned integral type size_t
size_t OurString::max_size() const
{
	return 100;
};

/* Method that resizes the string to a length of n characters.
If n is smaller than the current string length, the current value is shortened to its first n character, removing the characters beyond the nth.
If n is greater than the current string length, the current content is extended by inserting at the end as many characters as needed to reach a size of n.
If c is specified, the new elements are initialized as copies of c, otherwise, they are value-initialized characters (null characters).
*/
void OurString::resize(size_t n, char c)
{
	if(n <= 100 && n >= 0)
	{
		if (length() < n)
		{
			char* new_string = new char[n+1];
			strcpy(new_string, string_);
			size_t i = length();
			while(i < n)
			{
				new_string[i] = c;
				i++;
			}
			new_string[i] = '\0'	;
			
			string_ = new char[n];
			strcpy(string_, new_string);
		}
		else
		{
			char* new_string = new char[n+1];
			strcpy(new_string, string_);
			new_string[n] = '\0';
			string_ = new char[n+1];
			strcpy(string_, new_string);
		}
	}
};

// Operator of assignement: takes the OurString &string as new content and return a new one
OurString& OurString::operator=(const OurString &string) 
{
	size_t new_size = size_(string.string_);
	string_ = new char[new_size+1];
	strcpy(string_, string.string_); //string_ =/= string.string_ !!
	return *this;
};

// Operator of concatenation: concatenate the content of our string object with a single character
OurString OurString::operator+(char c)
{	
	if (length()+1 <= 100)
	{
		char* newc = new char[length()+2];
		strcpy(newc, string_);

		newc[length()] = c;
		newc[length()+1] = '\0';

		OurString news(newc);
	
		return news; //renvoie objet OurString news
	};
	
	OurString news(string_);
	
	return news; //renvoie objet OurString news
};
