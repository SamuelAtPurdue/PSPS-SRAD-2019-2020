/*
 * Vector.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeff
 */
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

Vector* Vector_new(double x0, double x1, double x2) {
	Vector* v = malloc(sizeof(Vector));
	double x[3] = {x0, x1, x2};

	for(int i = 0; i < 3; i++)
		v->x[i] = x[i];

	return v;
}

Vector* addV(Vector* v0, Vector* v1) {
	Vector* v = malloc(sizeof(Vector));

	for(int i = 0; i < 3; i++)
		v->x[i] = v0->x[i] + v1->x[i];

	return v;
}

Vector* subV(Vector* v0, Vector* v1) {
	Vector* v = malloc(sizeof(Vector));

	for(int i = 0; i < 3; i++)
		v->x[i] = v0->x[i] - v1->x[i];

	return v;
}

Vector* mulV(Vector* v0, double d) {
	Vector* v = malloc(sizeof(Vector));

	for(int i = 0; i < 3; i++)
		v->x[i] = v0->x[i] * d;

	return v;
}

Vector* divV(Vector* v0, double d) {
	Vector* v = malloc(sizeof(Vector));

	for(int i = 0; i < 3; i++)
		v->x[i] = v0->x[i] / d;

	return v;
}

void printV(Vector* v) {
	printf("%f, %f, %f\n", v->x[0],v->x[1],v->x[2]);
}
