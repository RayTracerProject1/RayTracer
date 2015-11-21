typedef struct sphere
{
    Vector pos;
    double size; // Might want to use radius instead.
    //int material; //number of the material it has to choose or get.
}sphere;

bool intersectRayTracer(rayTracer *r, sphere *s);

Vector hitPointPos(rayTracer *r, sphere *s);
