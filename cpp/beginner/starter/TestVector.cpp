// TestVector.cpp

#include <iostream>
#include "Vector.h"
using namespace std;

int Vector::size;

int main()
{
	// explain this code in detail for documentation
	Vector::size = 3;
	int arr1[] = {1, 2, 3};
	int arr2[] = {1, 4, 9};
	Vector v1;
	Vector v2;
	v1.Set(arr1);
	v2.Set(arr2);
	v1.Print();
	v2.Print();
	cout << v1 * v2 << endl;
}


