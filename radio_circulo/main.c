#include <stdio.h>
#include <stdlib.h>
float pedirNumero();
float calculaRadioCirculo(float radio);
int main()
{
    float numeroIngresado;
    float area;
    numeroIngresado=pedirNumero();
    area=calculaRadioCirculo(numeroIngresado);
    printf("el area es %.2f : ",area);


    return 0;
}
float pedirNumero()
{
    float Numero;
    printf("ingrese un numero : ");
    scanf("%f",&Numero);
    return Numero;
}
float calculaRadioCirculo(float radio)
{
    float resultado;
    resultado= 3.14 * radio * radio;
    return resultado;


}
