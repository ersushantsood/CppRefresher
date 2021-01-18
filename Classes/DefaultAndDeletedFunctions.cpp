#include <iostream>

class DataStructure {
    int data_holder;
    char type;

public:
    /*DataStructure(){
        data_holder = 0;
        type = 's';
    }*/
    //Use Default to create default constructor
    DataStructure() = default;
    //default of a copy constructor. Default can be used only for functions created by compiler
    DataStructure(const DataStructure &) = default;

    //If you want to prevent the defaulting of functions created by compiler
    DataStructure(const DataStructure &) = delete;

    DataStructure(int value,char type){
        data_holder = value;
        this->type = type;
    }

    int Get(){
        return this->data_holder;
    }

    
};

int main() {
    DataStructure datahold;
    std::cout<< datahold.Get();
    return 0;
}