/*
 * Determines the color at the point the ray hits the object
 */

#include "headers.h"

color colorCoeMul(double coef, color *c)
{
	color result = {c->red * coef, c->green * coef, c->blue * coef};
	return result;
}