#include <iostream>

using std::cout;

struct Student
{
    char ime[15];
    int JMBAG;
    int god_studija;
    int ECT_polozeno;
    double prosjek;
};

void filter_students(Student s[], int n, void (*action)(Student &), bool (*cond)(const Student &))
{

    for (int i = 0; i < n; i++)
    {
        if (cond(s[i]))
        {
            action(s[i]);
        }
    }
}

void ispis(Student &s)
{
    cout << s.ime << " JMBAG: " << s.JMBAG << "\n";
}

void povecanje(Student &s)
{
    s.god_studija++;
}

int main()
{

    Student studenti[5] = {
        {"Ivan", 9741209, 1, 30, 3.5},
        {"Marko", 7489279, 2, 45, 4.2},
        {"Ana", 4124214, 1, 15, 3.8},
        {"Petra", 4241424, 3, 60, 4.7},
        {"Luka", 2321324, 2, 50, 2.9}};

    auto polozenIspit = [](const Student &s)
    {
        return (s.god_studija == 1 && s.ECT_polozeno != 0);
    };

    auto prosjekVeci = [](const Student &s)
    {
        return s.prosjek > 3.5;
    };

    auto Vise45Ects = [](const Student &s)
    {
        return s.ECT_polozeno >= 45;
    };

    int n = sizeof(studenti) / sizeof(studenti[0]);
    cout << "Prvi filter:\n";
    filter_students(studenti, n, ispis, polozenIspit);
    cout << "\nDrugi filter:\n";
    filter_students(studenti, n, ispis, prosjekVeci);
    cout << "\nTreci filter:\n";
    filter_students(studenti, n, povecanje, Vise45Ects);
    for (int i = 0; i < n; i++)
    {
        cout << studenti[i].ime
             << " JMBAG: " << studenti[i].JMBAG
             << " Godina: " << studenti[i].god_studija << "\n";
    }
}