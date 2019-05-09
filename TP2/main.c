
#include "ArrayEmployees.h"

#define TAM_EMPLOYEES 1000

int main()
{
    int r;

    char seguir = 's';
    int opcion;
    int flag=0;
    int idABorrar;
    float promedioTotal;
    int criterioOrdenamiento;

    Employee listEmployees[TAM_EMPLOYEES];

    r = initEmployees(listEmployees,TAM_EMPLOYEES);
    hardcodeEmployees(listEmployees,TAM_EMPLOYEES);

    do
    {
        opcion = menuDeOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORME\n0.SALIR\nElija una opcion: \n");

        if(flag==0 && (opcion == 2 || opcion == 3 || opcion == 4))
        {
            printf("Debe ingresar por lomenos 1 empleado.\n");
            system("pause");
            system("cls");
            continue;
        }

        switch(opcion)
        {
        case 1:
            printf("\nALTA DE EMPLOYEE:\n");
            addEmployee(listEmployees,TAM_EMPLOYEES);
            flag = 1;
            break;
        case 2:
            modifyEmployee(listEmployees,TAM_EMPLOYEES);
            break;
        case 3:
            printEmployees(listEmployees,TAM_EMPLOYEES);

            printf("\nIngrese el id del empleado a borrar: ");
            scanf("%d", &idABorrar);

            removeEmployee(listEmployees,TAM_EMPLOYEES, idABorrar);
            break;
        case 4:
             printEmployees(listEmployees,TAM_EMPLOYEES);

            printf("Ingrese el criterio de ordenamiento de los empleados: \n1.ASCENDENTE\n0.DESCENDENTE\n");
            scanf("%d",&criterioOrdenamiento);
            while(criterioOrdenamiento != 1 && criterioOrdenamiento != 0)
            {
                printf("Reingrese el criterio de ordenamiento de los empleados: \n 1.ASCENDENTE\n0.DESCENDENTE\n");
                scanf("%d",&criterioOrdenamiento);
            }
            sortEmployees(listEmployees,TAM_EMPLOYEES,criterioOrdenamiento);
            printf("\n1. \n");
            printEmployees(listEmployees,TAM_EMPLOYEES);

            printf("\n2. \n");
            calcularPromedio(listEmployees,TAM_EMPLOYEES);

            break;

        case 0:
            printf("Saliendo del programa.\n");
            seguir = 'n';
        default:
            printf("Ingrese una opcion valida.");
            break;
        }
        system("pause");
        system("cls");
    }while(seguir != 'n');



        return 0;
}

