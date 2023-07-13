#pragma once
#include "Account.h"
#include <string>
class Checking :
    public Account
{
    float f_min_balance;
public:    
    Checking(const std::string& sName, float fBalance, float fMinBalance); //using Account::Account; -> Inherit a constructor
    ~Checking();

    void vWithdraw(float fAmount) override;
    float fGetMinBalance() const;
};

