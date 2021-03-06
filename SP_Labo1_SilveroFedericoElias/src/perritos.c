#include "perritos.h"

/**
 * @brief
 * @return
 */
ePerro* perro_new()
{
	ePerro* new = NULL;
	new = (ePerro*) malloc (sizeof(ePerro));
	return new;
}
/**
 * @brief
 * @param id
 * @param nombre
 * @param peso
 * @param edad
 * @param raza
 * @return
 */
ePerro* perro_newParam(char* id, char* nombre, char* peso, char* edad, char* raza)
{
	ePerro* new;

	new = perro_new();
	if(id != NULL && nombre != NULL && peso != NULL && edad != NULL && raza != NULL && new != NULL)
	{
		perro_setId(new, id);
		perro_setNombre(new, nombre);
		perro_setPeso(new, peso);
		perro_setRaza(new, raza);
		perro_setEdad(new, edad);
	}

	return new;
}
/**
 * @brief
 * @param this
 * @param id
 * @return
 */
int perro_setId (ePerro* this, char* id)
{
	int ret = 1;
	int auxId;
	if(this != NULL && id != NULL)
	{
		auxId = atoi(id);
		this->id = auxId;
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @param nombre
 * @return
 */
int perro_setNombre(ePerro* this, char* nombre)
{
	int ret = 1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @param peso
 * @return
 */
int perro_setPeso (ePerro* this, char* peso)
{
	int ret = 1;
	float auxPeso;
	if(this != NULL && peso != NULL)
	{
		auxPeso = atof(peso);
		this->peso = auxPeso;
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @param edad
 * @return
 */
int perro_setEdad (ePerro* this, char* edad)
{
	int ret = 1;
	int auxEdad;
	if(this != NULL && edad != NULL)
	{
		auxEdad = atoi(edad);
		this->edad = auxEdad;
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @param raza
 * @return
 */
int perro_setRaza(ePerro* this, char* raza)
{
	int ret = 1;
	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @param racion
 * @return
 */
int perro_setCantidadComida (ePerro* this, float racion)
{
	int ret = 1;
	if(this != NULL)
	{
		this->cantidadComidaRacion = racion;
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @return
 */
int perro_getId(ePerro* this)
{
	int id = -1;

	if(this != NULL)
	{
		id = this->id;
	}

	return id;
}
/**
 * @brief
 * @param this
 * @param nombre
 * @return
 */
int perro_getNombre(ePerro* this, char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}

	return ret;
}
/**
 * @brief
 * @param this
 * @return
 */
float perro_getPeso(ePerro* this)
{
	float peso = -1;
	if(this != NULL)
	{
		peso = this->peso;
	}

	return peso;
}
/**
 * @brief
 * @param this
 * @return
 */
int perro_getEdad(ePerro* this)
{
	int edad = -1;
	if(this != NULL)
	{
		edad = this->edad;
	}

	return edad;
}
/**
 * @brief
 * @param this
 * @param raza
 * @return
 */
int perro_getRaza(ePerro* this, char* raza)
{
	int ret = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->raza);
		ret = 0;
	}

	return ret;
}
/**
 * @brief
 * @param this
 * @return
 */
float perro_getRacion(ePerro* this)
{
	float racion = -1;
	if(this != NULL)
	{
		racion = this->cantidadComidaRacion;
	}

	return racion;
}
/**
 * @brief
 * @param pFile
 * @param pListaPerritos
 * @return
 */
int perro_parser(FILE* pFile , LinkedList* pListaPerritos)
{
	char auxId[21];
	char auxNombre[21];
	char auxPeso[21];
	char auxEdad[21];
	char auxRaza[21];

	int ret = 1;

	if (pFile != NULL && pListaPerritos != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza);
		while ( !feof(pFile) )
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza);
			ePerro* auxPerro = perro_newParam(auxId, auxNombre, auxPeso, auxEdad, auxRaza);
			ll_add(pListaPerritos, auxPerro);
		}

		ret = 0;
	}

	return ret;
}
/**
 * @brief
 * @param pFile
 * @param pListaPerritos
 * @return
 */
int perro_parserBinary(FILE* pFile, LinkedList* pListaPerritos)
{
	int ret = 1;


	if(pFile != NULL && pListaPerritos != NULL)
	{
		while( !feof(pFile) )
		{
			ePerro* auxPerro = perro_new();
			fread(auxPerro, sizeof(ePerro), 1 , pFile);
			if( feof (pFile) )
			{
				ret = 0;
				break;
			}

			ll_add(pListaPerritos, auxPerro);
		}
	}

	return ret;
}
/**
 * @brief
 * @param path
 * @param pListaPerros
 * @return
 */
int perro_load(char* path , LinkedList* pListaPerros)
{
	FILE* pFile;
	int ret = 1;

	if( path != NULL && pListaPerros != NULL)
	{
		pFile = fopen (path, "r");
		if(pFile != NULL)
		{
			perro_parser(pFile, pListaPerros);
			ret = 0;
		}
	}

	fclose(pFile);
	return ret;
}
/**
 * @brief
 * @param path
 * @param pListaPerros
 * @return
 */
int perro_loadFromBinary(char* path, LinkedList* pListaPerros)
{
	int ret = 1;
	FILE* pFile;

	if( path != NULL && pListaPerros != NULL)
	{
		pFile = fopen(path, "rb");
		if(pFile != NULL)
		{
			ret = perro_parserBinary(pFile, pListaPerros);
		}
	}

	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortByName(void* pointer1 , void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	char auxName1[21];
	char auxName2[21];
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		perro_getNombre(aux1, auxName1);
		perro_getNombre(aux2, auxName2);
		ret = strcmp(auxName1 , auxName2);
	}
	aux1 = NULL;
	aux2 = NULL;
	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortByRaza(void* pointer1, void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	char auxRaza1[21];
	char auxRaza2[21];
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		perro_getRaza(aux1, auxRaza1);
		perro_getRaza(aux2, auxRaza2);
		ret = strcmp(auxRaza1, auxRaza2);
	}

	aux1 = NULL;
	aux2 = NULL;
	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortById(void* pointer1, void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	int ret = -2;
	int auxId1;
	int auxId2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		auxId1 = perro_getId(aux1);
		auxId2 = perro_getId(aux2);
		if(auxId1 > auxId2)
		{
			ret = 1;
		}
		else if( auxId1 < auxId2)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortByPeso(void* pointer1, void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	float auxPeso1;
	float auxPeso2;
	int ret = -2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		auxPeso1 = perro_getPeso(aux1);
		auxPeso2 = perro_getPeso(aux2);
		if(auxPeso1 > auxPeso2)
		{
			ret = 1;
		}
		else if(auxPeso1 < auxPeso2)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortByEdad(void* pointer1, void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	int ret = -2;
	int auxEdad1;
	int auxEdad2;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		auxEdad1 = perro_getEdad(aux1);
		auxEdad2 = perro_getEdad(aux2);
		if(auxEdad1 > auxEdad2)
		{
			ret = 1;
		}
		else if(auxEdad1 < auxEdad2)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @brief
 * @param pointer1
 * @param pointer2
 * @return
 */
int perro_sortByCantidadComida(void* pointer1, void* pointer2)
{
	ePerro* aux1 = (ePerro*) pointer1;
	ePerro* aux2 = (ePerro*) pointer2;
	float auxRacion1;
	float auxRacion2;
	int ret = -2;


	if(pointer1 != NULL && pointer2 != NULL)
	{
		auxRacion1 = perro_getRacion(aux1);
		auxRacion2 = perro_getRacion(aux2);
		if(auxRacion1 > auxRacion2)
		{
			ret = 1;
		}
		else if(auxRacion1 < auxRacion2)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
		}
	}
	return ret;
}
/**
 * @brief
 * @param pListaPerros
 * @return
 */
int perro_listar(LinkedList* pListaPerros)
{
	ePerro* auxPerro;
	int ret = 1;
	int len;
	int i;

	int auxId;
	int retNombre;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	int retRaza;
	char auxRaza[21];

	int (*pFuncionOrdenarNombre) (void*, void*);
	pFuncionOrdenarNombre = perro_sortByName;
	ll_sort(pListaPerros, pFuncionOrdenarNombre, 1);

	if (pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-10s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);

			auxId = perro_getId(auxPerro);
			retNombre = perro_getNombre(auxPerro, auxNombre);
			auxPeso = perro_getPeso(auxPerro);
			auxEdad = perro_getEdad(auxPerro);
			retRaza = perro_getRaza(auxPerro, auxRaza);

			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-10s", auxId, auxNombre, auxPeso, auxEdad, auxRaza );
			}
		}
		ret = 0;
	}

    return ret;
}
/**
 * @brief
 * @param pListaPerros
 * @return
 */
int perro_listarConRacion(LinkedList* pListaPerros)
{
	ePerro* auxPerro;
	int ret = 1;
	int len;
	int i;

	int auxId;
	int retNombre;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	int retRaza;
	char auxRaza[21];
	float auxRacion;

	int (*pFuncionOrdenarNombre) (void*, void*);
	pFuncionOrdenarNombre = perro_sortByName;
	ll_sort(pListaPerros, pFuncionOrdenarNombre, 1);

	if (pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-20s %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);

			auxId = perro_getId(auxPerro);
			retNombre = perro_getNombre(auxPerro, auxNombre);
			auxPeso = perro_getPeso(auxPerro);
			auxEdad = perro_getEdad(auxPerro);
			retRaza = perro_getRaza(auxPerro, auxRaza);
			auxRacion = perro_getRacion(auxPerro);

			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-20s %-20.2f", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxRacion );
			}
		}
		ret = 0;
	}

    return ret;
}
/**
 * @brief
 * @param pListaPerros
 * @param pFunc
 * @return
 */
int perro_listarConCriterio(LinkedList* pListaPerros)
{
	ePerro* auxPerro;
	int criterio;
	int ret = 1;
	int len;
	int i;

	int auxId;
	int retRaza;
	int auxEdad;
	int retNombre;
	char auxRaza[21];
	char auxNombre[21];
	float auxPeso;
	float auxRacion;

	int (*pFuncionOrdenar) (void*, void*);//puntero a funcion

	getInt(&criterio,	"\n==================CRITERIO DE ORDENAMIENTO==================\n"
						"\n1. SEGUN ID"
						"\n2. SEGUN NOMBRE"
						"\n3. SEGUN PESO"
						"\n4. SEGUN EDAD"
						"\n5. SEGUN RAZA"
						"\n6. SEGUN CANTIDAD DE COMIDA"
						"\n============================================================\n"
						"\nIngrese un criterio de ordenamiento: ",
						"\n==================CRITERIO DE ORDENAMIENTO==================\n"
						"\n1. SEGUN ID"
						"\n2. SEGUN NOMBRE"
						"\n3. SEGUN PESO"
						"\n4. SEGUN EDAD"
						"\n5. SEGUN RAZA"
						"\n6. SEGUN CANTIDAD DE COMIDA"
						"\n============================================================\n"
						"\nERROR. Reingrese un criterio de ordenamiento valido (1-6): ", 1 , 6);

	printf("\nLISTANDO PERROS SEGUN UN CRITERIO ESPECIFICO, AGUARDE UNOS SEGUNDOS...\n\n");
	switch(criterio)
	{
		case 1:
				pFuncionOrdenar = perro_sortById;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
		case 2:
				pFuncionOrdenar = perro_sortByName;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
		case 3:
				pFuncionOrdenar = perro_sortByPeso;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
		case 4:
				pFuncionOrdenar = perro_sortByEdad;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
		case 5:
				pFuncionOrdenar = perro_sortByRaza;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
		case 6:
				pFuncionOrdenar = perro_sortByCantidadComida;
				ll_sort(pListaPerros, pFuncionOrdenar, 1);
				break;
	}

	if(pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-20s %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);
			auxId = perro_getId(auxPerro);
			retNombre = perro_getNombre(auxPerro, auxNombre);
			auxPeso = perro_getPeso(auxPerro);
			auxEdad = perro_getEdad(auxPerro);
			retRaza = perro_getRaza(auxPerro, auxRaza);
			auxRacion = perro_getRacion(auxPerro);
			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-20s %-20.2f", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxRacion );
			}
		}
		ret = 0;
	}
	return ret;
}
/**
 * @brief
 * @param this
 * @return
 */
