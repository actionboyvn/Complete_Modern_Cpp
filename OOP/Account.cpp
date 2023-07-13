#include "Account.h"
#include <iostream>

int Account::si_number_generator = 1000000;

Account::Account(const std::string& sName, float fBalance):s_name(sName), f_balance(fBalance)
{
	i_number = ++si_number_generator;
	std::cout << "Account()" << std::endl;
}

Account::~Account()
{
	std::cout << "~Account()" << std::endl;
}

const std::string Account::sGetName() const
{
	return s_name;
}

int Account::iGetNumber() const
{
	return i_number;
}

float Account::fGetBalance() const
{
	return f_balance;
}

float Account::fGetRate() const
{
	return 0.0f;
}

void Account::vWithdraw(float fAmount)
{
	if (f_balance >= fAmount)
		f_balance -= fAmount;
	else
		std::cout << "Insuficient balance, withdrawal failed" << std::endl;
}

void Account::vDeposit(float fAmount)
{
	f_balance += fAmount;
}

void Account::vAccumulateInterest()
{
}
