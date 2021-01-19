/*
1. Copy Constructors create copy of an object state into another object.
2. By default, Copy constructor will just copy values.
3. If you have not add one copy constructor , then compiler adds one default on its own.
3. Copy Constructors dont work well with pointers, so create your own for pointers.
*/

#include <iostream>
#include "classes.h"

VehicleWithDefaultCopyConstructor::VehicleWithDefaultCopyConstructor(){
    //allocate a member of size int and init with 0
    pointer_member = new int(0);
}

VehicleWithDefaultCopyConstructor::VehicleWithDefaultCopyConstructor(int value){
    pointer_member = new int(value);
}

int VehicleWithDefaultCopyConstructor::GetValue(){
    return *pointer_member;
}

void VehicleWithDefaultCopyConstructor::SetValue(int value){
    *pointer_member = value;
}

VehicleWithDefaultCopyConstructor::~VehicleWithDefaultCopyConstructor(){
    // delete pointer_member;
}

void PrintVehicle(VehicleWithDefaultCopyConstructor &vehicle){

}

//Explicit Copy Constructor called when you perform object assignment in any way
VehicleWithExplicitCopyConstructor::VehicleWithExplicitCopyConstructor(VehicleWithExplicitCopyConstructor &copy){
    //This is called deep copy
    pointer_member = new int(*copy.pointer_member);
}

/*Here when you use default copy constructor and use pointers, It will
    copy the the address only , so it will be a Shallow copy.
    int *p2 = p1; So any change in one copy , will reflect in other copies

    But we want to do Deep copy , means we want to copy the value at the address
    by creating a new memory location and copy the value at address. So its good
    to perform Deep copy.
    
    //Deep copy , creating a new memory location and initialize with value at p1 i.e *p1
    int *p4 = new int(*p1);
    */
int main() {
    VehicleWithDefaultCopyConstructor vehicle(5);
    std::cout<< vehicle.GetValue() <<std::endl;

    //Copying just an object which means I am just taking the value of object
    //and assigning it to other.

    //this is default copy constructor
    VehicleWithDefaultCopyConstructor vehicle2(vehicle);

    //I am copying the vehicle here by passing it to function
   // PrintVehicle(vehicle);

    return 0;
}