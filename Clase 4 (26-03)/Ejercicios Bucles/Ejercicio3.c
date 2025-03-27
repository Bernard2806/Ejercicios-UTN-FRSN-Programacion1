#include <stdio.h> // Incluir la librería estándar para usar printf

int main()
{
    int i = 10; // Empezamos con i igual a 10, que será el primer valor que vamos a imprimir

    // Empezamos con un bucle do-while, que siempre se ejecuta al menos una vez
    do
    {
        printf("%d\n", i); // Imprimimos el valor de i
        i--;               // Restamos 1 a i en cada iteración
    } while (i >= 1); // El bucle sigue ejecutándose mientras que i sea mayor o igual a 1

    // Una vez que el bucle termina, imprimimos un mensaje para saber que ya terminó
    printf("\nFin del bucle");

    return 0; // Fin del programa
}