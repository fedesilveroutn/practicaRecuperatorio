
#ifndef INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define INPUT_H_



int getInt (int* num, char* message, char* errorMessage, int min, int max);
int getFloat (float* num, char* message, char* errorMessage, int min, int max);
int getChar (char* c , char* message, char* errorMessage, char min, char max);
void getString (char* string, char* message, char* errorMessage, int max);
int systemPause(char* message);
int getLastIdFromTxt ();
int saveLastIdToTxt (int lastIdFromMain);


#endif /* INPUT_H_ */
