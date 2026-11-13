#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct PasswordInfo
{
    int length = 0, digits = 0, uppercase = 0, special = 0;
};

PasswordInfo analyze(const std::string &password)
{

    PasswordInfo analyzed;
    analyzed.length = password.length();

    auto digit = [](char x)
    { return std::isdigit(x); };
    auto upper = [](char x)
    { return std::isupper(x); };
    auto punct = [](char x)
    { return std::ispunct(x); };

    analyzed.digits = count_if(password.begin(), password.end(), digit);
    analyzed.uppercase = count_if(password.begin(), password.end(), upper);
    analyzed.special = count_if(password.begin(), password.end(), punct);

    return analyzed;
}

bool is_strong(const PasswordInfo &info)
{
    if (info.length >= 10 && info.digits >= 1 &&
        info.uppercase >= 1 && info.special >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    PasswordInfo lozinka1 = analyze("Lozinka123");
    PasswordInfo lozinka2 = analyze("Lozinka123!");

    std::cout << "lozinka123: duljina " << lozinka1.length
              << ", znamenke " << lozinka1.digits
              << ", velika " << lozinka1.uppercase
              << ", posebni " << lozinka1.special
              << " -> " << (is_strong(lozinka1) ? "jaka" : "slaba") << "\n";

    std::cout << "Lozinka123!: duljina " << lozinka2.length
              << ", znamenke " << lozinka2.digits
              << ", velika " << lozinka2.uppercase
              << ", posebni " << lozinka2.special
              << " -> " << (is_strong(lozinka2) ? "jaka" : "slaba") << "\n";
}