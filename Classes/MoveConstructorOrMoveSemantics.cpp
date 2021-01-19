/*
Move Symantics is where state of the source object is moved to the destination object instead of deep copying the source object to destination.
Either use only Move constructor or use std::Move function to force invoke Move constructor
auto dest_obj(std::move(source_obj)) where move converts a into r-value and force move constructor invocation.

Details :
1.Copy Constructor derives Copy semantics which is used when Copy constructor is called and object is deep copied.
2.Move Constructor derives Move Semantics where pointers in the source object being assigned are moved and pointed to NULLPTR
  and pointer in the new object created is pointed to the existing address which was pointed by pointer in source object.
3.Move Semantics are used where objects are being created as temporary r-values as part of any expression evaluation.
4.When Copy and Move constructor are added , then for temporary or rvalue oobjects, Move constructor is always called
*/

/*RULE of 5 
If user implements Destructor , now should implement all 5 mentioned below
1. Destructor
2.Copy Constructor or Copy semantics
3.Copy assignment operator
4.Move Constructor
5.Move assignment operator
*/

#include <iostream>

class DataStructure {
    int data_holder;
    int *pointer_member;
    char type;

public:
    /*DataStructure(){
        data_holder = 0;
        type = 's';
    }*/
    //Use Default to create default constructor
    DataStructure() = default;
    //default of a copy constructor. Default can be used only for functions created by compiler
    //DataStructure(const DataStructure &) = default;
    DataStructure(const DataStructure & copy){
        std::cout<< "Calling Copy Constructor DataStructure(const DataStructure &)" << std::endl;
        this->pointer_member = new int(*copy.pointer_member);
    }

    //MOVE Constructor for Move Semantics where data will be stolen from temporary obj 
    //passed to r-value reference during assignment and it will be done by creating a SHALLOW copy of temp obj
    DataStructure(DataStructure &&obj){
        std::cout<< "Calling the Move constructor";
        //shallow copy of addresses so both object point to same address
        this->pointer_member = obj.pointer_member;
        obj.pointer_member = nullptr;  //pointing the source object pointer to NULL
    }

    //If you want to prevent the defaulting of functions created by compiler
   //DataStructure(const DataStructure &) = delete;


    DataStructure(int value){
        std::cout<<"Calling Parameterized Constructor DataStructure(int value)"<<std::endl;
        data_holder = value;
        this->type = 'i';
    }

    DataStructure(int value,char type){
        data_holder = value;
        this->type = type;
    }

    int GetValue(){
        return this->data_holder;
    }

    void SetValue(int data){
        this->pointer_member = &data;
        this->data_holder = data;
    }

    
};

DataStructure add(DataStructure &x,DataStructure &y){
    DataStructure temporary;
    temporary.SetValue(x.GetValue() + y.GetValue());
    return temporary;
}

int main() {
    DataStructure datahold;
    std::cout<< datahold.GetValue();

    DataStructure x(1),y(5);
    datahold.SetValue(add(x,y).GetValue());
    return 0;
}