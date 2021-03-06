#include "Employee.h"



/**
 * @brief reserva un lugar en la memoria del heap para una estructura del tipo Employee
 * @return retorna un empleado
 */
Employee* employee_new()
{
	Employee* employee = NULL;
	employee = (Employee*) malloc (sizeof (Employee) );
	return employee;
}

/**
 * @brief reserva espacio en memoria dentro del heap para una estructura Employee y ademas carga los campos ID, NOMBRE y HORAS
 *
 * @param idStr char*
 * @param nombreStr char*
 * @param horasTrabajadasStr char*
 * @return retorna un empleado con sus campos cargados
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr)
{
	Employee* employee = NULL;
	employee = employee_new();
	int auxId;
	int auxHoras;
	int auxSalario;

	if (employee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && salarioStr != NULL)
	{
		auxId = atoi (idStr);
		auxHoras = atoi (horasTrabajadasStr);
		auxSalario = atoi (salarioStr);

		employee_setId(employee, auxId);
		employee_setNombre(employee, nombreStr);
		employee_setHorasTrabajadas(employee, auxHoras);
		employee_setSueldo(employee, auxSalario);
	}
	return employee;
}

/**
 * @brief asigna el ID recibido, al campo ID del puntero a una estructura Employee
 *
 * @param this Employee*
 * @param id int
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_setId(Employee* this,int id)
{
	int ret = -1;
	if (this != NULL)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}

/**
 * @brief guarda el ID del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 *
 * @param this Employee*
 * @param id int*
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_getId(Employee* this,int* id)
{
	int ret = -1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}

/**
 * @brief asigna el NOMBRE recibido, al campo nombre de la estructura Employeee
 *
 * @param this Employee*
 * @param nombre char*
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int ret = -1;
	if (this != NULL)
	{
		strcpy ( this->nombre , nombre );
		ret = 0;
	}
	return ret;
}

/**
 * @brief guarda el NOMBRE del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 *
 * @param this Employee*
 * @param nombre char*
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int ret = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy (nombre , this->nombre);
		ret = 0;
	}
	return ret;
}

/**
 * @brief asigna las HORAS TRABAJADAS recibidas, al campo horasTrabajadas de la estructura Employeee
 * @param this Employee*
 * @param horasTrabajadas int
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ret = -1;
	if (this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		ret = 0;
	}
	return ret;
}

/**
 * @brief guarda las HORAS TRABAJADAS del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 * @param this Employee*
 * @param horasTrabajadas int*
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret = -1;
	if (this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		ret = 0;
	}
	return ret;
}

/**
 * @brief asigna el SUELDO recibido, al campo sueldo de la estructura Employeee
 * @param this Employee*
 * @param sueldo int
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int ret = -1;
	if(this != NULL)
	{
		this->sueldo = sueldo;
		ret = 0;
	}
	return ret;
}

/**
 * @brief guarda el SUELDO del campo de la estructura Employee, en el puntero que se pasa como segundo parámetro
 * @param this Employee*
 * @param sueldo int*
 * @return retorna -1 si hubo error o 0 si funciono correctamente
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret = -1;
	if(this != NULL)
	{
		*sueldo = this->sueldo;
		ret = 0;
	}
	return ret;
}

/**
 * @brief compara los ids de dos empleados
 *
 * @param pointer1 void*
 * @param pointer2 void*
 * @return retorna -1 si el primer id es menor que el segundo, o 1 si si mayor o -2 si son iguales
 */
int employee_sortById (void* pointer1 , void* pointer2)
{
	Employee* aux1 = (Employee*) pointer1;
	Employee* aux2 = (Employee*) pointer2;
	int auxId1;
	int auxId2;
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getId(aux1, &auxId1);
		employee_getId(aux2, &auxId2);

		if (auxId1 < auxId2)
		{
			ret = -1;
		}

		else if (auxId1 > auxId2)
		{
			ret = 1;
		}

		else if (auxId1 == auxId2)
		{
			ret = -2;
		}
	}
	return ret;
}

/**
 * @brief compara los nombres de dos empleados
 *
 * @param pointer1 void*
 * @param pointer2 void*
 * @return retorna el resultado de la comparacion entre dos cadenas de caracteres
 */
int employee_sortByName (void* pointer1 , void* pointer2)
{
	Employee* aux1 = (Employee*) pointer1;
	Employee* aux2 = (Employee*) pointer2;
	char auxName1[128];
	char auxName2[128];
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getNombre(aux1, auxName1);
		employee_getNombre(aux2, auxName2);
		ret = strcmp(auxName1 , auxName2);
	}
	aux1 = NULL;
	aux2 = NULL;
	return ret;
}

