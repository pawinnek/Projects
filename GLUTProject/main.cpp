//Created by Pawel Sobczyk all rights reserved :D
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include "World.hpp"
#include "pomoc/glpomoc.h"
#include "Materials/materials.h"
#include "pomoc/glloadtga.c"

using namespace std;

#define Number_Of_Textures 3
bool litm = false;

unsigned obiektyTextur[Number_Of_Textures];
char* plikiTextur[] = {"C:/Users/Troll/Desktop/Gra/Rysowanie 3.0/Grass.tga","C:/Users/Troll/Desktop/Gra/Rysowanie 3.0/Wood.tga","C:/Users/Troll/Desktop/Gra/Rysowanie 3.0/Slonce.tga"};
static int slices = 16;
static int stacks = 16;

float *BUFF = new float[3];
ShownObjects World = ShownObjects();

string rzut = "frustrum",skala;

int menuIds[53];

GLfloat *PointList = new GLfloat[1000] ;

void Lights()
{
    glLightfv(GL_LIGHT0, GL_AMBIENT,  World.light_ambient[0]);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  World.light_diffuse[0]);
    glLightfv(GL_LIGHT0, GL_SPECULAR, World.light_specular[0]);
    glLightfv(GL_LIGHT0, GL_POSITION, World.light_position[0]);
    //glLightfv(GL_LIGHT0, GL_POSITION, BUFF);

    glLightfv(GL_LIGHT1, GL_AMBIENT,  World.light_ambient[1]);
    glLightfv(GL_LIGHT1, GL_DIFFUSE,  World.light_diffuse[1]);
    glLightfv(GL_LIGHT1, GL_SPECULAR, World.light_specular[1]);
    glLightfv(GL_LIGHT1, GL_POSITION, World.light_position[1]);
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, BUFF);

    glLightfv(GL_LIGHT2, GL_AMBIENT,  World.light_ambient[2]);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  World.light_diffuse[2]);
    glLightfv(GL_LIGHT2, GL_SPECULAR, World.light_specular[2]);
    glLightfv(GL_LIGHT2, GL_POSITION, World.light_position[2]);

    glLightfv(GL_LIGHT2, GL_AMBIENT,  World.light_ambient[3]);
    glLightfv(GL_LIGHT2, GL_DIFFUSE,  World.light_diffuse[3]);
    glLightfv(GL_LIGHT2, GL_SPECULAR, World.light_specular[3]);
    glLightfv(GL_LIGHT2, GL_POSITION, World.light_position[3]);

    glLightfv(GL_LIGHT3, GL_AMBIENT,  World.light_ambient[4]);
    glLightfv(GL_LIGHT3, GL_DIFFUSE,  World.light_diffuse[4]);
    glLightfv(GL_LIGHT3, GL_SPECULAR, World.light_specular[4]);
    glLightfv(GL_LIGHT3, GL_POSITION, World.light_position[4]);

    glLightfv(GL_LIGHT4, GL_AMBIENT,  World.light_ambient[5]);
    glLightfv(GL_LIGHT4, GL_DIFFUSE,  World.light_diffuse[5]);
    glLightfv(GL_LIGHT4, GL_SPECULAR, World.light_specular[5]);
    glLightfv(GL_LIGHT4, GL_POSITION, World.light_position[5]);

    glLightfv(GL_LIGHT5, GL_AMBIENT,  World.light_ambient[5]);
    glLightfv(GL_LIGHT5, GL_DIFFUSE,  World.light_ambient[5]);
    glLightfv(GL_LIGHT5, GL_SPECULAR, World.light_specular[5]);
    glLightfv(GL_LIGHT5, GL_POSITION, World.light_position[5]);

    glLightfv(GL_LIGHT6, GL_AMBIENT,  World.light_ambient[5]);
    glLightfv(GL_LIGHT6, GL_DIFFUSE,  World.light_ambient[5]);
    glLightfv(GL_LIGHT6, GL_SPECULAR, World.light_specular[5]);
    glLightfv(GL_LIGHT6, GL_POSITION, World.light_position[5]);

    glLightfv(GL_LIGHT7, GL_AMBIENT,  World.light_ambient[5]);
    glLightfv(GL_LIGHT7, GL_DIFFUSE,  World.light_ambient[5]);
    glLightfv(GL_LIGHT7, GL_SPECULAR, World.light_specular[5]);
    glLightfv(GL_LIGHT7, GL_POSITION, World.light_position[5]);
}

