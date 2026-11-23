// Vjezba 8, zadatak 2: napisite klase Enemy, Goblin, Bat, Ghost i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase

class Enemy
{
protected:
    std::string naziv;
    int zdravlje;

public:
    Enemy(const std::string &n, int h) : naziv(n), zdravlje(h) {}

    std::string get_naziv() const { return naziv; }
    int get_zdravlje() const { return zdravlje; }

    virtual void take_damage(int d)
    {
        if (zdravlje - d < 0)
        {
            zdravlje = 0;
        }
        else
        {
            zdravlje -= d;
        }
    }

    virtual ~Enemy()
    {
        std::cout << naziv << " nestaje\n";
    }
};

class Goblin : public Enemy
{
public:
    Goblin(const std::string &n = "Goblin") : Enemy(n, 20) {}
};

class Bat : public Enemy
{
    int brojac = 0;
public:
    Bat(const std::string &n = "Bat") : Enemy(n, 15) {}

    void take_damage(int d) override
    {
        brojac = (brojac + 1) % 2;
        if (brojac) {
            Enemy::take_damage(d);      
        } else {
            std::cout << "Bat izbjegne udarac\n";
        }
    }
};

class Ghost : public Enemy
{
public:
    Ghost(const std::string &n = "Ghost") : Enemy(n, 30) {}

    void take_damage(int d) override
    {
        Enemy::take_damage(d / 2);
    }
};

class Level
{
    std::vector<Enemy *> enemies;

public:
    Level() = default;

    Level(const Level &) = delete;
    Level &operator=(const Level &) = delete;

    ~Level()
    {
        for (Enemy *ptr : enemies)
        {
            delete ptr;
        }
    }
    void add(Enemy *e)
    {
        enemies.push_back(e);
    }

    int size()
    {
        return enemies.size();
    }

       void print() const
    {
        for (Enemy *ptr : enemies)
        {
            std::cout << ptr->get_naziv() << ' ' << ptr->get_zdravlje() << '\n';
        }
    }

    void explode(int d)
    {
        for (Enemy *ptr : enemies)
        {
            ptr->take_damage(d);
        }
    }

    void remove_dead()
    {
        for (auto it = enemies.begin(); it != enemies.end(); )
        {
            if ((*it)->get_zdravlje() == 0)
            {
                delete *it;               
                it = enemies.erase(it);      
            }
            else
            {
                ++it;                        
            }
        }
    }

};

int main()
{
    Level cave;
    cave.add(new Goblin); // od sada je cave vlasnik neprijatelja
    cave.add(new Bat);
    cave.add(new Ghost);
    cave.add(new Goblin);
    std::cout << cave.size() << '\n';

    cave.explode(10); // bomba pogodi sve neprijatelje
    cave.print();
    std::cout << "---\n";
    cave.explode(10);
    cave.print();
    std::cout << "---\n";
    cave.remove_dead();
    std::cout << cave.size() << '\n';
    std::cout << "--- kraj ---\n";
    return 0; // destruktor klase Level brise preostale neprijatelje
}

/*
Ocekivani ispis:

    4
    Goblin 10
    Bat 5
    Ghost 25
    Goblin 10
    ---
    Bat izbjegne udarac
    Goblin 0
    Bat 5
    Ghost 20
    Goblin 0
    ---
    Goblin nestaje
    Goblin nestaje
    2
    --- kraj ---
    Bat nestaje
    Ghost nestaje
*/
