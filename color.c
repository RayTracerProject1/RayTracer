/*
 * Determines the color at the point the ray hits the object
 */

#include "headers.h"

color colorCoeMul(double coef, color *c)
{
	color result = {c->red * coef, c->green * coef, c->blue * coef};
	return result;
}

color colorAdd(color *c1, color *c2)
{
	color c = {c1->red + c2->red, c1->green + c2->green, c1->blue + c2->blue};
	return c;
}

color colorMul(color *c1, color *c2)
{
	color c = {c1->red * c2->red, c1->green * c2->green, c1->blue * c2->blue};
	return c;
	}
}