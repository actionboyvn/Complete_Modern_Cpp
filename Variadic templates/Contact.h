#pragma once
#include <string>
class Contact
{
	std::string s_name;
	std::string s_phone_number;
	std::string s_email;
	std::string s_address;
public:
	Contact();
	Contact(std::string sName, std::string sPhoneNumber, std::string sEmail, std::string sAddress);
	~Contact();

	std::string sGetName() const;
	std::string sGetPhoneNumber() const;
};

inline Contact::Contact():s_name(),s_phone_number(),s_email(),s_address()
{
}

inline Contact::Contact(std::string sName, std::string sPhoneNumber, std::string sEmail, std::string sAddress):
	s_name(sName),s_phone_number(sPhoneNumber),s_email(sEmail),s_address(sAddress)
{
}

inline Contact::~Contact()
{
}

inline std::string Contact::sGetName() const
{
	return s_name;
}

inline std::string Contact::sGetPhoneNumber() const
{
	return s_phone_number;
}

