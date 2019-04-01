#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int opcion;
    char seguir = 's';
    float operandoUno = 0;
    float operandoDos = 0;

    int flagMenu=0;

    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorialUno;
    int resultadoFactorialDos;

    printf("1-Ingresar 1er operando (A=x)");
    printf("\n2-Ingresar 2do operando (B=y)");
    printf("\n3-Calcular todas las operaciones");
    printf("\n4-Informar resultados");
    printf("\n5-Salir\n");
    printf("\nElija una opcion: ");

    do
    {
        if(flagMenu==1)
        {
            printf("1-Ingresar 1er operando (A=%.4f)",operandoUno);
            printf("\n2-Ingresar 2do operando (B=%.4f)",operandoDos);
            printf("\n3-Calcular todas las operaciones");
            printf("\n4-Informar resultados");
            printf("\n5-Salir\n");
            printf("\nElija una opcion: ");
        }
        flagMenu = 1;
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            operandoUno = pedirNumero("Ingrese el primer operando: ");
            break;

        case 2:
            operandoDos = pedirNumero("Ingrese el segundo operando: ");
            break;

        case 3:

            resultadoSuma = hacerSuma(operandoUno,operandoDos);

            resultadoResta = hacerResta(operandoUno,operandoDos);

            if(operandoDos > 0)
            {
                resultadoDivision = hacerDivision(operandoUno,operandoDos);
            }

            resultadoMultiplicacion = hacerMultiplicacion(operandoUno,operandoDos);

            resultadoFactorialUno = hacerFactorial(operandoUno);
            resultadoFactorialDos = hacerFactorial(operandoDos);

            printf("Se han calculado las operaciones correctamente.\n");
            system("pause");

            break;

        case 4:

            //suma
            printf("El resultado de A+B es: %.4f \n", resultadoSuma);
            //resta
            printf("El resultado de A-B es: %.4f \n", resultadoResta);

            //division
            if(operandoDos == 0)
            {
                printf("Error, no se puede dividir por 0.\n");
            }
            else
            {
                printf("El resultado de A/B es: %.4f \n", resultadoDivision);
            }

            //multiplicacion
            printf("El resultado de la multiplicacion es: %.4f \n", resultadoMultiplicacion);

            //factorial
            if(operandoUno < 0 || operandoDos < 0)
            {
                printf("No se puede sacar factorial de numero negativo.\n");
            }
            else
            {
                printf("El factorial de A es: %d y el factorial de B es: %d\n", resultadoFactorialUno, resultadoFactorialDos);
            }

            system("pause");

            break;

        case 5:
            printf("\nSaliendo del programa!\n");
            seguir = 'n';
            break;

        default:
            printf("\nNo ingreso una opcion valida!\n");
        }

        system("pause");//pausa el programa
        system("cls");//borra la pantalla

    }while(seguir == 's');



    return 0;
}

