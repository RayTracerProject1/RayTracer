/*
* Defines what the camera needs for it to work correctly.
* Makes a function for the camera init and setup.
* Look at camera.c
*/

#include "headers.h"

typedef struct camera
{
    Vector pos;
    Vector dir;
    Vector planeCenter;
    Vector planeDirX;
    Vector planeDirY;
    double len;
    double wid;
    double hei;
}camera;

void cameraInit(camera *cam, Vector pos, Vector dir, double len, double wid, double hei);
void cameraSetup(camera *c);
