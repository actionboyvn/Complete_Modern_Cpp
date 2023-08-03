#include "User.h"

void User::vDisplayContacts(int iOption)
{
	if (iOption == 0) {
		std::sort(v_contacts.begin(), v_contacts.end(), [](const Contact& contactA, const Contact& contactB) {
			return contactA.s_first_name < contactB.s_first_name;
			});
	}
	else {
		std::sort(v_contacts.begin(), v_contacts.end(), [](const Contact& contactA, const Contact& contactB) {
			return contactA.s_last_name < contactB.s_last_name;
			});
	}
	for (const auto& c : v_contacts)
		c.vDisplay();
}

void User::vDisplayFirstNamesAndPrimaryNumbers() const
{
	for (const auto& c : v_contacts)
		std::cout << c.s_first_name << ' ' << c.s_primary_phone_number << '\n';
}

void User::vDisplayContactsFromTheCompany() const
{
	struct ContactsFromCompany {
		std::vector<Contact> v_company_contacts;
		std::string s_company;
		ContactsFromCompany(std::string sCompany) :s_company(sCompany) {
		};
		void operator()(const Contact& contact) {
			if (contact.s_company == s_company)
				v_company_contacts.push_back(contact);
		}
	};
	auto c_contacts = std::for_each(v_contacts.begin(), v_contacts.end(), ContactsFromCompany(s_company));
	for (const Contact& c : c_contacts.v_company_contacts)
		c.vDisplay();
}

void User::vDisplayContactsBasedOnGroup(Group eGroup) const
{
	for (const Contact& c : v_contacts)
		if (c.e_group == eGroup)
			c.vDisplay();
}

std::vector<Contact> User::pcSearchContact(int iOption, std::string sName)
{
	std::vector<Contact> v_contacts_searched{};
	for (const Contact& c : v_contacts)
		if (iOption == 0 && c.s_first_name == sName ||
			iOption == 1 && c.s_last_name == sName)
			v_contacts_searched.push_back(c);
	return v_contacts_searched;
}

void User::vDisplayContactCount(std::string sCompany, Group eGroup) const
{
	int i_count{};
	std::for_each(v_contacts.begin(), v_contacts.end(), [&](const Contact& contact) {
		if (contact.s_company == sCompany && contact.e_group == eGroup)
			i_count++;
		});
	std::cout << "Count: " << i_count << '\n';
}
