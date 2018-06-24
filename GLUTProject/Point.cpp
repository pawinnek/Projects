#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include "World.hpp"

using namespace std;

Point::Point(float _x , float _y, float _z)
{
    x = _x;
    y = _y;
    z = _z;
    UsedIn = 0;
    cout << x << " " << y << " " << z << endl;
}

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
    UsedIn = 0;
}

Point::Point(const Point *p)
{
    x = p->x;
    y = p->y;
    z = p->z;
    UsedIn = p->UsedIn;
}

Point::debug()
{
    cout << "DEBUG: " << x << " " << y << " " << z << '\n';
}
