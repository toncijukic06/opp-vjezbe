#include <iostream>
#include <cmath>

struct Point
{
    double x, y;
};

void move_by(Point *p, double dx, double dy)
{
    (*p).x += dx;
    (*p).y += dy;
}

double dist(const Point *a, const Point *b)
{
    double dx = (*a).x - (*b).x;
    double dy = (*a).y - (*b).y;
    return std::sqrt(dx * dx + dy * dy);
}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main()
{

    Point p1 = {2.0, 2.0};
    Point p2 = {3.0, 6.0};

    Point tocke[5] = {
        {3.5, 4.0},   
        {-1.0, 0.2},  
        {7.0, -2.0},  
        {-4.0, -3.0},
        {2.0, 2.0}    
    };

    move_by(&p1, 1.0, 5.0);
    double d1 = dist(&p1, &p2);

    move_by(p1, 1.0, 5.0);
    double d2 = dist(p1, p2);
}