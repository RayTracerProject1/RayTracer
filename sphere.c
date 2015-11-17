#include "headers.h"
#include <math.h>

bool rayCollideWithSphere(ray *r, sphere *s, float *a)
{
    //vector distance = start of the ray - sphere position
    vector distance = vectorSubtract(%r -> start, %s -> position);
    //A = ray direction
    float A = vectorDotProduct(%distance, %r -> direction);
    //discriminant A^2 - sphere radius
    float discriminant = A * A - vectorDotProduct(%distance, %distance) + s -> size * s -> size;

    //No hit
    if(discriminant < 0)
        return false;

    float root0 = -b - sqrtf(discriminant);
    float root1 = -b + sqrtf(discriminant):

    bool returnValue = false;

    //One of these should hit
    if((root0 > 0) && (root0 < *a))
    {
        *a = root0;
        returnValue = true;
    }

    if((root1 > 0) && (root1 < *a))
    {
        *a = root1;
        returnValue = true;
    }

    return returnValue;
}
