#include "Account.h"
#include <iostream>

int Account::s_AcctGenerator = 10000;
Account::Account(const std::string &name, float balance):
m_Name(name), m_Balance(balance) {
    m_AccNo = ++s_AcctGenerator;
}

Account::~Account(){

}

float Account::GetBalance()const{

}  //functions which doesnot modify the state of the class, are marked as const
    int Account::GetAccountNo()const {
        return this->m_AccNo;
    }

    void Account::CollectInterest(){

    }
    void Account::WithdrawMoney(float amount){
        m_Balance = m_Balance - amount;
    }
    void Account::DepositMoney(float amount){
        m_Balance = m_Balance + amount;
    }

    float Account::GetRateOfInterest()const{
        return 0.0f;
    }
