#include "headers.h"

ray shadowRayMake(Vector hitpoint, Vector lightpos)
{
	ray shadowRay;

	shadowRay.start = hitpoint;
	shadowRay.dir = vecSubtract(lightpos, hitpoint);

}

bool inShadow(ray shadowRay, Vector lightpos)
{
	/*
	 * Do we need a function to check for shadows?
	 * we can just use the collide with sphere function
	 * just using the shadow ray instead of the raytracer ray
	 */
}