#include "headers.h"
#include <math.h>

bool intersectRayTracer(rayTracer *r, sphere *s)
{
    double A = vecDotProduct(&r -> direction, &r -> direction);

    Vector Distance = vecSubtract(&r -> start, &s -> position);

    double B = 2 * vecDotProduct(&r -> direction, &Distance);

    double C = vecDotProduct(&Distance, &Distance) - (s -> radius *s -> radius);

    //Or pow, easy way B*B = B^2
    double Discriminant = B * B - 4 * A * C;

    if(Discriminant < 0)
        return false;
    else
        return true;
}

// function to find position of the intersection point
vector hitPointPos(rayTracer *r, sphere *s)
{
    double A = VectorDotProduct(&r -> direction, &r -> direction);

    Vector Distance = VectorSubtract(&r -> start, &s -> position);

    double B = 2 * VectorDotProduct(&r -> direction, &Distance);

    double C = VectorDotProduct(&Distance, &Distance) - (s -> radius *s -> radius);

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
    vector hitPos = &r->start + (&r->direction * distToHit);

    return hitPos;
}
