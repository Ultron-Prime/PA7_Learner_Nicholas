/* -------------------------------------------------

FILE:		MyString.cpp
DESCRIPTION:	MyString.cpp file for Project 7 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-10-30	1.0 Created this file
Nick Learner		2019-10-30	1.1 Added class MyString implementation
*/

#include "MyString.h"

//(1)
MyString::MyString()
{
	
	m_size = 1;
	buffer_allocate(1);
	
	std::cout << "MyString default ctor called" << std::endl;
}

//(2)
MyString::MyString(const char * str)
{
	size_t size = strlen(str);
	
	buffer_allocate(size + 1);
	
	strcpy(m_buffer, str);
	
	std::cout << "MyString parametrized ctor called" << std::endl;
}

//(3)
MyString::MyString(const MyString & other)
{
	size_t size = other.m_size;
	
	buffer_allocate(size);
	
	strcpy(m_buffer, other.m_buffer);
	
	std::cout << "MyString copy ctor called" << std::endl;
}

//(4)
MyString::~MyString()
{
	buffer_deallocate();
	
	std::cout << "MyString destructor called" << std::endl;
}

//(5)
size_t MyString::size() const
{
	return m_size;
}

//(6)
size_t MyString::length() const
{
	return strlen(m_buffer);
}

//(7)
const char * MyString::c_str() const
{
	return m_buffer;
}

//(8)
bool MyString::operator==(const MyString & other) const
{
	return (!(strcmp(m_buffer, other.m_buffer)));
}

//(9)
MyString & MyString::operator=(const MyString & other)
{
	int sizediff = m_size - strlen(other.m_buffer);
	
	if (sizediff <= 0)
	{
		std::cout << "Not enough memory allocated" << std::endl;
	}else
	{
		strcpy(m_buffer, other.m_buffer);
	}
	
	return *this;
}

//(10)
MyString MyString::operator+(const MyString & other_myStr) const
{
	size_t size = m_size + other_myStr.m_size;
	char tempstr[size];
	
	strcpy(tempstr, m_buffer);
	strcat(tempstr, other_myStr.m_buffer);
	
	MyString tempmystring(tempstr);
	
	return tempmystring;
}

//(11a)
char & MyString::operator[](size_t index)
{
	return m_buffer[index];
}

//(11b)
const char & MyString::operator[](size_t index) const
{
	return m_buffer[index];
}

//(12)
std::ostream & operator<<(std::ostream & os, const MyString & myStr)
{
	for (int i = 0; i < abs(myStr.m_size); ++i)
	{
		if (myStr.m_buffer[i] == '\0')
		{
			return os;
		}else
		{
			os << myStr.m_buffer[i];
		}
	}
	
	return os;
}

//(13)
void MyString::buffer_deallocate()
{
	delete [] m_buffer;
	m_size = 0;
}

//(14)
void MyString::buffer_allocate(size_t size)
{
	m_buffer = NULL;
	
	try
	{
		m_buffer = new char [size];
		m_size = size;
	}catch(const std::bad_alloc & ex)
	{
		delete [] m_buffer;
	}
}

