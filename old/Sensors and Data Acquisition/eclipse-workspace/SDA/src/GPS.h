/*
 * GPS.h
 *
 *  Created on: Oct 7, 2019
 *      Author: Jeffrey Kaji
 */

#ifndef VECTOR_H_
#include "Vector.h"
#endif

#ifndef GPS_H_
#define GPS_H_

Vector* GPS_getLLA();
unsigned char GPS_getSAT();
unsigned int GPS_getTME();

#endif /* GPS_H_ */
