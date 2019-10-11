/*
 * Matrix.h
 *
 *  Created on: Oct 4, 2019
 *      Author: Jeffrey Kaji
 */
#include "Vector.h"

#ifndef MATRIX_H_
#define MATRIX_H_

typedef struct Matrix { Vector* e[3]; } Matrix;

Matrix* Matrix_new(Vector* e0, Vector* e1, Vector* e2);
Matrix* MatrixRef_new(Vector* e0, Vector* e1);

Matrix* getMUnit(Matrix* m0);

Vector* mulMV(Matrix* m0, Vector* v0);

void printM(Matrix* m);


#endif /* MATRIX_H_ */
