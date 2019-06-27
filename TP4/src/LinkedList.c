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
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
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

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int lenList;
    int i;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(nodeIndex >= 0 && nodeIndex < lenList)
        {
            if(nodeIndex == 0)
            {
                pNode = this->pFirstNode;
            }
            else
            {
                pNode = this->pFirstNode;
                for(i=0; i<nodeIndex; i++)
                {
                    pNode = pNode->pNextNode;
                }
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
    int lenList;

    Node* pNodeNew;
    Node* pNodeBefore;

    pNodeNew = (Node*) malloc(sizeof(Node));//espacio para el nuevo nodo
    if(this != NULL && pNodeNew != NULL)
    {
        lenList = ll_len(this);
        if(nodeIndex >= 0 && nodeIndex <= lenList)
        {
            if(nodeIndex == 0)
            {
                pNodeNew->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodeNew;

                this->size++;//aumento el size
                returnAux = 0;
            }
            else
            {
                pNodeBefore = getNode(this,nodeIndex-1);

                pNodeNew->pNextNode = pNodeBefore->pNextNode;//es como hacer un pull,
                pNodeBefore->pNextNode = pNodeNew;

                this->size++;//aumento el size
                returnAux = 0;
            }
            pNodeNew->pElement = pElement;
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
    int indice = 0;
    Node* actual;

    if(this != NULL)
    {
        actual = this->pFirstNode;
        while(actual != NULL)//busco el ultimo elemento
        {
            actual = actual->pNextNode;//paso de nodo en nodo hasta llegar al que tiene NULL
            indice++;
        }
        returnAux = addNode(this, indice, pElement);

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
    Node* pNodeAux;
    int lenList;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(index >= 0 && index < lenList)
        {
            pNodeAux = getNode(this,index);//tomo el nodo del indice
            if(pNodeAux != NULL)
            {
                returnAux = pNodeAux->pElement;//devuelvo el elemento de ese nodo
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
    int lenList;
    Node* pNodeAux;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(index >= 0 && index < lenList)
        {
            pNodeAux = getNode(this, index);//tomo el nodo
            if(pNodeAux != NULL)
            {
                pNodeAux->pElement = pElement;//cambio el elemento del nodo por el elemento actual
                returnAux = 0;
            }
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
    int lenList;

    Node* pNodeActual;
    Node* pNodeBefore;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(index >= 0 && index <= lenList)
        {
            if(index == 0)
            {
                pNodeActual = this->pFirstNode;//le paso el primer nodo
                this->pFirstNode = pNodeActual->pNextNode;//asigno al primero nodo el siguiente que tenia el otro

                this->size--;//modifico el size pq elimine un nodo
                free(pNodeActual);//libero el espacio del actual
                returnAux = 0;
            }
            else
            {
                pNodeBefore = getNode(this,index-1);
                pNodeActual = getNode(this,index);
                if(pNodeActual != NULL && pNodeBefore != NULL)
                {
                    pNodeBefore->pNextNode = pNodeActual->pNextNode;//hago que el anterior al actual apunte al siguiente del siguiente del actual

                    this->size--;//modifico el size pq elimine un nodo
                    free(pNodeActual);//libero el espacio del nodo actual.
                    returnAux = 0;
                }
            }
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
    int lenList;
    int i;

    if(this != NULL)
    {
        lenList = ll_len(this);
        for(i=0 ; i<lenList; i++)
        {
            returnAux = ll_remove(this,i);
        }
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

    if(this != NULL)
    {
        returnAux = ll_clear(this);
        if(returnAux == 0)
        {
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
    int lenList;
    int i;
    Node* pNodeAux;

    if(this != NULL)
    {
        lenList = ll_len(this);

        pNodeAux = this->pFirstNode;
        if(pNodeAux->pElement == pElement)
        {
            returnAux = 0;
        }
        else
        {
            for(i=1 ; i<lenList ; i++)
            {
                pNodeAux = getNode(this,i);

                if(pNodeAux->pElement == pElement)
                {
                    returnAux = i;
                    break;
                }
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
    int lenList;
    if(this != NULL)
    {
        lenList = ll_len(this);
        if(lenList == 0)
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
    int lenList;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(index >= 0 && index <= lenList)
        {
            if(index == 0)
            {
                if(!addNode(this,index,pElement))
                {
                    returnAux = 0;
                }

            }
            else
            {
                if(!addNode(this,index,pElement))
                {
                    returnAux = 0;
                }
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
    int lenList;

    Node* pNodeActual;
    Node* pNodeBefore;

    if(this != NULL)
    {
        lenList = ll_len(this);
        if(index >= 0 && index <= lenList)
        {
            //llget para tomar el elemento y devolverlo, luego saco el nodo con getnode y hago que el anterior apunte al siguiente siguiente
            returnAux = ll_get(this,index);

            if(index == 0)
            {
                pNodeActual = this->pFirstNode;//le paso el primer nodo
                this->pFirstNode = pNodeActual->pNextNode;//asigno al primero nodo el siguiente que tenia el otro

                this->size--;//modifico el size pq elimine un nodo
                ///free(pNodeActual);//libero el espacio del actual
            }
            else
            {
                pNodeBefore = getNode(this,index-1);
                pNodeActual = getNode(this,index);
                if(pNodeActual != NULL && pNodeBefore != NULL)
                {
                    pNodeBefore->pNextNode = pNodeActual->pNextNode;//hago que el anterior al actual apunte al siguiente del siguiente del actual

                    this->size--;//modifico el size pq elimine un nodo
                    ///free(pNodeActual);//libero el espacio del nodo actual.
                }
            }
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

    if(this != NULL)
    {
        if(pElement != NULL)
        {
            if(ll_indexOf(this,pElement) == -1)
            {
                returnAux = 0;
            }
            else
            {
                returnAux = 1;
            }
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
    int returnAux = -1;
    int lenList;
    int lenList2;
    void* pElementAux;
    int i;

    if(this != NULL && this2 != NULL)
    {
        lenList = ll_len(this);
        lenList2 = ll_len(this2);
        returnAux = 0;

        if(lenList >= lenList2)//o mayor a LL2
        {
            for(i=0; i<lenList; i++)
            {
                pElementAux = ll_get(this2,i);

                if(pElementAux != NULL)
                {
                    if(ll_contains(this,pElementAux))
                    {
                        returnAux = 1;
                    }
                    else
                    {
                        returnAux = 0;
                        break;
                    }
                }
            }
        }
        else
        {
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
    int lenList;
    int i;
    void* pElementAux;

    if(this != NULL)
    {
        lenList = ll_len(this);

        if(from >= 0 && from < to && to <= lenList)//limites
        {
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL)
            {
                for(i=from; i<to; i++)
                {
                    pElementAux = ll_get(this,i);
                    ll_add(cloneArray,pElementAux);
                }
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

    if(this != NULL)
    {
        cloneArray = ll_subList(this,0,ll_len(this));

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
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;

    void* pElementUno;
    void* pElementDos;
    void* pElementAux;
    int i;
    int flag;
    int lenList;

    if(this!=NULL)
    {
        if (pFunc!= NULL)
        {
            if(order == 0 || order == 1)
            {
                lenList = ll_len(this);
                if(lenList > 0)
                {
                    do
                    {
                        flag = 0;
                        for(i=0; i<lenList-1; i++)
                        {
                            pElementUno = ll_get(this,i);
                            pElementDos = ll_get(this,i+1);

                            if((pFunc(pElementUno, pElementDos) <0 && order==0) || (pFunc(pElementUno, pElementDos) >0 && order==1))
                            {
                                pElementAux = pElementUno;
                                ll_set(this,i,pElementDos);
                                ll_set(this,i+1,pElementAux);
                                flag=1;
                            }
                            returnAux=0;
                        }
                    }while(flag);
                }
            }
        }
    }
return returnAux;
}

