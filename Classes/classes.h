#pragma once
#include <iostream>

/*This is the decalaration of the members of the class*/
class Vehicle {

private:
    float fuel { 0 };
    char *type = new char[8] {'t','r','u','c','k'};
    int passengers { 0 };
    float speed { 0 };
    // auto i = 5; //auto does not work in non-static initializers

    //static member can only be initialized outside of the class.
    static int colorsAvailable;
public:
    void AddFuel(float amount);
    void Accelerate();
    void Brake();
    void AdaptiveCruiseControl(bool enable);
    void Dashboard();
    void IamReadOnlyFn()const; //I can be invoked only by const object
    static void IamStaticMemberFn(){
        std::cout<<"I am static member and can access only static members";
    }
};

class VehicleWithDefaultCopyConstructor {
    int *pointer_member;
    private:
    float fuel { 0 };
    char *type = new char[8] {'t','r','u','c','k'};
    int passengers { 0 };
    float speed { 0 };
    // auto i = 5; //auto does not work in non-static initializers

    //static member can only be initialized outside of the class.
    static int colorsAvailable;
public:
    VehicleWithDefaultCopyConstructor();
    VehicleWithDefaultCopyConstructor(int i);
    ~VehicleWithDefaultCopyConstructor(); //destructor
    int GetValue();
    void SetValue(int i);
    void AddFuel(float amount);
    void Accelerate();
    void Brake();
    void AdaptiveCruiseControl(bool enable);
    void Dashboard();
    void IamReadOnlyFn()const; //I can be invoked only by const object
    static void IamStaticMemberFn(){
        std::cout<<"I am static member and can access only static members";
    }
};

class VehicleWithExplicitCopyConstructor {
    int *pointer_member;
    private:
    float fuel { 0 };
    char *type = new char[8] {'t','r','u','c','k'};
    int passengers { 0 };
    float speed { 0 };
    // auto i = 5; //auto does not work in non-static initializers

    //static member can only be initialized outside of the class.
    static int colorsAvailable;

public:
    VehicleWithExplicitCopyConstructor();
    VehicleWithExplicitCopyConstructor(int i);
    ~VehicleWithExplicitCopyConstructor(); //destructor

    //Explicit Copy Constructor
    VehicleWithExplicitCopyConstructor(VehicleWithExplicitCopyConstructor &copy);

    int GetValue();
    void SetValue(int i);
    void AddFuel(float amount);
    void Accelerate();
    void Brake();
    void AdaptiveCruiseControl(bool enable);
    void Dashboard();
    void IamReadOnlyFn()const; //I can be invoked only by const object
    static void IamStaticMemberFn(){
        std::cout<<"I am static member and can access only static members";
    }
};