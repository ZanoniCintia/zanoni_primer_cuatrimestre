#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD 10

int main()
{
    char nombre[CANTIDAD];
    char buffer[CANTIDAD];
    int i;

    printf("\n ingrese nombre :");
    fgets(buffer,sizeof(nombre),stdin);

    for(i=0; buffer[i]!= '\0';i++)
    {
        printf("%d",i);
        if((buffer[i] <'A' || buffer[i] >'Z') && (buffer[i] <'a' || buffer[i] >'z'))
        {
            printf("error");
            break;
        }
    }


    return 0;
}

