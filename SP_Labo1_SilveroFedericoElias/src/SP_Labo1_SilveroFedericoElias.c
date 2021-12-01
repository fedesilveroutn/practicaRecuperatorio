/*
 ============================================================================
 Name        : SP_Labo1_SilveroFedericoElias.c
 Author      : Federico Elías Silvero
 Version     : 1
 Copyright   : Your copyright notice
 Description : Segundo parcial Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perritos.h"
#include "LinkedList.h"
#include "input.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* pListaPerros = ll_newLinkedList();
	LinkedList* pListaFiltrada = ll_newLinkedList();
	int (*pFunction)(void*);
	int (*pFilterFunction)(void*);

	int opcion;
	int flag = 0;//Para que no muestre basura
	int flagLoad = 0;//Para que no cargue el archivo dos veces

	do
	{
		getInt(&opcion, "\n================================MENU================================\n"
						"\n1. CARGAR DATOS DE ARCHIVO (MODO TEXTO)"
						"\n2. LISTAR PERROS"
						"\n3. CALCULAR RACION"
						"\n4. LISTAR PERROS CON SU RACION"
						"\n5. FILTRAR"
						"\n6. GUARDAR (MODO TEXTO)"
						"\n7. GUARDAR (MODO BINARIO)"
						"\n8. CARGAR DATOS DE ARCHIVO (MODO BINARIO)"
						"\n9. LISTAR PERROS ORDENADOS POR UN CRITERIO ESPECIFICO"
						"\n10.SALIR"
						"\n====================================================================\n"
						"\nIngrese una opcion: ",
						"\n================================MENU================================\n"
						"\n1. CARGAR DATOS DE ARCHIVO (MODO TEXTO)"
						"\n2. LISTAR PERROS"
						"\n3. CALCULAR RACION"
						"\n4. LISTAR PERROS CON SU RACION"
						"\n5. FILTRAR"
						"\n6. GUARDAR (MODO TEXTO)"
						"\n7. GUARDAR (MODO BINARIO)"
						"\n8. CARGAR DATOS DE ARCHIVO (MODO BINARIO)"
						"\n9. LISTAR PERROS ORDENADOS POR UN CRITERIO ESPECIFICO"
						"\n10.SALIR"
						"\n====================================================================\n"
						"\nERROR. Reingrese una opcion valida (1-7): ", 1 , 10);

		switch(opcion)
		{
			case 1:
					if(!flagLoad)
					{
						//PARA LEER Y GUARDAR DINAMICAMENTE EN LINKEDLIST
						perro_load("src\\perritos.csv", pListaPerros);
						printf("\n***ARCHIVO LEIDO EXITOSAMENTE***");
						flag = 1;
						flagLoad = 1;
					}

					else
					{
						printf("\nERROR. EL ARCHIVO YA FUE CARGADO!");
					}


					break;

			case 2:
					if(flag)
					{
						//PARA LISTAR
						printf("\nLISTANDO PERROS, AGUARDE UNOS SEGUNDOS...");
						perro_listar(pListaPerros);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 3:
					if(flag)
					{
						//PARA CALCULAR RACION
						pFunction = perro_laQueMapea;
						ll_map(pListaPerros, pFunction);
						printf("\n***RACION DIARIA CALCULADA EXITOSAMENTE***");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 4:
					if(flag)
					{
						//PARA LISTAR CON RACION
						printf("\nLISTANDO PERROS CON RACION DE COMIDA, AGUARDE UNOS SEGUNDOS...");
						perro_listarConRacion(pListaPerros);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 5:
					if(flag)
					{
						//PARA FILTRAR
						pFilterFunction = perro_laQueFiltra;
						pListaFiltrada = ll_filter(pListaPerros, pFilterFunction);
						printf("\nLISTA FILTRADA...\n");
						perro_listarConRacion(pListaFiltrada);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 6:
					if(flag)
					{
						//PARA GUARDAR EN MODO TEXTO
						perro_guardarTexto("src\\galgosFlaquitos.csv", pListaFiltrada);
						printf("\n***ARCHIVO GUARDADO (MODO TEXTO) EXITOSAMENTE***");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 7:
					if(flag)
					{
						//PARA GUARDAR EN MODO BINARIO
						//perro_guardarBinario("src\\galgosFlaquitosBinarios.csv", pListaFiltrada);
						perro_guardarBinario("src\\perritosOrdenadosPorCriterio.csv", pListaPerros);
						printf("\n***ARCHIVO GUARDADO (MODO BINARIO) EXITOSAMENTE***");
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;

			case 8:
					if(!flagLoad)
					{
						//PARA LEER EN MODO BINARIO Y GUARDAR DINAMICAMENTE EN LINKEDLIST
						//perro_loadFromBinary("src\\galgosFlaquitosBinarios.csv", pListaPerros);
						perro_loadFromBinary("src\\perritosOrdenadosPorCriterio.csv", pListaPerros);
						printf("\n***ARCHIVO LEIDO (MODO BINARIO) EXITOSAMENTE***");
						flag = 1;
						flagLoad = 1;
					}

					else
					{
						printf("\nERROR. EL ARCHIVO YA FUE CARGADO!");
					}
					break;

			case 9:
					if(flag)
					{
						perro_listarConCriterio(pListaPerros);
					}

					else
					{
						printf("\nERROR. ACCESO DENEGADO!");
					}
					break;


			case 10:
					printf("\nSaliendo del programa...");
					break;
		}

		systemPause("\nPresione ENTER para continuar...");

	}while(opcion != 10);


	printf("\nFIN DEL PROGRAMA.");


	return 0;
}







/*
 * CODIGO DE RESPALDO
 *
 *
	//PARA LEER Y GUARDAR DINAMICAMENTE EN LINKEDLIST
	perro_load("src\\perritos.csv", pListaPerros);


	//PARA LISTAR
	printf("\nORDENANDO PERROS...");
	perro_listar(pListaPerros);
	systemPause("\nPresione ENTER para continuar...");


	//PARA CALCULAR RACION
	pFunction = perro_laQueMapea;
	ll_map(pListaPerros, pFunction);


	//PARA LISTAR CON RACION
	printf("\nCALCULANDO RACION DE COMIDA...");
	perro_listarConRacion(pListaPerros);
	systemPause("\nPresione ENTER para continuar...");


	//PARA FILTRAR
	pFilterFunction = perro_laQueFiltra;
	pListaFiltrada = ll_filter(pListaPerros, pFilterFunction);
	perro_listarConRacion(pListaFiltrada);


	//PARA GUARDAR EN MODO TEXTO
	perro_guardarTexto("src\\galgosFlaquitos.csv", pListaFiltrada);*/
