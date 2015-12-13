#include <stdio.h>
#include <math.h>

#include "headers.h"

/* global variables */
unsigned char *img = NULL;


color raytrace(ray *viewRay, scene *myScene)
{
	color output = {0.0f, 0.0f, 0.0f};
	double coef = 1.0f;
	int level = 0;

	do{
		Vector hitpoint, n;
		int  currentSphere = -1;
		int currentTriangle = -1;
		material currentMat;
		double root = 20000.0f;
		double temp;
		Vector normal1;

		unsigned int i;
		for(i = 0; i < myScene->numSpheres; ++i) {
			if(collideWithSphere(viewRay, &myScene->spheres[i], &root))
				currentSphere = i;
		}

		for(i = 0; i < myScene->numTriangles; ++i) {
			if(collideWithTriangle(viewRay, &myScene->triangles[i], &root, &n1)) {
				currentTriangle = i;
				currentSphere = -1;
			}
		}

		if(currentSphere != -1) {
			Vector scaled = vecMultiply(&viewRay->dir, root);
			hitpoint = vecAddition1(&viewRay->start, &scaled);
			n = vecSubtract(&hitpoint, &myScene->spheres[currentSphere].pos);
			temp = vecDotProduct(&n, &n);
			if(temp == 0.0f)
				break;
			temp = (1.0f / sqrtf(temp));
			n = vecMultiply(&n, temp);
			currentMat = myScene->materials[myScene->spheres[currentSphere].material];
		
		} else if(currentTriangle != -1) {
			Vector scaled = vecMultiply(&viewRay->dir, root);
			hitpoint = vecAddition1(&viewRay->start, &scaled);
			n = normal1;
			temp = vecDotProduct(&n, &n);
			if(temp == 0.0f)
				break;
			temp = (1.0f / sqrtf(temp));
			n = vecMultiply(&n, temp);
			currentMat = myScene->material[myScene->triangles[currentTriangle].material];

		} else {
			/* no hit - add background */
			color test = {0.05, 0.05, 0.35};
			color tmp = colorCoeMul(coef, &test);
			output = colorAdd(&output, &tmp);
			break;
		}

		bool inside;

		if(vecDotProduct(&n, &viewRay->dir) > 0.0f) {
			n = vecMultiply(&n, -1.0f);
			inside = TRUE;
		} else {
			inside = FALSE;
		}

		if(!inside) {

			ray lightRay;
			lightRay.start = hitpoint;

			/* find the value of the light at this point */
			unsigned int j;
			for(j = 0; j < myScene->numLights; ++j) {
				light currentLight = myScene->lights[i];
				lightRay.dir = vecSubtract(&currentLight.pos, &hitpoint);

				double lightprojection = vecDotProduct(&lightRay.dir, &n);

				if(lightprojection <= 0.0f)
					continue; /* goes back and finds another light */
				double lightdist = vecDotProduct(&lightRay.dir, &lightRay.dir);
				double temp = lightdist;

				if(temp == 0.0f)
					continue;
				temp = (1.0f / sqrtf(temp));
				lightRay.dir = vecMultiply(&lightRay.dir, temp);
				lightprojection = temp * lightprojection;

				/* calculate shadows */
				bool inshadow = FALSE;
				double t = lightdist;

				unsigned int k;

				for(k = 0; k < myScene->numSpheres; ++k) {
					if(collideWithSphere(&lightRay, &myScene->spheres[k], &root)) {
						inshadow = TRUE;
						break;
					}
				}

				for(k = 0; k < myScene->numTriangles; ++k) {
					if(collideWithTriangle(&lightRay, &myScene->triangles[k], &root, &normal1)) {
						inshadow = TRUE;
						break;
					}
				}

				if(!inshadow) {
					/* Diffuse refraction based on lamberts sine law */
					double lambert = vecDotProduct(&lightRay.dir, &n) * coef;
					double noiseCoef = 0.0f;
					int level = 0;

					switch(currentMat.MatType) {
						/* TODO: make cases for materials */
					}

					/* Blinn specular */
					double viewprojection = vecDotProduct(%viewRay->dir, &n);
					Vector blinnDir = vecSubtract(&lightRay.dir, &viewRay.dir);
					double temp = vecDotProduct(&blinnDir, &blinnDir);
					if(temp != 0.0f) {
						double blinn = (1.0f / sqrtf(temp)) * max(lightprojection - viewprojection, 0.0f);
						blinn = coef * powf(blinn, currentMat.power);
						color tmp1 = colorCoeMul(blinn, &currentMat.specular);
						color tmp2 = colorMul(&tmp1, &currentLight.intensity);
						output = colorAdd(&output, &tmp2);
					}

				}
			}
			/* iterate ove the reflection */

			coef *= currentMat.reflection;
			double reflect = 2.0f * vecDotProduct(&viewRay->dir, &n);
			viewRay->start = hitpoint;

			Vector tmp = vecMultiply(&n, reflect);
			viewRay->dir = vecSubtract(&viewRay->dir, &tmp);
		}
		level++;
		/* limit iteration depth to 10 */
	} while((coef > 0.0f) && (level < 10));
	return output;
}