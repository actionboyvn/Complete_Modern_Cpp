#include "Checking.h"
#include <iostream>
Checking::Checking(const std::string& sName, float fBalance, float fMinBalance):Account(sName, fBalance)
{
	f_min_balance = fMinBalance;
	std::cout << "Checking()" << std::endl;
}

Checking::~Checking()
{
	std::cout << "~Checking()" << std::endl;
}

void Checking::vWithdraw(float fAmount)
{
	if (f_balance - fAmount >= 50)
		Account::vWithdraw(fAmount);
	else
		std::cout << "Withdrawal failed - Invalid amount" << std::endl;
}

float Checking::fGetMinBalance() const
{
	return f_min_balance;
}
