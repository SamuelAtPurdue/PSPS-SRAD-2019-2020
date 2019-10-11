/*
 ============================================================================
 Name        : main.c
 Author      : Bahaa Elshimy, Jeffrey Kaji, Matthew Wilson
 Version     :
 Copyright   : Intended for use by Purdue Space Program Solids
 Description : Main file for debug
 //TODO free memory
 ============================================================================
 */

#include "Bahaa.h"
#include "Jeff.h"
#include "Matt.h"

int main(void) {
	int exit_status;

	exit_status = JeffMain();
	//exit_status = BahaaMain();
	//exit_status = MattMain();

	return exit_status;
}
