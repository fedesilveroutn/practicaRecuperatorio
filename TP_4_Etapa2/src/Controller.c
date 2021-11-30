
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si hubo error o 0 si es que la funcion parser funciono
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path , "r");
		if(pFile != NULL)
		{
			ret = parser_EmployeeFromText(pFile , pArrayListEmployee);
		}
		fclose(pFile);
	}

	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 1 si hubo error o 0 si es que la funcion parser binario funciono
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 1;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen(path , "rb");
		if(pFile != NULL)
		{
			ret = parser_EmployeeFromBinary(pFile , pArrayListEmployee);
		}
		fclose(pFile);
	}

	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	int ret = 0;
	int lastId = getLastIdFromTxt();

	if(pArrayListEmployee != NULL)
	{
		auxEmployee = employee_add(lastId);

		if ( employee_confirmacion(auxEmployee) )
		{
			ll_add(pArrayListEmployee, auxEmployee);
			printf("\n*****EMPLEADO CARGADO EXITOSAMENTE*****");
			ret = 1;
		}

		else
		{
			printf("\nHa cancelado la carga!");
		}
	}

    return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret = 0;
	int option;
	int i;

	int len;
	int auxId;
	int idFromEmployee;
	char auxName[128];
	int auxHours;
	int auxSalary;
	Employee* auxEmployee = NULL;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese el ID correspondiente al empleado que desea modificar: ");
		fflush(stdin);
		scanf("%d", &auxId);
		for (i = 0; i < len; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idFromEmployee);
			if (auxId == idFromEmployee)
			{
				getInt(&option, "\n------------------------------------------------------------\n"
								"\n1. Modificar nombre"
								"\n2. Modificar horas trabajadas"
								"\n3. Modificar sueldo"
								"\n------------------------------------------------------------\n"
								"\nIngrese la opcion a modificar (1-3): ",
								 "\n------------------------------------------------------------\n"
								"\n1. Modificar nombre"
								"\n2. Modificar horas trabajadas"
								"\n3. Modificar sueldo"
								"\n------------------------------------------------------------\n"
								"\nERROR. Reingrese una opcion valida (1-3): ", 1 , 3 );
				switch (option)
				{
					case 1:
							getString(auxName, "\nIngrese el nuevo nombre: ", "\nERROR. Reingrese un nombre valido (hasta 127 caracteres): ", 127);
							employee_setNombre(auxEmployee, auxName);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;

					case 2:
							getInt(&auxHours, "\nIngrese la nueva cantidad de horas: ", "\nERROR. Reingrese cantidad valida (hasta 10000): ", 0 , 10000);
							employee_setHorasTrabajadas(auxEmployee, auxHours);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;

					case 3:
							getInt(&auxSalary, "\nIngrese el nuevo salario: ", "\nERROR. Reingrese un monto valido (1000-1000000): ", 1000 , 1000000);
							employee_setSueldo(auxEmployee, auxSalary);
							ll_set(pArrayListEmployee, i, auxEmployee);
							break;
				}

				ret = 1;
			}
		}
	}

    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	int idFromEmployee;
	int auxId;
	int len;
	int i;
	int ret = 0;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		controller_ListEmployee(pArrayListEmployee);
		printf("\nIngrese el ID correspondiente al empleado que desea dar de baja: ");
		fflush(stdin);
		scanf("%d", &auxId);

		for (i = 0; i < len; i++)
		{
			auxEmployee = ll_get(pArrayListEmployee, i);
			employee_getId(auxEmployee, &idFromEmployee);
			if (auxId == idFromEmployee)
			{
				ll_remove(pArrayListEmployee, i);
				employee_delete(auxEmployee);
			}
		}
		ret = 1;
	}

    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = 0;
	int len;
	int i;

	Employee* auxEmployee;
	int auxId;
	char auxNombre[21];
	int auxHorasTrabajadas;
	int auxSueldo;

	if (pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);

		printf("\n%-5s %-14s %-9s %-10s\n", "ID", "NOMBRE", "HORAS", "SALARIO");
		for (i = 0; i < len; i++ )
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

			employee_getId(auxEmployee, &auxId);
			employee_getNombre(auxEmployee, auxNombre);
			employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas);
			employee_getSueldo(auxEmployee, &auxSueldo);

			printf("\n%-5d %-14s %-9d %-10d", auxId, auxNombre, auxHorasTrabajadas, auxSueldo );
		}

		ret = 1;
	}

    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret = 0;
	int option;
	int order;
	int (*pFunctionSortById) (void* , void*);
	int (*pFunctionSortByName) (void* , void*);
	int (*pFunctionSortByHours) (void* , void*);
	int (*pFunctionSortBySalary) (void* , void*);

	pFunctionSortById = employee_sortById;
	pFunctionSortByName = employee_sortByName;
	pFunctionSortByHours = employee_sortByHours;
	pFunctionSortBySalary = employee_sortBySalary;

	getInt(&order, "De que manera desea ordenar la lista? (1 = CRECIENTE / 0 = DECRECIENTE): ",
				   "\nERROR. INGRESAR UN NUMERO VALIDO (1 = CRECIENTE / 0 = DECRECIENTE): ", 0 , 1);

	getInt(&option , "\n------------------------SUBMENU-------------------------\n"
					 "\n1. Ordenar segun el ID"
					 "\n2. Ordenar segun el NOMBRE"
					 "\n3. Ordenar segun las HORAS TRABAJADAS"
					 "\n4. Ordenar segun el SUELDO"
					 "\n--------------------------------------------------------\n"
					 "\nIngrese una opcion (1-4): ",
					 "\nERROR!\n"
					 "\n------------------------SUBMENU-------------------------\n"
					 "\n1. Ordenar segun el ID"
					 "\n2. Ordenar segun el NOMBRE"
					 "\n3. Ordenar segun las HORAS TRABAJADAS"
					 "\n4. Ordenar segun el SUELDO"
					 "\n--------------------------------------------------------\n"
					 "\nReingrese una opcion valida (1-4): ", 1 , 4	);
	switch (option)
	{
		case 1:
				printf("\nOrdenando segun el ID. Puede tomar tiempo, aguarde...");
				ll_sort(pArrayListEmployee, pFunctionSortById, order);
				printf("\n*****LISTA ORDENADA SEGUN ID EXITOSAMENTE*****");
				break;

		case 2:
			printf("\nOrdenando segun el NOMBRE. Puede tomar tiempo, aguarde...");
				ll_sort(pArrayListEmployee, pFunctionSortByName, order);
				printf("\n*****LISTA ORDENADA SEGUN NOMBRE EXITOSAMENTE*****");
				break;

		case 3:
				printf("\nOrdenando segun las HORAS TRABAJADAS. Puede tomar tiempo, aguarde...");
				printf("\n*****LISTA ORDENADA SEGUND HORAS TRABAJADAS EXITOSAMENTE*****");
				ll_sort(pArrayListEmployee, pFunctionSortByHours, order);
				break;

		case 4:
				printf("\nOrdenando segun el SUELDO. Puede tomar tiempo, aguarde...");
				printf("\n*****LISTA ORDENADA SEGUND SUELDO EXITOSAMENTE*****");
				ll_sort(pArrayListEmployee , pFunctionSortBySalary , order);
				break;
	}

	ret =  1;
	systemPause("\nPresione enter para continuar...\n");
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret = 0;
	int len;
	int i;

	int auxId;
	char auxName[128];
	int auxHours;
	int auxSalary;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "w");
		len = ll_len(pArrayListEmployee);
		if (pFile != NULL)
		{
			fprintf(pFile,"%s\n", "id,nombre,horasTrabajadas,sueldo");
			for(i = 0; i < len; i++)
			{
				Employee* auxEmployee = (Employee*) ll_get (pArrayListEmployee , i );
				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxName);
				employee_getHorasTrabajadas(auxEmployee, &auxHours);
				employee_getSueldo(auxEmployee, &auxSalary);

				fprintf(pFile, "%d,", auxId);
				fprintf(pFile, "%s," , auxName);
				fprintf(pFile, "%d," , auxHours);
				fprintf(pFile, "%d\n" , auxSalary);
			}

			ret = 1;
		}
		fclose (pFile);
		pFile = NULL;
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si hubo error o 1 si el alta fue exitosa
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee = NULL;
	FILE* pFile;
	int ret = 0;
	int len;
	int i;

	int auxId;
	char auxName[128];
	int auxHours;
	int auxSalary;

	if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = fopen (path, "wb");
		len = ll_len(pArrayListEmployee);
		if (pFile != NULL)
		{
			fwrite(auxEmployee, sizeof(Employee), 1 , pFile );

			for(i = 0; i < len; i++)
			{
				auxEmployee = (Employee*) ll_get (pArrayListEmployee , i );

				employee_getId(auxEmployee, &auxId);
				employee_getNombre(auxEmployee, auxName);
				employee_getHorasTrabajadas(auxEmployee, &auxHours);
				employee_getSueldo(auxEmployee, &auxSalary);
				fwrite(auxEmployee, sizeof(Employee), 1 , pFile );
			}

			ret = 1;
		}
		fclose (pFile);
		pFile = NULL;
	}
	return ret;
}

