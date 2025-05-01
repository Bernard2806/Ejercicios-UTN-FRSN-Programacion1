#include <stdio.h>

int main()
{
    // Array original con algunos valores desordenados
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, min_idx, temp;
    // 11 34 25 12 22 64 90  primera pasada
    // 11 12 25 34 22 64 90  segunda pasada
    printf("Array original: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        // Encontrar el elemento mínimo en el array no ordenado
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Intercambiar el elemento mínimo encontrado con el primer elemento
        if (min_idx != i)
        {
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }

        // Mostrar el estado del array después de cada pasada
        printf("Después de pasada %d: ", i + 1);
        for (int k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    printf("Array ordenado: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}