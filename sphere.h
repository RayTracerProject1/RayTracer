typedef struct sphere
{
    Vector pos;
    double size;
    //int material; //number of the material it has to choose or get.
}sphere;

bool intersectRayTracer(rayTracer *r, sphere *s)
