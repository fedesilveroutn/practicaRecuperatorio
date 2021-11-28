
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int lastIdFromMain); //al prototipo se le añadio "int lastIdFromMain" para poder mostrar los datos correctamente al confirmar el alta de un empleado
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployeeHere (LinkedList* pArrayListEmployee, int lastIdFromMain );
int controller_removeEmployeeHere (LinkedList* pArrayListEmployee, int lastIdFromMain );
int controller_isEmpty(LinkedList* pArrayListEmployee);
int controller_createSublist(LinkedList* pArrayListEmployee);
int controller_checkContainsAll(LinkedList* pArrayListEmployee1, LinkedList* pArrayListEmployee2);


