// Vjezba 6, zadatak 6: napisite klasu RecentlyPlayed iznad main.

#include <cassert>
#include <iostream>
#include <string>

// ovdje napisite klasu RecentlyPlayed
class RecentlyPlayed
{
private:
    std::string *niz;
    int kapacitet;
    int brojNaslova = 0;
    int next = 0;

public:
    RecentlyPlayed(int n) : kapacitet(n)
    {
        assert(kapacitet > 0);
        niz = new std::string[kapacitet];
    }

    RecentlyPlayed(const RecentlyPlayed &other)
        : kapacitet(other.kapacitet), brojNaslova(other.brojNaslova), next(other.next)
    {
        niz = new std::string[kapacitet];
        for (int i = 0; i < kapacitet; ++i)
        {
            niz[i] = other.niz[i];
        }
    }


    ~RecentlyPlayed()
    {
        delete[] niz;
    }

    void play(const std::string &title)
    {
        niz[next] = title;
        next = (next + 1) % kapacitet;
        if (brojNaslova < kapacitet)
        {
            ++brojNaslova;
        }
    }

    int size() const
    {
        return brojNaslova;
    }

    int capacity() const
    {
        return kapacitet;
    }

    std::string get(int i) const
    {
        assert(i >= 0 && i < brojNaslova);
        int idx = (next - 1 - i + kapacitet * 2) % kapacitet;
        return niz[idx];
    }

    void print() const
    {
        for (int i = 0; i < brojNaslova; ++i)
        {
            if (i > 0)
            {
                std::cout << ", ";
            }
            std::cout << get(i);
        }
        std::cout << '\n';
    }
};

int main()
{
    RecentlyPlayed recent(3);
    recent.play("Heroes");
    recent.play("Literary Mind");
    std::cout << recent.size() << ' ' << recent.capacity() << '\n';
    recent.play("Sports");
    recent.print();
    recent.play("Henry Don't Got Love");     // buffer je pun: prepisuje se najstarija
    recent.print();

    RecentlyPlayed copy = recent;             // copy konstruktor
    recent.play("Guided by Angels");
    recent.print();
    copy.print();
    std::cout << copy.get(0) << '\n';
    return 0;
}


/*
Ocekivani ispis:

    2 3
    Sports, Literary Mind, Heroes
    Henry Don't Got Love, Sports, Literary Mind
    Guided by Angels, Henry Don't Got Love, Sports
    Henry Don't Got Love, Sports, Literary Mind
    Henry Don't Got Love
*/
