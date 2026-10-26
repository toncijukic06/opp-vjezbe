#include <iostream>
#include <array>
#include <algorithm>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS> &hours)
{
    double sum = 0.0;
    for (int i = 0; i < DAYS; ++i)
    {
        sum += hours[i];
    }
    return sum;
}

int best_day(const std::array<double, DAYS> &hours)
{
    int max_index = 0;
    double max_hours = hours[0];
    
    for (int i = 1; i < DAYS; ++i)
    {
        if (hours[i] > max_hours)
        {
            max_hours = hours[i];
            max_index = i;
        }
    }
    
    return max_index + 1;
}

int main()
{
    std::array<double, DAYS> sati;
    std::cout << "Unesite sate učenja za 7 dana:\n";
    for (int i = 0; i < DAYS; ++i)
    {
        std::cin >> sati[i];
    }

    std::cout << "Ukupan broj sati u prvom tjednu: " << total(sati) << "\n";
    std::cout << "Dan s najviše sati učenja (redni broj): " << best_day(sati) << "\n";

    std::array<double, DAYS> drugi_tjedan;
    drugi_tjedan.fill(1.5);

    std::cout << "Jesu li tjedni jednaki? " << (sati == drugi_tjedan ? "Da" : "Ne") << "\n";
    std::cout << "Je li prvi tjedan manji od drugog ? " << (sati < drugi_tjedan ? "Da" : "Ne") << "\n";

    std::swap(sati, drugi_tjedan);

    std::cout << "Nakon zamjene:\n";
    std::cout << "Ukupan broj sati u prvom tjednu: " << total(sati) << "\n";
    std::cout << "Ukupan broj sati u drugom tjednu: " << total(drugi_tjedan) << "\n";

    return 0;
}   