




/** \brief solicita un numero y devuleve el resultado
 * \param mensaje a ser mostrado
 * \return el numero ingresado
 *
 */
int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
/**\brief  solicita un numero y devulve el resultado
 * \param mensaje a ser mostrado
 * \return el numero ingresado
 */

float getFloat(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
/** \brief solicita un caracter y devuelve el resultado
 * \param mensaje a ser mostrado
 * \return el caracter ingresado
 */

char getchar(char mensaje[])
{
    char auxiliar;
    printf("%s",amensaje);
    fflush(stdin);
    //fpurge(stdin);linux
    scanf("%s",&auxiliar);
    return auxiliar;
}
