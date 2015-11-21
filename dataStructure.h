#include "headers.h"

typedef struct {
	Vector pos; // Starting position of ray
	Vector dir; // Direction of the ray from the starting position
} ray;

typedef struct light
{
    Vector pos;
    double intensity;
}light;

light lightMake(Vector pos, double intensity);
Vector lightGetDirection(const light *light, Vector point);
double lightGetDiffusedHighlight(const light *light, Vector lightDirection, Vector normal);
double lightGetSpecularHighlight(const light *light, Vector lightDirection, Vector normal, Vector rayDirection, double specularity);
