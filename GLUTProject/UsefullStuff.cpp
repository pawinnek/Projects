#pragma once
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "World.hpp"

using namespace std;


float isGood(float *a)
{

    if(!cin.good())
    {
        cout <<  "Bad Data, Write number: ";
        cin.clear();
        cin.sync();
        cin >> *a;
    }
    else return *a;
    isGood(a);
    return *a;
}
int isGood(int *a)
{
    if(!cin.good())
    {
        cout <<  "Bad Data, Write number: ";
        cin.clear();
        cin.sync();
        cin >> *a;
    }
    else return *a;
    isGood(a);
    return *a;
}

int stoi(string str)
{
    int integer = 0;
    for (int i = 0; i < str.length();i++)
    {
        //cout  << (int)str[i] << endl;
        int d = 1;
        if(str[0] == '-')
        {
            d = -1;
            i++;
        }
        for (int j = i+1;j < str.length();j++)
        {
            d *=10;
        }
        integer += ((int)str[i] - 48) * d;
    }
    cout << "STOI: " << integer;
    return integer;
}
float stof(string str)
{
    cout << "Str: " << str << endl;
    float floatingpoint = 0;
    int point = 0;
    for(int i = 0; i < str.length();i++)
    {
        point = i+1;
        if(str[i] == '.')
        {
            point = i;
            break;
        }
    }
    for (int i = 0;i < point;i++)
    {
        //if(str[i] == '.') continue;
        float d = 1.0f;
        if(str[0] == '-')
        {
            d = -1.0f;
            if(i == 0) continue;
        }
        for (int j = i+1;j < point;j++)
        {
            d *=10;
        }

        floatingpoint += (float)((int)str[i] - 48) * d;
        cout << "FLOATING POINT: " << floatingpoint << " and " << (float)((int)str[i] - 48) << " and d " << d << '\n';
    }
    for(int i = point+1; i < str.length(); i++)
    {
        float d = 1.0f;
        if(str[0] == '-')
        {
            d = -1.0f;
            if(i == 0) continue;
        }
        for(int j = 0; j < i-point;j++)
        {
            d /=10;
        }
         floatingpoint += (float)((int)str[i] - 48) * d;
         cout << "FLOATING POINT: " << floatingpoint << " and " << (float)((int)str[i] - 48) << " and d " << d << '\n';
    }


    return floatingpoint;
}

