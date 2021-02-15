#include "Account.h"
#include "Checking.h"
#include "iostream"

int mina() {
    Checking checkingAcc("Sood", 100);
    //dynamic binding or runtime polymorphism
    Account *account = &checkingAcc;

    //below is invalid until account is explicitly casted with Checking class  , as account can be any like Savings etc.
    //Checking *pcheckingAcc = account;

    //this is downcasting from Account to Checking, static_cast does casting at compile time
    Checking *pcheckingAcc = static_cast<Checking*>(account);

    //Use dynamic_cast does casting at runtime by checking typeof object and helps avoid the use of RTTI typeid to check the type of child object which dynamic binded to parent
    //Avoid RTTI or dynamic_cast if possible as it adds overhead to the programs as it makes compiler to add more details in the VTable where virtual methods 
    //function pointers are stored. dynamic_cast goes through all the hierarchy of child objects to decide the cast
    Checking *pdynamicChecking = dynamic_cast<Checking*>(account);
}