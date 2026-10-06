#include <iostream>

namespace geo
{

    inline constexpr double PI = 3.14;
}

double area(double r)
{

    return r * r * geo::PI;
}

double area(double a, double b)
{
    return a * b;
}

int area(int a)
{
    return a * a;
}

void print_line(char c = '-', int length = 30)
{

    for (int i = 0; i < length; i++)
    {
        std::cout << c;
    }
    std::cout<<'\n';
}

int main()
{

    print_line();
    std::cout << "area(5)   = " << area(5) << '\n';
    print_line();

    std::cout << "area(5.0) = " << area(5.0) << '\n';
    print_line();

    std::cout << "area(2, 3)= " << area(2, 3) << '\n';
    print_line();

    std::cout << "area('A') = " << area('A') << '\n';
    print_line();
}