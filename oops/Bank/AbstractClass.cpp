#include <iostream>

//abstract classes are created using pure virtual functions

//this abstract class cannot to instantiated and it has to have atleast one pure virtual func but in java its not the case . Abstract class can exist without abstract functions
class abstractClass {
    virtual void pureVirtualFn() = 0;  // = 0 makes the function as pure virtual

};
