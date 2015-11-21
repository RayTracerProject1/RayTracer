//Define zero point of the vector.
#define VECTOR_ZERO vec_make(0.0, 0.0, 0.0)

//Define addition calculation           This for seperation
#define VECTOR_ADDITION1(out, a, b)          \
                (out).x = (a).x + (b).x;     \
                (out).y = (a).y + (b).y;     \
                (out).z = (a).z + (b).z;
//Define addition calculation               This for seperation
#define VECTOR_ADDITION2(out, a, b, c)              \
                (out).x = (a).x + (b).x + (c).x;    \
                (out).y = (a).y + (b).y + (c).x;    \
                (out).z = (a).z + (b).z + (c).x;

//Define subtraction calculation         This for seperation
#define VECTOR_SUBTRACTION(out, a, b)       \
                (out).x = (a).x - (b).x;    \
                (out).y = (a).y - (b).y;    \
                (out).z = (a).z - (b).z;

//Define dot product calculation        This for seperation
#define VECTOR_DOTPRODUCT(a, b)              \
                ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z)

//Define cross product calculation                 This for seperation
#define VECTOR_CROSSPRODUCT(out, a, b)                     \
                (out).x=((a).y * (b).z) - ((b).y * (a).z); \
                (out).y=((a).z * (b).x) - ((b).z * (a).x); \
                (out).z=((a).x * (b).y) - ((b).x * (a).y);

//Define multiply calculation      This for seperation
#define VECTOR_MULTIPLYVEC(out, a, b)   \
                (out).x = (a).x * b;    \
                (out).y = (a).y * b;    \
                (out).z = (a).z * b

//Define multiply calculation             this for seperation
#define VECTOR_MULTIPLY2(out, a, b)          \
                (out).x = (a).x * (b).x;     \
                (out).y = (a).y * (b).y;     \
                (out).z = (a).z * (b).z;

//Define divide calculation         This for seperation
#define VECTOR_DIVIDE(out, a, b)      \
                (out).x = (a).x / b;  \
                (out).y = (a).y / b;  \
                (out).z = (a).z / b;

//Make vector with x, y and z axis
typedef struct Vector
{
    double x, y, z;
}Vector;

//Use Vector for all calculations
Vector vecMake(double x, double y, double z);
Vector vecAddition1(Vector a, Vector b);
Vector vecAddition2(Vector a, Vector b, Vector c);
double vecDotProduct(Vector a, Vector b);
Vector vecSubtract(Vector a, Vector b);
Vector vecMultiplyByVec(Vector a, Vector b);
Vector vecMultiply(Vector v, double b);
Vector vecDivide(Vector v, double b);
double vecLength(Vector v);
Vector vecUnit(Vector v);
Vector vecCrossProduct(Vector a, Vector b);
Vector vecNegate(Vector v);

