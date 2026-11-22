#include <iostream>
#include <string>

// ovdje napisite klasu Ticket
class Ticket
{
    std::string naziv;
    int id;
    static int brUlaznica;

public:
    Ticket(const std::string &n) : naziv(n)
    {
        brUlaznica++;
        id = brUlaznica;
    }

    Ticket(const Ticket&) = delete;
    

    int get_id() const
    {
        return id;
    }

    static int issued()
    {
        return brUlaznica;
    }

    friend void print(const Ticket& t);
};

int Ticket::brUlaznica = 0;

void print(const Ticket& t)
{
    std::cout << t.get_id() << " " << t.naziv << '\n';
}

int main()
{
    std::cout << Ticket::issued() << '\n';
    Ticket t1("Shame, Zagreb");
    Ticket t2("Shame, Zagreb");
    Ticket t3("Viagra Boys, Ljubljana");
    std::cout << t1.get_id() << ' ' << t2.get_id() << ' ' << t3.get_id() << '\n';
    std::cout << Ticket::issued() << '\n';
    print(t1);

    return 0;
}