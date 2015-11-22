#include "headers.h"
#include <math.h>

bool collideWithSphere(rayTracer *r, sphere *s, double *t)
{
    Vector dist = vecSubtract(&r->start, &s->pos);
    double B = vecDotProduct(&dist, &r->dir);
    double D = pow(B, 2) - vecDotProduct(&dist, &dist) + s->size * s->size;

    if(D < 0)
        return false;

    double root1 = -B - sqrtf(D);
    double root2 = -B +sqrtf(D);

    bool returnValue = false;

    if((root1 > 0) && (root1 < *t))
    {
        *t = root1;
        returnValue = true;
    }
    if((root2 > 0) && (root2 < *t))
    {
        *t = root2;
        returnValue = true;
    }

    return returnValue;
}

// function to find position of the intersection point
vector hitPointPos(rayTracer *r, sphere *s)
{
    double A = vecDotProduct(&r -> direction, &r -> direction);

    Vector Distance = vecSubtract(&r -> start, &s -> position);

    double B = 2 * vecDotProduct(&r -> direction, &Distance);

    double C = vecDotProduct(&Distance, &Distance) - (s -> radius *s -> radius);

    //Or pow, easy way B*B = B^2
    double Discriminant = B * B - 4 * A * C;


    // start calculation of roots
    Discriminant = sqrt(Discriminant);

    double q;
    if(B < 0)
        q = (-b - Discriminant) * 0.5;
    else
        q = (-b + Discriminant) * 0.5;

    double root1 = q / A;
    double root2 = C / q;

    // setting root 1 to be the lowest root
    if(root1 > root2) {
        double temp = root1;
        root1 = root2;
        root2 = temp;
    }

    // start calculation of intersect point position

    // distance from ray start to hit position
    double distToHit = root1;
    if(distToHit < 0)
        distToHit = root2;

    Vector hitPos = &r->start + (&r->direction * distToHit);

    return hitPos;
}
