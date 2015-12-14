#include "headers.h"//YOLO

#define max(a, b) (((a) > (b)) ? (a) : (b))

#define GOURAUD 0
#define MARBLE 1
#define TURBULENCE 2

typedef struct material {
	int MatType;
	color diffuse;
	color mdiffuse;
	double bump, reflection;
	color specular;
	double power;
} material;

typedef struct {
	Vector start; // Starting position of ray
	Vector dir; // Direction of the ray from the starting position
} ray;

ray rayMake(Vector start, Vector dir);
//Need camera = done I guess
ray rayPixelForPixel(const camera *c, size_t x, size_t y);
//Need scene
color rayTraceColor(const ray *ray, const scene *scene);

//light.c
typedef struct light
{
    Vector pos;
    double intensity;
}light;

//function defines/redefines.
light lightMake(Vector pos, double intensity);
Vector lightGetDirection(const light *light, Vector point);
double lightGetDiffusedHighlight(const light *light, Vector lightDirection, Vector normal);
double lightGetSpecularHighlight(const light *light, Vector lightDirection, Vector normal, Vector rayDirection, double specularity);
