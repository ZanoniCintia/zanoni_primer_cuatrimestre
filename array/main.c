#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#define QTY_EMPLEADOS 10
int printArray(char arrayStrn[][50],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%s",arrayStrn[i]);

    }
    return 0;

}
int arrayInicializar(char arrayStrn[][50],int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
       strncpy(arrayStrn[i],"",50);

    }
    return 0;
}
int posicionVacia(char arrayStrn[][50],int limite)
{
    int i;

    int retorno;

    for(i=0;i<limite;i++)
    {
       if(  strcmp(arrayStrn[i],"")==0)
       {
            retorno=i;
            break;
       }

    }
    return retorno;
}
int nombreDuplicado(char arrayStrn [][50],char* nombre,int* nombreExistente,int limite)
{
    int retorno =-1;
    int i;
    for(i=0;i<limite;i++)
    {
        if(strncmp(arrayStrn[i],nombre,limite)==0)
        {
           *nombreExistente=i;
           retorno =0;
           break;
        }
    }
    return retorno;
}
int altaPersonal(char* msg,char* msgError,int minimo,int maximo,int limite,char array[][50],int reintentos)
{
    int retorno=-1;
    int posicionRepetida = -1;
    char buffer[4096];

    if(msg!=NULL,msgError!=NULL,minimo<maximo,reintentos>=0)
    {
        if(posicionVacia(array,limite)!=-1)
        {
            getName(msg,msgError,minimo,maximo,reintentos,&buffer);
            nombreDuplicado(array,buffer,&posicionRepetida,limite);
            if(posicionRepetida==-1)
            {
                strncpy(array[posicionVacia(array,limite)],buffer,maximo);
                retorno =0;
            }
            else
            {
                printf("%s",msgError);
            }
        }

    }
    return retorno;

}
int main()
{
    char auxName[500] = "test";
    int test=-1;
    char arrayNombres[QTY_EMPLEADOS][50];
    strncpy(arrayNombres[0],"juan0",50);
    strncpy(arrayNombres[1],"juan1",50);
    strncpy(arrayNombres[2],"juan2",50);

    nombreDuplicado(arrayNombres,"roberto",&test,50);
    printf("%d", test);
}
