#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    int num; // Variable para almacenar el número ingresado

    // Pedimos al usuario que ingrese un número
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    printf("\n"); // Salto de línea

    // Primero, verificamos si el número es 0
    if (num == 0)
    {
        printf("El numero es 0");
    }
    else
    {
        // Determinamos si es par o impar
        if (num % 2 == 0)
        {
            printf("El numero es par");
        }
        else
        {
            printf("El numero es impar");
        }

        // Determinamos si es positivo o negativo
        if (num > 0)
        {
            printf(" y positivo");
        }
        else
        {
            printf(" y negativo");
        }
    }

    return 0; // Fin del programa, todo salió bien
}
