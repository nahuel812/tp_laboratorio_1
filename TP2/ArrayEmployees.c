#include "ArrayEmployees.h"


int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}

int initEmployees(Employee *list,int len)
{
    int retorno = -1;
    int i;

    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
    if(i==len)
    {
        retorno = 0;
    }
    return retorno;
}

void hardcodeEmployees(Employee *list,int len)
{
    int id[5]= {100,101,102,103,104};
    char name[5][51]= {"Arnold","Roberto","Carlos","Marta","Mario"};
    char lastName[5][51]= {"Garcia","Ramirez","Gonzales","Rucs","Pino"};
    float salary[5]= {2000,3000.5,4000.5,1000.6,5020.9};
    int sector[5]= {1,2,3,4,5};

    int i;
    for(i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = 0;
    }
}


int addEmployee(Employee *list, int len)
{
    int indice;
    int retorno = -1;
    indice = buscarEspacioLibre(list,len);

    if(indice != -1)
    {
        list[indice].id = indice;

        printf("\nIngrese nombre: \n");
        fflush(stdin);
        gets(list[indice].name);

        printf("Ingrese apelldio: \n");
        fflush(stdin);
        gets(list[indice].lastName);

        printf("Ingrese salario: \n");
        scanf("%f", &list[indice].salary);
        while(list[indice].salary < 0 )
        {
            printf("Reingrese salario: \n");
            scanf("%f", &list[indice].salary);
        }

        printf("Ingrese sector: \n");
        scanf("%d",&list[indice].sector);
        while(list[indice].sector <= 0)
        {
            printf("Reingrese sector: \n");
            scanf("%d",&list[indice].sector);
        }

        list[indice].isEmpty = 0;//cambio el estado a ocupado

        printf("Se ha guardado el empleado correctamente.\n");
        retorno = 0;
    }
    else
    {
        printf("No hay espacio.\n");
    }
    return retorno;
}

