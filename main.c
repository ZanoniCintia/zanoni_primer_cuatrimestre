#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int indicarOperacion();
int pedirNumero();
int suma(int primerNumero,int segundoNumero);
int resta(int primerNumero,int segundoNumero);
int multiplicacion(int primerNumero, int segundoNumero);
float division(int primerNumero, int segundoNumero);



int main(void)
{
    int operacionSeleccionada;
    int primerNumero;
    int segundoNumero;
    int resultado;

    primerNumero=pedirNumero();
    segundoNumero=pedirNumero();
    operacionSeleccionada = indicarOperacion();

    switch(operacionSeleccionada)
    {
        case 1:
            printf("eligio suma");
            resultado = suma(primerNumero,segundoNumero);
            printf("\n la suma entre %d y %d es %d: ",primerNumero,segundoNumero,resultado);
            break;
        case 2:
            printf("\n eligio resta");
            resultado =resta(primerNumero,segundoNumero);
            printf("\n la resta entre %d y %d es %d: ",primerNumero,segundoNumero,resultado);
            break;
        case 3:
            printf("\n eligio multiplicacion");
            resultado = multiplicacion(primerNumero,segundoNumero);
            printf("\n la multiplicacion entre %d y %d es %d : ",primerNumero,segundoNumero,resultado);
            break;
        case 4:
            printf("\n eligio division");
            resultado = division(primerNumero,segundoNumero);
            printf("\n la division entre %d y %d es %f :",primerNumero,segundoNumero,(float) resultado);
            break;
        case 5:
            printf("\n eligio salir ");

            break;
    }

    return 0;

}

int indicarOperacion()
{
    int operaciones;
    if(operaciones!=5)
    {
        printf("\n0 <calculadora> elija una operacion: ");
        printf("\n1 suma ");
        printf("\n2 resta ");
        printf("\n3 multiplicacion ");
        printf("\n4 division ");
        printf("\n5 salir ");
        printf("\n elija una opcion : ");
        scanf("%d",&operaciones);
    }
    return operaciones;
}
int pedirNumero()
{
    int unNumero;
    printf("ingrese un numero: ");
    scanf("%d",&unNumero);
    return unNumero;
}

int suma(int primerNumero,int segundoNumero)
{
    int resultado;
    resultado = primerNumero + segundoNumero;

    return resultado;
}
int resta(int primerNumero,int segundoNumero)
{
    int resultado;
    resultado = primerNumero - segundoNumero;
    return resultado;
}
int multiplicacion(int primerNumero, int segundoNumero)
{
    int resultado;
    resultado = primerNumero * segundoNumero;
    return resultado;

}
float division(int primerNumero,int segundoNumero)
{
    float resultado;
    resultado=primerNumero/segundoNumero;
    return resultado;
}


