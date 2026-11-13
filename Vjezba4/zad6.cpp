#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<std::string> split_words(const std::string &text)
{
    std::vector<std::string> rijeci;
    int pocetak = 0;

    while (pocetak < text.length())
    {
        int kraj = text.find(' ', pocetak);

        if (kraj == std::string::npos)
            kraj = text.length();

        if (kraj > pocetak)
            rijeci.push_back(text.substr(pocetak, kraj - pocetak));

        pocetak = kraj + 1;
    }

    return rijeci;
}

int main()
{
    std::vector<std::string> rjecnik = {"programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije",
                                        "jednostavan", "za", "pocetnike"};

    std::sort(rjecnik.begin(), rjecnik.end());

    std::cout << "Recenica: ";
    std::string text;
    getline(std::cin, text);

    std::vector<std::string> rijeci = split_words(text);

    for (auto &rijec : rijeci)
    {
        rijec.erase(
            std::remove_if(rijec.begin(), rijec.end(), [](char c)
                           { return c == '.' || c == ','; }),
            rijec.end());
        for (char &c : rijec)
        {
            c = std::tolower(c);
        }
    }

    std::vector<std::string> nepoznate;
    for (const auto &rijec : rijeci)
    {
        if (!std::binary_search(rjecnik.begin(), rjecnik.end(), rijec))
        {
            nepoznate.push_back(rijec);
        }
    }

    std::cout << "nepoznatih rijeci: " << nepoznate.size();
    for (const auto &rijec : nepoznate)
    {
        std::cout << " " << rijec;
    }
    std::cout << "\n";

    return 0;
}