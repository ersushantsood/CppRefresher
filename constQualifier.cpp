#include <iostream>

void Print(const int &ref);

int main(){
    using namespace std;
    const int PI = 3.14f;
    const int *ptr = &PI;
    //*ptr = 3.6; not allowed
    int x =1;
    ptr = &x;

    //to restrict the updation of address as well , 
    //create const pointer
    const int *const ptr2 = &PI;
    int y =2;
    //ptr2 = &y;  // this is not allowed

    Print(1);

    return 0;
}

void Print(const int &ref){
    std::cout<<ref<<std::endl;
}