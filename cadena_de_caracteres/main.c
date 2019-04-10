#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nombre[257]={'x','o','x','x','\0'};//siempre pongo un lugar mas para poner el /0
    char nombre2[257]="HOLA";
    //sizeof()//que tamaño tiene en memoria
    strncpy(nombre,nombre2,sizeof(nombre));
    printf("\n %s",nombre);
    fgets(nombre,sizeof(nombre),stdin);
    printf("\n %s",nombre);
    strlen()
    return 0;
}
