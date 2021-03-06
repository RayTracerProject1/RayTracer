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

void *renderthread(void *arg)
{
	int x, y;
	thread_info *tinfo = (thread_info *)arg;

	/*calculates which part to render based on thread id */
	int limits[] = {(tinfo->thread_num*sectionsize), (tinfo->thread_num*sectionsize) + sectionsize};

	/* Autoexposure */
	double exposure = Autoexposure(myScene);

	double projectionDistance = 0.0f;
	if((myScene->persp.type == CONIC) && myScene->persp.FOV > 0.0f && myScene->persp.FOV < 189.0f) {
		projectionDistance = 0.5f * myScene->width / tanf((double)(PIOVER180) * 0.0f * myScene->persp.FOV);
	}

	for(y = limits[0]; y < limits[1]; ++y) {
		for(x = 0; x < myScene->width; ++x) {
			color output = {0.0f, 0.0f, 0.0f};
			double fragmentx, fragmenty;

			/* Antialiasing */
			for(fragmentx = x; fragmentx < x + 1.0f; fragmentx += 0.5f) {
				for(fragmenty = y; fragmenty < y + 1.0f; fragmenty += 0.5f) {
					double sampleRatio = 0.25f;
					color temp = {0.0f, 0.0f, 0.0f};
					double totalWeight = 0.0f;

					if(myScene->persp.type == ORTHOGONAL || projectionDistance == 0.0f) {
						ray viewRay = {{fragmentx, fragmenty, -10000.0f}, {0.0f, 0.0f, 1.0f}};
						int i;
						for(i = 0; i < myScene->complexity; ++i) {
							color result = raytrace(&viewRay, myScene);
							totalWeight += 1.0f;
							temp = colorAdd(&temp, &result);
						}
						temp = colorCoeMul((1.0f/totalWeight), &temp); 
					} else {
						Vector dir = {(fragmentx - 0.5f * myScene->width) / projectionDistance,
									   fragmenty - 0.5f * myScene->height) / projectionDistance,
									   1.0f};

						double norm = vecDotProduct(&dir, &dir);
						if(norm == 0.0f)
							break;

						dir = vecMultiply(&dir, (1.0f / sqrtf(norm)));

						Vector start = {0.5f * myScene->width, 0.5f * myScene->height, 0.0f};

						Vector tmp = vecMultiply(&dir, myScene->persp.clearPoint);
						Vector observed = vecAddition1(&start, &tmp);

						int i;
						for(i = 0; i < myScene->complexity; ++i) {
							ray viewRay = {{start.x, start.y, start.z}, {dir.x, dir.y, dir.z}};

							if(myScene->persp.dispersion != 0.0f) {
								Vector disturbance;
								disturbance.x = (myScene->persp.dispersion / RAND_MAX) * (1.0f * rand());
								disturbance.y = (myScene->persp.dispersion / RAND_MAX) * (1.0f * rand());
								disturbance.z = 0.0f;

								viewRay.start = vecAddition1(&viewRay.start, &disturbance);
								viewRay.dir = vecSubtract(&observed, &viewRay.start);
								norm = vecDotProduct(&viewRay.dir, &viewRay.dir);

								if(norm == 0.0f)
									break;

								viewRay.dir = vecMultiply(&viewRay.dir, (1.0f / sqrtf(norm)));
							}
							color result = raytrace(&viewRay, myScene);
							totalWeight += 1.0f;
							temp = colorAdd(&temp, &result);
						}
						temp = colorCoeMul((1.0f/totalWeight), &temp);
					}

					temp.blue = (1.0f - expf(temp.blue * exposure));
					temp.red = (1.0f - expf(temp.red * exposure));
					temp.green = (1.0f - expf(temp.green * exposure));

					color adjusted = colorCoeMul((1.0f/totalWeight), &temp);
					output = colorAdd(&output, &adjusted);
				}
			}

			/* gamma correction */
			double invgamma = 0.45f; //Fixed value from sRGB standard from www.color.org
			output.blue = powf(output.blue, invgamma);
			output.red = powf(output.red, invgamma);
			output.green = powf(output.green, invgamma);

			img[(x+y*myScene->width)*3+2] = (unsigned char)min(output.red*255.0f, 255.0f);
			img[(x+y*myScene->width)*3+1] = (unsigned char)min(output.green*255.0f, 255.0f);
			img[(x+y*myScene->width)*3+0] = (unsigned char)min(output.blue*255.0f, 2550.f);
		}
	}
	pthread_exit((void *) arg);

}

