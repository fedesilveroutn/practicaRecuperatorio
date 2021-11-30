#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  retorna 1 si hubo error o 0 si se pudieron cargar los datos dentro de la linkedlist
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	//declaro los auxiliares donde se guardaran los datos leidos desde el archivo de texto
	char auxId[51];
	char auxName[128];
	char auxHours[51];
	char auxSalary[51];
	int ret = 1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxHours, auxSalary);//escaneo el encabezado para posicionar el cursor
		while (!feof(pFile))//leo una linea y muevo el cursor, repito hasta que se alcance el final del archivo (cuando feof no devuelva 0)
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxName, auxHours, auxSalary);//escaneo con el formato indicado y guardo en los aux
			Employee* auxEmployee = employee_newParametros(auxId, auxName, auxHours, auxSalary);//invoco al constructor parametrizado y le paso los aux
			ll_add(pArrayListEmployee, auxEmployee);//agrego el auxEmployee a la linkedlist
			if (feof (pFile))//si se alcanza el final del archivo se rompe el bucle
			{
				ret = 0;
				break;
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo dataBinary.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si hubo error o 0 si se pudieron cargar los datos dentro de la linkedlist
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = 1;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while ( feof(pFile) == 0 )
		{
			Employee* auxEmployee = employee_new();
			fread(auxEmployee, sizeof(Employee), 1 , pFile);//leo el binario y guardo los datos en auxEmployee
			if ( feof(pFile) )
			{
				ret = 0;
				break;
			}

			ll_add(pArrayListEmployee, auxEmployee);//agrego auxEmployee a la linkedlist
		}
	}
	return ret;
}
