/*
 * Matrix.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: Jeff
 */

#include "Vector.h"
#include "Matrix.h"

Matrix::Matrix(Vector e0, Vector e1) {
    _e[0] = e0;
    _e[1] = projP(e0, e1);
    _e[2] = cross(_e[0],_e[1]);

}

Matrix::Matrix(const Matrix &other) {
    memcpy(_e, other._e, sizeof(_e));

}

Matrix::Matrix(Matrix &&other) {
    // TODO Auto-generated constructor stub

}

Matrix& Matrix::operator=(const Matrix &other) {
    // TODO Auto-generated method stub

}

Matrix& Matrix::operator=(Matrix &&other) {
    // TODO Auto-generated method stub

}

