#include <iostream>

using namespace std;
//When class is created with struct keyword , all the members are created PRIVATE by default

//struct with constructor
struct Timemachine {
    //constructor
    Timemachine(){
    year = 2019;
    }
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

//constructor with parameter
struct TimeMachineWithParam {
    //constructor
    TimeMachineWithParam(int year_input){
    year = year_input;
    }
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
    Timemachine clock ;
    clock.addYear();
    //constructor with param
    TimeMachineWithParam clockParam {2070};
    clockParam.addYear();
    //clock.setYear(2018);
    cout<< "Incremeted Year : "<< clock.getYear();
    cout<< "\n Year initialized by passing into constructor: " << clockParam.getYear();
}