#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    char id[30];
    char nombre[30];
    char horasTrabajadas[30];
    char sueldo[30];

    int cantLeida;

    Employee* pNewEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {

            cantLeida = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);///leo y guardo
            //printf("%s | %s  | %s  | %s\n",id,nombre,horasTrabajadas,sueldo);//muestro los datos

            if(cantLeida == 4)
            {
                pNewEmployee = employee_new();///constructor - nuevo espacio en memoria para 1 empleado

                //employee_setId(pNewEmployee,atoi(id));
                pNewEmployee->id = atoi(id);
                strcpy(pNewEmployee->nombre, nombre);
                pNewEmployee->horasTrabajadas = atoi(horasTrabajadas);
                pNewEmployee->sueldo = atoi(sueldo);

                retorno = 0;

                ll_add(pArrayListEmployee,pNewEmployee);///agrego a la lista
            }
            else
            {
                printf("Ha ocurrido un error.\n");
            }

        }
    }

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pNewEmployee;
    int r;

    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        pNewEmployee = employee_new();
        fread(pNewEmployee,sizeof(Employee),1,pFile);
        while(!feof(pFile))
        {
            pNewEmployee = employee_new();///nuevo empleado
            if(pNewEmployee != NULL)
            {
                r = fread(pNewEmployee,sizeof(Employee),1,pFile);///leo el archivo

                if(r == 1)
                {
                    ll_add(pArrayListEmployee,pNewEmployee);///lo agrego a la lista
                    retorno = 0;
                }
            }
        }
    }

    return retorno;
}
