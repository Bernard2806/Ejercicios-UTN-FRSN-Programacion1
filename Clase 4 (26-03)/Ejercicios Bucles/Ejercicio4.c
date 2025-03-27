#include <stdio.h> // Importamos la librería estándar para usar printf

int main()
{
    // Bucle principal que recorre los números del 1 al 10
    for (int i = 1; i <= 10; i++)
    {

        // Bucle interno que también recorre los números del 1 al 10
        for (int j = 1; j <= 10; j++)
        {
            // Imprime la multiplicación de i y j
            printf("%d * %d = %d\n", i, j, i * j);
        }

        // Imprime un salto de línea para separar cada tabla de multiplicar
        printf("\n");
    }

    return 0; // Fin del programa
}