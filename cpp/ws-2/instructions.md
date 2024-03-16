Use Copilot to help wrte C++ code that demonstrates the use of lambda functions and the std::function class template.

Here's a breakdown of the assignment:

1) Create functions `sqrGen` and `cubeGen` that return lambda functions. The lambda functions take an integer as input and return its square and cube, respectively.

2) Declare an array `ar` and initilize with five elements: (eg. 10, 20, 30, 40, 5).

3) In the main function, declare a vector `v` of `std::function` objects. std::function is a general-purpose polymorphic function wrapper. In this case, it's used to store any callable taking one int and returning an int.

4) The lambda functions returned by `sqrGen` and `cubeGen` will need to be added to the vector `v`.

5) Iterate over each element `n` in the array `ar`. For each `n`,  print `n`, the square of `n` (computed using the first function in vector `v`), and the cube of `n` (computed using the second function in vector `v`).

The output of this program will be the numbers 10, 20, 30, 40, 50, along with their squares and cubes.
