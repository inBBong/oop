#include"String.h"

String::String(int l) :len(l)
{
	str = NULL;
}

String::String(const char* s)
{
	len = strlen(s) + 1;
	str = new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
}

String& String::operator=(const String& s)
{
	delete[]str;
	len = s.len;
	str = new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+=(const String& s)
{
	//String temp;
	//temp.len = len + s.len;		
	//temp.str = new char[temp.len + 1];
	//strcpy(temp.str, strcat(str, s.str));
	//
	//return temp;
	char* tempStr;
	len += s.len - 1;
	tempStr = new char[len];
	strcpy(tempStr, str);
	strcat(tempStr, s.str);

	if (str != NULL)
		delete[]str;
	str = tempStr;
	return *this;
}

String String::operator+(const String& s)
{
	char* tempStr = new char[len + s.len - 1];
	strcpy(tempStr, str);
	strcat(tempStr, s.str);
	String newStr(tempStr);
	delete[] tempStr;
	return newStr;
}
bool String::operator==(const String& s)
{
	return (strcmp(str, s.str)) ? false : true;
}

String::~String()
{
	if (str != NULL)
		delete[] str;
}
ostream& operator<<(ostream& os, const String& s)
{
	os << s.str;
	return os;
}
istream& operator>>(istream& is, const String& s)
{
	is >> s.str;
	return is;
}