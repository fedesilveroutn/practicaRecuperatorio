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
						"\n10.SALIR"
						"\n====================================================================\n"
						"\nERROR. Reingrese una opcion valida (1-7): ", 1 , 10);

		switch(opcion)
		{
			case 1:
					//PARA LEER Y GUARDAR DINAMICAMENTE EN LINKEDLIST
					perro_load("src\\perritos.csv", pListaPerros);
					break;

			case 2:
					//PARA LISTAR
					printf("\nORDENANDO PERROS...");
					perro_listar(pListaPerros);
					break;

			case 3:
					//PARA CALCULAR RACION
					pFunction = perro_laQueMapea;
					ll_map(pListaPerros, pFunction);
					break;

			case 4:
					//PARA LISTAR CON RACION
					printf("\nCALCULANDO RACION DE COMIDA...");
					perro_listarConRacion(pListaPerros);
					break;

			case 5:
					//PARA FILTRAR
					pFilterFunction = perro_laQueFiltra;
					pListaFiltrada = ll_filter(pListaPerros, pFilterFunction);
					perro_listarConRacion(pListaFiltrada);
					break;

			case 6:
					//PARA GUARDAR EN MODO TEXTO
					perro_guardarTexto("src\\galgosFlaquitos.csv", pListaFiltrada);
					break;

			case 7:
					//PARA GUARDAR EN MODO BINARIO
					perro_guardarBinario("src\\galgosFlaquitosBinarios.csv", pListaFiltrada);
					break;

			case 8:
					//PARA LEER EN MODO BINARIO Y GUARDAR DINAMICAMENTE EN LINKEDLIST
					perro_loadFromBinary("src\\galgosFlaquitosBinarios.csv", pListaPerros);
					break;

		}

		systemPause("\nPresione ENTER para continuar...");

	}while(opcion != 10);

/*
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

	printf("\nFIN DEL PROGRAMA.");


	return 0;
}





