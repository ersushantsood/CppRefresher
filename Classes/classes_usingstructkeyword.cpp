#include <iostream>

using namespace std;
//When class is created with struct keyword , all the members are created PRIVATE by default
//In c++ classes and structs are same . Only difference is that members of struct are by default 
// public whereas members of call are by default private , if access specifier is not mentioned

struct Timemachine {
    private :
        int year;
    public :
        void addYear(){
        year++;
    }
    public :
        void setYear(int newyear){
        year = newyear;
    }
    int getYear(){
        return year;
    }
};

int main(){
    Timemachine clock;
    clock.setYear(2018);
    clock.addYear();
    cout<< "Incremeted Year : "<< clock.getYear();
}