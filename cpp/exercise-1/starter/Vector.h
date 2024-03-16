// Vector.h
#pragma once
#include <iostream>

using std::cout, std::endl;
class Vector
{
public:
	static int size;
	Vector();
	~Vector();
	void Set(int* arr);
	void Print();
	friend int operator * (const Vector& v1, const Vector& v2);
private:
	int* m_vec;
};