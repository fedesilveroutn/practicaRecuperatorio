
#include <string.h>
#include "input.h"



/**
 * @fn int getInt(int*, char*, char*, int, int)
 * @brief asks for an int and validates it in the given range
 *
 * @param num int*
 * @param message char*
 * @param errorMessage char*
 * @param min int
 * @param max int
 * @return 0 if function worked
 */
int getInt (int* num, char* message, char* errorMessage, int min, int max)
{
	int ret = -1;
	int enteredNum;

	if(num != NULL && message != NULL && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%d", &enteredNum);

			while(enteredNum < min || enteredNum > max)
			{
				printf("%s", errorMessage);
				fflush(stdin);
				scanf("%d", &enteredNum);
			}

		*num = enteredNum;
		ret = 0;
	}

	return ret;
}



/**
 * @fn int getFloat(float*, char*, char*, int, int)
 * @brief asks for a float and validates it in the given range
 *
 * @param num float*
 * @param message char*
 * @param errorMessage char*
 * @param min int
 * @param max int
 * @return 0 if function worked
 */
int getFloat(float* num, char* message, char* errorMessage, int min, int max)
{
	int ret = -1;
	float enteredNum;

	if (num != NULL && message && errorMessage != NULL && min < max)
	{
		printf("%s", message);
		fflush(stdin);
		scanf("%f", &enteredNum);

			while(enteredNum < min || enteredNum > max)
			{
				printf("%s", errorMessage);
				fflush(stdin);
				scanf("%f", &enteredNum);
			}

		*num = enteredNum;
		ret = 0;
	}

	return ret;
}



/**
 * @fn int getChar(char*, char*)
 * @brief asks for a char
 *
 * @param c char*
 * @param message char*
 * @param errorMessage char*
 * @param min char
 * @param max char
 * @return 0 if function worked
 */
int getChar(char* c , char* message, char* errorMessage, char min, char max)
{
	int ret = -1;
	char enteredChar;

	if (c != NULL && message != NULL)
	{
		printf("%s", message);
		fflush(stdin);
		enteredChar = getchar();

			while (enteredChar < min || enteredChar > max)
			{
				printf("%s", errorMessage);
				fflush(stdin);
				enteredChar = getchar();
			}

		*c = enteredChar;
		ret = 0;
	}
	return ret;
}



/**
 * @fn void getString(char*, char*, char*, int)
 * @brief asks for a string and validates if it is smaller than the given limit
 *
 * @param string char*
 * @param message char*
 * @param errorMessage char*
 * @param max int
 */
void getString (char* string, char* message, char* errorMessage, int max)
{
	char unvalidatedString[200];
	int tam;

	printf("%s", message);
	fflush(stdin);
	scanf("%[^\n]", unvalidatedString);
	tam = strlen (unvalidatedString);

		while (tam > max)
		{
			printf("%s", errorMessage);
			fflush(stdin);
			scanf("%[^\n]", unvalidatedString);
			tam = strlen (unvalidatedString);
		}

	strcpy (string, unvalidatedString);
}




/**
 * @fn int systemPause(char*)
 * @brief pausa la ejecucion del programa momentaneamente hasta que el usuario presione alguna tecla
 *
 * @param message recibe un mensaje para ser mostrado al usuario
 * @return retonra 0 si funcionó y -1 si hubo error
 */
int systemPause(char* message)
{
	int ret=-1;
	if(message!=NULL)
	{
		fflush(stdin);
		printf("\n%s",message);
		getchar();
		ret=0;
	}
	return ret;
}



int getLastIdFromTxt ()
{
	FILE* pFile = NULL;
	char auxId[10];
	int idFound;

	pFile = fopen ("src\\lastId.txt", "r");
	if (pFile != NULL)
	{
		fscanf(pFile , "%s\n", auxId );
		while (!feof(pFile))
		{
			fscanf(pFile , "%s\n", auxId );
			if (feof(pFile))
			{
				break;
			}
		}
		idFound = atoi(auxId);
	}

	fclose(pFile);
	pFile = NULL;
	return idFound;
}



int saveLastIdToTxt (int lastIdFromMain)
{
	FILE* pFile = NULL;
	int ret = 1;
	pFile = fopen("src\\lastId.txt", "w");
	if (pFile != NULL)
	{
		fprintf(pFile, "%d\n", lastIdFromMain );
		ret = 0;
	}
	fclose(pFile);

	return ret;
}





