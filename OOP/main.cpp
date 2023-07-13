#include "Savings.h"
#include "Checking.h"
#include <iostream>

void vPerformTransactions(Account* pc_acc) {
	std::cout << "Balance before: " << std::endl;
	std::cout << pc_acc->fGetBalance() << std::endl;		
	if (typeid(*pc_acc) == typeid(Checking)) {
		std::cout << "Minimum balance: " << std::endl;
		Checking* p_checking = static_cast<Checking*>(pc_acc); // Downcasting
		std::cout << p_checking->fGetMinBalance() << std::endl;
	}
	/* Dynamic cast should be avoided due to performance
	Checking* p_checking = dynamic_cast<Checking*>(pc_acc);
	if (p_checking != nullptr) {
		//Print minimum balance of the checking account
	}*/

	pc_acc->vWithdraw(500);
	pc_acc->vDeposit(100);
	pc_acc->vAccumulateInterest();

	std::cout << "Balance after: " << std::endl;
	std::cout << pc_acc->fGetBalance() << std::endl;
}
int main() {
	Account *my_account = new Savings{ "Hien", 2000, 0.05};
	vPerformTransactions(my_account);	
	delete my_account;
	return 0;
}