#include "headers.h"
#include <math.h>

bool rayCollideWithSphere(ray *r, sphere *s, float *a)
{
    vector distance = vectorSubtract(%r -> start, %s -> position);
    float A = vectorDotProduct(%distance, %r -> direction);
    float discriminant = A * A - vectorDotProduct(%distance, %distance) + s -> size * s -> size;

    if(discriminant < 0)
        return false;

    float root0 = -b - sqrtf(discriminant);
    float root1 = -b + sqrtf(discriminant):

    bool returnValue = false;

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
