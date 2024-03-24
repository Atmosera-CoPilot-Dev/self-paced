/*
This file demonstrates the use of lambda functions and std::function in the context of a vector of functions.
The program declares two functions sqrGen and cubeGen that return lambda functions that will square
and cube the argument passed to the lambda respectively.
The program then declares a vector of std::function<int(int)> and pushes the lambda functions returned by sqrGen and cubeGen into the vector.
The program then iterates through an array of integers and prints the integer, the square of the integer and the cube of the integer.
*/

#include <iostream>
#include <functional>
#include <vector>

using std::cout, std::endl;

/*
Create a function 'sqrGen' which returns a lamda function
that will square the argument passed to the lambda
Example usage:
auto sqr = sqrGen(); int result = sqr(5); // result will be 25
*/
auto sqrGen() {
    return [](int m)->int {return m * m;};
}

/*
Create a function 'cubeGen' which returns a lamda function
that will square the argument passed to the lambda
Example usage:
auto cube = cubeGen(); int result = cube(5); // result will be 125
*/
auto cubeGen() {
	return [](int m)->int {return m * m * m;};
}

int ar[] = {10, 20, 30, 40, 50};

int main(int argc, char* argv[]) {
    // declare an std::vector v to match the sqrGen and cubeGen functions
	std::vector<std::function<int(int)>> v;

    // push sqrGen and cubeGen into vector
    v.push_back( sqrGen());
    v.push_back( cubeGen());

    // for every n in array ar print n, square of n and cube of n
    // sample row: n: 10   Squared: 100    Cubed: 1000
    for (auto n : ar){
        cout << "n: "
             << n
             << "\tSquared: " 
             << v[0](n) 
             << "\tCubed: " 
             << v[1](n)
             << endl;
    }
 
 	return 0;
}
