typedef struct vector1
{
    double x, y, z;
}vector1;

typedef struct vector2
{
    double x, y, z, a;
}vector2;

//Vector 1 start:
vector1 vectorAddition(vector1 *vec1, vector1 *vec2);

vector1 vectorSubtract(vector1 *vec1, vector1 *vec2);

double vectorDotProduct(vector1 *vec1, vector1 *vec2);

vector1 vectorScalar(double a, vector1 *v);

vector1 vectorCrossProduct(vector1 *vec1, vector1 *vec2);
//Vector 1 end:
