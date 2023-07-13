#pragma once
#include <string>
class Account
{
	std::string s_name;
	int i_number;	
	static int si_number_generator;
protected:
	float f_balance;
public:
	Account(const std::string& sName, float fBalance);
	virtual ~Account();

	const std::string sGetName() const;
	int iGetNumber() const;
	float fGetBalance() const;
	virtual float fGetRate() const;

	virtual void vWithdraw(float fAmount);
	void vDeposit(float fAmount);
	virtual void vAccumulateInterest();
};

