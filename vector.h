
typedef struct {
        double x;
        double y;
        double z;
} vector;


// Function Prototypes

//vector addition product
vector vectorAddition(vector *v1, vector *v2);

//vector subtract product
vector vectorSubtract(vector *v1, vector *v2);

//vector dot product
vector vectorDotProduct(vector *v1, vector *v2);

//vector scalar product
vector vectorScalar(double a, vector *v);

//vector cross product
vector vectorCrossProduct(vector *v1, vector *v2);