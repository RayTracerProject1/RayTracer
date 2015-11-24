typedef struct sphere
{
    Vector pos;
    double size; // Might want to use radius instead.
    //int material; //number of the material it has to choose or get.
}sphere;

bool collideWithSphere(rayTracer *r, sphere *s, double *root);

Vector hitPointPos(rayTracer *r, sphere *s);