void Floor ()
{
    bool flaga=true;
	GLfloat Range = 20.0f;
	GLfloat Tlo_x;
	GLfloat	Tlo_z;
	GLfloat red = 0.1f;
	GLfloat green = 0.1f;
	GLfloat blue = 0.1f;

    /*glMaterialfv(GL_FRONT, GL_AMBIENT, ambient_gold);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse_gold);
        glMaterialfv(GL_FRONT, GL_SPECULAR, specular_gold);
        glMaterialf(GL_FRONT, GL_SHININESS, shininess_gold);*/

	//glColor3f (red, green, blue);
	for (Tlo_x = -Range * 5; Tlo_x <=  Range * 5;  Tlo_x += 2.0)
	{
		glColor4f (0.8f, 0.1f, 0.1f, 0.6f);
		for (Tlo_z = -Range * 5; Tlo_z <= Range * 5; Tlo_z += 2.0)
		{
			if (flaga)
			{
                glEnable(GL_TEXTURE_2D);
				red = 1.0f;
				green = 1.0f;
				blue = 1.0f;
				flaga=0;
				glBindTexture(GL_TEXTURE_2D,obiektyTextur[0]);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			}
			else
			{
				red=1.0f;
				green=1.0f;
				blue=1.0f;
				flaga=1;
				glBindTexture(GL_TEXTURE_2D,obiektyTextur[1]);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
				glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			}
			glColor4f (red, green, blue, 0.6f);
			glBegin (GL_QUADS);
				//wektory normalne wskazujace gore
 			    glNormal3f (0.0f, 1.0f, 0.0f);
 			    glTexCoord2f(0.0f,0.0f);
				glVertex3f (Tlo_x, -2.0f, Tlo_z);
				glTexCoord2f(0.0f,1.0f);
				glVertex3f (Tlo_x, -2.0f, Tlo_z + 2.0f);
				glTexCoord2f(1.0f,1.0f);
				glVertex3f (Tlo_x + 2.0f, -2.0f, Tlo_z + 2.0f);
				glTexCoord2f(1.0f,0.0f);
				glVertex3f (Tlo_x + 2.0f, -2.0f, Tlo_z);
			glEnd ();
        }
        glDisable(GL_TEXTURE_2D);

	}
}


void COMMIT()
{
    for(int i = 0; i < World.getPlaneTabSize(); i++)
    {
        int i12 = i*12;
        //World.Points[World.Planes[i].first].debug();
        PointList[i12+0] = World.Points[World.Planes[i].first].x;
        PointList[i12+1] = World.Points[World.Planes[i].first].y;
        PointList[i12+2] = World.Points[World.Planes[i].first].z;
        //World.Points[World.Planes[i].first].debug();
        PointList[i12+3] = World.Points[World.Planes[i].second].x;
        PointList[i12+4] = World.Points[World.Planes[i].second].y;
        PointList[i12+5] = World.Points[World.Planes[i].second].z;
        PointList[i12+6] = World.Points[World.Planes[i].third].x;
        PointList[i12+7] = World.Points[World.Planes[i].third].y;
        PointList[i12+8] = World.Points[World.Planes[i].third].z;
        PointList[i12+9] = World.Points[World.Planes[i].fourth].x;
        PointList[i12+10] = World.Points[World.Planes[i].fourth].y;
        PointList[i12+11] = World.Points[World.Planes[i].fourth].z;
    }
    cout << "COMMIT: " << World.getPlaneTabSize() << '\n';
}

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(rzut == "frustrum")
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);

    GLdouble aspect = 1;
    GLfloat zakres = 250.0f;
    GLfloat blisko = 1.0f;
    GLfloat daleko = 250.0f;
    cout << rzut;
    if (rzut=="ortho")
    {
        // skala 1:1
        if (skala=="Aspect_1_1")
        {
           if (width < height && width > 0)
              glOrtho (-zakres,zakres,-zakres*height/width,zakres*height/width,2,100);
           else
               if (width >= height && height > 0)
                  glOrtho (-zakres*width/height,zakres*width/height,-zakres,zakres,2,100);
        }
        else
            glOrtho (-zakres,zakres,-zakres,zakres,-zakres,zakres);
    }

    // rzutowanie perspektywiczne
    if (rzut=="persp")
    {
        if (height > 0)
           aspect = width/(GLdouble)height;
        gluPerspective (90,aspect,1,11);
    }
    glLoadIdentity() ;
}

