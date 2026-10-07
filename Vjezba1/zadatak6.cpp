#include <iostream>

struct Fraction
{
    int num, denum;

    void reduce()
    {
        int a = num;
        int b = denum;

        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }

        int nzd = a;

        num /= nzd;
        denum /= nzd;
    }

    double value()
    {
        return static_cast<double>(num) / denum;
    }

    void print()
    {
        std::cout << num << "/" << denum << '\n';
    }
};

Fraction sum(const Fraction &a, const Fraction &b)
{
    Fraction result;

    result.num = a.num * b.denum + b.num * a.denum;
    result.denum = a.denum * b.denum;

    result.reduce();

    return result;
}

int main()
{
    Fraction raz1 = {4, 32};
    Fraction raz2 = {1, 4};
    raz1.reduce();
    
    std::cout << "Decimalna vrijednost: " << raz1.value();
    std::cout << '\n';
    std::cout << "Razlomak: ";
    raz1.print();

    Fraction rez = sum(raz1, raz2); // 1/4 + 1/4 = 2/4 -> skraćeno u 1/2

    std::cout << "\nZbroj: ";
    rez.print();
}