int perro_laQueMapea (void* this)
{
	int ret = 1;
	float cantidad;
	ePerro* auxPerro;

	auxPerro = this;

	if(this != NULL)
	{
		cantidad = auxPerro->peso * 23;
		perro_setCantidadComida(this, cantidad);
		ret = 0;
	}

	return ret;
}
/**
 * @brief
 * @param this
 * @return
 */
int perro_laQueFiltra(void* this)
{
	ePerro* auxPerro;
	int ret = -1;

	char auxRaza[21];
	int auxEdad;
	float auxCantidadComida;

	if(this != NULL)
	{
		auxPerro = (ePerro*) this;

		perro_getRaza(auxPerro, auxRaza);
		auxEdad = perro_getEdad(auxPerro);
		auxCantidadComida = perro_getRacion(auxPerro);

		if(strcmp(auxRaza , "Galgo") == 0  && auxEdad > 10 && auxCantidadComida < 200 )
		{
			ret = 0;
		}
	}

	return ret;
}
/**
 * @brief
 * @param path
 * @param pListaPerros
 * @return
 */
int perro_guardarTexto(char* path, LinkedList* pListaPerros)
{
	FILE* pFile;
	int ret = 1;
	int len;

	int auxId;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	char auxRaza[21];
	float auxCantidadComidaRacion;



	if( path != NULL && pListaPerros != NULL)
	{
		pFile = fopen(path, "w");
		len = ll_len(pListaPerros);
		if(pFile != NULL)
		{
			fprintf(pFile,"%s\n", "id,nombre,peso,edad,raza,racion");

			for(int i = 0; i < len ; i++)
			{
				ePerro* auxPerro = ll_get(pListaPerros, i);
				auxId = perro_getId(auxPerro);
				perro_getNombre(auxPerro, auxNombre);
				auxPeso = perro_getPeso(auxPerro);
				auxEdad = perro_getEdad(auxPerro);
				perro_getRaza(auxPerro, auxRaza);
				auxCantidadComidaRacion = perro_getRacion(auxPerro);

				fprintf(pFile, "%d,", auxId);
				fprintf(pFile, "%s,", auxNombre);
				fprintf(pFile, "%f,", auxPeso);
				fprintf(pFile, "%d,", auxEdad);
				fprintf(pFile, "%s,", auxRaza);
				fprintf(pFile, "%f\n", auxCantidadComidaRacion);
			}

			ret = 0;
		}

		fclose(pFile);
		pFile = NULL;
	}

	return ret;
}
/**
 * @brief
 * @param path
 * @param pListaPerritos
 * @return
 */
int perro_guardarBinario(char* path, LinkedList* pListaPerritos)
{
	int ret = 1;
	int len;
	int i;

	FILE* pFile;

	if( path != NULL && pListaPerritos != NULL)
	{
		len = ll_len(pListaPerritos);
		pFile = fopen(path, "wb");
		if(pFile != NULL)
		{
			for( i = 0; i < len; i++)
			{
				ePerro* auxPerro = ll_get(pListaPerritos, i);
				fwrite(auxPerro, sizeof(ePerro), 1 , pFile);
			}
		}

		fclose(pFile);
		ret = 0;
	}

	return ret;
}
