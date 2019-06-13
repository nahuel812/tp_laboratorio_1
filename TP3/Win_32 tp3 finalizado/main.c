#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    int r;
    int i;
    int flagCargarDatos=0;

    do{
        printf("1.Cargar datos empleado modo texto\n");
        printf("2.Cargar los datos de los empleados desde el archivo data.csv (modo binario)\n\n");
        printf("3.Alta de empleado\n");
        printf("4.Modificar datos de empleado\n");
        printf("5.Baja de empleado\n\n");
        printf("6.Listar empleados\n");
        printf("7.Ordenar empleados\n\n");
        printf("8.Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9.Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
        printf("0.Salir\n");

        printf("Elija una opcion: \n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:///cargar datos empleados modo texto
                if(flagCargarDatos == 0 )
                {
                    controller_loadFromText("data.csv",listaEmpleados);
                    flagCargarDatos = 1;
                }
                else
                {
                    printf("\nYa se han cargaron los datos.\n");
                }

                break;
            case 2:///cargar datos empleado modo binario
                if(flagCargarDatos == 0)
                {
                    controller_loadFromBinary("data.dat",listaEmpleados);
                    flagCargarDatos = 1;
                }
                else
                {
                    printf("\nYa se han cargaron los datos.\n");
                }

                break;

            case 3:///alta empleado
                controller_addEmployee(listaEmpleados);
                break;
            case 4:///modificacion empleado
                controller_editEmployee(listaEmpleados);
                break;
            case 5:///baja empleado
                controller_removeEmployee(listaEmpleados);

            case 6:///listar empleados
                controller_ListEmployee(listaEmpleados);
                if(ll_len(listaEmpleados)== 0)
                {
                    printf("No hay empleados.\n");
                }
                else
                {
                    printf("Cant empleados: %d\n",ll_len(listaEmpleados)-1);
                }
                break;
            case 7:///ordenar empleados
                controller_sortEmployee(listaEmpleados);
                break;

            case 8:///guardar texto
                controller_saveAsText("data.csv",listaEmpleados);
                break;

            case 9:///guardar binario
                controller_saveAsBinary("data.dat",listaEmpleados);
                break;

            case 0:
                r = ll_clear(listaEmpleados);
                printf("\nSe borraron los nodos de empleados correctamente.\n");
                ll_deleteLinkedList(listaEmpleados);
                break;

        }
        system("pause");
        system("cls");
    }while(option != 0);
    return 0;
}

