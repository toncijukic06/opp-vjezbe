#include <iostream>
#include <string>

int main()
{
    int god;
    std::string ImePrezime;

    std::cout << "Unesite god rodenja: ";
    std::cin >> god;

    std::cout << "Unesite ime i prezime: ";
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, ImePrezime);

    std::cout << "Inicijali: ";

    std::cout << ImePrezime[0] << ". ";


    for (int i = 1; i < ImePrezime.length(); i++)
    {
        if (ImePrezime[i - 1] == ' ' && ImePrezime[i] != ' ')
        {
            std::cout << ImePrezime[i] << ".";
            break;
        }
    }

    int brojac = 0;

    for (auto n : ImePrezime)
    {
        if (n != ' ')
        {
            brojac++;
        }
    }

    std::cout << "\nBroj znakova: " << brojac << '\n';
    std::cout << "Broj godina u 2026: " << 2026-god <<" godina" <<'\n';

    return 0;
}
