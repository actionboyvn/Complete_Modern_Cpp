#pragma once
#include <string>
#include <iostream>
using namespace std;
enum class Group{FRIENDS, FAMILY, COWORKER, ACQUAINTANCE};
class Contact
{
public:
	string s_first_name;
	string s_last_name;
	string s_primary_phone_number;
	string s_secondary_phone_number;
	int i_email_id;
	string s_address;
	string s_company;
	Group e_group;

	Contact(string sFirstName, string sLastName, string sPrimaryPhoneNumber,
		string sSecondaryPhoneNumber, int iEmailId, string sAddress, string sCompany,
		Group eGroup):s_first_name(sFirstName),s_last_name(sLastName),
		s_primary_phone_number(sPrimaryPhoneNumber),s_secondary_phone_number(sSecondaryPhoneNumber),
		i_email_id(iEmailId),s_address(sAddress),s_company(sCompany),e_group(eGroup){
	};
	~Contact() {
	};		

	void vDisplay() const;
};

