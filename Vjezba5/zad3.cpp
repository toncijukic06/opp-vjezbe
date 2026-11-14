// Vjezba 5, zadatak 3: napisite strukturu Song i klasu Album iznad main.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Song
{
public:
    std::string title;
    std::string artist;
    int seconds;
};

class Album
{

    std::string title;
    int year;
    std::vector<Song> songs;

public:
    Album(const std::string &t, int y, Song first)
        : title(t), year(y), songs{first} {}

    bool add(const Song &s)
    {
        auto it = std::find_if(songs.begin(), songs.end(),
                               [&s](const Song &postojeca)
                               {
                                   return postojeca.title == s.title;
                               });

        if (it != songs.end())
        {
            return false;
        }

        songs.push_back(s);
        return true;
    }
    int const duration()
    {
        int suma=0;
        for(Song s:songs){
            suma+=s.seconds;
        }
        return suma;

    }
    const void print(){
        std::cout<<title<<" ("<<year<<"), "<<songs.size()<<" pjesme, "<<duration()/60<<":"<<duration()%60<<"\n";
        for (int i = 0; i < songs.size(); i++)
        {
            std::cout<<i+1<<". "<<songs[i].title<<"\n";
        }
        
        
    }
};

// ovdje napisite Song i Album

int main()
{
    Album a("Sol Invictus", 2015, {"Sol Invictus", "Faith No More", 156});
    a.add({"Superhero", "Faith No More", 315});
    a.add({"Matador", "Faith No More", 368});
    std::cout << a.add({"Superhero", "Faith No More", 315}) << '\n'; // vec postoji
    a.print();
    return 0;
}

/*
Ocekivani ispis:

    0
    Sol Invictus (2015), 3 pjesme, 13:59
      1. Sol Invictus
      2. Superhero
      3. Matador
*/
