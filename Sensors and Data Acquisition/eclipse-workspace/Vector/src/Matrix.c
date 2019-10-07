/*
 * Matrix.c
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeffrey Kaji
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Vector.h"
#include "Matrix.h"

Matrix* Matrix_new(Vector* e0, Vector* e1, Vector* e2) {
	Matrix* m = malloc(sizeof(Matrix));

	m->e[0] = e0;
	m->e[1] = e1;
	m->e[2] = e2;

	return m;
}


Matrix* MatrixRef_new(Vector* e0, Vector* e1) {
	Matrix* m = malloc(sizeof(Matrix));

	m->e[0] = e0;
	m->e[1] = projP(e0, e1);
	m->e[2] = crossV(m->e[0],m->e[1]);

	return getMUnit(m);
}

Matrix* getMUnit(Matrix* m0) {
	Matrix* m = malloc(sizeof(Matrix));

	for(int i = 0; i < 3; i++)
		m->e[i] = getVUnit(m0->e[i]);

	return m;
}

Vector* mulMV(Matrix* m0, Vector* v0) {
	Vector* v = malloc(sizeof(Vector));

	for(int i = 0; i < 3; i++) {
		v->x[i] = 0;
		for(int j = 0; j < 3; j++)
			v->x[i] += m0->e[j]->x[i] * v0->x[j];
	}

	return v;
}

void printM(Matrix* m) {
	for(int i = 0; i < 3; i++)
	printf("[%f, %f, %f] ", m->e[i]->x[0],m->e[i]->x[1],m->e[i]->x[2]);
	printf("\n");
}
