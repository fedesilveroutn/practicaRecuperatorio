#include "Dog.h"

ePerro* perro_new()
{
	ePerro* new = NULL;
	new = (ePerro*) malloc (sizeof(ePerro));
	return new;
}

ePerro* perro_newParam(int id, char* nombre, char* raza, int edad)
{
	ePerro* new = NULL;
	new = perro_new();

	if(new != NULL)
	{
		perro_setId(new, id);
		perro_setNombre(new, nombre);
		perro_setRaza(new, raza);
		perro_setEdad(new, edad);
	}

	return new;
}

int perro_setId (ePerro* this, int id)
{
	int ret = -1;
	if(this != NULL)
	{
		this->id = id;
		ret = 0;
	}

	return ret;
}

int perro_setNombre(ePerro* this, char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}

	return ret;
}

int perro_setRaza(ePerro* this, char* raza)
{
	int ret = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		ret = 0;
	}

	return ret;
}

int perro_setEdad(ePerro* this, int edad)
{
	int ret = -1;

	if(this != NULL)
	{
		this->edad = edad;
		ret = 0;
	}

	return ret;
}


int perro_getId(ePerro* this)
{
	int id = -1;

	if(this != NULL)
	{
		id = this->id;
	}

	return id;
}

char* perro_getNombre(ePerro* this)
{
	char* nombre = NULL;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
	}

	return nombre;
}


char* perro_getRaza(ePerro* this)
{
	char* raza = NULL;

	if(this != NULL)
	{
		strcpy(raza, this->raza);
	}

	return raza;
}


int perro_getEdad(ePerro* this)
{
	int edad = -1;

	if(this != NULL)
	{
		edad = this->edad;
	}

	return edad;
}



ePerro* perro_add(int ultimoId)
{
	ePerro* nuevoPerro = NULL;
	int id;
	char nombre[31];
	char raza[31];
	int edad;

	id = ultimoId + 1;
	getString(nombre, "\nIngrese el nombre del nuevo perro (hasta 30 caracteres): ", "\nERROR. Reingrese nombre valido (hasta 30 caracteres): ", 30);
	getString(raza, "\nIngrese la raza del nuevo perro (hasta 30 caracteres): ", "\nERROR. Reingrese raza valida (hasta 30 caracteres): ", 30);
	getInt(&edad, "\nIngrese la edad del nuevo perro (1-20):", "\nERROR. Reingrese una edad valida (1-20): ", 1, 20);

	nuevoPerro = perro_newParam(id, nombre, raza, edad);
	return nuevoPerro;
}





