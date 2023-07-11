#include <iostream>
#include <memory>
#include "Integer.h"
#include "Employee.h"
Integer* pGetPointer(int iVal) {
	Integer* p_new = new Integer{ iVal };
	return p_new;
}

void vPrint(Integer* p_obj) {
	if (p_obj == nullptr)
		return;
	std::cout << p_obj->iGetVal() << std::endl;
}

void vPrintUniquePointer(std::unique_ptr<Integer>& up_obj) {
	//std::cout << up_obj.get()->iGetVal() << std::endl;
	std::cout << up_obj->iGetVal() << std::endl;
	//std::cout << (*up_obj).iGetVal() << std::endl;	
}
void TestUniquePointers() {
	std::unique_ptr<Integer> up_new{pGetPointer(5)};
	if (up_new == nullptr)
		up_new.reset(new Integer{});
	(*up_new).vSetVal(100);
	vPrint(up_new.get());
	up_new.reset(new Integer{});
	(*up_new) = 8;	
	vPrintUniquePointer(up_new);
	std::unique_ptr<Integer> up_another{std::move(up_new)};//Moving the ownership of the underlying pointer	
}
void TestSharedPointers() {
	std::shared_ptr<Project> sp_project = std::make_shared<Project>("New project 1");
	std::shared_ptr<Employee> sp_employee1 = std::make_shared<Employee>();
	sp_employee1->vSetProject(sp_project);
	std::shared_ptr<Employee> sp_employee2 = std::make_shared<Employee>();
	sp_employee2->vSetProject(sp_project);
	std::shared_ptr<Employee> sp_employee3 = std::make_shared<Employee>();
	sp_employee3->vSetProject(sp_project);

	sp_employee3.reset();

	std::cout << sp_project.use_count() << std::endl;
}
int main() {
	//TestUniquePointers();
	TestSharedPointers();
	return 0;
}