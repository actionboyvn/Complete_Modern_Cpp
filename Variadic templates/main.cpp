#include <iostream>
#include "Employee.h"
#include "Contact.h"

template<typename T, typename ...Params>
T* CreateObject(Params ...args) {
	return new T(args...);
}
int main() {
	int* i_num = CreateObject<int>(513);
	std::cout << *i_num << std::endl;

	std::string* s_name = CreateObject<std::string>("Van Hien");
	std::cout << *s_name << std::endl;
	
	Contact* c_new_contact = CreateObject<Contact>("Michal", "0124123123", "michal.nguyen@gmail.com", "Poland");
	std::cout << c_new_contact->sGetName() << ' ' << c_new_contact->sGetPhoneNumber() << '\n';

	Employee* c_new_employee = CreateObject<Employee>("Marek", 1, 5000);
	std::cout << c_new_employee->sGetName() << '\n';

	delete i_num;
	delete s_name;
	delete c_new_contact;
	delete c_new_employee;
	return 0;
}