void glVertex3f(Point p) // przeciazenie wbudowanego glVertex
{
    glVertex3f(p.x,p.y,p.z);
}

/*            ORTHOGRAPHIC
{ 2/(r-l)    0        0      -(r+l)/(r-l) }
{    0     2/(t-b)    0      -(t+b)/(t-b) }
{    0       0      2/(f-n)  -(f+n)/(f-n) }
{    0       0        0            1      }
*/

/*
{ 2*zN/(r-l)
{
{
{
*/
int saa = 0;
static void display(void)
{
    glLoadIdentity();
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glPushMatrix();
    glTranslated(World.XTransformPosition, World.YTransformPosition, World.ZTransformPosition);
    if(litm == false)
    glRotated(World.Angle, World.XRotation, World.YRotation, World.ZRotation);
    else
    glRotated(a,World.XRotation, World.YRotation, World.ZRotation);
    Floor();
    if(World.ShowPoints)
    {


            if(World.getPointTabSize()>0)
            {
                glPointSize(5);
                glBegin(GL_POINTS);
                for(int i = 0; i < World.getPointTabSize(); i++)
                {
                    if(World.ChoosenPoint > -1)
                    {
                        if(&World.Points[i] != &World.Points[World.ChoosenPoint])
                        {
                            glPushMatrix();
                                glVertex3f(World.Points[i]);
                            glPopMatrix();
                        }
                    }
                    else
                    {
                        glPushMatrix();
                            glVertex3f(World.Points[i]);
                        glPopMatrix();
                    }
                }
                glEnd();
                glPointSize(5);
                glColor3d(0,1,0);
                glBegin(GL_POINTS);
                if(World.ChoosenPoint > -1)
                {
                    glPushMatrix();
                    glVertex3f(World.Points[World.ChoosenPoint]);
                    glPopMatrix();
                }
                glEnd();
            }
    }

    if(World.ShowPlanes)
    {
            if(World.getPlaneTabSize() > 0)
            {

                glPushMatrix();
                glColor3d(1,0,0);
                glBegin(GL_QUADS);
                for(int i = 0; i <  World.getPlaneTabSize();i++)
                {
                    if(World.ChoosenPlane != i )
                    {
                        int i12 = i *12;
                        glVertex3f(PointList[i12+0] , PointList[i12+1], PointList[i12+2]);
                        glVertex3f(PointList[i12+3] , PointList[i12+4], PointList[i12+5]);
                        glVertex3f(PointList[i12+6] , PointList[i12+7], PointList[i12+8]);
                        glVertex3f(PointList[i12+9] , PointList[i12+10], PointList[i12+11]);
                    }
                }
                glEnd();
                glPopMatrix();
                glColor3d(0,1,0);
                glBegin(GL_QUADS);
                //glRotated(a,0,1,0);
                if(World.ChoosenPlane > -1)
                {
                    glPushMatrix();
                        if(World.ShowPoints == false)
                        glRotated(a,0,30,0);
                        int i12 = World.ChoosenPlane *12;
                        glVertex3f(PointList[i12+0] , PointList[i12+1], PointList[i12+2]);
                        glVertex3f(PointList[i12+3] , PointList[i12+4], PointList[i12+5]);
                        glVertex3f(PointList[i12+6] , PointList[i12+7], PointList[i12+8]);
                        glVertex3f(PointList[i12+9] , PointList[i12+10], PointList[i12+11]);
                    glPopMatrix();
                }
                glEnd();
            }
    }
    glPopMatrix();
    glutSwapBuffers();
}
bool piatka = false;
// Przykladowe swiatlo (DO EDYCJI)
float light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f }; // otaczajace
float light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };//rozproszone
float light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };//punktowe
float light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };//pozycja

float mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
float mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
float mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
float high_shininess[] = { 100.0f };

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27 :
            exit(0);
            break;
        case 'd':
            World.DuplicatePoint();
            break;
        case '.':
            World.WritePoints();
            break;
        case '\\' :
            {
                if(World.ChoosenPoint > -1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.Points[World.ChoosenPoint].x += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.Points[World.ChoosenPoint].y += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.Points[World.ChoosenPoint].z += World.Step;
                    }
                    glLoadIdentity();
                    COMMIT();
                }

                break;
            }

        case '\'' :
            {
                if(World.ChoosenPoint > -1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.Points[World.ChoosenPoint].x -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.Points[World.ChoosenPoint].y -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.Points[World.ChoosenPoint].z -= World.Step;
                    }
                    glLoadIdentity();
                    COMMIT();
                }

                break;
            }
        case 'c':
            {
                cout << "LICZBA PUNKTOW: " << World.getPointTabSize() << endl;
                cout << "LICZBA PLANOW: " << World.getPlaneTabSize() << endl;

            }
            break;
        case 'n':
            World.ChooseNextPoint();
            cout << "Choosen Point: " << World.ChoosenPoint <<'\n';
            break;
        case 'p':
            World.ChoosePreviousPoint();
            cout << "Choosen Point: " << World.ChoosenPoint <<'\n';
            break;
        case 'b':
            World.ChooseNextPlane();
            cout << "Choosen Plane: " << World.ChoosenPlane <<'\n';
            break;
        case 'o':
            World.ChoosePreviousPlane();
            cout << "Choosen Plane: " << World.ChoosenPlane <<'\n';
            break;
        case 'x':
            World.ChoosenDimension = 'x';
            break;
        case 'w':
            World.ChoosenDimension = 'w';
            break;
        case '[':
            {
                if(World.ChoosenPlane > -1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].x += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].x += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].x += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].x += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].y += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].y += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].y += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].y += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].z += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].z += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].z += World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].z += World.Step;
                    }
                    //glLoadIdentity();
                    COMMIT();
                }
            }
            break;
        case ']':
            {
                if(World.ChoosenPlane > -1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].x -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].x -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].x -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].x -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].y -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].y -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].y -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].y -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.Points[World.Planes[World.ChoosenPlane].first].z -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].second].z -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].third].z -= World.Step;
                        World.Points[World.Planes[World.ChoosenPlane].fourth].z -= World.Step;
                    }
                    glLoadIdentity();
                    COMMIT();
                }
            }
            break;
        case 'y':
            World.ChoosenDimension = 'y';
            break;
        case 'z':
            World.ChoosenDimension = 'z';
            break;
        case 'X':
            if(!World.ChoosenPoint) break;
            cout << "Podaj X: ";
            cin >> World.Points[World.ChoosenPoint].x;
            break;
        case 'Y':
            if(!World.ChoosenPoint) break;
            cout << "Podaj Y: ";
            cin >> World.Points[World.ChoosenPoint].y;
            break;
        case 'Z':
            if(!World.ChoosenPoint) break;
            cout << "Podaj Z: ";
            cin >> World.Points[World.ChoosenPoint].z;
            break;
        case '+':
            World.Step += 0.01;
            cout << "Step: " << World.Step << '\n';
            break;
        case '-':
            World.Step -= 0.01;
            cout << "Step: " << World.Step << '\n';
            break;
        case '9':
            {
                if(piatka == false)
                {
                    World.XTransformPosition += World.Step;
                }
                else
                {
                    World.XRotation += World.Step;
                }
            }
            break;
        case '6':
            {
                if(piatka == false)
                {
                    World.YTransformPosition += World.Step;
                }
                else
                {
                    World.YRotation += World.Step;
                }
            }
            break;
        case '3':
            {
                if(piatka == false)
                {
                    World.ZTransformPosition += World.Step;
                }
                else
                {
                    World.ZRotation += World.Step;
                }
            }
            break;
        case '7':
            {
                if(piatka == false)
                {
                    World.XTransformPosition -= World.Step;
                }
                else
                {
                    World.XRotation -= World.Step;
                }
            }
            break;
        case '4':
            {
                if(piatka == false)
                {
                    World.YTransformPosition -= World.Step;
                }
                else
                {
                    World.YRotation -= World.Step;
                }
            }
            break;
        case '1':
            {
                if(piatka == false)
                {
                    World.ZTransformPosition -= World.Step;
                }
                else
                {
                    World.ZRotation -= World.Step;
                }
            }
            break;
        case '5':
            {
                if(piatka == false)
                {
                    cout << "Rotation: " << World.XRotation << " "<< World.YRotation << " " << World.ZRotation << " " << World.Angle << '\n';
                    piatka = true;
                }
                else
                {
                    cout << "Position: " << World.XTransformPosition << " "<< World.YTransformPosition << " " << World.ZTransformPosition << '\n';
                    piatka = false;
                }
            }
            break;
        case '8':
            {
                if(piatka == true)
                {
                    World.Angle += World.Step;
                }
            }
            break;
        case '2':
            {
                if(piatka == true)
                {
                    World.Angle -= World.Step;
                }
            }
            break;
        case'0':
            {
                World.XRotation =0;
                World.YRotation =0;
                World.ZRotation =0;
                World.Angle = 0;
            }
            break;
        case 'P':
            {
                int index;
                cout << "Write not Shown Plane's index: ";
                cin >> index;
                World.PlaneSwapSide(index);
                COMMIT();
            }
            break;
        case 19: // ctrl + s
            {
                cout << "ZAPISYWANIE\n";
                World.SAVE();
            }
            break;
        case 12: // ctrl + l
            {
                cout << "Wczytywanie\n";
                World.CLEAR();
                World.LOAD();
                glLoadIdentity();
                    COMMIT();
            }
            break;
        case 't':
            {
                if(World.LightType == 0)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_ambient[World.ChoosenLight][0] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_ambient[World.ChoosenLight][1] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_ambient[World.ChoosenLight][2] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_ambient[World.ChoosenLight][3] += World.Step/100;
                    }

                }
                else if(World.LightType == 1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_diffuse[World.ChoosenLight][0] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_diffuse[World.ChoosenLight][1] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_diffuse[World.ChoosenLight][2] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_diffuse[World.ChoosenLight][3] += World.Step/100;
                    }
                }
                else if(World.LightType == 2)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_specular[World.ChoosenLight][0] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_specular[World.ChoosenLight][1] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_specular[World.ChoosenLight][2] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_specular[World.ChoosenLight][3] += World.Step/100;
                    }
                }
                else if(World.LightType == 3)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_position[World.ChoosenLight][0] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_position[World.ChoosenLight][1] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_position[World.ChoosenLight][2] += World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_position[World.ChoosenLight][3] += World.Step/100;
                    }
                }
                Lights();
            }
            break;
        case'r':
            {
                if(World.LightType == 0)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_ambient[World.ChoosenLight][0] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_ambient[World.ChoosenLight][1] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_ambient[World.ChoosenLight][2] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_ambient[World.ChoosenLight][3] -= World.Step/100;
                    }

                }
                else if(World.LightType == 1)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_diffuse[World.ChoosenLight][0] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_diffuse[World.ChoosenLight][1] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_diffuse[World.ChoosenLight][2] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_diffuse[World.ChoosenLight][3] -= World.Step/100;
                    }
                }
                else if(World.LightType == 2)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_specular[World.ChoosenLight][0] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_specular[World.ChoosenLight][1] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_specular[World.ChoosenLight][2] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_specular[World.ChoosenLight][3] -= World.Step/100;
                    }
                }
                else if(World.LightType == 3)
                {
                    if(World.ChoosenDimension == 'x')
                    {
                        World.light_position[World.ChoosenLight][0] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'y')
                    {
                        World.light_position[World.ChoosenLight][1] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'z')
                    {
                        World.light_position[World.ChoosenLight][2] -= World.Step;
                    }
                    else if(World.ChoosenDimension == 'w')
                    {
                        World.light_position[World.ChoosenLight][3] -= World.Step/100;
                    }
                }
                Lights();
            }
            break;
        case ',':
            {   cout << '\n' <<
                World.light_ambient[World.ChoosenLight][0] << " " <<
                World.light_ambient[World.ChoosenLight][1] << " " <<
                World.light_ambient[World.ChoosenLight][2] << " " <<
                World.light_ambient[World.ChoosenLight][3] << '\n' <<
                World.light_diffuse[World.ChoosenLight][0] << " " <<
                World.light_diffuse[World.ChoosenLight][1] << " " <<
                World.light_diffuse[World.ChoosenLight][2] << " " <<
                World.light_diffuse[World.ChoosenLight][3] << '\n' <<
                World.light_specular[World.ChoosenLight][0] << " " <<
                World.light_specular[World.ChoosenLight][1] << " " <<
                World.light_specular[World.ChoosenLight][2] << " " <<
                World.light_specular[World.ChoosenLight][3]<< '\n' <<
                World.light_position[World.ChoosenLight][0]<< " " <<
                World.light_position[World.ChoosenLight][1]<< " " <<
                World.light_position[World.ChoosenLight][2]<< " " <<
                World.light_position[World.ChoosenLight][3] << '\n';

            }
        case 'O':
            World.obrot = !World.obrot;
            break;
        case 'M':
            litm = !litm;
            break;
    }


    glutPostRedisplay();
}
static void idle(void)
{
    glutPostRedisplay();
}

