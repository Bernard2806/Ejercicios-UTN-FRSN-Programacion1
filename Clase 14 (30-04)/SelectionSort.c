#include <stdio.h>

// Prototipos de funciónes
void mostrarArreglo(int arr[], int n);

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i, j, min_idx, temp;

    printf("Arreglo original: ");
    mostrarArreglo(arr, n);

    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        
    }

    return 0;
}

void mostrarArreglo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}