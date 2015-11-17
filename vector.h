typedef struct vector1
{
    float x, y, z;
}vector1;

typedef struct vector2
{
    float x, y, z, a;
}vector2;

vector1 vectorAddition(vector1 *vec1, vector1 *vec2);

vector1 vectorSubtract(vector1 *vec1, vector1 *vec2);

float vectorDotProduct(vector1 *vec1, vector1 *vec2);

vector1 vectorScalar(float a, vector1 *v);

vector1 vectorCrossProduct(vector1 *vec1, vector1 *vec2);
