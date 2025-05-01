#include <stdio.h>

int main()
{
    // Array original con algunos valores desordenados
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp;

    printf("Array original:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    printf("Bubble Sort Básico:\n");

    // Creamos una copia del array original para el primer algoritmo
    int arrBasic[n];
    for (i = 0; i < n; i++)
    {
        arrBasic[i] = arr[i];
    }

    // Implementación de Bubble Sort Básico
    printf("Estado inicial: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arrBasic[i]);
    }
    printf("\n");

    // Bucle externo: n-1 pasadas
    for (i = 0; i < n - 1; i++)
    {

        printf("Pasada %d:\n", i + 1);

        // Bucle interno: comparar elementos adyacentes
        for (j = 0; j < n - i - 1; j++)
        {
            // Si el elemento actual es mayor que el siguiente
            if (arrBasic[j] > arrBasic[j + 1])
            {
                // Intercambiarlos
                temp = arrBasic[j];
                arrBasic[j] = arrBasic[j + 1];
                arrBasic[j + 1] = temp;

                // Mostrar el estado del array después de cada intercambio
                printf("  Intercambio: arr[%d]=%d y arr[%d]=%d  →  ", j, arrBasic[j + 1], j + 1, arrBasic[j]);
                for (int k = 0; k < n; k++)
                {
                    printf("%d ", arrBasic[k]);
                }
                printf("\n");
            }
        }
    }

    printf("\nArray ordenado con Bubble Sort Básico:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arrBasic[i]);
    }
    printf("\n\n");

    return 0;
}