/*
 * Vector.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeffrey Kaji
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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



double dotV(Vector* v0, Vector* v1) {
	double total = 0;

	for(int i = 0; i < 3; i++)
		total += v0->x[i] * v1->x[i];

	return total;
}

Vector* crossV(Vector* v0, Vector* v1) {
	Vector* v = malloc(sizeof(Vector));

	v->x[0] = v0->x[1] * v1->x[2] - v1->x[1] * v0->x[2];
	v->x[1] = v0->x[2] * v1->x[0] - v1->x[2] * v0->x[0];
	v->x[2] = v0->x[0] * v1->x[1] - v1->x[0] * v0->x[1];

	return v;
}



double getVVal(Vector* v0, int n) {
	return v0->x[n];
}

double getVMag(Vector* v0) {
	double total = 0;

	for(int i = 0; i < 3; i++)
		total += pow(v0->x[i], 2);

	return sqrt(total);
}

Vector* getVUnit(Vector* v0) {
	return divV(v0, getVMag(v0));
}

double getVUnitVal(Vector* v0, int n) {
	return getVVal(getVUnit(v0),n);
}



double getVAngle(Vector* v0, Vector* v1) {
	double cosA = dotV(v0,v1) / getVMag(v0) / getVMag(v1);
	return acos(cosA);
}

double getVAngleDeg(Vector* v0, Vector* v1) {
	return rad2deg(getVAngle(v0,v1));
}



Vector* projV(Vector* target, Vector* v) {
	double scalar = dotV(target, v) / getVMag(target) / getVMag(target);
	return mulV(target, scalar);
}

Vector* projP(Vector* normal, Vector* v) {
	return subV(v, projV(normal, v));
}

void printV(Vector* v) {
	printf("[%f, %f, %f]\n", v->x[0],v->x[1],v->x[2]);
}




double deg2rad(double deg) {
	return deg * M_PI / 180;
}

double rad2deg(double rad) {
	return rad * 180 / M_PI;
}
