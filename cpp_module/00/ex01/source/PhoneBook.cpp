#include "PhoneBook.hpp"
#include "utils.hpp"

int PhoneBook::GetContactsNumber() const
{
    return (this->contacts_list_size);
}

const Contact& PhoneBook::GetContact(int index) const
{
    return (this->contacts_list[index]);
}

void PhoneBook::AddContact(std::string info_fields[5])
{
    /*
    void(Contact::*setters[5])(std::string) = 
    {
        &Contact::SetSecret,
        &Contact::SetNickname,
        &Contact::SetLastName,
        &Contact::SetFirstName,
        &Contact::SetPhoneNumber
    };

    for (int i = 0; i < 5; i++)
        (this->contacts_list[this->contacts_list_size].*setters[i])(info_fields[i]);
    */
    namespace ixs = utils::contact_fields_ixs;

    int  last_contact_pos  = this->contacts_list_size >= 8 ? 7 : this->contacts_list_size++;
    Contact& last_contact           = this->contacts_list[last_contact_pos];
    
    last_contact.SetSecret(info_fields[ixs::secret]);
    last_contact.SetNickname(info_fields[ixs::nickname]);
    last_contact.SetLastName(info_fields[ixs::lastname]);
    last_contact.SetFirstName(info_fields[ixs::firstname]);
    last_contact.SetPhoneNumber(info_fields[ixs::phonenumber]);

}