/**
 * @brief compara la cantidad de horas trabajas de dos empleados
 *
 * @param pointer1 void*
 * @param pointer2 void*
 * @return retorna -1 si la cantidad de horas del primer empleado es menor, o 1 si es mayor o -2 si son iguales
 */
int employee_sortByHours (void* pointer1 , void* pointer2)
{
	Employee* aux1 = (Employee*) pointer1;
	Employee* aux2 = (Employee*) pointer2;
	int auxHours1;
	int auxHours2;
	int ret;

	if (pointer1 != NULL && pointer2 != NULL)
	{
		employee_getHorasTrabajadas(aux1, &auxHours1);
		employee_getHorasTrabajadas(aux2, &auxHours2);

		if (auxHours1 < auxHours2)
		{
			ret = -1;
		}

		else if (auxHours1 > auxHours2)
		{
			ret = 1;
		}

		else if (auxHours1 == auxHours2)
		{
			ret = -2;
		}
	}

	return ret;
}

/**
 * @brief compara el salario de dos empleados
 *
 * @param pointer1 void*
 * @param pointer2 void*
 * @return  retorna -1 si el salario del primer empleado es menor, o 1 si es mayor, o -2 si son iguales
 */
int employee_sortBySalary(void* pointer1 , void* pointer2)
{
	Employee* aux1 = (Employee*)pointer1;
	Employee* aux2 = (Employee*)pointer2;
	int auxSalary1;
	int auxSalary2;
	int ret;

	if(pointer1 != NULL && pointer2 != NULL)
	{
		employee_getSueldo(aux1, &auxSalary1);
		employee_getSueldo(aux2, &auxSalary2);

		if (auxSalary1 < auxSalary2)
		{
			ret = -1;
		}

		else if (auxSalary1 > auxSalary2)
		{
			ret = 1;
		}

		else if (auxSalary1 == auxSalary2)
		{
			ret = -2;
		}
	}
	return ret;
}

/**
 * @brief aniade un empleado
 *
 * @param lastIdFromMain int
 * @return retorna NULL si hubo error o un empleado cargado si funciono correctamente
 */
Employee* employee_add (int lastIdFromMain)
{
	Employee* newEmployee = NULL;
	int auxNewId = 0;
	int auxNewHours = 0;
	int auxNewSalary = 0;
	char newId [21];
	char newName[128];
	char newHours[21];
	char newSalary[21];

	auxNewId = lastIdFromMain + 1;
	getString(newName, "\nIngrese el NOMBRE del nuevo empleado: ", "ERROR. Reingrese un NOMBRE valido (hasta 127 caracteres): ", 127);
	getInt(&auxNewHours,"Ingrese las HORAS TRABAJADAS del nuevo empleado: ","ERROR. Reingrese cantidad de HORAS TRABAJADAS valida (hasta 1000): ",0 ,1000);
	getInt(&auxNewSalary, "Ingrese el SALARIO del nuevo empleado: ", "ERROR. Reingrese un SALARIO valido (1000-1000000): ", 1000 , 1000000);

	itoa(auxNewId, newId , 10);
	itoa(auxNewHours, newHours, 10);
	itoa(auxNewSalary, newSalary, 10);

	newEmployee = employee_newParametros( newId, newName, newHours, newSalary);
	return newEmployee;
}

/**
 * @brief muestra un empleado y pide al usuario que confirme los datos ingresados
 *
 * @param employee Employee*
 * @return retorna la respuesta del usuario (1 = SI / 0 = NO)
 */
int employee_confirmacion(Employee* employee)
{
	int id;
	char name[128];
	int hours;
	int salary;
	int ret;

	printf("\nDatos del empleado a ser cargado:"
		   "\n---------------------------------------------------------\n"
		   "%-5s %-20s %-20s %-20s\n", "ID" ,"NOMBRE" ,"HORAS TRABAJADAS" ,"SUELDO");

	employee_getId(employee, &id);
	employee_getNombre(employee, name);
	employee_getHorasTrabajadas(employee, &hours);
	employee_getSueldo(employee, &salary);

	printf("%-5d %-20s %-20d %-20d\n", id , name, hours, salary  );
	getInt (&ret, "\nDesea confirmar la carga del nuevo empleado? (1 = SI / 0 = NO): ", "\nERROR. Reingrese una opcion valida (1 = SI / 0 = NO): ", 0 , 1);

	return ret;
}

/**
 * @brief elimina un empleado
 *
 * @param this Employee*
 */
void employee_delete(Employee* this)
{
	free(this);
	this = NULL;
}








