#include <iostream>
#include "Account.h"
#include "Savings.h"
#include "Transaction.h"
#include <string>

int main()
{
    const std::string name = "Sood";
    Account myAccount(name,0);
   
    Savings mySavings(name,200,0.5);
    Transact(&mySavings);
    myAccount.DepositMoney(100);
    mySavings.DepositMoney(2000);
}