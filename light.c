#include <math.h>
#include "headers.h"

#define KS_CONSTANT 1.0

lightMake(Vector pos, double intensity)
{
    light l = {.pos = pos, .intensity = intensity};
    return l;
}

Vector lightGetDirection(const light *light, Vector point)
{
    return vecUnit(vecSubtract(point, light->pos));
}

double lightGetDiffusedHighlight(const light *light, Vector direction, Vector normal_distribution)
{
    double highlight = VECTOR_DOTPRODUCT(normal, direction);

    if(highlight < 0)
        return 0;
    else
        return highlight * light->intensity;
}

double lightGetSpecularHighlight(const light *light, Vector lightDirection, Vector normal, Vector rayDirection, double specularity)
{
    double highlight = VECTOR_DOTPRODUCT(normal, lightDirection);
    Vector V = vecNegate(rayDirection);
    Vector R = vecSubtract(lightDirection, vecMultiply(normal, highlight * 2.0));
    double dot = vecDotProduct(V, R);

    if (dot < 0)
        return 0;

    double spec = pow(dot, specularity) * KS_CONST * light->intensity;
    return spec;
}
