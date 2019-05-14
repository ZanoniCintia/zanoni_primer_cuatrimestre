#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);
int isValidChar(char letra, char maximo, char minimo);
int isValidArrayInt(int numero, int maximo, int minimo);
int getArrayInt(    char *msg,
                    char *msgError,
                    int maximo,
                    int minimo,
                    int reintentos,
                    int *arrayResultado,
                    int limite);
int printArrayInt(int *arrayResultado, int limite);
int doSwap(int *primerValor, int *segundoValor);
int ordenarArray(char *vector[10][50], int limite);
int getString(  char *mensaje,
                char *mensajeError,
                int minimo,
                int maximo,
                int reintentos,
                char *sString);
int isValidLengthString(char* buffer, int minimo, int maximo);
int encontrarNombre(char sArray[][50],char *nombre , int limite);
int encontrarVacio(char sArray[][50], int limite);
int inicializar(char sArray[][50], int limite);
int printArrayArray(char aString[][50], int limite);


