#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "World.hpp"

using namespace std;

void ShownObjects::addPointTabSize()
{
    Point *newtab = new Point[pointTabSize+1];
    for (int i = 0; i < pointTabSize;i ++)
    {
        newtab[i] = Point(Points[i]);
    }
    Points = new Point[pointTabSize+1];
    for (int i = 0; i < pointTabSize;i ++)
    {
        Points[i]= Point(newtab[i].x , newtab[i].y, newtab[i].z) ;
    }
    pointTabSize++;
}
void ShownObjects::addLineTabSize()
{
    Line *newtab = new Line[lineTabSize+1];
    for (int i = 0; i < planeTabSize;i ++)
    {
        newtab[i] = Lines[i];
    }
    Lines = newtab;
    lineTabSize++;
}

void ShownObjects::addPlaneTabSize()
{
    Plane *newtab = new Plane[planeTabSize+1]();
    for (int i = 0; i < planeTabSize;i++)
    {
        newtab[i].first = Planes[i].first;
        newtab[i].second = Planes[i].second;
        newtab[i].third = Planes[i].third;
        newtab[i].fourth = Planes[i].fourth;
    }
    for (int i = 0; i < planeTabSize;i++)
    {
        Planes[i].first = newtab[i].first;
        Planes[i].second = newtab[i].second;
        Planes[i].third = newtab[i].third;
        Planes[i].fourth = newtab[i].fourth;
    }
    /*cout << "POINTS: ";
    for (int i = 0; i < planeTabSize;i++)
    {
        cout << Planes[i].first << " " << Planes[i].second << " " <<Planes[i].third << " " <<Planes[i].fourth << '\n';

    }
    cout << endl;*/
    planeTabSize++;


}
/*void ShownObjects::addPlaneTabSize()
{
    Plane *newtab = new Plane[planeTabSize+1]();
    for (int i = 0; i < planeTabSize;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            newtab[i].Points[j] =  Planes[i].Points[j];
        }

    }
    Planes = new Plane[planeTabSize+1];
    for (int i = 0; i < planeTabSize;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            Planes[i].Points[j] = Plane newtab[i].Points[j];
        }

    }
    cout << "POINTS: ";
    for (int i = 0; i < planeTabSize;i++)
    {
        for (int j = 0; j < 4;j++)
        {
            cout << Planes[i].Points[j] << " ";
        }

    }
    cout << endl;
    planeTabSize++;
}*/



int ShownObjects::getPointTabSize() { return pointTabSize;}
int ShownObjects::getLineTabSize() { return lineTabSize;}
int ShownObjects::getPlaneTabSize() { return planeTabSize;}
int ShownObjects::getPointSize() {return pointSize;}


void ShownObjects::ChooseNextPoint()
{
    if(pointTabSize > 0)
    {
        if(pointTabSize-1 == ChoosenPoint )
        {
            ChoosenPoint = 0;
        }
        else
        {
            ChoosenPoint++;
        }
    }
    else
    {
        ChoosenPoint = -1;
    }


}

void ShownObjects::ChoosePreviousPoint()
{
    if(pointTabSize > 0)
    {
        if( 0 >= ChoosenPoint )
        {
            ChoosenPoint = pointTabSize-1;
        }
        else
        {
            ChoosenPoint--;
        }
    }
    else
    {
        ChoosenPoint = -1;
    }


}


void ShownObjects::ChooseNextPlane()
{
    if(planeTabSize > 0)
    {
        if(planeTabSize-1 == ChoosenPlane )
        {
            ChoosenPlane = 0;
        }
        else
        {
            ChoosenPlane++;
        }
    }
    else
    {
        ChoosenPlane = -1;
    }


}

void ShownObjects::ChoosePreviousPlane()
{
    if(planeTabSize > 0)
    {
        if( 0 >= ChoosenPlane )
        {
            ChoosenPlane = planeTabSize-1;
        }
        else
        {
            ChoosenPlane--;
        }
    }
    else
    {
        ChoosenPlane = -1;
    }


}



