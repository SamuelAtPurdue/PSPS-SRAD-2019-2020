/*
 ============================================================================
 Name        : main.c
 Author      : Jeffrey Kaji
 Version     :
 Copyright   : Intended for use by Purdue Space Program Solids
 Description : Main file for debug
 //TODO free memory
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "SDA_INCLUDE.h"

int main(void) {

	setup();


	Vector* v0 = Vector_new(0,0,0);
	Vector* v1 = Vector_new(3,4,5);
	Vector* v2 = Vector_new(5,3,2);
	Matrix* m0 = MatrixRef_new(v1,v2);
	Vector* v3 = Vector_new(-3,2,9);

	Vector* v4 = mulMV(m0,v3);




	printV(v1);

	return EXIT_SUCCESS;
}
