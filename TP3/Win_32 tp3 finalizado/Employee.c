#include "Employee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = 0;
        strcpy(pEmployee->nombre , "vacio");
        pEmployee->horasTrabajadas = 0;
        pEmployee->sueldo = 0;
    }

    return pEmployee;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* pEmployee;

    pEmployee = (Employee*) malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        /*
        strcpy(pEmployee->id,idStr);
        strcpy(pEmployee->nombre,nombreStr);
        strcpy(pEmployee->horasTrabajadas,horasTrabajadasStr);
        */
        //sueldo
    }

    return pEmployee;
}

void employee_delete(Employee* this)
{
    free(this);
}


////////////////////////////GETERS Y SETTERS///////////////////////////////////////////////////
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}




int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }

    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}




int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}





int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno = 0;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;
    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}
//////////////////////////////////////////////////////////

int employee_buscarPorId(LinkedList* pLista, int idEmployee)
{
    int indice = -1;
    int i;
    int tamLista;
    int idAux;
    Employee* pEmployeeAux;

    tamLista = ll_len(pLista);

    if(pLista != NULL)
    {
        for(i=0; i<tamLista; i++)
        {
            pEmployeeAux = (Employee*) ll_get(pLista,i);///tomo un empleado

            employee_getId(pEmployeeAux,&idAux);///tomo su id
            ///matcheo los ids
            if(idAux == idEmployee)///lo comparo, si son iguales retorno el indice
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int employee_sortByName(Employee* employee1, Employee* employee2)
{
    int retorno;

    retorno = stricmp(employee1->nombre, employee2->nombre);

    return retorno;
}

