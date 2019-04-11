#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Numero;
    int maximo;
    int minimo;
    int acumulador;
    int i;

    printf("ingrese un numero : ");
    scanf("%d",&Numero);
    maximo=Numero;
    minimo=Numero;
    acumulador=Numero;

    for(i=0;i<4;i++)
    {
        printf("ingrese un numero : ");
        scanf("%d",&Numero);
        acumulador = acumulador + Numero;

        if(Numero>maximo)
        {
            maximo=Numero;
        }
        if(Numero<minimo)
        {
            minimo=Numero;
        }
    }

     printf("el promedio de los numeros ingresados es : %.2f \n",(float)acumulador/5);
     printf("el numero maximo ingresado fue %d  y el minimo fue %d : ",maximo,minimo);



    return 0;
}

