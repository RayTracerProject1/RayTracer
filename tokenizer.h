#define MAX_VERTICES 10000
#define MAX_POLYGONS 10000

/* Vertex */
typedef struct {
	float x,y,z;
} vertex_type;

/* polygon */
typedef struct {
	int a,b,c;
} polygon_type;

typedef struct {
	float u,v;
} mapcoord_type;

/* Object */
typedef struct {
	char name[20];

	int vertices_qty;
	int polygon_qty;

	vertex_type vertex[MAX_VERTICES];
	polygon_type polygon[MAX_POLYGONS];
	mapcoord_type mapcoord[MAX_VERTICES];

} obj_type;

char Load3DS(obj_type *p_object, char *p_filename);

