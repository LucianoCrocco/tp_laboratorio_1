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

    if(this != NULL && nodeIndex > -1){

    	int len = ll_len(this);

    	Node* pNode = (Node*) malloc (sizeof(Node));
    	Node* pAuxNode = NULL;

    	if(len > -1 && nodeIndex <= len && pNode != NULL){
    		if(nodeIndex == 0){
    			pNode->pNextNode=getNode(this, nodeIndex);
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

    if(this != NULL){
		int len = ll_len(this);
		if(addNode(this, len, pElement) == 0){
			returnAux = 0;
		}
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
		   returnAux = pNode->pElement;
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

    if(this != NULL && index > -1){
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
int ll_remove(LinkedList* this,int index)//ESTA FUNCION HACE ROMPER EL LL_CONTAINSALL
{
    int returnAux = -1;

    /*El error es en esta funcion, por eso mostraba el mensaje 1 vez, el case 2 nunca llegaba a ejecutarse por un error en esta funcion.
      Basicamente si eliminaba un nodo en el index 0 y hacia que la siguiente condicion rompiese el programa.
		pNode = getNode(this, index);
		pAuxNode = getNode(this, index-1); -> Linea que deberia romper el programa si mi index es 0.
		pAuxNode->pNextNode=getNode(this, index+1);

    */
   if(this != NULL && index > -1){
    	int len = ll_len(this);
        Node* pNode = NULL;
        Node* pAuxNode = NULL;

        if(index < len){
        	pNode = getNode(this, index);
        	if(pNode != NULL){
				if(len == 1){
					this->pFirstNode = NULL;
				} else {
					if(index == 0){
						this->pFirstNode=pNode->pNextNode;
					} else {
						pAuxNode = getNode(this, index-1);
						pAuxNode->pNextNode=pNode->pNextNode;
					}
				}
				free(pNode);
				this->size--;
				returnAux = 0;
        	}
        }

	}
    /*if(this != NULL && index > -1){
        int len = ll_len(this);
        Node* pNode = NULL;
        Node* pAuxNode = NULL;

        if(index < len){
        	if(len == 1){
        		pNode = getNode(this, index);
        		this->pFirstNode = NULL;
        	} else {
        		pNode = getNode(this, index);
        		pAuxNode = getNode(this, index-1);
        		pAuxNode->pNextNode=getNode(this, index+1);
        	}
        	free(pNode);
			this->size--;
			returnAux = 0;
        }
    }*/

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
    	for(i=len-1;i>-1;i--){
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

    if(this != NULL){
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
    	returnAux = 0;

		if(len == 0){
			returnAux= 1;
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

    if(this != NULL && index > -1){

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
		ll_remove(this, index);
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
    if(this != NULL){
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
    int i;

    if(this != NULL && this2 != NULL){
    	returnAux = 1;
		void* pElement = NULL;
		int len = ll_len(this2);

		if(ll_isEmpty(this) == 0){
			for(i=0;i<len;i++){
				pElement = ll_get(this2,i);
				if(ll_contains(this,pElement) == 0){
					returnAux = 0;
					break;
				}
			}
		} else {
			returnAux = 0;
		}
    }

	/*if(this != NULL && this2 != NULL){
		returnAux = 1;
		void* pElement = NULL;
		int len = ll_len(this2);
		if(ll_isEmpty(this) == 1){
			for(i=0; i<len; i++){
				pElement = ll_get(this2, i);
				if(ll_contains(this, pElement) == 1){
					continue;
				} else {
					returnAux = 0;
					break;
				}
			}
		}
    }*/

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
    int i;

    if(this != NULL){
    	int len = ll_len(this);

    	if(from > -1 && to <= len){
    		cloneArray = ll_newLinkedList();

    		void* pCloneElement;

    		for(i=from;i<to;i++){
				pCloneElement = ll_get(this,i);
    			ll_add(cloneArray, pCloneElement);
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

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
    	int i;
    	int j;
    	int len = ll_len(this);
    	//void* pAux = NULL;//Si no uso un auxiliar, al pisar la funcion no estaria apuntando a distantas direccion pero los elementos no serian los mismos? -> No, ya que antes con los ll_get pido esos elementos en mis void* pElement
    	/* Tengo 3 posiciones de memoria, entonces cuando hago un ll_set no hago que el puntero pElement apunte a otra posicion de memoria pero el valor original de ese pELement tiene la misma posicion de memoria y no desapareico
    	 * Por eso la utilizacion del pAux es inutil, ya que no se piso mi direccion de memoria con su valor, solo cambie la direccion.
    	 *
    	 */
    	int condicion;
    	void* pElementOne;
		void* pElementTwo;

    	if(ll_isEmpty(this) == 0){
    		for(i=0;i<len-1;i++){
				//pElementOne = ll_get(this, i); Por que no funcionaria si lo posiciono aca?
    			for(j=i+1;j<len;j++){
    				pElementOne = ll_get(this, i);
    				pElementTwo = ll_get(this, j);
    				condicion = pFunc(pElementOne, pElementTwo);
    				if((order == 0 && condicion == -1) || (order == 1 && condicion == 1)){
    					ll_set(this, j, pElementOne);
    					ll_set(this, i, pElementTwo);
    				}
    			}
    		}
    		returnAux = 0;
    	}
    }



/*
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){// 0 Descendente || 1 Ascendente
    	int i;
    	int j;
    	if(ll_isEmpty(this) == 0){
			int len = ll_len(this);
    		for(i=0;i<len-1;i++){
    			for(j=i;j<len;j++){
    				void* pElementOne = ll_get(this, i);
    				void* pElementTwo = ll_get(this, j);
    				if(order == 1 && pFunc(pElementOne, pElementTwo) == 1){
    					ll_set(this, j, pElementOne);
    					ll_set(this, i, pElementTwo);
    				} else {
						if(order == 0 && pFunc(pElementOne, pElementTwo) == -1){
							ll_set(this, i, pElementTwo);
							ll_set(this, j, pElementOne);
						}
    				}
    			}
    		}
    		returnAux = 0;
    	}
    }
*/
    return returnAux;

}

