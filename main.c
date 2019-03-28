#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje,char *mensajeError,int minimo,int maximo, int reintentos, int *resultado);


int isValidInt(int numero,int minimo,int maximo);





int main()
{
    int numeroIngresado;

    getInt("ingrese el numero","error",0,100,2,&numeroIngresado);
    printf("el numero ingresado es %d  :",numeroIngresado);
    return 0;
}

int isValidInt(int numero,int minimo,int maximo)
{
    if(numero>=minimo && numero<=maximo)
    {
        return 1;
    }
        return 0 ;


}



int getInt(char *mensaje,char *mensajeError,int minimo,int maximo, int reintentos, int *resultado)
{
    int buffer;
    int i;
    int retorno=-1;

    if(mensaje != NULL && mensajeError != NULL && resultado!= NULL && maximo>=minimo && reintentos>=0)
    {
        for(i=0;i<=reintentos;i++)
        {
            printf("%s", mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer,minimo,maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }


    }


    return retorno;
}
