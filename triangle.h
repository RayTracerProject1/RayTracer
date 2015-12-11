typedef struct triangle {
	Vector v1, v2, v3; // Vertices
	int material;
} triangle;

bool collideWithTriangle(rayTracer *ray, triangle *t, double *result, Vector *normal);
