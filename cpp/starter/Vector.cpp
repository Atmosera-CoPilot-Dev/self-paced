// Vector.cpp

#include <iostream>
#include "Vector.h"
using namespace std;



Vector::Vector(){}
 // This is the constructor for the Vector class. It's called when an object of the Vector class is created.
 // It initializes the m_vec member variable as a new integer array of size size.

Vector::~Vector(){}
 // This is the destructor for the Vector class. It's called when an object of the Vector class is destroyed. 
 // It deallocates the memory that was previously allocated for the m_vec array in the constructor.

void Vector::Set(int *arr){}
 // This method sets the values of the m_vec array. 
 // It takes a pointer to an integer array as an argument and copies the values from the input array to m_vec.
 // It assumes that the input array has at least size elements.

void Vector::Print(){}
 // This method prints the elements of the m_vec array to the console using cout.
 // Each element is followed by two spaces.

int operator *(const Vector& v1, const Vector& v2){}
 // This is an overloaded multiplication operator. 
 // It takes two Vector objects as arguments and calculates the dot product of their m_vec arrays. 
 // The dot product is calculated as the sum of the products of the corresponding elements in the two arrays.