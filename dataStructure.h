#include "headers.h"

typedef struct {
	double x;
	double y;
	double z;
} vector;

typedef struct {
	vector pos; // Starting position of ray
	vector dir; // Direction of the ray from the starting position
} ray;

typdef stuct {
	double red;
	double green;
	double blue;
} color;

typedef struct {
	vector pos;
	color lightColor;
	double intensity;
} light;