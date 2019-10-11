/*
 * IMU.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Jeffrey Kaji
 */

#ifndef VECTOR_H_
#include "Vector.h"
#endif

#ifndef IMU_H_
#define IMU_H_

Vector* IMU_getACC();
Vector* IMU_getGYR();
Vector* IMU_getMAG();

#endif /* IMU_H_ */
