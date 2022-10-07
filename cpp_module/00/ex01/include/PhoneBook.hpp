#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

# include "Contact.hpp"

class PhoneBook
{
	int     contacts_list_size;
	Contact contacts_list[MAX_CONTACTS];

public:
	PhoneBook() 
	:
		contacts_list_size(0) 
	{};

	void AddContact(std::string[5]);

	int GetContactsNumber()                 const;
	const Contact& GetContact(int) const;
};

#endif