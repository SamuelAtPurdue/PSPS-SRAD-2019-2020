/*
 * Vector.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeff
 */

#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Vector {double x[3];} Vector;

Vector* Vector_new(double x0, double x1, double x2);

Vector* addV(Vector* v0, Vector* v1);
Vector* subV(Vector* v0, Vector* v1);
Vector* mulV(Vector* v0, double d);
Vector* divV(Vector* v0, double d);

void printV(Vector* v);

#endif /* VECTOR_H_ */
