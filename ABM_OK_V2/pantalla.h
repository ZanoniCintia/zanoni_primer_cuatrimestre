#ifndef PANTALLA_H_INCLUDED
#define PANTALLA_H_INCLUDED

typedef struct
{
    char nombre[20];
    char direccion[50];
    int isEmpty; // lleno=0 ; vacio=1
    int idPantalla; //autoincremental
    float precio;
    char tipo;

}Pantalla;

int pan_Inicializar(Pantalla *arrayPantalla, int cantidad);
int pan_buscarLibre(Pantalla *arrayPantalla, int cantidad, int *devuelve);
int pan_AltaPantalla(Pantalla *arrayPantalla, int cantidad, int posLibre);
void pan_mostrarArray(Pantalla *arrayPantalla, int cantidad);
int pan_baja(Pantalla *arrayPantalla, int cantidad);
int pan_buscarEnArray (Pantalla *arrayPantalla, int cantidad, int *pantallaEncontrada,char *textoAMostrar);
int getStringf(float *pResult, char *pMsg, char *pMsgError, int min, int max, int intentos);


#endif // PANTALLA_H_INCLUDED