ShownObjects::ShownObjects()
{
    Points = new Point[0];
    Lines = new Line[0];
    Planes = new Plane[0];
    ShowPoints = true;
    ShowLines = true;
    ShowPlanes = true;
    pointTabSize = 0;
    lineTabSize = 0;
    planeTabSize = 0;
    pointSize = 2,5;
    ChoosenPoint =-1;
    FirstPoint =-1;
    SecondPoint =-1;
    ThirdPoint =-1;
    FourthPoint =-1;
    Step = 1;
    ChoosenDimension = 'x';
    ChoosenPlane = -1;
    ShowLights[0] = true;
    for(int i = 1; i < 8; i++)
    {
        ShowLights[i] == false;
    }

}

ShownObjects::ShownObjects(Point *PointsTab, Line *LinesTab, Plane *PlanesTab)
{
    Points = PointsTab;
    Lines = LinesTab;
    Planes = PlanesTab;
    pointTabSize = 0;
    lineTabSize = 0;
    planeTabSize = 0;
    pointSize = 2,5;
}

//Adding AREA
void ShownObjects::AddPoint()
{
    float x , y, z;
    cout << "X: ";
    cin >> x;
    isGood(&x);
    cout << "Y: ";
    cin >> y;
    isGood(&y);
    cout << "Z: ";
    cin >> z;
    isGood(&z);

    addPointTabSize();

    Points[pointTabSize-1] = Point(x,y,z);

    cout << "Point Added" << endl;
}

void ShownObjects::AddPoint(float x,float y,float z)
{
    addPointTabSize();

    Points[pointTabSize-1] = new Point(x,y,z);

    cout << "Point Added" << endl;
}

void ShownObjects::DuplicatePoint()
{
    if(ChoosenPoint > -1)
    {
        AddPoint(Points[ChoosenPoint].x , Points[ChoosenPoint].y ,Points[ChoosenPoint].z);
    }
}
void ShownObjects::AddCLEARPoint()
{
    addPointTabSize();

    Points[pointTabSize-1] = Point();

    cout << "Point Added" << endl;
}

void ShownObjects::AddCLEARLine()
{
    int *tab = new int[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Podaj numer {" << i << "} Punktu: ";
        cin >> tab[i];
        isGood(&tab[i]);
    }
    addLineTabSize();

    Lines[lineTabSize] = Line();

}
void ShownObjects::AddPlane()
{
    if(FirstPoint > -1 && SecondPoint > -1 && ThirdPoint > -1 && FourthPoint > -1 && FirstPoint
       != SecondPoint && FirstPoint != ThirdPoint && FirstPoint != FourthPoint && SecondPoint
       != ThirdPoint && SecondPoint != FourthPoint && ThirdPoint != FourthPoint)
    {
        addPlaneTabSize();
        //cout <<"PLANE TAB SIZE: "<< planeTabSize << '\n';

        Planes[planeTabSize-1] = Plane(FirstPoint , SecondPoint, ThirdPoint, FourthPoint);

        cout << "Plane Created" <<endl;
    }
}

/*void ShownObjects::AddPlane(int first, int second, int third , int fourth)
{
    addPlaneTabSize();

    Planes[planeTabSize-1] = Plane(first , second, third, fourth);
    //if(planeTabSize)
    //cout << Planes[1].Points[0] << " " << Planes[1].Points[1] << " " << Planes[1].Points[2] << " " << Planes[1].Points[3] << " ";
    cout << "Plane Created" <<endl;
}*/

