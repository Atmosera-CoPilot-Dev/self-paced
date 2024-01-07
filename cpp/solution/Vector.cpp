// Implement Vector class methods
#include <iostream>
#include "Vector.h"
using namespace std; // remove if desired

 // Implement the constructor for the Vector class. 
 // It initializes the m_vec member variable as a new integer array of size Vector::size.
Vector::Vector()
{
	m_vec = new int[Vector::size];
}


 // Implement the destructor for the Vector class.
 // It deallocates the memory that was previously allocated for the m_vec array in the constructor.
Vector::~Vector()
{
	delete [] m_vec;
}

 // Implement the Vector::Set(int *arr) method for the Vector class.
 // It takes a pointer to an integer array as an argument and copies the values from the input array to m_vec.
 // It assumes that the input array has at least Vector::size elements.
void Vector::Set(int *arr)
{
	for (int i = 0; i < Vector::size; i++)
		m_vec[i] = arr[i];
}

 // Implement the Vector::Print() method.
 // It prints the elements of the m_vec array to the console using std::cout.
 // Each element is followed by two spaces.
void Vector::Print()
{
	for (int i = 0; i < Vector::size; i++)
		cout << m_vec[i] << "  ";
	cout << endl;
}

 // Implement an overloaded multiplication operator. 
 // It takes two Vector objects as arguments and calculates the dot product of their m_vec arrays. 
 // The dot product is calculated as the sum of the products of the corresponding elements in the two arrays.
 // For example, if the two arrays are [1, 2, 3] and [1, 4, 9], the dot product is 1*1 + 2*4 + 3*9 = 1 + 8 + 27 = 36.
int operator *(const Vector& v1,
			   const Vector& v2)
{
	int sum = 0;
	for (int i = 0; i < Vector::size; i++)
		sum += v1.m_vec[i] * v2.m_vec[i];
	return sum;
}
