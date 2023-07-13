#include "Savings.h"
#include <iostream>
Savings::Savings(const std::string& sName, float fBalance, float fRate):Account(sName, fBalance), f_rate(fRate)
{	
	std::cout << "Savings()" << std::endl;
}

Savings::~Savings()
{
	std::cout << "~Savings()" << std::endl;
}


float Savings::fGetRate() const
{
	return f_rate;	
}

void Savings::vAccumulateInterest()
{
	f_balance += f_balance * f_rate;
}
