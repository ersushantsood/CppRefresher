#include "Savings.h"

//defined by initializer list or chain constructor
Savings::Savings(const std::string &name, float balance,float m_Rate):Account(name,balance),m_Rate(m_Rate){

}
Savings::~Savings(){

}

float Savings::GetRateOfInterest()const{
    return m_Rate;
}

void Savings::CollectInterest(){
    m_Balance += (m_Balance * m_Rate);
}