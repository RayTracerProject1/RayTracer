#include <math.h>
#include "headers.h"

//half-velocity constant
#define KS_CONSTANT 1.0

//make light as a position + intensity. needs a position.
lightMake(Vector pos, double intensity)
{
    light l = {.pos = pos, .intensity = intensity};
    return l;
}

//direction of the light. Unit vector needed.
Vector lightGetDirection(const light *light, Vector point)
{
    return vecUnit(vecSubtract(point, light->pos));
}

//Diffused highlight
double lightGetDiffusedHighlight(const light *light, Vector direction, Vector normal_distribution)
{
    double highlight = VECTOR_DOTPRODUCT(normal, direction);

    if(highlight < 0)
        return 0;
    else
        return highlight * light->intensity;
}

//Specular highlight
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
