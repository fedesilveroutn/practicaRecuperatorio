#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "input.h"

int main()
{
	setbuf(stdout, NULL);

    int option = 0;
    int flag = 0;
    int flagCarga = 0;
    int lastIdMain;

    //obtengo el ultimo ID cargado en el archivo de texto
    lastIdMain = getLastIdFromTxt();

    //reservo espacio en memoria para dos linkedlist a traves del constructor
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaEmpleadosClonada;

    printf("\n******************************************************************************************************\n"
    		"\nINSTRUCCIONES:\n"
    		"\n1. PARA PODER OPERAR ES NECESARIO CARGAR EL ARCHIVO DE TEXTO O BINARIO PREVIAMENTE"
    		"\n2. NO SE PUEDEN ABRIR DOS ARCHIVOS SIMULTANEAMENTE. ELIJA CUIDADOSAMENTE O DEBERA VOLVER A EMPEZAR"
    		"\n3. LOS CAMBIOS QUE NO SEAN GUARDADOS SE PERDERAN\n"
    		"\n*****************************************************************************************************\n");


    do{

    	getInt (&option,
				 "\n------------------------------------MENU----------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo dataBinary.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo dataBinary.csv (modo binario)."
				 "\n10.Agregar un empleado en una posicion específica"
				 "\n11.Eliminar un empleado en una posicion específica"
				 "\n12.Verificar si la lista esta vacia"
				 "\n13.Clonar lista"
				 "\n14.Crear una sublista"
				 "\n15.Verificar si la segunda lista contiene todos los elementos de la primera"
				 "\n16.Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Ingrese una opcion (1 - 16): ",
				 "\nERROR!\n"
				 "\n------------------------------------MENU----------------------------------------\n"
				 "\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
				 "\n2. Cargar los datos de los empleados desde el archivo dataBinary.csv (modo binario)."
				 "\n3. Alta de empleado"
				 "\n4. Modificar datos de empleado"
				 "\n5. Baja de empleado"
				 "\n6. Listar empleados"
				 "\n7. Ordenar empleados"
				 "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
				 "\n9. Guardar los datos de los empleados en el archivo dataBinary.csv (modo binario)."
				 "\n10.Agregar un empleado en una posicion específica"
				 "\n11.Eliminar un empleado en una posicion específica"
				 "\n12.Verificar si la lista esta vacia"
				 "\n13.Clonar lista"
				 "\n14.Crear una sublista"
				 "\n15.Verificar si la segunda lista contiene todos los elementos de la primera"
				 "\n16.Salir"
				 "\n-------------------------------------------------------------------------------\n"
				 "Reingrese una opcion valida (1 - 16): ", 1 , 16 );


        switch(option)
        {

        	//leo el archivo de texto, lo parseo y lo copio en mi linkedlist
            case 1:

					if(!flagCarga)
					{
						if (!controller_loadFromText("src\\data.csv", listaEmpleados) )
						{
							printf("\n*****ARCHIVO LEIDO EXITOSAMENTE!*****\n");
							systemPause("Presione enter para continuar...\n");
							flag = 1;
							flagCarga = 1;
						}

						else
						{
							printf("\nERROR. NO SE HA PODIDO LEER EL ARCHIVO!");
							systemPause("\nPresione enter para continuar...\n");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. NO PUEDE CARGAR DOS VECES EL MISMO ARCHIVO NI CARGAR DESDE TEXTO Y DESDE BINARIO A LA VEZ!");
						systemPause("\nPresione enter para continuar...\n");
					}

					break;

			//leo el archivo binario, lo parseo y lo cargo en mi linkedlist
            case 2:
            	if(!flagCarga)
            	{
					if(!controller_loadFromBinary("src\\dataBinary.csv", listaEmpleados) )
					{
						printf("\n*****ARCHIVO LEIDO (MODO BINARIO) EXITOSAMENTE!*****\n");
						flagCarga = 1;
						flag = 1;
						systemPause("\nPresione enter para continuar...\n");
					}

					else
					{
						printf("\nERROR. NO SE HA PODIDO LEER EL ARCHIVO!");
						systemPause("\nPresione enter para continuar...\n");
					}

            	}

            	else
            	{
						printf("\nERROR. ACCESO DENEGADO. NO PUEDE CARGAR DOS VECES EL MISMO ARCHIVO NI CARGAR DESDE TEXTO Y DESDE BINARIO A LA VEZ!");
						systemPause("\nPresione enter para continuar...\n");
            	}

				break;

			//realizo el alta de un empleado
            case 3:
					if (flag)
					{
						if ( controller_addEmployee(listaEmpleados) )
						{
							lastIdMain++;
						}
						systemPause("\nPresione enter para continuar...\n");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

			//realizo la modificacion de un empleado
            case 4:
					if(flag)
					{
						controller_editEmployee(listaEmpleados);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

			//realizo la baja de un empleado
            case 5:
					if(flag)
					{
						if ( controller_removeEmployee(listaEmpleados) )
						{
							printf("\n*****EMPLEADO DADO DE BAJA EXITOSAMENTE!*****");
						}

						else
						{
							printf("\nERROR. NO FUE POSIBLE REALIZAR LA BAJA DEL EMPLEADO!");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

			//listo los empleados cargados en la linkedlist
            case 6:
					if(flag)
					{
						printf("\nListando empleados...\n");
						controller_ListEmployee(listaEmpleados);
						systemPause("\nPresione enter para continuar...\n");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

			//realizo el ordenamiento de la lista de empleados cargados en linkedlist
            case 7:
					if(flag)
					{
						controller_sortEmployee(listaEmpleados);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;


			//guardo los datos de la linkedlist dentro del archivo de texto
            case 8:
					if(flag)
					{
						if ( controller_saveAsText("src\\data.csv", listaEmpleados) )
						{
							saveLastIdToTxt(lastIdMain);
							printf("\n*****DATOS GUARDADOS (MODO TEXTO) EXITOSAMENTE!*****");
							systemPause("\nPresione enter para continuar...\n");
						}

						else
						{
							printf("\nERROR. NO SE HAN PODIDO GUARDAR LOS DATOS EN MODO TEXTO!");
							systemPause("\nPresione enter para continuar...\n");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
					break;

			//guardo los datos de la linkedlist dentro del archivo binario
            case 9:
					if(flag)
					{
						if (controller_saveAsBinary("src\\dataBinary.csv", listaEmpleados) )
						{
							saveLastIdToTxt(lastIdMain);
							printf("\n*****DATOS GUARDADOS (MODO BINARIO) EXITOSAMENTE!*****");
							systemPause("\nPresione enter para continuar...\n");
						}
						else
						{
							printf("\nERROR. NO SE HAN PODIDO GUARDAR LOS DATOS EN MODO BINARIO!");
							systemPause("\nPresione enter para continuar...\n");
						}
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("Presione enter para continuar...\n");
					}
					break;



			//realizo el alta de un empleado en una posicion en especifico
            case 10:
            		if(flag)
					{
            			controller_addEmployeeHere (listaEmpleados, lastIdMain );
					}
            		else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("Presione enter para continuar...\n");
					}

            		break;


            //realizo la baja de un empleado en una posicion en especifico
            case 11:
            		if(flag)
					{
						controller_removeEmployeeHere (listaEmpleados, lastIdMain );
					}
					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS PREVIAMENTE!");
						systemPause("Presione enter para continuar...\n");
					}

            		break;


            //pregunto si la linkedlist esta o no vacia
            case 12:
            		if(flag)
            		{
            			controller_isEmpty(listaEmpleados);
        			}
					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS (MODO TEXTO) PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
            		break;


            //clono la linkedlist y tengo dos identicas
            case 13:
            		if(flag)
            		{
            		listaEmpleadosClonada = ll_clone(listaEmpleados);
            		controller_ListEmployee(listaEmpleadosClonada);
            		systemPause("\nPresione enter para continuar...\n");
            		}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS (MODO TEXTO) PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
            		break;


            //especifico un rango de la linkedlist y con eso genero una sublista
            case 14:
            		if(flag)
            		{
            		controller_createSublist(listaEmpleados);
            		systemPause("\nPresione enter para continuar...\n");
            		}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS (MODO TEXTO) PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
            		break;


            //pregunto si todos los elementos de la segunda lista estan contenidos dentro de la primera
            case 15:
            		if(flag)
            		{
            		controller_checkContainsAll(listaEmpleados, listaEmpleadosClonada);
            		systemPause("\nPresione enter para continuar...\n");
            		}

					else
					{
						printf("\nERROR. ACCESO DENEGADO. DEBE CARGAR LOS DATOS DE LOS EMPLEADOS (MODO TEXTO) PREVIAMENTE!");
						systemPause("\nPresione enter para continuar...\n");
					}
            		break;


            //salgo del programa
            case 16:
            		printf("\nSaliendo del programa...");
            		ll_deleteLinkedList(listaEmpleados);
            		break;
        }

    }while(option != 16);

    printf("\nFIN DEL PROGRAMA.");

    return 0;
}