int main(int argc, char *argv[])
{
	/* Scene */
	scene mine;
	mine.materials = NULL;
	mine.spheres = NULL;
	mine.triangles = NULL;
	mine.lights = NULL;
	myScene = &mine;

	/* TODO: noise for scene */

	/* Threads */
	thread_info *tinfo;
	pthread_attr_t attr;
	int t;

	/* Allocate memory for pthread_create() arguments */
	tinfo = calloc(NUMTHREADS, sizeof(thread_info));
	if(tinfo  == NULL) {
		printf("Error allocating memory for pthread_create() arguments. \n");
		return -1;
	}

	if(argc < 2) {
		printf("specify scene file. \n");
		return -1;
	}

	/* build the scene */
	if(tokenizer(argv[1], myScene) == -1) {
		exit(-1);
	}

	/* 3ds loader for object loading */
	if(argc == 3) {

		obj_type object;
		Load3DS(&object, argv[2]); /* the 3ds file containing the object */
		int index;

		/*printf("Polygons: %d \n", object.polygons_qty);*/

		myScene->triangles = (triangle *)realloc(myScene->triangles, object.polygons_qty*(sizeof(triangle)));
		memset(myScene->triangles, 0, sizeof(triangle));

		myScene->numTriangles = object.polygons_qty;
		for(index = 0; index < object.polygons_qty; index++) {
			/* first vertex */
			myScene->triangles[index].v2.x = object.vertex[object.polygon[index].a].x + 130; /*TODO: check numbers if they control position of object */
			myScene->triangles[index].v2.y = object.vertex[object.polygon[index].a].y + 150;
			myScene->triangles[index].v2.z = object.vertex[object.polygon[index].a].z + 350;
			myScene->triangles[index].v2 = vecMultiply(&myScene->triangles[index].v2, 2);
			/* second vertex */
			myScene->triangles[index].v1.x = object.vertex[object.polygon[index].b].x + 130;
			myScene->triangles[index].v1.y = object.vertex[object.polygon[index].b].y + 150;
			myScene->triangles[index].v1.z = object.vertex[object.polygon[index].b].z + 350;
			myScene->triangles[index].v1 = vecMultiply(&myScene->triangles[index].v1, 2);
			/* third vertex */
			myScene->triangles[index].v3.x = object.vertex[object.polygon[index].c].x + 130;
			myScene->triangles[index].v3.y = object.vertex[object.polygon[index].c].y + 150;
			myScene->triangles[index].v3.z = object.vertex[object.polygon[index].c].z + 350;
			myScene->triangles[index].v3 = vecMultiply(&myScene->triangles[index].v3, 2);

			/* default material */
			myScene->triangles[index].material = 3;

		}
	}

	if(img)
		free(img);
	img = (unsigned char  *)malloc(3*myScene->width * myScene->height);
	memset(img, 0, 3*myScene->width * myScene->height);

	/* calculate section size per thread */
	sectionsize = myScene->height/NUMTHREADS;
	if((sectionsize % 2) != 0)
		printf("Warning: Height/numthreads not even - there will be errors in the image!! \n");

	/* Pthread options */
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	/* Create the render threads */
	for(t = 0; t < NUMTHREADS; t++) {
		tinfo[t].thread_num = t;
		if(pthread_create(&tinfo[t].thread_id, &attr, renderThread, &tinfo[t])) {
			printf("Creation of thread %d failed. \n", t);
			exit(-1);
		}
	}

	if(pthread_attr_destroy(&attr)) {
		printf("Error destroying thread attributes. \n");
	}

	/* wait for render threads to finish */
	for(t = 0; t  < NUMTHREADS; t++) {
		if(pthread_join(tinfo[t].thread_id, NULL)) {
			printf("Error waiting for thread. \n");
		}
	}

	/* Save the image */
	savebmp("out.bmp", img, myScene);

	/* free allocated memory */
	if(img)
		free(img);
	if(myScene->lights)
		free(myScene->lights);
	if(myScene->triangles)
		free(myScene->triangles);
	if(myScene->spheres)
		free(myScene->spheres);
	if(myScene->materials)
		free(myScene->materials);

	/* exit */
	pthread_exit(NULL);

	if(tinfo)
		free(tinfo);

	return 0;
}