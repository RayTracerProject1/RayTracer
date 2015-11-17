#include "headers.h"
#include <math.h>

bool intersectRayTracer(rayTracer *r, Sphere *s)
{
    double A = VectorDotProduct(&r -> direction, &r -> direction);

    Vector Distance = VectorSubtract(&r -> start, &s -> position);

    double B = 2 * VectorDotProduct(&r -> direction, &Distance);

    double C = VectorDotProduct(&Distance, &Distance) - (s -> radius *s -> radius);

    //Or pow, easy way B*B = B^2
    double Discriminant = B * B - 4 * A * C;

    if(Discriminant < 0)
        return false;
    else
        return true;
}


