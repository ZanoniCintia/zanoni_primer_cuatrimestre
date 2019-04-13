#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
 int isValidDocumento (char* cadena);
 int getDocumento(   char* msg,
                    char* msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char* resultado);


int getString ( char* msg,char* msgError, int minimo,int maximo,int reintentos,  char* resultado)
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
int getDocumento(   char* msg,
                    char* msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char* resultado)
 {
     int retorno = -1;
     char bufferDNI[4096];
     if(msg!= NULL && msgError!=NULL && minimo<maximo && reintentos>=0 && resultado!=NULL)
     {
         if(!getString(msg,msgError,minimo,maximo,reintentos,bufferDNI))
         {
              if(isValidDocumento(bufferDNI))
            {
                strncpy(resultado, bufferDNI,maximo);
                retorno = 0;
            }
         }
     }
 }
 int isValidDocumento (char* cadena)
{
    int retorno=TRUE;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
         if(cadena[i] > '48' || cadena[i] < '57')  )
        {
            retorno = FALSE;
            break;
        }
    }
    return retorno;
}
