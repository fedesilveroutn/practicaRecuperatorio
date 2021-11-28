
#ifndef employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* salarioStr);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_sortByName (void* pointer1 , void* pointer2);
int employee_sortById (void* pointer1 , void* pointer2);
int employee_sortByHours (void* pointer1 , void* pointer2);
int employee_sortBySalary(void* pointer1 , void* pointer2);

Employee* employee_add (int lastIdFromMain);
int employee_confirmacion(Employee* employee);

#endif // employee_H_INCLUDED
