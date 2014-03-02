#include <iostream>
#include <stdio.h>
#include<string.h>

class String
{
public:

	String()
	{
		_str = nullptr;
		_length = 0;
	}

	String(String &str)
	{
		CopyStr(str._str);
	}

	String(char * str)
	{
		CopyStr(str);
	}

	~String()
	{
		DeleteStr();
	}

	String&  operator=(char* str)
	{
		DeleteStr();
		CopyStr(str);
		return *this;
	}

	String&  operator=(String &str)
	{
		DeleteStr();
		CopyStr(str._str);
		return *this;
	}

	String operator+(String &str)
	{
		String result;

		result._length = Length() + str.Length();
		int strSize = result._length + 1;
		result._str = new char[strSize];
		memcpy(result._str, _str, Length());
		memcpy(result._str + Length() , str._str, str.Length() + 1);

		return result;
	}

	friend std::ostream& operator<<(std::ostream& os,String& str)
	{
		os << str._str;
		return os;
	}

	int Length()
	{
		return _length;
	}

private:
	
	void DeleteStr()
	{
		if (_str != nullptr)
		{
			delete _str;
		}
	}

	void CopyStr(char* str)
	{
		_length = strlen(str);
		int strSize = _length + 1;
		_str = new char[strSize];
		memcpy(_str, str, strSize);
	}

	int _length;
	char* _str;
};


int main()
{
	
	
	std::string

	std::cout << c;

	return 0;
}
