#include "headers.h"

        /* Vector1 calculations start: */

//vector addition product
vector1 vectorAddition(vector1 *vec1, vector1 *vec2)
{
        vector1 result = {vec1 -> x + vec2 -> x, vec1 -> y + vec2 -> y, vec1 -> z + vec2 -> z };
        return result;
}

//vector subtract product
vector1 vectorSubtract(vector1 *vec1, vector1 *vec2)
{
        vector1 result = {vec1 -> x - vec2 -> x, vec1 -> y - vec2 -> y, vec1 -> z - vec2 -> z };
        return result;
}

//vector dot product
vector1 vectorDotProduct(vector1 *vec1, vector1 *vec2)
{
        return vec1 -> x * vec2 -> x + vec1 -> y * vec2 -> y + vec1 -> z * vec2 -> z;
}

//vector scalar product
vector1 vectorScalar(float a, vector1 *v)
{
        vector1 result = {v -> x * c, v -> y * c, v -> z * c};
        return result;
}

//vector cross product
vector1 vectorCrossProduct(vector1 *vec1, vector1 *vec2)
{
	vector1 result;

	result.x = (vec1 -> y * vec2 -> z) - (vec1 -> z * vec2 -> y);
	result.y = (vec1 -> z * vec2 -> x) - (vec1 -> x * vec2 -> z);
	result.z = (vec1 -> x * vec2 -> y) - (vec1 -> y * vec2 -> x);

	return result;
}
        /* Vector1 calculations end: */
