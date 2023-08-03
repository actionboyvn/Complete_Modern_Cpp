#include "User.h"
#include <iostream>

void vAddRandomContacts(User& pc_user) {	
	Contact c{ "Hien", "Le", "0123456789", "", 1, "Wroclaw", "Nokia", Group::FRIENDS };	
	pc_user.vAddContact(c);	
	
	pc_user.vAddContact(Contact("Michal", "Nguyen", "0643861354", "0985271963", 2, "Wroclaw", "Nokia", Group::COWORKER));
	pc_user.vAddContact(Contact("Marek", "Vo", "0531456789", "", 2, "Krakow", "Dolby", Group::FAMILY));

	pc_user.vAddContact("Gosia", "Le", "0531431689", "", 2, "Wroclaw", "Dolby", Group::FAMILY);
}
int main() {
	User u{ "User" , "Nokia"};
	vAddRandomContacts(u);
	u.vDisplayContacts(0);
	u.vDisplayContactsFromTheCompany();
	u.vDisplayContactCount("Nokia", Group::FRIENDS);
	return 0;
}