int buscarEspacioLibre(Employee *list, int len)
{
    int indice = -1;
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int findEmployeeById(Employee *list, int len,int id)
{
    int i;
    int retorno;//retorno el indice donde coincide id que ingreso con id del empleado.

    for(i=0; i<len; i++)
    {
        if(id == list[i].id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int removeEmployee(Employee *list, int len, int id)
{
    int i;
    int retorno= -1;
    char respuesta;

    for(i=0; i<len; i++)
    {
        if(id == list[i].id && list[i].isEmpty == 0)
        {
            printf("¿Esta seguro que desea borrar este empleado?\n");
            mostrarUnEmployee(list[i]);
            printf("Presione 's' para confirmar o 'n' para cancelar:");
            fflush(stdin);
            respuesta = getche();

            while(respuesta != 's' && respuesta!= 'n')//validacion de respuesta
            {
                printf("\nPresione 's' para confirmar o 'n' para cancelar.\n");
                fflush(stdin);
                respuesta = getche();
            }

            if(respuesta == 's')
            {
                list[i].isEmpty = 1;
                printf("\nSe ha dado de baja el empleado correctamente.\n");
                retorno = 0;
                system("pause");
            }
            else
            {
                printf("\nSe ha cancelado la baja del empleado.\n");
                retorno = 1;
                system("pause");
            }
        }
    }
    return retorno;
}

int modifyEmployee(Employee *list, int len)
{
    int retorno= -1;
    int idAux;
    int indice;
    int opcion;
    int respuesta = 's';

    do
    {
        if(respuesta == 's')
        {
            printf("\nIngrese el id del usuario a modificar: \n");
            printEmployees(list,len);
            scanf("%d",&idAux);

            indice = findEmployeeById(list,len,idAux);

            mostrarUnEmployee(list[indice]);
            if(idAux == list[indice].id && list[indice].isEmpty == 0)
            {
                opcion = menuDeOpciones("Que dato desea modificar?\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n\n0.SALIR\n");
                switch(opcion)
                {
                case 1://NOMBRE
                    printf("\nMODIFICAR NOMBRE\n\n");
                    printf("\nIngrese el nuevo nombre: \n");
                    fflush(stdin);
                    gets(list[indice].name);
                    break;
                case 2://APELLIDO
                    printf("\nMODIFICAR APELLIDO\n\n");
                    printf("Ingrese el nuevo apelldio: \n");
                    fflush(stdin);
                    gets(list[indice].lastName);
                    break;
                case 3://SALARIO
                    printf("\nMODIFICAR SALARIO\n\n");
                    printf("Ingrese el nuevo salario: \n");
                    scanf("%f", &list[indice].salary);
                    break;
                case 4://SECTOR
                    printf("\nMODIFICAR SECTOR\n\n");
                    printf("Ingrese el nuevo sector: \n");
                    scanf("%d",&list[indice].sector);
                    while(list[indice].sector <=0 )
                    {
                        printf("Reingrese sector: \n");
                        scanf("%d",&list[indice].sector);
                    }
                    break;
                case 0:

                    break;
                default:
                    printf("\nIngrese una opcion valida.\n");
                    break;
                }
                retorno = 0;
            }
        }

        printf("Desea modificar otro usuario? s/n \n");
        fflush(stdin);
        respuesta = getche();
        while(respuesta != 's' && respuesta!= 'n')//validacion de respuesta
        {
            printf("\nIngrese 's' para confirmar o 'n' para cancelar\n");
            fflush(stdin);
            respuesta = getche();
        }
    }
    while(respuesta != 'n');


    return retorno;
}


int sortEmployees(Employee *list,int len,int order)
{
    int i;
    int j;
    int retorno=-1;
    Employee employeeAux;

    if(order == 1)
    {
        retorno = 1;
        for(i=0; i<len-1; i++)
        {
            if(list[i].isEmpty == 0)
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[j].isEmpty == 0)
                    {
                        if(stricmp(list[i].lastName,list[j].lastName) > 0)
                        {
                            ///SWAP
                            employeeAux = list[i];
                            list[i] = list[j];
                            list[j] = employeeAux;
                        }
                        else if(stricmp(list[i].lastName,list[j].lastName) == 0)
                        {
                            if(list[i].sector > list[j].sector)
                            {
                                employeeAux = list[i];
                                list[i] = list[j];
                                list[j] = employeeAux;
                            }
                        }
                    }
                }
            }
        }
    }
    else if(order == 0)
    {
        retorno = 1;
        for(i=0; i<len-1; i++)
        {
            if(list[i].isEmpty == 0)
            {
                for(j=i+1; j<len; j++)
                {
                    if(list[j].isEmpty == 0)
                    {
                        if(stricmp(list[i].lastName,list[j].lastName) < 0)
                        {
                            ///SWAP
                            employeeAux = list[i];
                            list[i] = list[j];
                            list[j] = employeeAux;
                        }
                        else if(list[i].sector > list[j].sector)
                        {
                            employeeAux = list[i];
                            list[i] = list[j];
                            list[j] = employeeAux;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}

void mostrarUnEmployee(Employee list)
{
    printf("ID:%4d | NOMBRE:%10s | APELLIDO:%10s | SALARIO:%8.3f   | SECTOR:%2d\n", list.id, list.name, list.lastName,list.salary,list.sector);
}

int printEmployees(Employee *list, int len)
{
    int retorno=-1;
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            mostrarUnEmployee(list[i]);
            retorno = 0;
        }
    }
    return retorno;
}

int calcularPromedio(Employee *list,int len)
{
    int i;
    int retorno=-1;
    float promedioAux = 0;
    int tamActualEmpleados=0;
    float promedioTotal;
    int empleadosSuperanPromedio=0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            promedioAux = list[i].salary + promedioAux;
            tamActualEmpleados++;
        }
    }

    promedioTotal = (float)promedioAux/tamActualEmpleados;//casteo

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            if(list[i].salary > promedioTotal)
            {
                empleadosSuperanPromedio++;
                retorno=0;
            }
        }
    }

    printf("El promedio de los salarios de los empleados es de %.3f\n",promedioTotal);
    printf("Los empleados que superan el promedio de salario son %d\n",empleadosSuperanPromedio);
    system("pause");

    return retorno;
}

