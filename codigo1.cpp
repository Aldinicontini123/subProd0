#include <iostream>
int main(int argc, char **argv)
{
    // filas representa 3 estados: 0, 1, 2, mientras que el de aceptacion es 3 y el estado de error es -1
    // columnas representan las entradas (0 y 1)
    // Este analizador solo puede leer tokens de un solo digito binario
    int MT[3][2] = {
        {1, 0},
        {-1, 2}, 
        {-1, 3}
    };
    int simbolo;
    int estado = 0;
    while (estado != 3)
    {
        std::cout << "dame la nueva entrada: ";
        std::cin >> simbolo;
        estado = MT[estado][simbolo];
        std::cout << estado << "\n";
    }
    return 0;
}