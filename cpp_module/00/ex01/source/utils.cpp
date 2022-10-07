#include "utils.hpp"

void        utils::io::show_field(std::string field)
{
    std::cout << std::setw(10) << std::right << (field.length() <= 10 ? field : field.substr(0, 9) + '.') << '|';
}

std::string utils::io::get_field(std::string field_name)
{
    std::string input("");


    while (input.empty())
    {
        std::cout << "\tInput " << field_name << ">";
        std::getline(std::cin, input);
    }
    return (input);
}

void    utils::cmd::add(PhoneBook& phone_book)
{
    namespace ixs = utils::contact_fields_ixs;

    std::string fields[5];

    fields[ixs::secret]         = utils::io::get_field("darkest secret");
    fields[ixs::nickname]       = utils::io::get_field("nickname");
    fields[ixs::lastname]       = utils::io::get_field("lastname");
    fields[ixs::firstname]      = utils::io::get_field("firstname");
    fields[ixs::phonenumber]    = utils::io::get_field("phone number");

    phone_book.AddContact(fields);
}

void    utils::cmd::search(PhoneBook& phone_book)
{
    int    contacts_num;
    int    i_target_contact;
    std::string     s_target_contact;

    contacts_num        = phone_book.GetContactsNumber();
    i_target_contact    = 0;

    if (!contacts_num)
    {
        std::cout << "Phone book is empty" << std::endl;
        return ;
    }

    utils::io::show_field("index");
    utils::io::show_field("Firstname");
    utils::io::show_field("Lastname");
    utils::io::show_field("Nickname");
    std::cout << std::endl;
    
    for (int i = 0; i < contacts_num; i++)
    {
        const   Contact& contact = phone_book.GetContact(i);

        std::cout << std::setw(10) << std::right << i << '|';
        utils::io::show_field(contact.GetFirstName());
        utils::io::show_field(contact.GetLastName());
        utils::io::show_field(contact.GetNickname());
        std::cout << std::endl;
    }

    while (true)
    {
        std::cout << "Input target contact index>";
        std::getline(std::cin, s_target_contact);

        if (s_target_contact.empty() || (s_target_contact.length() > 1) || !(std::isdigit(s_target_contact[0])))
            std::cout  << "index is wrong" << std::endl;
        else if ((i_target_contact = std::stoi(s_target_contact)) > contacts_num - 1)
            std::cout << "index is out of range" << std::endl;
        else
            break;
    }

    const Contact& target_contact = phone_book.GetContact(i_target_contact);

    utils::io::show_field("firstname");
    utils::io::show_field("lastname");
    utils::io::show_field("nickname");
    utils::io::show_field("phone number");
    utils::io::show_field("darkest secret");
    std::cout << std::endl;
    utils::io::show_field(target_contact.GetFirstName());
    utils::io::show_field(target_contact.GetLastName());
    utils::io::show_field(target_contact.GetNickname());
    utils::io::show_field(target_contact.GetPhoneNumber());
    utils::io::show_field(target_contact.GetSecret());
    std::cout << std::endl;

}

void    utils::cmd::exit()
{
    std::cout << "Exitting phonebook programm" << std::endl;
}

bool    utils::parse_cmd(std::string& cmd, PhoneBook& phone_book)
{
    if (cmd == "EXIT")
    {
        utils::cmd::exit();
        return (false);
    }

    if (cmd == "ADD")
    {
        utils::cmd::add(phone_book);
        return (true);
    }

    if (cmd == "SEARCH")
    {
        utils::cmd::search(phone_book);
        return (true);
    }

    std::cout << "Invalid command" << std::endl;

    return (true);
}

void    utils::surf_phonebook(PhoneBook& phone_book)
{
    std::string tmp;

    do
    {
        std::cout << "Input command>";
        std::getline(std::cin, tmp);
    }
    while (utils::parse_cmd(tmp, phone_book));
}