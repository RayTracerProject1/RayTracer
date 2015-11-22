#include "headers.h"

Vector vecMake(double x, double y, double z)
{
    Vector v;
    v.x = x, v.y = y, v.z = z;
    return v;
}

Vector vecAddition1(Vector a, Vector b)
{
    return vecMake(a.x + b.x, a.y + b.y, a.z + b.z);
}

Vector vecAddition2(Vector a, Vector b, Vector c)
{
    return vecMake(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z);
}

double  vecDotProduct(Vector a, Vector b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

Vector vecSubtract(Vector a, Vector b)
{
    return vecMake(a.x - b.x, a.y - b.y, a.z - b.z);
}

Vector vecMultiplyByVec(Vector a, Vector b)
{
    return vecMake(a.x * b.x, a.y * b.y, a.z * b.z);
}

Vector vecMultiply(Vector v, double b)
{
    return vecMake(v.x * b, v.y * b, v.z * b);
}

Vector vecDivide(Vector v, double b)
{
    return vecMultiply(v, 1.0 / b);
}

double vecLength(Vector v)
{
    return sqrt(SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z));
}

//Copy Pasta. Needed this for units.
static double invSqrt1(double y)
{
    double xhalf = ( double )0.5 * y;
    long long i = *( long long* )( &y );

//LL suffix for (long long) type for GCC
    i = 0x5fe6ec85e7de30daLL - ( i >> 1 );
    y = *( double* )( &i );
    y = y * ( ( double )1.5 - xhalf * y * y );

    return y;
}

Vector vecUnit(Vector v)
{
    double is = invSqrt1(SQUARE(v.x) + SQUARE(v.y) + SQUARE(v.z));
    return vecMultiply(v, is);
}

Vector vecCrossProduct(Vector a, Vector b)
{
    Vector v;
    v.x = (a.y * b.z) - (b.y * a.z);
    v.y = (a.z * b.x) - (b.z * a.x);
    v.z = (a.x * b.y) - (b.x * a.y);
    return v;
}

Vector vecNegate(Vector v)
{
    return vecMake(-v.x, -v.y, -v.z);
}
