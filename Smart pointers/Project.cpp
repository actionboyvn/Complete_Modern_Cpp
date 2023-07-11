#include "Project.h"

Project::Project():Project("Default")
{
}

Project::Project(std::string sProjectsName)
{
	s_name = sProjectsName;
	std::cout << "Project()" << std::endl;
}

Project::~Project()
{
	std::cout << "~Project()" << std::endl;
}

void Project::vSetProjectsName(std::string sProjectsName)
{
	s_name = sProjectsName;
}

std::string Project::sGetProjectsName()
{
	return s_name;
}
