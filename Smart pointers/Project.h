#include <iostream>
#pragma once
class Project
{
	std::string s_name;
public:
	Project();
	Project(std::string sProjectsName);
	~Project();

	void vSetProjectsName(std::string sProjectsName);
	std::string sGetProjectsName();
	
	
};

