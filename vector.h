//vector addition product

typedef struct vec1
{
    float x;
    float y;
    float z;
}vec1;

typedef struct vec2
{
    float x;
    float y;
    float z;
    float a;
}vec2;

vector vectorAddition(vector *v1, vector *v2)
{
        vector result = {v1 -> x + v2 -> x, v1 -> y + v2 -> y, v1 -> z + v2 -> z };
        return result;
}

//vector subtract product
vector vectorSubtract(vector *v1, vector *v2)
{
        vector result = {v1 -> x - v2 -> x, v1 -> y - v2 -> y, v1 -> z - v2 -> z };
        return result;
}

//vector dot product
vector vectorDotProduct(vector *v1, vector *v2)
{
        return v1 -> x * v2 -> x + v1 -> y * v2 -> y + v1 -> z * v2 -> z;
}

//vector scalar product
vector vectorScalar(double a, vector *v)
{
        vector result = {v -> x * c, v -> y * c, v -> z * c};
        return result;
}

//vector cross product
vector vectorCrossProduct(vector *v1, vector *v2)
{
	vector result;

	result.x = (v1 -> y * v2 -> z) - (v1 -> z * v2 -> y);
	result.y = (v1 -> z * v2 -> x) - (v1 -> x * v2 -> z);
	result.z = (v1 -> x * v2 -> y) - (v1 -> y * v2 -> x);

	return result;
}
