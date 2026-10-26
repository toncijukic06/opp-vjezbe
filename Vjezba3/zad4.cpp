#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain)
{
    auto first_at = email.find('@');
    auto last_at = email.rfind('@');

    if (first_at == std::string::npos || first_at != last_at)
    {
        return false;
    }

    if (first_at == 0 || first_at == email.length() - 1)
    {
        return false;
    }

    user = email.substr(0, first_at);   
    domain = email.substr(first_at + 1);

    if (domain.find('.') == std::string::npos)
    {
        return false;
    }

    return true;
}

int main()
{
    std::string email;
    std::string user;
    std::string domain;

    std::cout << "Unesite e-mail adresu: ";
    std::getline(std::cin, email);

    if (split_email(email, user, domain))
    {
        std::cout << "Korisničko ime: " << user << "\n";
        std::cout << "Domena: " << domain << "\n";
    }
    else
    {
        std::cout << "Neispravna e-mail adresa.\n";
    }

    return 0;
}