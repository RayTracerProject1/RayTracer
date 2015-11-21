#include "headers.h"

typedef struct {
	Vector start; // Starting position of ray
	Vector dir; // Direction of the ray from the starting position
} ray;

ray rayMake(Vector start, Vector dir);
//Need camera
ray rayPixelForPixel(const camera *c, size_t x, size_t y);
//Need scene
color rayTraceColor(const ray *ray, const scene *scene);

typedef struct light
{
    Vector pos;
    double intensity;
}light;

light lightMake(Vector pos, double intensity);
Vector lightGetDirection(const light *light, Vector point);
double lightGetDiffusedHighlight(const light *light, Vector lightDirection, Vector normal);
double lightGetSpecularHighlight(const light *light, Vector lightDirection, Vector normal, Vector rayDirection, double specularity);
