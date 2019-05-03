#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "Pantalla.h"
#include "Publicidad.h"
#define REINTENTOS 3
#define LEN_LISTA 5
int ordenarMayoraMenor(Pantalla *arrayPantalla,int len);
void valorMayorAdiez(Pantalla *arrayPantalla, int len);
void pubMenorADiezDias(Pantalla *arrayPantalla,Publicidad *arrayPublicidad,int len);
int main()
{
    Pantalla visores[LEN_LISTA];
    Publicidad Marketing[LEN_LISTA];
    int flag=0;
    int posLibre;
    int opcion=0;
    pan_initPantalla(visores,LEN_LISTA);
    pub_initPublicidad(Marketing,LEN_LISTA);


    strcpy(visores[0].direccion,"mitre 750");
    visores[0].isEmpty=0;
    strcpy(visores[0].nombre,"pantalla 1");
    visores[0].precio=1000.20;
    visores[0].tipo=0;
    visores[0].idPantalla=0;

    strcpy(visores[1].direccion,"belgrano 750");
    visores[1].isEmpty=0;
    strcpy(visores[1].nombre,"pantalla 2");
    visores[1].precio=2000.20;
    visores[1].tipo=0;
    visores[1].idPantalla=1;

    strcpy(Marketing[0].archivo,"archivo1.mp4");
    strcpy(Marketing[0].cuit,"20-20056654-5");
    Marketing[0].dias=30;
    Marketing[0].isEmpty=0;
    Marketing[0].idPublicidad=1;
    Marketing[0].idPantalla=0;

    strcpy(Marketing[1].archivo,"archivo2.mp4");
    strcpy(Marketing[1].cuit,"20-22556654-5");
    Marketing[1].dias=3;
    Marketing[1].isEmpty=0;
    Marketing[1].idPublicidad=2;
    Marketing[1].idPantalla=0;


    strcpy(Marketing[2].archivo,"archivo3.mp4");
    strcpy(Marketing[2].cuit,"20-22554454-5");
    Marketing[2].dias=5;
    Marketing[2].isEmpty=0;
    Marketing[2].idPublicidad=3;
    Marketing[2].idPantalla=0;



    flag=1;
    while(opcion!=8)
    {
        getIntInRange(&opcion,"\n1)Alta de pantalla\n2)Modificar datos de pantalla\n3)Baja de pantalla\n"
                      "4)Contratar Publicidad\n5)Mostrar Pantallas\n 6)informe\n 7) filtrar \n8)Salir\n\n    INGRESE OPCION: ","ERROR\n",1,8,3);
        switch(opcion)
        {
            case 1:
            {
                posLibre=pan_findFree(visores,LEN_LISTA);
                if(posLibre>=0)
                {
                    printf("\n----Se encontro lugar----\n");
                    if(!pan_addPan(visores,LEN_LISTA,posLibre,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        flag=1;
                        printf("\n----Se dio de ALTA exitosamente!----\n");
                    }
                    else
                    {
                        printf("\n----No se realizo el ALTA!----\n");
                    }
                }
                else
                {
                    printf("\n----No se encontro lugar libre!----\n");
                }
                break;
            }
            case 2:
            {
                if(flag)
                {
                    if(pan_alter(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----Se modifico exitosamente----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 3:
            {
                if(flag)
                {
                    if(pan_removePantalla(visores,LEN_LISTA,"DATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La BAJA se realizo con exito!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay ALTAS en la NOMINA!----\n");
                }
                break;
            }
            case 4:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                    if(!pub_addPub(Marketing,visores,LEN_LISTA,"\nDATO NO VALIDO\n",REINTENTOS))
                    {
                        printf("\n----La CONTRATACION se realizo con exito!----\n");
                    }
                    else
                    {
                        printf("\n----No pudo CONTRATARSE la pantalla!----\n");
                    }
                }
                else
                {
                    printf("\n----No hay PANTALLAS en la NOMINA!----\n");
                }
                break;
            }
            case 5:
            {
                if(flag)
                {
                    pan_printPantalla(visores,LEN_LISTA);
                }
                break;
            }
            case 6:
            {
                ordenarMayoraMenor(visores,LEN_LISTA);
                pan_printPantalla(visores,LEN_LISTA);
                break;
            }
            case 7:
            {
                //valorMayorAdiez(visores,LEN_LISTA);
                pubMenorADiezDias(visores,Marketing,LEN_LISTA);
                break;
            }

        }
    }
    return 0;
}

int ordenarMayoraMenor(Pantalla *arrayPantalla,int len)
{
    int i;
    int j;
    int retorno =-1;
    Pantalla aux;

    for(i=0;i<len;i++)
    {
        for(j=0;j<=len;j++)
        {
            if(arrayPantalla[i].precio > arrayPantalla[j].precio)
            {
                aux=arrayPantalla[i];
                arrayPantalla[i]=arrayPantalla[j];
                arrayPantalla[j]=aux;
                retorno =0;
            }else if(arrayPantalla[i].precio==arrayPantalla[j].precio)
                    {
                        if(strncmp(arrayPantalla[i].nombre,arrayPantalla[j].nombre,50)<0)
                        {
                            aux=arrayPantalla[i];
                            arrayPantalla[i]=arrayPantalla[j];
                            arrayPantalla[j]=aux;
                            retorno =0;

                        }
                    }
        }


    }

    return retorno;

}

void valorMayorAdiez(Pantalla *arrayPantalla, int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(arrayPantalla[i].precio <=10)
        {
                printf("\nID: %d\nNombre: %s\nDireccion: %s\nPrecio: %.2f\nTipo: %d\n-------",
                arrayPantalla[i].idPantalla,arrayPantalla[i].nombre,arrayPantalla[i].direccion,arrayPantalla[i].precio,arrayPantalla[i].tipo);
        }
    }

}

void pubMenorADiezDias(Pantalla *arrayPantalla,Publicidad *arrayPublicidad,int len)
{
    int i;
    int j;
    int auxPan;
    float precioTotal;
    for(i=0;i<len;i++)
    {
        if(arrayPublicidad[i].dias<=10&& arrayPublicidad[i].isEmpty==0)
        {
            auxPan=arrayPublicidad[i].idPantalla;
            j=pan_findPanById(arrayPantalla,len,auxPan);
            precioTotal = arrayPublicidad[i].dias * arrayPantalla[j].precio;
            printf("\n Nombre: %s \n Precio : %.2f \n dias : %d \nprecio total: %.2f\n\n",
            arrayPantalla[j].nombre,arrayPantalla[j].precio,arrayPublicidad[i].dias,precioTotal);

        }

    }
}
