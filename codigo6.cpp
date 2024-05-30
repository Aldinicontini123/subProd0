#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// Definición de tokens
enum Token
{
    TOKEN_IDENTIFICADOR,
    TOKEN_ASIGNACION,
    TOKEN_ENTERO,
    TOKEN_SUMA,
    TOKEN_FIN
};
// Función para obtener el siguiente token
enum Token obtenerToken(char *lexema)
{
    // checamos que el caracter actual sea un token 
    // lo que hacemos es iterar sobre cada caracter y vemos si el lexema es token o no y a que token
    // corresponde
    int c = getchar();
    if (c == 'a')
    {
        strcpy(lexema, "a");
        return TOKEN_IDENTIFICADOR;
    }
    else if (c == '=')
    {
        strcpy(lexema, "=");
        return TOKEN_ASIGNACION;
    }
    else if (isdigit(c))
    {
        ungetc(c, stdin);
        scanf("%s", lexema);
        return TOKEN_ENTERO;
    }
    else if (c == '+')
    {
        strcpy(lexema, "+");
        return TOKEN_SUMA;
    }
    else if (c == '\n' || c == EOF)
    {
        return TOKEN_FIN;
    }
    else
    // podriamos dar error de sintaxis ya que dicho caracter (lexema) no se encuentra en nuestros tokens
    {
        strcpy(lexema, "DESCONOCIDO");
        return TOKEN_FIN;
    }
}
int main()
{
    char lexema[100];
    enum Token token;
    std::cout << "escribe: ";
    // declaramos un arreglo de caracteres (que contendra el lexema), despues llamamos la funcion la cual
    // hara un getchar (entrada del usuario) y comparara dicho caracter con nuestros posibles tokens y copia el 
    // char al array de lexema para posteriormente imprimirlo junto con el token devuelto
    do
    {
        token = obtenerToken(lexema);
        printf("Token: %d, Lexema: %s\n", token, lexema);
    } while (token != TOKEN_FIN);

    return 0;
}