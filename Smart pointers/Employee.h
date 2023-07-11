#include "Project.h"
#pragma once
class Employee
{
	std::shared_ptr<Project> sp_project;
public:
	Employee();
	~Employee();

	void vSetProject(std::shared_ptr<Project> &spProject);
	std::shared_ptr<Project>* spGetProject();

};

