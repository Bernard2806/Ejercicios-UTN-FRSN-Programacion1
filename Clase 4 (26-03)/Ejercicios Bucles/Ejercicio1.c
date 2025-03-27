#include <stdio.h> // Incluimos la librería estándar para las funciones de entrada y salida

int main()
{
    int sumaTotal = 0; // Iniciamos la variable para acumular la suma de los números

    // Empezamos el bucle "for" que va desde 1 hasta 10 (inclusive)
    for (int i = 1; i <= 10; i++)
    {
        printf("%d\n", i); // Imprimimos cada número en la secuencia (1, 2, 3,... 10)
        sumaTotal += i;    // Sumamos el número "i" a la variable sumaTotal
    }

    // Imprimimos la suma total después de haber sumado todos los números
    printf("\nLa suma total es: %d", sumaTotal);
    return 0; // Fin del programa
}