#include <stdio.h>
#include "funciones.h"


float pedirNumero(char mensaje[])
{
    float numeroIngresado;

    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}


float hacerSuma(float a, float b)
{
    float resultado;

    resultado = a + b;
    return resultado;
}


float hacerResta(float a, float b)
{
    float resultado;

    resultado = a - b;
    return resultado;
}


float hacerDivision(float a, float b)
{
    float resultado;

    resultado = (float)a / b;//casteo
    return resultado;
}


float hacerMultiplicacion(float a, float b)
{
    float resultado;

    resultado =(float)a * b;//casteo
    return resultado;
}


int hacerFactorial(int a)
{
    int i;
    int factor=1;//a

    for(i=a; i>=1; i--)
    {
        factor=factor*i;
    }
    return factor;
}
