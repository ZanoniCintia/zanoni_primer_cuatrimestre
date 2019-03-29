#include <stdio.h>
#include <stdlib.h>
float isValidInt(float numero, float minimo,float maximo);
float getfloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado);


int main()
{
    float numeroIngresado;
    getfloat("ingrese un numero decimal","error",1.2,10.5,2,&numeroIngresado);
    printf("el numero ingresado es : %f",numeroIngresado);

    return 0;
}

float isValidInt(float numero, float minimo,float maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
        return 0;

}

float getfloat(char *mensaje, char *mensajeError, float minimo, float maximo, int reintentos, float *resultado)
{
    float buffer;
    int  retorno= -1;
    if(mensaje!= NULL && mensajeError != NULL && resultado!= NULL && maximo>=minimo && reintentos>=0)
    {
        do
        {
            printf("%s",mensaje);
            scanf("%f",&buffer);
            if(isValidInt(buffer,maximo,minimo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }else
            {
                printf("%s",mensajeError);
            }
            reintentos--;

        }while(reintentos>=0);
    }return retorno;

}
