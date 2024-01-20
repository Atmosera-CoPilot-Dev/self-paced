# C++ Vector

This exercise will give you an opportunity to use prompt engineering to implement the methods of a Vector class in the `starter` folder.

## Instructions

- Use Copilot to find the file containing the entrypoint `main()`. This file does not need to be changed.

- Use Copilot to implement the vector methods in the file Vector.cpp

- There are 5 methods that you need to implement. The first two are the constructor and destructor. The constructor initializes the m_vec member variable as a new integer array of size size. The destructor deallocates the memory that was previously allocated for the m_vec array in the constructor.

- The next two methods are Set and Print. The Set method sets the values of the m_vec array. It takes a pointer to an integer array as an argument and copies the values from the input array to m_vec. It assumes that the input array has at least size elements. The Print method prints the elements of the m_vec array to the console using cout. Each element is followed by two spaces.

- The last method is an overloaded multiplication operator. It takes two Vector objects as arguments and calculates the dot product of their m_vec arrays. The dot product is calculated as the sum of the products of the corresponding elements in the two arrays.

- Once you have implemented all the methods, compile and run the program.