/**
 * @brief aniade un empleado en una posicion especifica
 *
 * @param pArrayListEmployee
 * @param lastIdFromMain
 * @return -1 si hubo error o 0 si funciono
 */
int controller_addEmployeeHere (LinkedList* pArrayListEmployee, int lastIdFromMain )
{
	Employee* auxEmployee;
	int ret = -1;
	int i;

	if ( pArrayListEmployee != NULL )
	{
		getInt(&i, "\nIngrese la posicion en la cual desea agregar el empleado: " , "\nERROR. Reingrese una posicion correcta (1-1000): ", 1 , 1000);
		auxEmployee = employee_add(lastIdFromMain);
		if(employee_confirmacion(auxEmployee))
		{
			ll_push(pArrayListEmployee, i, auxEmployee);
			ret = 0;
			printf("\n*****EMPLEADO CARGADO EN LA POSICION %d EXITOSAMENTE*****", i);
		}
	}

	return ret;
}

/**
 * @brief remueve un empleado en una posicion especifica
 *
 * @param pArrayListEmployee
 * @param lastIdFromMain
 * @return -1 si hubo error o 0 si funciono correctamente
 */
int controller_removeEmployeeHere (LinkedList* pArrayListEmployee, int lastIdFromMain )
{
	int ret = -1;
	int i;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		getInt(&i, "\nIngrese la posicion perteneciente al empleado a eliminar: " , "\nERROR. Reingrese una posicion correcta (1-1000): ", 1 , 1000);
		ll_pop(pArrayListEmployee, i);
		ret = 0;
		printf("\n*****EMPLEADO ELIMINADO EN LA POSICION %d EXITOSAMENTE*****", i);
	}
	return ret;
}

