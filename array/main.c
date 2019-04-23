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
       else
       continue;
    }
    return retorno;
}

int main()
{
    char auxName[500] = "test";
    char arrayNombres[QTY_EMPLEADOS][50];
    strncpy(arrayNombres[0],"juan0",50);
    strncpy(arrayNombres[1],"juan1",50);
    strncpy(arrayNombres[2],"juan2",50);

    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }
    return 0;
}
