#include "headers.h"
#include <math.h>

bool IntersectRayTracer(RayTracer * r, Sphere * s)
{
    float A = VectorDotProduct(&r -> direction, &r -> direction);

    Vector Distance = VectorSubtract(&r -> start, &s -> position);

    float B = 2 * VectorDotProduct(&r -> direction, &Distance);

    float C = VectorDotProduct(&Distance, &Distance) - (s -> radius * s -> radius);

    float Discriminant = B * B - 4 * A * C;//Or pow, easy way B*B = B^2

    if(Discriminant < 0)
        return false;
    else
        return true;
}
