#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int> &v)
{

    int unos;
    do
    {

        std::cout << "Unesite broj: ";
        std::cin >> unos;
        if (unos != 0)
        {
            v.push_back(unos);
        }

    } while (unos != 0);
}

int main()
{

    std::vector<int> v;

    input_vector(v);

    int k;
    
    do
    {

        std::cout << "Unesite k(veci od 0): ";
        std::cin >> k;

    } while (k == 0);

    auto neg = [](int n)
    { return n < 0; };

    auto cnt = std::count_if(v.begin(), v.end(), neg);
    std::cout << "negativnih: " << cnt << "\n";

    auto viseK = [k](int br)
    { return br % k == 0; };

    auto it = std::find_if(v.begin(), v.end(), viseK);

    if (it != v.end())
    {
        std::cout << "prvi visekratnik od " << k << ": " << *it << "(pozicija " << it - v.begin() << ")\n";
    }
    else
    {
        std::cout << "Nema visekratnika od " << k << "\n";
    }

    auto mx = std::max_element(v.begin(), v.end());
    auto mn = std::min_element(v.begin(), v.end());
    std::cout << "max " << *mx << " (pozicija" << mx - v.begin() << ")\n";
    std::cout << "min " << *mn << " (pozicija" << mn - v.begin() << ")\n";

    v.erase(std::remove_if(v.begin(), v.end(), viseK), v.end());

    std::cout << "bez visekratnika: ";
    for (int br : v)
    {
        std::cout << br << " ";
    }

    
}