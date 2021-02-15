#include <iostream>
#include <typeinfo>

//Avoid RTTI if possible as it adds overhead to the programs as it makes compiler to add more details in the VTable where virtual methods 
//function pointers are stored.
int main(){
    int val{};
    float fval{};
    const std::type_info &typeInfo = typeid(val); //it is same as typeof(obj) in C# and instanceof in java
    std::cout<< typeInfo.name() <<std::endl;
}