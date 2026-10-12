#include <iostream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

inline int my_max(int a, int b)
{
    return (a > b) ? a : b;
}

template <typename T>
T my_max2(T a, T b) {

    return (a > b) ? a : b;
}

int main()
{

    int a = MAX(3, 5);
    int b = 2 * MAX(3, 5);
    int c = MAX(3, 5) + 1;

    std::cout << a << " " << b << " " << c << '\n';

    int i = 3;

    std::cout << "MAX: " << MAX(++i, 2) << " my_max: " << my_max(++i, 2) << '\n';

    std::cout << "MY MAX ZA INT: " << my_max2(5, 4) << "  ";
    std::cout << "MY MAX ZA DOUBLE: " << my_max2(0.5, 0.6) << " ";
    std::cout << "MY MAX ZA CHAR: " << my_max2('V', 'c') << "  ";
    std::cout << "MY MAX ZA STRING: " << my_max2(std::string("dan"), std::string("noc")) << '\n';

}