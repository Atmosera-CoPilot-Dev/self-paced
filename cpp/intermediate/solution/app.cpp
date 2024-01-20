#include <iostream>
#include <functional>
#include <vector>

using std::cout, std::endl;

// this returns a function that will square the argument
auto sqrGen() {
	return [=](int m)->int {return m * m;};
}

// this returns a function that will cube the argument
auto cubeGen() {
	return [](int m)->int {return m * m * m;};
}

int ar[] = {10, 20, 30, 40, 50};

int main(int argc, char* argv[]) {
    // declare an std::vector v to match the gen functions
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
