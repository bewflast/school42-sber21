#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{

    std::string secret;
    std::string nickname;
    std::string last_name;
    std::string first_name;
    std::string phone_number;

public:

    Contact() 
    : 
        secret(""),
        nickname(""),
        last_name(""),
        first_name(""),
        phone_number("")
    {};

    void SetSecret(std::string);
    void SetNickname(std::string);
    void SetLastName(std::string);
    void SetFirstName(std::string);
    void SetPhoneNumber(std::string);

    std::string GetSecret()         const;
    std::string GetNickname()       const;
    std::string GetLastName()       const;
    std::string GetFirstName()      const;
    std::string GetPhoneNumber()    const;

};

#endif