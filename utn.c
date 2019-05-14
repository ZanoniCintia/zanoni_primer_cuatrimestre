#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {

        do
        {
            printf("%s",msg);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1] = '\0';
            if(strlen(bufferStr)>=minimo && strlen(bufferStr) <maximo)
            {
                strncpy(resultado,bufferStr,maximo);
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",msgError);
        }while(reintentos>=0);
    }
    return retorno;
}

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado)
{
    int retorno = -1;
    char bufferStr[4096];
    if(msg != NULL && msgError != NULL && minimo < maximo && reintentos>=0 && resultado != NULL)
    {
        if(!getString(msg,msgError,minimo,maximo,reintentos,bufferStr))
        {
            if(isValidName(bufferStr))
            {
                strncpy(resultado, bufferStr,maximo);
                retorno = 0;
            }
        }

    }
    return retorno;
}


int isValidName (char* cadena)
{
    int retorno = TRUE;
    int i;
    for( i=0 ; cadena[i] != '\0'  ; i++)
    {
        if((cadena[i] > 'Z' || cadena[i] < 'A') && (cadena[i] > 'z' || cadena[i] < 'a')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"

int isValidInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}

int getInt(
    char *mensaje,
    char *mensajeError,
    int minimo,
    int maximo,
    int reintentos,
    int *resultado)
{
    int buffer; //variables que no estan validadas = buffer
    int retorno = -1;
    int i;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        for(i=0; i<= reintentos; i++)
        {
            printf("%s\n", mensaje);//imprimir mensaje
            //fflush(stdin);
            __fpurge(stdin);
            scanf("%d", &buffer);
            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
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

int getFloat(
char *mensaje,
char *mensajeError,
float minimo,
float maximo,
int reintentos,
float *resultado)
{
    float buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &buffer);
            if(isValidInt(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
            reintentos--;
        }while(reintentos >=0);
    }
    return retorno;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero >= minimo && numero <= maximo)
    {
        return 1;
    }
    return 0;
}

int getChar(char *mensaje, char *mensajeError, char minimo, char maximo, int reintentos, char *resultado)
{
    char buffer;
    int retorno = -1;

    if(mensaje != NULL && mensajeError != NULL && resultado != NULL && maximo >= minimo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);

            __fpurge(stdin);

            scanf("%c", &buffer);

            if(isValidChar(buffer, maximo, minimo))
            {
                *resultado = buffer;
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }while(reintentos--);
    }
    return retorno;
}

int isValidChar(char letra, char maximo, char minimo)
{
    if(letra >= minimo && letra <= maximo)
    {
        return 1;
    }
    return 0;
}

int isValidArrayInt(int numero, int maximo, int minimo) //las funcionjes con is devuelven "TRUE" or "FALSE"
{
    if(numero >= minimo && numero <=maximo)
    {
        return 1;
    }
        return 0;
}



int getArrayInt(    char *msg,
                    char *msgError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int *arrayResultado,
                    int limite)
{
    int retorno = -1;
    int j = 0;
    int buffer;

    if(msg != NULL && msgError != NULL && arrayResultado != NULL && maximo >= minimo && reintentos >= 0 && limite > 0)
    {

        for(j = 0; j < limite; j++)
        {
            getInt(msg,msgError,minimo, maximo, reintentos, &buffer);
            *(arrayResultado+j) = buffer;
            retorno = 0;
        }

    }
    return retorno;
}



int printArrayInt(int *arrayResultado, int limite)
{
    int i;
    for(i = 0; i<limite; i++)
    {
        printf("%d\n", arrayResultado[i]);
    }
    return 0;
}

int doSwap(int *primerValor, int *segundoValor)
{
    int aux;
    aux = *primerValor;
    *primerValor = *segundoValor;
    *segundoValor = aux;
    return 0;
}

int ordenarArray(char *vector[10][50], int limite)
{
    int i;
    int flagSwap;
    char aux[1];

    do
    {
        flagSwap = 0;
        for(i = 0; i <limite-1; i++)     //int aEdades[10] = {8,1,0,4,9,5,2,3,6,7};
        {
            if(strcmp(vector[i][0], vector[i+1][0]) > 0)
            {
                strncpy(aux, vector[i][0], limite);
                strncpy(vector[i+1][0], vector[i][0], limite);
                strncpy(vector[i][0],aux, limite);
                flagSwap = 1;
            }
        }
    }while(flagSwap);

    return 0;
}



int isValidLengthString(char* buffer, int minimo, int maximo)
{
    int retorno = 1;
    int lengthBuffer;
    lengthBuffer = strlen(buffer);

    if(lengthBuffer >= minimo && lengthBuffer < maximo)
    {
        retorno = 0;
    }

    return retorno;
}


int encontrarNombre(char sArray[][50],char *nombre , int limite)
{
    int i;
    int retorno = -1;

    for(i = 0; i < limite; i++)
    {
        if(strcmp(sArray[i], nombre) == 0)
        {
            retorno = i;
        }
    }
    return retorno;
}


int encontrarVacio(char sArray[][50], int limite)
{
    int i;
    int retorno = -1;

    for(i = 0; i < limite; i++)
    {
        if((strcmp(sArray[i], "\0") == 0))
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}

int inicializar(char sArray[][50], int limite)
{
    int i;
    for(i = 0; i < limite; i++)
    {
        strncpy(sArray[i], "\0", limite);
    }

    return 0;
}

int printArrayArray(char aString[][50], int limite)
{
    int i;

    for (i = 0; i < limite; i++)
    {
        printf("%s\n", aString[i]);
    }
    return 0;
}

