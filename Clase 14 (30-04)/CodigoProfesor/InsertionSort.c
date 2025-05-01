#include <stdio.h>

int main()
{
    // Array original con algunos valores desordenados
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // Array ordenado: 11 12 22 25 34 64 90

    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, key;

    printf("Array original: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        key = arr[i]; // key = 22
        j = i - 1;    // j = 3 i= 4

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Mostrar el estado del array después de cada pasada
        printf("Después de pasada %d: ", i);
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