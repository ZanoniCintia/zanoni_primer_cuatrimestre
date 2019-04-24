#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "empleado.h"
#include <string.h>
#define LEN_LISTA    100

int emp_initArray(Empleado* arrayEmpleados ,int limite)
{
    int i;
    int retorno=-1;

    if(arrayEmpleados!=NULL && limite>0)
    {
        for (i=0;i<limite;i++)
        {
            arrayEmpleados[i].isEmpty= 1;

        }
        retorno =0;
    }
    return retorno;
}
int emp_lugarLibreArray(Empleado* arrayEmpleados,int limite,int*indice)
{
    int i;
    int retorno=-1;

    if(arrayEmpleados!=NULL && indice!=NULL && limite>0)
    {
        for (i=0;i<limite;i++)
        {
            if(arrayEmpleados[i].isEmpty== 1)
            {
                *indice=i;
                retorno =1;
                break;
            }
    }
        retorno =0;
    }
    return retorno;
}
int emp_buscarPorNombre(Empleado* arrayEmpleados, int limite,char*nombre,int*indice)
{
    int i;
    int retorno=-1;
    if(arrayEmpleados!=NULL && limite>0 && nombre!=NULL && indice!=NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(strcmp(arrayEmpleados[i].nombre,nombre)==0)
            {
                *indice=i;
                retorno=1;
                break;
            }
        }
    retorno =0;
    }
    return retorno;
}
