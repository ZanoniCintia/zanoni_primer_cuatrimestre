#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "funciones_string.h"

#define CANTIDAD_PANTALLA 10

int main()
{
    char seguir='s'; //MENU
    int opcion; //MENU
    int valor;
    int posLibre;
    Pantalla pantallas[CANTIDAD_PANTALLA];

    valor=pan_Inicializar(pantallas, CANTIDAD_PANTALLA);

    if (valor==0)
    {
        printf("sistema inicializado correctamente\n\n\n");
    }
    while (seguir=='s')
    {
        printf("\t\tMENU");
        printf("\n\n1-Alta pantalla");
        printf("\n\n2-Mostrar empleado");
        printf("\n\n3-Borrar nombre");
        printf("\n\n4-Salir\n");

        do
        {
            printf("\n\t\tingrese opcion: ");
            scanf("\n%d",&opcion);
        }
        while (opcion<1 || opcion>4);

        switch (opcion)
        {
        case 1:

            if(pan_buscarLibre(pantallas,CANTIDAD_PANTALLA, &posLibre)!=0)
            {
                printf("LLENO\n\n");
            }
            else
            {
                switch (pan_AltaPantalla(pantallas, CANTIDAD_PANTALLA, posLibre))
                {
                case 0:
                    printf("dato ingresado correctamente\n\n");

                    break;
                case 1:
                    printf("dato ingresado INCORRECTAMENTE\n\n");
                    break;
                }
            }
            break;

        case 2:

            pan_mostrarArray(pantallas, CANTIDAD_PANTALLA);
            break;

        case 3:
            if (pan_baja(pantallas, CANTIDAD_PANTALLA)==0)
            {
                printf("exito");
            }
            break;

        case 4:
            seguir='f';
            break;
        }
    }
    return 0;
}
