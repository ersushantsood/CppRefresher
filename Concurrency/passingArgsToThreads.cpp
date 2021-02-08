#include <iostream>
#include <list>
#include <thread>
#include <string>
std::list<int> lstData;
const int listSize = 600000;

class String {
public:
    String() {
        std:: cout << "String()" << std::endl;
    }
    //Copy constructor
    String(const String&){
        std::cout << "This is copy constructor String(const)"<< std::endl;
    }

    //assignment operator overloading: its special functions which called when overloaded operator is used, as compiler substitute the operator with function
    //global functions created for opOverloading have 2 args
    String & operator=(const String&){
        std::cout<< "operator overloading for assignment operator =" << std::endl;

        return *this;
    } 

    ~String(){
        std::cout<< "Calling destructor" << std::endl;
    }
};

void LongOperation(std::string &arg){
    std::cout << "[Starting long blocking operation with arg] "<< arg << std::endl;
    for(int i=0;i < listSize; i++){
        lstData.push_back(i);
    }
}

int main(){
    std::string arg{"threadarg2"};
    std::cout << "[Main Operation started]" << std::endl;
    //Passing callable function in the thread constructor and additional arg
    //always pass args to threads by ref , as threads copy the args to another local arg
    std::thread parallelThread(LongOperation,std::ref(arg));
    //if you want to detach the thread from the main thread you can detach it but then that thread is not joinable
    parallelThread.detach();
    std::cout << "[Main operation completed]" << std::endl;
    if( parallelThread.joinable()){
        parallelThread.join();
    }

    //as you made child thread detached so main function would not wait for child thread , so to pause the main use system("Pause")
    system("pause");
    return 0;
}