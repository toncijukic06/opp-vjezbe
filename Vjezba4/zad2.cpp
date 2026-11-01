#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Song
{
    std::string title, artist;
    int year, plays;
};

void print_song(const Song &s)
{

    std::cout << s.title << "-" << s.artist << "---" << s.year << " Broj slusanja " << s.plays << "\n";
}

int main()
{

    std::vector<Song> pjesme = {
        {"Cesarica", "Oliver Dragojevic", 1993, 150000},
        {"Moja domovina", "Hrvatski Band Aid", 1991, 200000},
        {"Tek je 12 sati", "ET", 1993, 180000},
        {"Ako me ostavis", "Miso Kovac", 1984, 120000},
        {"Zigolo", "Dino Dvornik", 1995, 95000},
        {"Libar", "Gibonni", 2001, 250000},
        {"Nije u soldima sve", "Mladen Grdovic", 1997, 170000},
        {"Trag u beskraju", "Oliver Dragojevic", 2002, 300000},
        {"Ginem", "Magazin", 2002, 220000}};

    sort(pjesme.begin(), pjesme.end(), [](const Song &a, const Song &b)
         { 
            if (a.year == b.year){
                return a.title<b.title;
            }else{
                return a.year < b.year;
            } });
    for (Song s : pjesme)
    {
        print_song(s);
    }

    std::string unos;
    std::cout << "Unesite ime izvodaca: ";
    getline(std::cin, unos);

    int broj = 0;
    int najstarija = -1;

    for (int i = 0; i < pjesme.size(); i++)
    {
        std::string artist = pjesme[i].artist;

        if (artist == unos)
        {
            broj++;

            if (najstarija == -1)
            {
                najstarija = i;
            }
        }
    }

    if (broj == 0)
    {
        std::cout << "Nema pjesama tog izvodaca.\n";
    }
    else
    {
        std::cout << "Broj pjesama: " << broj << "\n";
        std::cout << "Najstarija pjesma: ";
        print_song(pjesme[najstarija]);
    }

    auto mx = std::max_element(pjesme.begin(), pjesme.end(), [](const Song &a, const Song &b)
                               { return a.plays; });
    std::cout << "Najslusanija pjesma: \n";
    print_song(*mx);
}