void menu(int value){
    if(value == menuIds[4])
    {
        World.ShowPoints = !World.ShowPoints;
        cout << World.ShowPoints << endl;

    }
    else if(value == menuIds[5])
    {
        World.ShowLines = !World.ShowLines;
    }
    else if(value == menuIds[6])
    {
        World.ShowPlanes = !World.ShowPlanes;
    }
    else if(value == menuIds[7]) //CHOOSE POINT 7-10
    {
        if(World.FirstPoint)
        {
            World.ChoosenPoint = World.FirstPoint;
        }
    }
    else if(value == menuIds[8])
    {
        if(World.SecondPoint)
        {
            World.ChoosenPoint = World.SecondPoint;
        }
    }
    else if(value == menuIds[9])
    {
        if(World.ThirdPoint)
        {
            World.ChoosenPoint = World.ThirdPoint;
        }
    }
    else if(value == menuIds[10])
    {
        if(World.FourthPoint)
        {
            World.ChoosenPoint = World.FourthPoint;
        }
    }
    else if(value == menuIds[11]) // SET POINT 11-14
    {
        if(World.ChoosenPoint > -1)
        {
            cout << "Jestem w srodku\n";
            World.FirstPoint = World.ChoosenPoint;
        }
    }
    else if(value == menuIds[12])
    {
        if(World.ChoosenPoint > -1)
        {
            cout << "Jestem w srodku\n";
            World.SecondPoint = World.ChoosenPoint;
        }
    }
    else if(value == menuIds[13])
    {
        if(World.ChoosenPoint > -1)
        {
            cout << "Jestem w srodku\n";
            World.ThirdPoint = World.ChoosenPoint;
        }
    }
    else if(value == menuIds[14])
    {
        cout << "value: " << value << " Choosen: " << World.ChoosenPoint << endl;
        if(World.ChoosenPoint > -1)
        {
            World.FourthPoint = World.ChoosenPoint;
        }
    }
    else if(value == menuIds[16])
    {
        World.AddCLEARPoint();
    }
    else if(value == menuIds[17])
    {
        //World.AddLine();
    }
    else if(value == menuIds[18])
    {
        World.AddPlane();
    }
    else if(value == menuIds[19]) // Lights type
    {
        World.LightType = 0;
    }
    else if(value == menuIds[20])
    {
        World.LightType = 1;
    }
    else if(value == menuIds[21])
    {
        World.LightType = 2;
    }
    else if(value == menuIds[22])
    {
        World.LightType = 3;
    }
    else if(value == menuIds[31]) // CHOOSE LIGHT 31-38
    {
        World.ChoosenLight = 0;
    }
    else if(value == menuIds[32])
    {
        World.ChoosenLight = 1;
    }
    else if(value == menuIds[33])
    {
        World.ChoosenLight = 2;
    }
    else if(value == menuIds[34])
    {
        World.ChoosenLight = 3;
    }
    else if(value == menuIds[35])
    {
        World.ChoosenLight = 4;
    }
    else if(value == menuIds[36])
    {
        World.ChoosenLight = 5;
    }
    else if(value == menuIds[37])
    {
        World.ChoosenLight = 6;
    }
    else if(value == menuIds[38])
    {
        World.ChoosenLight = 7;
    }
    else if(value == menuIds[40]) // SWITCH LIGHTS 40-47
    {
        if(World.ShowLights[0] == true)
        {
            World.ShowLights[0] = false;
            glDisable(GL_LIGHT0);
        }
        else
        {
            World.ShowLights[0] = true;
            glEnable(GL_LIGHT0);
        }
    }
    else if(value == menuIds[41])
    {
        if(World.ShowLights[1] == true)
        {
            World.ShowLights[1] = false;
            glDisable(GL_LIGHT1);
        }
        else
        {
            World.ShowLights[1] = true;
            glEnable(GL_LIGHT1);
        }
    }
    else if(value == menuIds[42])
    {
        if(World.ShowLights[2] == true)
        {
            World.ShowLights[2] = false;
            glDisable(GL_LIGHT2);
        }
        else
        {
            World.ShowLights[2] = true;
            glEnable(GL_LIGHT2);
        }
    }
    else if(value == menuIds[43])
    {
        if(World.ShowLights[3] == true)
        {
            World.ShowLights[3] = false;
            glDisable(GL_LIGHT3);
        }
        else
        {
            World.ShowLights[3] = true;
            glEnable(GL_LIGHT3);
        }
    }
    else if(value == menuIds[44])
    {
        if(World.ShowLights[4] == true)
        {
            World.ShowLights[4] = false;
            glDisable(GL_LIGHT4);
        }
        else
        {
            World.ShowLights[4] = true;
            glEnable(GL_LIGHT4);
        }
    }
    else if(value == menuIds[45])
    {
        if(World.ShowLights[5] == true)
        {
            World.ShowLights[5] = false;
            glDisable(GL_LIGHT5);
        }
        else
        {
            World.ShowLights[5] = true;
            glEnable(GL_LIGHT5);
        }
    }
    else if(value == menuIds[46])
    {
        if(World.ShowLights[6] == true)
        {
            World.ShowLights[6] = false;
            glDisable(GL_LIGHT6);
        }
        else
        {
            World.ShowLights[6] = true;
            glEnable(GL_LIGHT6);
        }
    }
    else if(value == menuIds[47])
    {
        if(World.ShowLights[7] == true)
        {
            World.ShowLights[7] = false;
            glDisable(GL_LIGHT7);
        }
        else
        {
            World.ShowLights[7] = true;
            glEnable(GL_LIGHT7);
        }
    }
    else if(value == menuIds[49])  //rzut 49 - 52
    {
        rzut = "frustrum";
        resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
    }
    else if(value == menuIds[50])  //rzut 49 - 52
    {
        rzut = "ortho";
        skala = "Nie";
        resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
    }
    else if(value == menuIds[51])  //rzut 49 - 52
    {
        rzut = "ortho";
        skala = "Aspect_1_1";
        resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
    }
    else if(value == menuIds[52])  //rzut 49 - 52
    {
        rzut = "persp";
        resize (glutGet (GLUT_WINDOW_WIDTH),glutGet (GLUT_WINDOW_HEIGHT));
    }
    COMMIT();
}


