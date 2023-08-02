#include "Contact.h"

void Contact::vDisplay() const
{	
	std::cout << s_first_name << ' ' << s_last_name << ' ' << s_primary_phone_number << ' '
		<< s_secondary_phone_number << ' ' << i_email_id << ' ' << ' ' << s_address << ' '
		<< s_company << '\n';
}
