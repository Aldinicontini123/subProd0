#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Definición de tokens
enum Token
{
    TOKEN_LETRA_A,
    TOKEN_LETRA_B,
    TOKEN_FINAL,
    TOKEN_DESCONOCIDO
};

int main(int argc, char **argv)
{
    // Apertura del archivo "prueba.txt" en modo de lectura
    FILE *fichero;
    fichero = fopen("prueba.txt", "rt");
    if (!fichero)
    {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;  // Termina el programa con un código de error
    }

    // Definición de una matriz de transición de estados
    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}};

    char simbolo;
    int estado = 0;

    // Bucle de procesamiento: lee caracteres del archivo y realiza transiciones
    while (estado != 3 && fscanf(fichero, "%c", &simbolo) != EOF)
    {
        // Imprime el símbolo leído en esta iteración
        std::cout << "La nueva entrada: " << simbolo << std::endl;

        // Determina el token asociado al símbolo leído
        Token token;
        if (simbolo == 'a')
        {
            token = TOKEN_LETRA_A;
        }
        else if (simbolo == 'b')
        {
            token = TOKEN_LETRA_B;
        }
        else if (simbolo == '\n' || simbolo == '\r' || simbolo == EOF)
        {
            token = TOKEN_FINAL;
        }
        else
        {
            token = TOKEN_DESCONOCIDO;
        }

        // Realiza la transición de estado según la matriz de transición
        estado = MT[estado][token];

        // Imprime el token y el nuevo estado
        std::cout << "Token: " << token << ", Estado: " << estado << std::endl;
    }

    // Cierra el archivo después de procesar todos los caracteres
    fclose(fichero);

    return 0;  // Termina el programa sin errores
}
