#include "Transaction.h"
#include <iostream><<

void Transact(Account * account){
    std::cout << "Transaction started" << std::endl;
    std::cout << "Initial balance" << account->GetBalance() << std::endl;
    account->DepositMoney(100);
    account->CollectInterest();
    account->WithdrawMoney(30);
}