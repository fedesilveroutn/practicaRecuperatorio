#ifndef DOG_H_
#define DOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"


typedef struct
{
	int id;
	char nombre [31];
	char raza [31];
	int edad;

} ePerro;

//CONSTRUCTORES
ePerro* perro_new();
ePerro* perro_newParam(int id, char* nombre, char* raza, int edad);

//SETTER
int perro_setId (ePerro* this, int id);
int perro_setNombre(ePerro* this, char* nombre);
int perro_setRaza(ePerro* this, char* raza);
int perro_setEdad(ePerro* this, int edad);

//GETTER
int perro_getId(ePerro* this);
char* perro_getNombre(ePerro* this);
char* perro_getRaza(ePerro* this);
int perro_getEdad(ePerro* this);




#endif /* DOG_H_ */
