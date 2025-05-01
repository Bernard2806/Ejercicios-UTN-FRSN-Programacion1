#include <stdio.h>

int main()
{
    // Array original con algunos valores desordenados
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, temp;

    // Creamos una copia del array original
    int arrFlag[n];
    for (i = 0; i < n; i++)
    {
        arrFlag[i] = arr[i];
    }

    // Implementación de Bubble Sort con Flag
    printf("Estado inicial: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arrFlag[i]);
    }
    printf("\n");

    int swapped; // Bandera para detectar si hubo intercambios

    // Bucle externo: n-1 pasadas
    for (i = 0; i < n - 1; i++)
    {
        // printf("Pasada %d:\n", i+1);
        swapped = 0; // Inicializar bandera como falso al inicio de cada pasada

        // Bucle interno: comparar elementos adyacentes
        for (j = 0; j < n - i - 1; j++)
        {
            // Si el elemento actual es mayor que el siguiente
            if (arrFlag[j] > arrFlag[j + 1])
            {
                // Intercambiarlos
                temp = arrFlag[j];
                arrFlag[j] = arrFlag[j + 1];
                arrFlag[j + 1] = temp;
                swapped = 1; // Activar bandera porque hubo intercambio

                // Mostrar el estado del array después de cada intercambio
                printf("  Intercambio: arr[%d]=%d y arr[%d]=%d  →  ", j, arrFlag[j + 1], j + 1, arrFlag[j]);
                for (int k = 0; k < n; k++)
                {
                    printf("%d ", arrFlag[k]);
                }
                printf("\n");
            }
        }

        // Si no hubo intercambios en esta pasada, el array ya está ordenado
        if (swapped == 0)
        {
            printf("  ¡No hubo intercambios! El array ya está ordenado.\n");
            break;
        }
    }

    printf("\nArray ordenado con Bubble Sort Con Flag:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arrFlag[i]);
    }
    printf("\n");

    return 0;
}