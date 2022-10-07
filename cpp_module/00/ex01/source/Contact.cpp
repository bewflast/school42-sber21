#include "Contact.hpp"

void Contact::SetSecret(std::string secret)
{
    this->secret = secret;
};

void Contact::SetNickname(std::string nickname)
{
    this->nickname = nickname;
};

void Contact::SetLastName(std::string last_name)
{
    this->last_name = last_name;
};

void Contact::SetFirstName(std::string first_name)
{
    this->first_name = first_name;
};

void Contact::SetPhoneNumber(std::string phone_number)
{
    this->phone_number = phone_number;
};



std::string Contact::GetSecret()         const
{
    return (this->secret);
};

std::string Contact::GetNickname()       const
{
    return (this->nickname);
};

std::string Contact::GetLastName()       const
{
    return (this->last_name);
};

std::string Contact::GetFirstName()      const
{
    return (this->first_name);
};

std::string Contact::GetPhoneNumber()    const
{
    return (this->phone_number);
};
