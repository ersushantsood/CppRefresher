#include "DelegatingConstructors.h"
#include <iostream>


//chaining the constructor 
ChainOrDelegateConstructorCalls::ChainOrDelegateConstructorCalls():ChainOrDelegateConstructorCalls(4.0){
    std::cout<< "Value of Num is initialized to: "<<this->num;
}

ChainOrDelegateConstructorCalls::ChainOrDelegateConstructorCalls(float changeVal):ChainOrDelegateConstructorCalls(4.0,0.5){
    std::cout<<"Calling chained single arg constructor"<<std::endl;
}

ChainOrDelegateConstructorCalls::ChainOrDelegateConstructorCalls(float changeVal, float delta){
    this->num = changeVal+delta;
}

int main(){
    ChainOrDelegateConstructorCalls delegatingCons;
}