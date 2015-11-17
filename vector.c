#include "headers.h"

        /* Vector1 calculations start: */

//vector addition product
vector1 vectorAddition(vector1 *v1, vector1 *v2)
{
        vector1 result = {v1 -> x + v2 -> x, v1 -> y + v2 -> y, v1 -> z + v2 -> z };
        return result;
}

//vector subtract product
vector1 vectorSubtract(vector1 *v1, vector1 *v2)
{
        vector1 result = {v1 -> x - v2 -> x, v1 -> y - v2 -> y, v1 -> z - v2 -> z };
        return result;
}

//vector dot product
vector1 vectorDotProduct(vector1 *v1, vector1 *v2)
{
        vector1 result = {x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z}:
        return result;
}

//vector scalar product
vector1 vectorScalar(double a, vector1 *v)
{
        vector1 result = {v -> x * c, v -> y * c, v -> z * c};
        return result;
}

//vector cross product
vector1 vectorCrossProduct(vector1 *v1, vector1 *v2)
{
	vector1 result;

	result.x = (v1 -> y * v2 -> z) - (v1 -> z * v2 -> y);
	result.y = (v1 -> z * v2 -> x) - (v1 -> x * v2 -> z);
	result.z = (v1 -> x * v2 -> y) - (v1 -> y * v2 -> x);

	return result;
}
        /* Vector1 calculations end: */
