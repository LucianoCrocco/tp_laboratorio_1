#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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
    LinkedList* this= NULL;

    this = (LinkedList*) malloc (sizeof(LinkedList));//probar calloc

    if(this!=NULL){
    	this->size = 0;
    	this->pFirstNode = NULL;
    }

    return this;
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

    if(this != NULL){
    	returnAux = this -> size;
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
	int i;
	Node* pNode = NULL;

	if(this != NULL && nodeIndex > -1){
		int len = ll_len(this);

		if(len > -1 && nodeIndex < len){
			pNode=this->pFirstNode;
			for(i=0;i<nodeIndex;i++){
				pNode = pNode->pNextNode;
			}
		}

	}

    return pNode;
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;

    if(this != NULL /*&& pElement != NULL */&& nodeIndex > -1){//El error es pq en el primer test le pasa un pElement nulo, por lo tanto nunca entra al if

    	int len = ll_len(this);

    	//printf("-----%d----\n", len);//El size se incremeta, es un error del test, se comprueba con los printf
    	//printf("......%d.....\n", this->size);

    	Node* pNode = (Node*) malloc (sizeof(Node));
    	Node* pAuxNode = NULL;

    	if(len > -1 && nodeIndex <= len && pNode != NULL){
    		if(nodeIndex == 0){
    			pNode->pNextNode=getNode(this, nodeIndex);//Si no hay un nodo siguiente devuelve NULL | Por lo tanto siempre this->pFirstNode == NULL es innecesario
    			this->pFirstNode=pNode;
    		} else {
    			pAuxNode=getNode(this,nodeIndex-1);
    			pAuxNode->pNextNode=pNode;
    			pNode->pNextNode=getNode(this,nodeIndex);
    		}
    		this->size++;
    		pNode->pElement=pElement;
    		returnAux = 0;
    	}
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
    int len = ll_len(this);
    int validar;

    if(this != NULL){
		validar = addNode(this, len, pElement);
		returnAux = validar;
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


   if(this != NULL && index > -1){
	   Node* pNode = NULL;
	   int len = ll_len(this);

	   if(len > -1 && index < len){
		   pNode = getNode(this,index);

		   if(pNode != NULL){
			   returnAux = pNode->pElement;
		   }
	   }

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

    if(this != NULL && index > -1 /*&& pElement != NULL*/){// mismo problema que el addNode, no se puede verificar pElement != NULL xq el test le pasa un NULL.
        int len = ll_len(this);
        Node* pNode = NULL;
        if(index < len){
        	pNode = getNode(this, index);
        	pNode->pElement=pElement;
        	returnAux = 0;
        }
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


    if(this != NULL && index > -1){
        int len = ll_len(this);
        Node* pNode = NULL;
        Node* pAuxNode = NULL;

        if(index < len){
        	if(len == 1){
        		pNode = getNode(this, index);
        		this->pFirstNode = NULL;
        		free(pNode);
        	} else {
        		pNode = getNode(this, index);
        		pAuxNode = getNode(this, index-1);
        		pAuxNode->pNextNode=getNode(this, index+1);
        		free(pNode);
        	}
			this->size--;
			returnAux = 0;
        }
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
    int returnAux = -1;
    int len = ll_len(this);
    int i;

    if(this != NULL){
    	for(i=len;i>-1;i--){
    		ll_remove(this,i);
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

    if(this != NULL){
    	if(ll_clear (this) == 0){
        	free(this);
        	returnAux = 0;
    	}
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
    int returnAux = -1;

    if(this != NULL/* && pElement != NULL*/){//Mismo error que el addNode
    	int len = ll_len(this);
    	int i;
    	void* pAuxElement = NULL;
    	for(i=0;i<len;i++){
    		pAuxElement = ll_get(this, i);
    		if(pAuxElement == pElement){
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

    if(this != NULL){
    	int len = ll_len(this);
		if(len == 0){
			returnAux= 1;
		} else {
			if(len > 0){
				returnAux = 0;
			}
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

    if(this != NULL && index > -1 /*&& pElement != NULL */){//Mismo error addNode

		int len = ll_len(this);

		if(index <= len){
			if(addNode(this,index,pElement) == 0){
				returnAux = 0;
			}
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

    if(this != NULL && index > -1){
    	returnAux = ll_get(this, index);
    	if(returnAux != NULL){
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
    if(this != NULL /*&& pElement != NULL*/){ //Mismo error addNode.
    	returnAux = 0;
    	if(ll_indexOf(this,pElement) != -1){
    		returnAux = 1;
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
    int returnAux = -1;
    printf("ROMPE1\n\n");

    if(this != NULL && this2 != NULL){
    	int len = ll_len(this);
    	int len2 = ll_len(this2);
    	printf("ROMPE2\n\n");

    	if(len == len2){
    		int i;
    		void* pAuxElement = NULL;
    		returnAux = 1;
    		printf("ROMPE3\n\n");
    		for(i=0;i<len2;i++){
    			printf("ROMPE4\n\n");
    			pAuxElement = ll_get(this2, i);
    			if(ll_contains(this, pAuxElement) != 1){
    				printf("ROMPE5\n\n");
    				returnAux = 0;
    				break;
    			}
    		}
    	} else {
    		returnAux = 0;
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
    LinkedList* cloneArray = NULL;

    if(this != NULL){
    	int len = ll_len(this);

    	if(from > -1 && to <= len){
    		cloneArray = ll_newLinkedList();
    		int i;
    		int j=0;
    		void* pCloneElement;

    		for(i=from;i<to;i++){
				pCloneElement = ll_get(this,i);
    			ll_add(cloneArray, pCloneElement);
    			j++;
    		}
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

    if(this != NULL){
    	int len = ll_len(this);
    	if(len > -1 && ll_isEmpty(this) == 0){
    		cloneArray = ll_subList(this, 0, len);
    	}
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
    int returnAux =-1;

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){// 0 Descendente || 1 Ascendente
    	int i;
    	int j;
    	int len = ll_len(this);
    	if(len > -1 && ll_isEmpty(this) == 0){
    		void* pAux = NULL;
    		for(i=0;i<len-1;i++){
    			for(j=i;j<len;j++){
    				void* pElementOne = ll_get(this, i);
    				void* pElementTwo = ll_get(this, j);
    				if(order == 1 && pFunc(pElementOne, pElementTwo) == 1){
    					pAux = pElementTwo;
    					ll_set(this, j, pElementOne);
    					ll_set(this, i, pAux);
    				}
    				if(order == 0 && pFunc(pElementOne, pElementTwo) == -1){
    					pAux = pElementOne;
    					ll_set(this, i, pElementTwo);
    					ll_set(this, j, pAux);
    				}

    			}
    		}
    		returnAux = 0;
    	}
    }

    return returnAux;

}

