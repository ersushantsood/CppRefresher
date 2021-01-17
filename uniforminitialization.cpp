#include <iostream>

int main() {
    int a{}; //Uniform initialization
    int a1{5}; //Direct initialization
    int a2 = 0; //Copy initialization

    int arr[8]{}; //Uniform Value initialization

    int arra[8] = {1,2,3,4,5,6}; //Aggregate initialization with Copy initialization
 
    std::cout << "*************Direct initialization**** a1: " << a1;

/*
1. Value initialization : where variable is initialized with default value of type => T obj{}
2. Direct Initialization => T obj{value}
3. Copy Initialization T obj = value // THIS SHOULD BE AVOIDED and uniform init should be PREFERRED

COPY init first stores the RHS value to temp variable or location and copy it to LHS variable location. So it should be avoided.
*/
}