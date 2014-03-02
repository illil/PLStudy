#include <iostream>
#include <stdio.h>
#include<string.h>

class String
{
public:

	String()
	{
		_str = nullptr;
	}

	~String()
	{
		if (_str != nullptr)
		{
			delete _str;
		}
	}

	String&  operator=(char* str)
	{
		if (_str != nullptr)
		{
			delete _str;
		}

		int strSize = strlen(str)+1;
		_str = new char[strSize];
		memcpy(_str, str, strSize);
		return *this;
	}

	String&  operator=(String &str)
	{
		if (_str != nullptr)
		{
			delete _str;
		}

		int strSize = strlen(str._str)+1;
		_str = new char[strSize];
		memcpy(_str, str._str, strSize);
		return *this;
	}

private:
	char* _str;
};

int main()
{
	
	String a;
	String b;
	a = "1111";
	b = a = "2222";
	
	return 0;
}
