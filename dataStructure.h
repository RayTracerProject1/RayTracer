#include "headers.h"

//Brug vector headeren, den findes allerede -> vector.h
/*typedef struct {
	double x, y, z;
} vector;
* Also might want the structures for each ting in it's own header file,
* so the struct for color will be in the color.h
*/

//test
#define WOOD 0
#define BRONZE 1
#define SILVER 2
#define GOLD 3
#define PLATINUM 4
#define DIAMOND 5
#define TITANIUM 6

//test
typedef struct material
{
    int materialType;
}material;

typedef struct {
	vector1 pos; // Starting position of ray
	vector1 dir; // Direction of the ray from the starting position
} ray;

typedef struct {
	vector1 pos;
	color lightColor;
	double intensity;
} light;
