#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED


typedef struct
{
    int idEmpleado;
    int isEmpty;
    //--------------------
    char nombre[50];

}Empleado;

int emp_initArray(Empleado* arrayEmpleados,int limite);
int emp_lugarLibreArray(Empleado* arrayEmpleados,int limite,int*indice);
int emp_alta(Empleado* arrayEmpleados, int limite,int id);
int emp_baja(Empleado* arrayEmpleados, int limite);
int emp_buscarPorNombre(Empleado* arrayEmpleados, int limite,char*nombre,int*indice);
int emp_ordenarPorNombre(Empleado* arrayEmpleados, int limite);
#endif // EMPLEADO_H_INCLUDED
