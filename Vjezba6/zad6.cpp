// Vjezba 6, zadatak 5: napisite klase Enemy i Level iznad main.

#include <iostream>
#include <string>
#include <vector>

// ovdje napisite klase Enemy i Level

class Enemy
{
    std::string name;
    int x, y;
    int health = 100;

public:
    Enemy(std::string n, int x, int y) : name(n), x(x), y(y)
    {
    }
    std::string get_name()
    {
        return name;
    }
    int get_x()
    {
        return x;
    }

    int get_y()
    {
        return y;
    }

    const int get_health()
    {
        return health;
    }

    const bool is_alive()
    {
        return health > 0;
    }

    void move(int dx, int dy)
    {
        x += dx;
        y += dy;
    }
    void take_damage(int d)
    {
        if (health - d > 0)
        {
            health -= d;
        }
        else
        {
            health = 0;
        }
    }
};

class Level
{

    int rows;
    int cols;
    std::vector<Enemy> enemies;

public:
    Level(int r, int c) : rows(r), cols(c)
    {
    }
    bool add(Enemy e)
    {
        if (e.get_x() >= 0 && e.get_x() < cols && e.get_y() >= 0 && e.get_y() < rows)
        {
            enemies.push_back(e);
            return true;
        }
        return false;
    }
    void step(int dx, int dy)
    {
        for (Enemy &e : enemies)
        {
            int nx = e.get_x() + dx;
            int ny = e.get_y() + dy;
            if (nx >= 0 && nx < cols && ny >= 0 && ny < rows)
            {
                e.move(dx, dy);
            }
        }
    }
    void const print()
    {
        for (Enemy e : enemies)
        {
            std::cout << e.get_name() << " (" << e.get_x() << ", " << e.get_y() << ")" << e.get_health() << "\n";
        }
    }
};

int main()
{
    Level cave(5, 10);
    cave.add(Enemy("Gnome", 1, 1));
    std::cout << cave.add(Enemy("Troll", 8, 3))
              << cave.add(Enemy("Bat", 12, 2)) << '\n';
    cave.step(1, 1);
    cave.print();
    cave.step(1, 1);
    cave.print();
    return 0;
}

/*
Ocekivani ispis:

    10
    Gnome (2, 2) 100
    Troll (9, 4) 100
    Gnome (3, 3) 100
    Troll (9, 4) 100
*/
