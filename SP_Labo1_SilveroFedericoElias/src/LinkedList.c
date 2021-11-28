#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "perritos.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    LinkedList* ret = NULL;

    this = (LinkedList*) malloc (sizeof (LinkedList));//reservo espacio en memoria dinamica para un puntero a la estructura LinkedList
    if (this != NULL)
    {
    	this->pFirstNode = NULL;//va a apuntar a null porque no hay ningun nodo
    	this->size = 0;//el tam sera cero porque no hay ningun nodo
    	ret = this;//retorno el puntero al LinkedList
    }

    return ret;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if ( this != NULL)
    {
    	returnAux = this->size; //el size contiene la longitud de la linkedlist, por eso lo retorno
    }

    return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* auxNode = NULL;
	int len;
	int i;

	if ( this != NULL && nodeIndex > -1)
	{
		len = ll_len(this);
		if ( nodeIndex < len )
		{
			auxNode = this->pFirstNode;//esta asignacion es necesaria porque es la unica forma de conseguir toda la cadena de nodos
			for ( i = 0; i < nodeIndex ; i++)//recorre hasta el nodo indicado
			{
				auxNode = auxNode->pNextNode; //en cada iteracion se guarda el proximo nodo para que cuando termine el bucle quede cargado el nodo q quiero
			}
		}
	}

    return auxNode;//retorno el nodo que consegui
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex, void* pElement)
{
	Node* auxPreviousNode;
	Node* auxNode;
	int len = ll_len(this);
	int returnAux = -1;

	if ( this != NULL && nodeIndex < len + 1 && nodeIndex > -1)
	{
		auxNode = (Node*) malloc (sizeof(Node));//guardo espacio en memoria dinamica para un aux de la estructura Node
		auxNode->pElement = pElement;//le asigno el puntero a la estructura que quiero agregar

		if (nodeIndex == 0)//para agregar el nodo en la primera posicion de la linkedlist
		{
			auxNode->pNextNode = this->pFirstNode;//para que el anterior primer nodo no se pierda, debo guardarlos en el puntero al sig nodo de mi aux
			this->pFirstNode = auxNode;//le digo a la linkedlist que el primer nodo al que va a apuntar es el nuevo que cree
		}

		else if (nodeIndex > 0 && nodeIndex < len)//en cambio, para agregar entre medio de dos nodos
		{
			auxPreviousNode = getNode(this, nodeIndex - 1);//requiero saber cual es el nodo anterior a la posicion donde quiero guardar mi aux
			auxNode->pNextNode = auxPreviousNode->pNextNode;//el nodo siguiente al que apuntaba el nodo anterior, ahora es apuntado por mi aux
			auxPreviousNode->pNextNode = auxNode;//el nodo anterior ahora apunta a mi aux
		}

		else//en cambio, para agregar al final de la linkedlist
		{
			auxPreviousNode = getNode(this, nodeIndex - 1);
			auxPreviousNode->pNextNode = auxNode;//el nodo anterior apuntara a mi aux
			auxNode->pNextNode = NULL;//mi auxiliar apuntara a null porque es la ultima posicion
		}

		this->size++;//como agregue un nodo, aumento el size de la linkedlist
		returnAux = 0;
	}

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if( this != NULL && pElement != NULL)
    {
    	len = ll_len(this);
    	addNode(this, len, pElement);
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
	Node* auxNode;

    if( this != NULL && index > -1 && index < len )
    {
    	auxNode = getNode(this, index);
    	returnAux = auxNode->pElement;
    }

    return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if( this != NULL && index > -1 && index < len)
    {
    	Node* auxNode = getNode(this, index);
    	auxNode->pElement = pElement;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len = ll_len(this);
    Node* auxNode;
    Node* auxPreviousNode;

    if( this != NULL && index > -1 && index < len)
	{
    	if( index == 0)
    	{
    		auxNode = this->pFirstNode;
    		this->pFirstNode = auxNode->pNextNode;
    	}

    	else if (index > 0 && index < len)
    	{
    		auxPreviousNode = getNode(this, index - 1);
    		auxNode = getNode(this, index);
    		auxPreviousNode->pNextNode = auxNode->pNextNode;
    	}

    	else
    	{
    		auxPreviousNode = getNode(this, index - 1);
    		auxPreviousNode->pNextNode = NULL;

    	}

    	this->size--;
    	free(auxNode);
    	auxNode = NULL;
		returnAux = 0;
	}

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int len = ll_len(this);
    int returnAux = -1;
    int i;

    if( this != NULL)
    {
    	for( i = 0; i < len; i++)
    	{
    		ll_remove(this, i);
    	}

    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL )
    {
    	ll_clear(this);
    	free(this);
    	this = NULL;

    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    void* auxElement;
    int returnAux = -1;
    int len;
    int i;

    if( this != NULL)
    {
    	len = ll_len(this);
    	for (i = 0; i < len; i++)
    	{
    		auxElement = ll_get(this, i);
    		if (auxElement == pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	if (this->size > 0)
    	{
    		returnAux = 0;
    	}

    	else
    	{
    		returnAux = 1;
    	}
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
   int returnAux = -1;
   int len;

    if(this != NULL && index > -1 )
    {
    	len = ll_len(this);
    	if ( index < len + 1)
    	{
    		returnAux = addNode(this, index, pElement);
    	}
    }

    return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;

    if( this != NULL && index > -1)
    {
    	len = ll_len(this);
    	if( index < len + 1)
    	{
    		returnAux = ll_get(this, index);
    		ll_remove(this, index);
    	}
    }

    return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this != NULL)
    {
    	i = ll_indexOf(this, pElement);
    	if (i != -1)
    	{
    		returnAux = 1;
    	}

    	else
    	{
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    void* pElement;
    int returnAux = -1;
    int containsRet;
    int len;
    int i;

    if( this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	len = ll_len(this);
    	for (i = 0; i < len; i++)
    	{
    		pElement = ll_get(this2, i);
    		containsRet = ll_contains(this, pElement);
    		if ( containsRet != 1 )
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    void* pElement;
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    int i;

    if(this != NULL && from > -1 && to < len + 1 && from < to)
    {
    	cloneArray = ll_newLinkedList();
    	for ( i = from; i < to; i++)
    	{
    		pElement = ll_get(this, i);
    		addNode(cloneArray, i, pElement);
    	}
    }

    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if( this != NULL )
    {
    	cloneArray = ll_newLinkedList();
    	cloneArray = this;
    }

    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	void* pElementOne = NULL;
	void* pElementTwo = NULL;
	void* pAuxElement = NULL;
	int returnAux =-1;
	int retFunction;
	int len;
	int i;
	int j;

	if( this != NULL && pFunc != NULL && (order == 0 || order == 1)  )
	{
		len = ll_len(this);

		for ( i = 0; i < len - 1 ; i++)
		{
			pElementOne = ll_get(this, i);
			for (j = i + 1 ; j < len; j++)
			{
				pElementTwo = ll_get(this, j);

				retFunction = pFunc(pElementOne , pElementTwo);

				if( order == 0)
				{
					if( retFunction == -1)
					{
						pAuxElement = pElementOne;
						pElementOne = pElementTwo;
						pElementTwo = pAuxElement;
					}
				}

				if ( order == 1)
				{
					if ( retFunction == 1)
					{
						pAuxElement = pElementTwo;
						pElementTwo = pElementOne;
						pElementOne = pAuxElement;
					}
				}

				ll_set(this, i, pElementOne);
				ll_set(this, j, pElementTwo);
			}
		}
		returnAux = 0;
	}

	return returnAux;
}



int ll_map(LinkedList* this, int (*pFunc)(void*) )
{
	int ret = 1;
	int len;
	int i;
	ePerro* auxPerro;

	if(this != NULL && pFunc != NULL)
	{
		len = ll_len(this);
		for(i = 0; i < len; i++ )
		{
			auxPerro = (ePerro*) ll_get(this, i);
			ret = pFunc (auxPerro);
		}
	}

	return ret;
}



LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	LinkedList* nuevaLista = ll_newLinkedList();
	ePerro* elemento;

	int len = ll_len(this);;
	int i;

	for( i = 0; i < len ; i++)
	{
		elemento = ll_get(this, i);
		if ( pFunc (elemento) == 0 )
		{
			ll_add(nuevaLista, elemento);
		}

	}

	return nuevaLista;
}














