#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool starts_with(const std::string &s, const std::string &prefix)
{
    if (prefix.size() > s.size())
    {
        return false;
    }

    return equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string &s, const std::string &suffix)
{

    if (suffix.size() > s.size())
    {
        return false;
    }

    return equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main()
{
    int brojiCpp = 0;
    std::vector<std::string> datoteka{"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};

    for (const std::string &x : datoteka)
    {
        if (ends_with(x, ".cpp"))
        {
            brojiCpp++;
        }
    }

    datoteka.erase(remove_if(datoteka.begin(), datoteka.end(), [](const std::string &x){ return starts_with(x, "vjezba"); }),datoteka.end());

    std::cout << ".cpp datoteka: " << brojiCpp << "\n";
    for (const std::string &x : datoteka)
    {
        std::cout<<x<<" ";
    }
    
}