/*
 * Matrix.h
 *
 *  Created on: Oct 3, 2019
 *      Author: Jeff
 */

#include "Vector.h"
#include <cstring>

#ifndef MATRIX_H_
#define MATRIX_H_

class Matrix {
private:
    Vector _e[3];
public:
    Matrix(Vector e0, Vector e1);
    Matrix(const Matrix &other);
    Matrix(Matrix &&other);
    Matrix& operator=(const Matrix &other);
    Matrix& operator=(Matrix &&other);
};

#endif /* MATRIX_H_ */
