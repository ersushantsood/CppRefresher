#include "Account.h"

class Checking: public Account {
public:
    //child class inheriting constructors from Parent. This can be used only if Checking class does not have its own private member variables
    using Account::Account;
   // Checking(const std::string &name, float balance, float rate);
    ~Checking();
    float GetRateOfInterest()const;
    void WithdrawMoney(float amount);
};