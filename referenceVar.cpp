#include <iostream>

int main(){
    using namespace std;
    //&ref is a reference variable which is bound to referent x
    //ref contains same value as x as it refers to the address of x
    int x = 5;
    int &ref = x;
    cout<<"x: "<<x<< endl;
    cout<< "ref: "<<ref <<endl;

    cout<< "address of x: "<<&x<<endl;
    cout<< "address of ref: "<< &ref<< endl;

    const int PI = 3.14;
    const int &refconst = PI; 
}