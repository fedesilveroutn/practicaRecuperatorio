
#ifndef PERRITOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define PERRITOS_H_

typedef struct
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];
	float cantidadComidaRacion;

}ePerro;


//CONSTRUCTORES
ePerro* perro_new();
ePerro* perro_newParam(char* id, char* nombre, char* peso, char* edad, char* raza);

//SETTER
int perro_setId (ePerro* this, char* id);
int perro_setNombre(ePerro* this, char* nombre);
int perro_setPeso (ePerro* this, char* peso);
int perro_setEdad (ePerro* this, char* edad);
int perro_setRaza(ePerro* this, char* raza);
int perro_setCantidadComida (ePerro* this, float racion);

//GETTER
int perro_getId(ePerro* this);
float perro_getPeso(ePerro* this);
int perro_getNombre(ePerro* this, char* nombre);
int perro_getEdad(ePerro* this);
int perro_getRaza(ePerro* this, char* raza);
float perro_getRacion(ePerro* this);


//PARSER
int perro_parser(FILE* pFile , LinkedList* pListaPerritos);

//LEER Y GUARDAR EN LINKEDLIST
int perro_load(char* path , LinkedList* pListaPerros);


//LISTAR PERROS
int perro_listar(LinkedList* pListaPerros);


//CALCULAR RACION
int perro_laQueMapea (void* this);


//LISTAR CON RACION
int perro_listarConRacion(LinkedList* pListaPerros);


//FILTRO
int perro_laQueFiltra(void* this);


//GUARDAR TEXTO
int perro_guardarTexto(char* path, LinkedList* pListaPerros);




#endif /* PERRITOS_H_ */
