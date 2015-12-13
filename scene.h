#include "sphere.h"
#include "triangle.h"
#include "dataStructure.h"

typedef struct scene {
	material *materials;
	sphere *spheres;
	triangle *triangles;
	light *lights;

	int width, height;

	int numSpheres;
	int numMaterials;
	int numLights;
	int numTriangles;

	int complexity;

} scene;