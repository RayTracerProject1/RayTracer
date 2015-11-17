typedef struct sphere
{
    vector1 position;
    double radius;
    //int material; //number of the material it has to choose or get.
}sphere;

bool rayCollideWithSphere(ray *r, sphere *s)
