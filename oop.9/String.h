#pragma once
#include"BankingCommonDecl07.h"
class String
{
private:
	int len;
	char* str;
public:
	String(int l = 0);
	String(const char* s);
	String(const String& s);
	
	String& operator=(const String& s);
	String& operator+=(const String& s);
	String operator+(const String& s);
	bool operator==(const String& s);
	~String();
	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, const String& s);
};
