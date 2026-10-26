
#include <iostream>
#include <string>
using namespace std;

string with_separators(string digits)
{
    int pocetak = (digits[0] == '-') ? 1 : 0;

    for (int i = digits.length() - 3; i > pocetak; i -= 3)
    {
        digits.insert(i, ".");
    }

    return digits;
}

string without_separators(string text)
{
    int poz;

    while ((poz = text.find('.')) != string::npos)
    {
        text.erase(poz, 1);
    }

    return text;
}

int main()
{
    string broj = "-123456789";

    cout << with_separators(broj) << endl;
    cout << without_separators("-123.456.789") << endl;

    return 0;
}
