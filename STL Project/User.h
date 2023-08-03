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

	template<typename T>
	void vAddContact(T&& contact) {
		v_contacts.push_back(std::forward<T>(contact));		
	};

	template<typename ...Params>
	void vAddContact(Params&& ...args) {
		v_contacts.emplace_back(std::forward<Params>(args)...);		
	}

	void vDisplayContacts(int iOption);
	void vDisplayFirstNamesAndPrimaryNumbers() const;
	void vDisplayContactsFromTheCompany() const;
	void vDisplayContactsBasedOnGroup(Group eGroup) const;
	std::vector<Contact> pcSearchContact(int iOption, std::string sName);
	void vDisplayContactCount(std::string sCompany, Group eGroup) const;	
};

