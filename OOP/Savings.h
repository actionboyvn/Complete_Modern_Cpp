#pragma once
#include "Account.h"
#include <string>
class Savings : public Account
{
	float f_rate;	
public:
	Savings(const std::string& sName, float fBalance, float fRate);
	~Savings();

	float fGetRate() const override;
	void vAccumulateInterest() override;
};

