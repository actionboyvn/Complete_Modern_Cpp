#pragma once
#include <string>
class Employee
{
	std::string s_name;
	int i_id;
	float f_salary;
public:
	Employee();
	Employee(std::string sName, int iId, float fSalary);
	~Employee();

	std::string sGetName() const;
};

inline Employee::Employee() :s_name(), i_id(), f_salary()
{
}

inline Employee::Employee(std::string sName, int iId, float fSalary) :s_name(sName)
				, i_id(iId), f_salary(fSalary) 
{
}

inline Employee::~Employee() {
}

inline std::string Employee::sGetName() const
{
	return s_name;
}
