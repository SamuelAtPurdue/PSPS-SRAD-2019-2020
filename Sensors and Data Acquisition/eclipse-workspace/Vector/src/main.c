/*
 ============================================================================
 Name        : main.c
 Author      : Jeffrey Kaji
 Version     :
 Copyright   : Intended for use by Purdue Space Program Solids
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int main(void) {

	Vector *v0 = Vector_new(1,2,3);
	Vector *v1 = Vector_new(4,5,6);
	Vector *v2 = addV(v0,v1);
	Vector *v3 = subV(v0,v1);

	Vector *v4 = mulV(v3, -1);
	Vector *v5 = divV(v3, 3);

	printV(v0);
	printV(v1);
	printV(v2);
	printV(v3);
	printf("\n");
	printV(v4);
	printV(v5);

	return EXIT_SUCCESS;
}
