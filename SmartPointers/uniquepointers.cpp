#include "classes.h"
#include <memory>

//method signature to return pointer variable
 VehicleWithDefaultCopyConstructor * GetVehiclePointer(){
    VehicleWithDefaultCopyConstructor *vehiclePointer = new VehicleWithDefaultCopyConstructor{};
    return vehiclePointer;
}
//Smart pointers are wrapper objects over the basic pointers to :
    //=> simplify the memory management of the pointers and these pointers call delete on underlying pointer it is holding to release the memory
    //=> no need to call delete on the pointers yourself to release memory.
//Unique pointer is a smart pointer which is created as replacement to those pointers which are used 
//locally and not shared outside with other parts of program.
void useUniquePointer(int value){
    //creating object of unique_pointer and unique pointer is a template accepting type to which unique pointer need to be created
    std::unique_ptr<VehicleWithDefaultCopyConstructor> unique_pointerObj{GetVehiclePointer()};

    if(unique_pointerObj == nullptr){
        //reset method sets new reference to underlying pointer inside unique_ptr
        unique_pointerObj.reset(new VehicleWithDefaultCopyConstructor{});
    }

    //-> is used by pointer to call method of the object its pointing to.
    unique_pointerObj->Brake();

    //getting underlying pointer from the uniquePointer
    VehicleWithDefaultCopyConstructor *underlyingPointer = unique_pointerObj.get();

}