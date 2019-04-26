#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "funciones_string.h"

int pan_Inicializar(Pantalla *arrayPantalla, int cantidad)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        arrayPantalla[i].isEmpty=1;
        retorno=0;
    }

    return retorno;
}

int pan_buscarLibre(Pantalla *arrayPantalla, int cantidad, int *devuelve)
{
    int retorno=-1;
    for (int i=0; i<cantidad;i++)
    {
        if (arrayPantalla[i].isEmpty==1)
        {
            *devuelve=i;
            retorno=0;
            break;
        }

        retorno=1;
    }

    return retorno;
}

int pan_AltaPantalla(Pantalla *arrayPantalla, int cantidad, int posLibre)
{
    int retorno=-1;
    if (getString(arrayPantalla[posLibre].nombre,"ingrese un nombre: ","error, vuelva a ingresar\n\n",2,20,2)==0)
    {
        if (getString(arrayPantalla[posLibre].direccion,"Ingrese el direccion:","error, vuelva a intentar\n\n",2,20,2)==0)
        {
            if(getStringf(&arrayPantalla[posLibre].precio, "ingrese precio","error, vuelva a ingresar\n\n",2,30,2)==0)
            {
               if(getString(&arrayPantalla[posLibre].tipo,"ingrese tipo <LED/LCD>","error, vuelva a ingresar\n\n",2,30,2)==0)
               {
                    if(arrayPantalla[posLibre].tipo!='L' && arrayPantalla[posLibre].tipo!='D')
                    {
                        printf("INGRESO INCORRECTO");
                    }
                    arrayPantalla[posLibre].isEmpty=0;
                    retorno=0;
               }
            }
        }
    }
    else
    {
        retorno=1;
    }

    return retorno;
}

void pan_mostrarArray(Pantalla *arrayPantalla, int cantidad)
{
    int i;

    for (i=0; i<cantidad;i++)
    {
        if(arrayPantalla[i].isEmpty==0)
        {
            printf("posicion %d :estado %d\n", i, arrayPantalla[i].isEmpty);
            printf("posicion %d :nombre %s\n", i, arrayPantalla[i].nombre);
            printf("posicion %d :direccion %s\n", i, arrayPantalla[i].direccion);
            printf("posicion %d :precio %f\n", i, arrayPantalla[i].precio);
            printf("posicion %d :tipo %c\n", i, arrayPantalla[i].tipo);
        }

        //printf("Press 'Enter' to continue: ... ");
        //while ( getchar() != '\n');
    }

}
int pan_baja(Pantalla *arrayPantalla, int cantidad)
{

    int posPantalla;
    switch (pan_buscarEnArray(arrayPantalla, cantidad,&posPantalla,"ingrese nombre de pantalla a eliminar"))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            arrayPantalla[posPantalla].isEmpty=1;
            printf("la pantalla borrada es: %s\n\n",arrayPantalla[posPantalla].nombre);

        }
        break;
    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int pan_buscarEnArray (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada,char *textoAMostrar)
{
    int retorno=1;
    Pantalla auxPantalla;

    if (getString(auxPantalla.nombre,textoAMostrar,"Vuelva a ingresar",2,20,3)==0)
    {
        //auxEmpleados.nombre=tolower(auxEmpleados.nombre);
        retorno=-1;
        for(int i=0;i<cantidad;i++)
        {
            //empleados[i].nombre=tolower(empleados[i].nombre);
            if (strcmp(arrayPantalla[i].nombre, auxPantalla.nombre)==0)
            {
                retorno=0;
                *pantallaEncontrada=i;
                break;
            }
        }
    }
    return retorno;
}

int pan_modificacion(Pantalla *arrayPantalla, int cantidad)
{

     int posPantalla;
    switch (pan_buscarEnArray(arrayPantalla, cantidad,&posPantalla,"ingrese el nombre de la pantalla a modificar"))
    {
    case 0:
        if (arrayPantalla[posPantalla].isEmpty==0)
        {
            printf("hubo coincidencia\n\n");
            if (getString(arrayPantalla[posPantalla].nombre,"ingrese el nuevo nombre de la pantalla","error",2,20,2)==0)
            {
                printf("la pantalla modificada es: %s\n\n",arrayPantalla[posPantalla].nombre);
            }

        }
        break;

    case 1:
        printf("no se encontro el nombre y no entro al if");
        break;

    default:
        printf("ingreso al if pero no encontro el nombre");
        break;
    }
    return 1;
}

int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos)
{
    int ret=-1;
    float arrayAuxiliar;
    while(intentos>0)
    {
        printf(pMsg);
        //fflush( stdin ); //LIMPIA BUFFER WINDOWS
        __fpurge(stdin); //LIMPIA BUFFER LINUX
        scanf("%f", &arrayAuxiliar);
        if( pResult != NULL && arrayAuxiliar >= min && arrayAuxiliar <= max)
        {
            *pResult = arrayAuxiliar;

            ret=0;
            break;
        }
        else
        {
            printf(pMsgError);
        }
        intentos--;
    }
    return ret;
}



