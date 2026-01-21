#pragma once
#include"Account07.h"

typedef Account* ACCOUNT_PTR;
template<typename T>
class BoundCheckAccountPtrArray
{
private:
	T* arr;
	int arrlen;

	BoundCheckAccountPtrArray(const BoundCheckAccountPtrArray& arr){}
	BoundCheckAccountPtrArray& operator=(const BoundCheckAccountPtrArray&arr){}
public:
	BoundCheckAccountPtrArray(int len) :arrlen(len)
	{
		arr = new T[len];
	}
	T& operator[] (int idx)
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}
	T operator[] (int idx) const
	{
		if (idx < 0 || idx >= arrlen)
		{
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}

		return arr[idx];
	}
	int GetArrLen() const
	{
		return arrlen;
	}
	~BoundCheckAccountPtrArray()
	{
		delete[]arr;
	}
};