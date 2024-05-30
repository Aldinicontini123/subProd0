#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // Abre un archivo llamado "prueba.txt" en modo lectura de texto
    FILE *fichero;
    fichero = fopen("prueba.txt", "rt");

    // Definición de la matriz de transición
    int MT[3][2] = {{1, 0}, {-1, 2}, {-1, 3}};

    // Variable para almacenar el símbolo de entrada
    int simbolo;

    // Estado inicial de la máquina
    int estado = 0;

    // Bucle que se ejecuta hasta que el estado sea 3
    while (estado != 3)
    {
        // Mostrar mensaje para indicar que se está esperando una nueva entrada
        std::cout << "La nueva entrada: ";

        // Leer un carácter del archivo de entrada
        fscanf(fichero, "%c", &simbolo);

        // Convertir el carácter a un número entero
        simbolo = simbolo - '0';

        // Mostrar el símbolo de entrada leído
        std::cout << "es: " << simbolo << "\n";

        // Realizar una transición de estado basada en la matriz de transición
        estado = MT[estado][simbolo];

        // Mostrar el nuevo estado después de la transición
        std::cout << estado << "\n";
    }

    // Cerrar el archivo de entrada
    fclose(fichero);

    // Devolver 0 como código de salida
    return 0;
}

