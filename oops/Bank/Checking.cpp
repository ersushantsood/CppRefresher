#include "Checking.h"

//defined by initializer list or chain constructor
//commented the constructor as this class inheriting constructors from Parent
/*Checking::Checking(const std::string &name, float balance,float m_Rate):Account(name,balance),m_Rate(m_Rate){

}*/


Checking::~Checking(){

}


void Checking::WithdrawMoney(float money){
    m_Balance = m_Balance - money;
}