void ShownObjects::AddCLEARPlane()
{
    int *tab = new int[4];
    for (int i = 0; i < 4; i++)
    {
        cout << "Podaj numer {" << i << "} Punktu: ";
        do{
        cin >> tab[i];
        isGood(&tab[i]);
        }while (tab[i] > pointTabSize);

    }
    addPlaneTabSize();

    Planes[planeTabSize] = Plane(tab[0],tab[1],tab[2],tab[3]);

    cout << "Plane Created" <<endl;

}
void ShownObjects::WritePoints()
{
    for(int i = 0; i < pointTabSize;i++)
    {
        cout << "PUNKT "<< i << " : "<< Points[i].x << " "  << Points[i].y << " " << Points[i].z << endl;
    }
    cout << "/////////////////\n";
    for(int i = 0; i < planeTabSize;i++)
    {
        cout << "Plane: " << i << "\nPoints: ";
        cout << Planes[i].first << " " << Planes[i].second << " " << Planes[i].third << " " << Planes[i].fourth << '\n';
    }
}

void ShownObjects::PlaneSwapSide(int index)
{
    if(index < planeTabSize)
    {
        int foo = Planes[index].first;
        Planes[index].first = Planes[index].fourth;
        Planes[index].fourth = foo;
        foo = Planes[index].second;
        Planes[index].second = Planes[index].third;
        Planes[index].third = foo;
    }
}

void ShownObjects::SAVE()
{



    CreateDirectory("C:/GLUTEDITORPROJECTS" , NULL);
    ofstream plik("C:/GLUTEDITORPROJECTS/FOO.txt", std::ios::trunc);
    if(plik.is_open())
    {
        plik << XTransformPosition << " " << YTransformPosition << " " << ZTransformPosition << '\n';
        if(pointTabSize > 0)
        {
            plik << "[GL_POINTS]\n";
            for(int i = 0; i < pointTabSize;i++)
            {
                plik << Points[i].x << " " << Points[i].y << " " << Points[i].z << '\n';
            }
            plik << "[END_OF_GL_POINTS]\n";
            if(planeTabSize > 0)
            {
                plik << "[GL_QUADS]\n";
                for (int i = 0; i < planeTabSize; i++)
                {
                    plik << Planes[i].first << " " << Planes[i].second << " " << Planes[i].third << " " << Planes[i].fourth << '\n';
                }
            }
            plik << "[END_OF_GL_QUADS]\n";
        }

        cout << "zapisano\n";
    }
    else
    {
        cout << "NIE UTWORZONO PLIKU";
    }
}

void ShownObjects::CLEAR()
{
    Points = new Point[0];
    Lines = new Line[0];
    Planes = new Plane[0];
    pointTabSize = 0;
    lineTabSize = 0;
    planeTabSize = 0;
}

void ShownObjects::LOAD()
{
    ifstream plik("C:/GLUTEDITORPROJECTS/FOO.txt");
    char* foo2;
    if(plik.is_open())
    {
        string foo;
        plik >> foo;
        XTransformPosition = stof(foo);
        plik >> foo;
        YTransformPosition = stof(foo);
        plik >> foo;
        ZTransformPosition = stof(foo);
        cout << XTransformPosition << " " << YTransformPosition << " " << ZTransformPosition << '\n';
        for(;!plik.eof();)
        {
            plik >> foo;
            if(foo == "[GL_POINTS]")
            {
                for(;;)
                {
                    string x,y,z;
                    plik >> x;
                    if(x == "[END_OF_GL_POINTS]") break;
                    plik >> y;
                    plik >> z;
                    //float asd = stof(x);
                    AddPoint(stof(x),stof(y.c_str()),stof(z.c_str()));
                }
            }
            if(foo == "[GL_QUADS]")
            {
                for(int i = 0;!plik.eof(); i++)
                {
                    string first,second,third,fourth;
                    plik >> first;
                    if(first == "[END_OF_GL_QUADS]") break;
                    plik >> second;
                    plik >> third;
                    plik >> fourth;
                    cout << first << " " << stoi(second) << " " << stoi(third)<< " " << stoi(fourth) << '\n';
                    FirstPoint = stoi(first);
                    SecondPoint = stoi(second);
                    ThirdPoint = stoi(third);
                    FourthPoint = stoi(fourth);
                    AddPlane();
                }
            }
        }
        cout << "Wczytano" << '\n';
    }
}


ShownObjects::~ShownObjects()
{
    delete Points;
    delete Lines;
    delete Planes;
}
