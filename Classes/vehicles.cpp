#include "classes.h"
#include <iostream>

//initializing the static variable which can be initialized outside of class only
int Vehicle::colorsAvailable = 5;

/*This is the definition of the members of the class Vehicle*/
void Vehicle::Accelerate() {

    // 1. this pointer contains the address of the object created for the class
    // then compiler passes the address of object in all the functions.
 this->speed++;    //this pointer is optional
 this->fuel -=0.5f;   
}
void Vehicle::Brake(){
    this->speed =0;
}

void Vehicle::Dashboard(){
    std::cout<< speed << std::endl;
    std::cout<< Vehicle::colorsAvailable << std::endl;
}

 void Vehicle::IamReadOnlyFn()const{
    std::cout<< "I am const member function i.e readonly function" << std::endl;
}

int main(){
    using namespace std;
    Vehicle tesla;
    tesla.Accelerate();
    tesla.Dashboard();

    const Vehicle constObject;
    constObject.IamReadOnlyFn(); //I can be invoked only by const object

    Vehicle::IamStaticMemberFn(); 

}