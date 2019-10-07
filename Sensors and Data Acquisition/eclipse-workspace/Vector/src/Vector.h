/*
 * Vector.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeffrey Kaji
 */

#ifndef VECTOR_H_
#define VECTOR_H_

typedef struct Vector {double x[3];} Vector;

Vector* Vector_new(double x0, double x1, double x2);

Vector* addV(Vector* v0, Vector* v1);
Vector* subV(Vector* v0, Vector* v1);
Vector* mulV(Vector* v0, double d);
Vector* divV(Vector* v0, double d);

double dotV(Vector* v0, Vector* v1);
Vector* crossV(Vector* v0, Vector* v1);

double getVVal(Vector* v0, int n);
double getVMag(Vector* v0);
Vector* getVUnit(Vector* v0);
double getVUnitVal(Vector* v0, int n);

double getVAngle(Vector* v0, Vector* v1);
double getVAngleDeg(Vector* v0, Vector* v1);

Vector* projV(Vector* target, Vector* v);
Vector* projP(Vector* normal, Vector* v);

void printV(Vector* v);


double deg2rad(double deg);
double rad2deg(double rad);


#endif /* VECTOR_H_ */
