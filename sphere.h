typedef struct sphere
{
    vector position;
    float radius;
    //int material; //number of the material it has to choose or get.
}sphere;

bool rayCollideWithSphere(ray *r, sphere *s, float *a)
