#include <stdio.h>
#include "headers.h"

void cameraInit(camera *cam, Vector pos, Vector dir, double len, double wid, double hei)
{
    cam->pos = pos;
    cam->len = len;
    cam->wid = wid;
    cam->hei = hei;
    cam->dir = vecUnit(dir);
}

//http://people.cs.clemson.edu/~dhouse/courses/405/notes/raycamera.pdf
void cameraSetup(camera *c)
{
    Vector Xc = c->pos;
    Vector Uc = c->dir;
    double Zp = c->len;
    Vector Vup = vecMake(0.0, -1.0, 0.0);
    Vector C0 = vecAddition1(Xc, vecMultiply(Uc, Zp));
    Vector Ux = vecUnit(vecCrossProduct(Uc, Vup));
    Vector Uy = vecCrossProduct(vecMultiply(Uc, -1.0), Ux);

    c->planeCenter = C0;
    c->planeDirX = Ux;
    c->planeDirY = Uy;
}
