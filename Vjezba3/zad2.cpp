#include <iostream>
#include <vector>
#include <algorithm>

int main()
{

    int n;

    std::cout << "Unesite broj dana: \n";
    std::cin >> n;

    std::vector<double> temp(n);
    for (int i = 0; i < n; i++)
    {

        std::cin >> temp.at(i);
    }

    std::vector<double> tempPromjena(n - 1);
    int br = 0;
    auto itPrva = temp.begin();
    for (itPrva; itPrva != temp.end() - 1; ++itPrva)
    {
        tempPromjena.at(br++) = (*(itPrva + 1)) - (*itPrva);
    }

    std::cout << "Promjene: ";
    for (auto it = tempPromjena.begin(); it != tempPromjena.end(); ++it)
        std::cout << *it << " ";

    temp.resize(7, *itPrva);
    std::cout << "\nIzvjestaj: ";
    for (int i = 0; i < temp.size(); i++)
    {

        std::cout << temp.at(i) << " ";
    }
}