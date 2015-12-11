#include <stdio.h>
#include <math.h>

#include "headers.h"

bool collideWithTriangle(rayTracer *ray, triangle *t, double *result, Vector *normal)
{
	double det, invdet;
	Vector edge1 = vecSubtract(&t->v2, &t->v1);
	Vector edge2 = vecSubtract(&t->v3, &t->v1);

	Vector s1 = vecCrossProduct(&ray->dir, &edge2);

	det = vecDotProduct(&edge1, &s1);
	if(det > -0.000001 && det < 0.000001)
		return FALSE;

	invdet = det*0.5;

	Vector s2
}