int main(int argc, char *argv[])
{

    for(int i = 0; i < 1000;i++)
    {
        PointList[i] = 0.0f;
    }

    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);


    glEnable(GL_DEPTH_TEST);
//////////////////////NOWE////////////////////////////
	glEnable(GL_TEXTURE_2D);
	glGenTextures(Number_Of_Textures,obiektyTextur);
	glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE, GL_MODULATE);
	for(int i=0;i<Number_Of_Textures;i++)
    {
        GLubyte *pBytes;
        GLint iWidth, iHeight, iComponents;
        GLenum eFormat;
        glBindTexture(GL_TEXTURE_2D,obiektyTextur[i]);
        pBytes=glploadtga(plikiTextur[i],&iWidth,&iHeight,&iComponents,&eFormat);

        gluBuild2DMipmaps(GL_TEXTURE_2D,iComponents,iWidth,iHeight,eFormat,GL_UNSIGNED_BYTE,pBytes);

        free(pBytes);

        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        //glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);

    }
	///////////////////////////////////////////////////////////////

	//glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_LIGHTING);
	// Je¿eli ten znacznik bêdzie ustawiony, to wielok¹ty zwrócone
	// ty³em do widza bêd¹ rysowane tylko w postaci szkieletu
	glPolygonMode(GL_BACK,GL_LINE);
	glPolygonMode(GL_FRONT,GL_FILL);



    //RIGHT MOUSE BUTTON
    {

    for (int i = 0; i < 53; i++)
        menuIds[i] = glutCreateMenu (menu);

    glutSetMenu(menuIds[0]);

    glutAddSubMenu("Display Options", menuIds[1]);
    glutAddSubMenu("Choose Point" , menuIds[2]);
    glutAddSubMenu("Set Point", menuIds[3]);
    glutAddSubMenu("Create" , menuIds[15]);
    glutAddSubMenu("Light Options", menuIds[29]);
    glutAddSubMenu("Rzut i skala", menuIds[48]);
    glutSetMenu(menuIds[29]);
    glutAddSubMenu("Lights" , menuIds[19]);
    glutAddSubMenu("Mat" , menuIds[24]);
    glutAddSubMenu("Choose Light", menuIds[30]);
    glutAddSubMenu("Turn Light" , menuIds[39]);

    glutSetMenu(menuIds[1]);
    glutAddMenuEntry("Turn Points", menuIds[4]);
    glutAddMenuEntry("Turn Lines", menuIds[5]);
    glutAddMenuEntry("Turn Planes", menuIds[6]);

    glutSetMenu(menuIds[2]);
    glutAddMenuEntry("Choose first", menuIds[7]);
    glutAddMenuEntry("Choose second", menuIds[8]);
    glutAddMenuEntry("Choose third", menuIds[9]);
    glutAddMenuEntry("Choose fourth", menuIds[10]);

    glutSetMenu(menuIds[3]);
    glutAddMenuEntry("set first", menuIds[11]);
    glutAddMenuEntry("set second", menuIds[12]);
    glutAddMenuEntry("set third", menuIds[13]);
    glutAddMenuEntry("set fourth", menuIds[14]);

    glutSetMenu(menuIds[15]);
    glutAddMenuEntry("Add Point", menuIds[16]);
    glutAddMenuEntry("Add Line", menuIds[17]);
    glutAddMenuEntry("Add Plane", menuIds[18]);


    glutSetMenu(menuIds[19]);
    glutAddMenuEntry("Ambient", menuIds[20]);
    glutAddMenuEntry("Diffuse", menuIds[21]);
    glutAddMenuEntry("Specular", menuIds[22]);
    glutAddMenuEntry("Transform", menuIds[23]);

    glutSetMenu(menuIds[24]);
    glutAddMenuEntry("Ambient", menuIds[25]);
    glutAddMenuEntry("Diffuse", menuIds[26]);
    glutAddMenuEntry("Specular", menuIds[27]);
    glutAddMenuEntry("Shininess", menuIds[28]);

    glutSetMenu(menuIds[30]);

    glutAddMenuEntry("GL_LIGHT 0", menuIds[31]); // World.(int)ChoosenLight
    glutAddMenuEntry("GL_LIGHT 1", menuIds[32]);
    glutAddMenuEntry("GL_LIGHT 2", menuIds[33]);
    glutAddMenuEntry("GL_LIGHT 3", menuIds[34]);
    glutAddMenuEntry("GL_LIGHT 4", menuIds[35]);
    glutAddMenuEntry("GL_LIGHT 5", menuIds[36]);
    glutAddMenuEntry("GL_LIGHT 6", menuIds[37]);
    glutAddMenuEntry("GL_LIGHT 7", menuIds[38]);

    glutSetMenu(menuIds[39]);

    glutAddMenuEntry("GL_LIGHT 0", menuIds[40]); // 0 enabled 1-7 disabled at start
    glutAddMenuEntry("GL_LIGHT 1", menuIds[41]); // World.(bool)ShowLights[0-7]
    glutAddMenuEntry("GL_LIGHT 2", menuIds[42]);
    glutAddMenuEntry("GL_LIGHT 3", menuIds[43]);
    glutAddMenuEntry("GL_LIGHT 4", menuIds[44]);
    glutAddMenuEntry("GL_LIGHT 5", menuIds[45]);
    glutAddMenuEntry("GL_LIGHT 6", menuIds[46]);
    glutAddMenuEntry("GL_LIGHT 7", menuIds[47]);

    glutSetMenu(menuIds[48]);
    glutAddMenuEntry("Frustrum", menuIds[49]);
    glutAddMenuEntry("Ortho", menuIds[50]);
    glutAddMenuEntry("Ortho + Aspect_1_1", menuIds[51]);
    glutAddMenuEntry("Perspective", menuIds[52]);


    glutSetMenu(menuIds[0]);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    }

    Lights();

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);





    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();

    return EXIT_SUCCESS;
}
