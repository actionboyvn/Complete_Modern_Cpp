#pragma once
#include "Contact.h"
#include <vector>
#include <iostream>
#include <algorithm>
class User
{
	std::string s_name;
	std::string s_company;
	std::vector<Contact> v_contacts;
public:
	User(std::string sName, std::string sCompany) :s_name(sName), s_company(sCompany){
	};
	~User() {
	};
	void vAddContact(const Contact& pc_other);
	void vAddContact(Contact&& pc_contact) noexcept;
	void vDisplayContacts(int iOption);
	void vDisplayFirstNamesAndPrimaryNumbers() const;
	void vDisplayContactsFromTheCompany() const;
	void vDisplayContactsBasedOnGroup(Group eGroup) const;
	std::vector<Contact> pcSearchContact(int iOption, std::string sName);
	void vDisplayContactCount(std::string sCompany, Group eGroup) const;	
};

