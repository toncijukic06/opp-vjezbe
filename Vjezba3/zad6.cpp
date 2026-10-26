
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split_words(const string& text)
{
    vector<string> rijeci;
    int pocetak = 0;

    while (pocetak < text.length())
    {
        int kraj = text.find(' ', pocetak);

        if (kraj == string::npos)
            kraj = text.length();

        if (kraj > pocetak)
            rijeci.push_back(text.substr(pocetak, kraj - pocetak));

        pocetak = kraj + 1;
    }

    return rijeci;
}

int main()
{
    string text;
    getline(cin, text);

    vector<string> rijeci = split_words(text);

    cout << "broj rijeci: " << rijeci.size() << endl;

    if (rijeci.empty())
        return 0;

    string najdulja = rijeci[0];
    string prva = rijeci[0];

    for (int i = 0; i < rijeci.size(); i++)
    {
        if (rijeci[i].length() > najdulja.length())
            najdulja = rijeci[i];

        if (rijeci[i] < prva)
            prva = rijeci[i];
    }

    cout << "najdulja: " << najdulja << endl;

    string obrnuto = "";

    for (int i = rijeci.size() - 1; i >= 0; i--)
    {
        obrnuto += rijeci[i];

        if (i > 0)
            obrnuto += "-";
    }

    cout << obrnuto << endl;
    cout << "prva po abecedi: " << prva << endl;

    return 0;
}
