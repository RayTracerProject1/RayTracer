/* Shading
 * to determine shade we look at the angle between the ray hitting the object and the
 * normal vector from the point which the ray hits.
 * taking the cosine of this angle gives a number between 0 and 1 which determines the shading from 
 * 0% to 100% 
 * this will be used in determining the color as the color coefficient
 */


 #include "headers.h"
 #include <math.h>

 double shadeCoef(vector1 spherePos, vector1 hitPos, vector1 lightPos)
 {
 	vector1 normal = vectorSubtract(spherePos, hitPos); // get the normal vector from the surface
 	vector1 lightVec = vectorSubtract(hitPos, lightPos); // the vector from the hit to the light

 	double shadeCoef = vectorDotProduct(normal, lightVec); // find the cosines of the angle between them

 	return shadeCoef;
 }

 // Might be able to upgrade the function to include reflections