/**
 * @brief verifica si una lista esta o no vacia
 *
 * @param pArrayListEmployee
 * @return -1 si hubo error o 0 si funciono correctamente
 */
int controller_isEmpty(LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int asw;
	if ( pArrayListEmployee != NULL )
	{
		asw = ll_isEmpty(pArrayListEmployee);
		if(asw)
		{
			printf("\nLA LISTA NO CONTIENE ELEMENTOS!");
		}
		else
		{
			printf("\nLA LISTA SI CONTIENE ELEMENTOS!");
		}

		ret = 0;
	}

	return ret;
}

/**
 * @brief crea una sublista con el rango especificado de los elementos de otra
 *
 * @param pArrayListEmployee
 * @return -1 si hubo error o 0 si funciono correctamente
 */
int controller_createSublist(LinkedList* pArrayListEmployee)
{
	LinkedList* sublist = NULL;
	int ret = -1;
	int min;
	int max;
	if( pArrayListEmployee)
	{
		getInt(&min, "\nIngrese desde que elemento quiere empezar a copiar: ", "\nERROR. Reingrese un numero valido (mayor a 0 y menor a 1000): ", 1, 1000);
		getInt(&max, "\nIngrese hasta que elemento quiere copiar: ", "\nERROR. Reingrese un numero valido (mayor a 0 y menor a 1000): ", 1, 1000);
		sublist = ll_subList(pArrayListEmployee, min, max);
		ret = 0;
		controller_ListEmployee(sublist);
	}

	return ret;
}

/**
 * @brief verifica si la primera lista contiene o no todos los elementos de la segunda
 *
 * @param pArrayListEmployee1
 * @param pArrayListEmployee2
 * @return -1 si hubo error o 0 si funciono correctamente
 */
int controller_checkContainsAll(LinkedList* pArrayListEmployee1, LinkedList* pArrayListEmployee2)
{
	int ret = -1;
	int asw;

	if (pArrayListEmployee1 != NULL && pArrayListEmployee2)
	{
		asw = ll_containsAll(pArrayListEmployee1, pArrayListEmployee2);
		if (asw)
		{
			printf("\nLa lista 1 contiene todos los elementos de la lista 2!");
		}
		else
		{
			printf("\nLa lista 1 NO contiene los elementos de la lista 2!");
		}

	}

	return ret;
}
