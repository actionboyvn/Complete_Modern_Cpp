#include "Employee.h"

Employee::Employee()
{
	std::cout << "Employee()" << std::endl;
}

Employee::~Employee()
{
	std::cout << "~Employee()" << std::endl;
}

std::shared_ptr<Project>* Employee::spGetProject()
{
	return &sp_project;
}

void Employee::vSetProject(std::shared_ptr<Project> &spProject)
{
	sp_project = spProject;
}
