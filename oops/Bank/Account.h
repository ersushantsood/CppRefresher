#pragma once
#include <string>

class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_AcctGenerator;
protected:
    float m_Balance;

//base class should always have a virtual destructor as in case of dynamic binding, 
    //when you delete parent class pointer , 
    //runtime will only call the destructor of parent and not the child if Destructor of parent is not marked virtual
    //Account *acct = new Savings("sood",100,0.5);
    //delete acc;
public:
    Account(const std::string &name, float balance);
    
    virtual ~Account();
    const std::string GetAccountName()const;
    float GetBalance()const;  //functions which doesnot modify the state of the class, are marked as const
    int GetAccountNo()const;

    virtual void CollectInterest();  
    //virtual keyword directs compiler to generated code to run Overridden method by the Parent Class object 
    //when dynamic binding or runtime polymorphism is implemented like Parent parent = new child{}; or Parent parent = child;
    //Compiler actually generates some code when it sees virtual keyword and these virtuals methods only work if invoked only using pointer/reference to the object
    virtual void WithdrawMoney(float amount);
    virtual void DepositMoney(float amount);
    float GetRateOfInterest();
};

//How Virtual methods work
/*
When compiler sees the virtual methods , it creates Virtual table/array and adds the 
functionpointer to these methods in the virtual table . virtual tables are created for
all the child classes as well. Addres of that table/array is stored in new pointer in the
class.
                                Account
VirtualTable   <-------------   virtual pointer (member pointer variable)
&Account::WithdrawMoney
&Account::DepositMoney
&Account::CollectInterest

//during dynamic binding , compiler will first find the object(Account) address
then it finds the virtual pointer which points to virtual table , then to access the
method's function pointer , compiler adds the offset in the virtual table address and 
calls the method using that function pointer.

//ONE CANNOT OVERRIDE THE NON-VIRTUAL METHODS THEN
*/