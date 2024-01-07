// Vector.cpp

#include <iostream>
#include "Vector.h"
using namespace std;


 // Implement the constructor for the Vector class. 
 // It initializes the m_vec member variable as a new integer array of size Vector::size.


 // Implement the destructor for the Vector class.
 // It deallocates the memory that was previously allocated for the m_vec array in the constructor.


 // Implement the Vector::Set(int *arr) method for the Vector class.
 // It takes a pointer to an integer array as an argument and copies the values from the input array to m_vec.
 // It assumes that the input array has at least Vector::size elements.



 // Implement the Vector::Print() method.
 // It prints the elements of the m_vec array to the console using std::cout.
 // Each element is followed by two spaces.


 // Implement an overloaded multiplication operator. 
 // It takes two Vector objects as arguments and calculates the dot product of their m_vec arrays. 
 // The dot product is calculated as the sum of the products of the corresponding elements in the two arrays.
 // For example, if the two arrays are [1, 2, 3] and [1, 4, 9], the dot product is 1*1 + 2*4 + 3*9 = 1 + 8 + 27 = 36.