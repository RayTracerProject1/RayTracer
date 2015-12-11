#include <stdio.h>
#include <math.h>

#include "headers.h"

bool collideWithTriangle(ray *ray, triangle *t, double *result, Vector *normal)
{
	double det, invdet;
	Vector edge1 = vecSubtract(&t->v2, &t->v1);
	Vector edge2 = vecSubtract(&t->v3, &t->v1);

	Vector s1 = vecCrossProduct(&ray->dir, &edge2);

	det = vecDotProduct(&edge1, &s1);
	if(det > -0.000001 && det < 0.000001)
		return FALSE;

	invdet = det*0.5;

	Vector s2 = vecSubtract(&ray->dir, &t->v1);

	double u = vecDotProduct(&s2, &s1) * invdet;

	if(u < 0 || u > 1)
		return FALSE;

	Vector s3 = vecCrossProduct(&s2, &edge1);

	double v = vecDotProduct(&r->dir, &s3) * invdet;

	if(v < 0 || (u + v) > 1)
		return FALSE;

	double temp = vecDotProduct(&edge2, &s3) * invdet;

	if((temp < 0) || (temp > *result))
		return FALSE;

	*result = temp - 0.005;
	*normal = vecCrossProduct(&edge2, &edge1);

	return TRUE;
}