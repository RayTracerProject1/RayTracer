#include "headers.h"

//Brug vector headeren, den findes allerede -> vector.h
/*typedef struct {
	double x;
	double y;
	double z;
} vector; */

typedef struct {
	vector1 pos; // Starting position of ray
	vector1 dir; // Direction of the ray from the starting position
} ray;

typdef stuct {
	double red;
	double green;
	double blue;
} color;

typedef struct {
	vector1 pos;
	color lightColor;
	double intensity;
} light;
