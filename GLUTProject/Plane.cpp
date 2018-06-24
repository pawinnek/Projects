#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include "World.hpp"


using namespace std;

Plane::Plane()
{
    first = 0;
    second = 1;
    third = 2;
    fourth = 3;
}
Plane::Plane(const Plane* p)
{
    first = p->first;
    second = p->second;
    third = p->third;
    fourth = p->fourth;

}
Plane::Plane(int _first, int _second, int _third, int _fourth)
{

    //cout << first << " " << second <<" " << third << " " << fourth << '\n';
    first = _first;
    second = _second;
    third = _third;
    fourth = _fourth;
    /*{for(int i = 0; i < 4;i ++)

        cout<< Points[i] << " ";
    }
    cout << endl;*/
}
Plane::~Plane(){}
