#include <stdio.h>

// Función que ordena un arreglo usando el algoritmo de burbujeo (Bubble Sort)

void bubbleSort(int arr[], int n)
{
    // Recorremos el arreglo varias veces
    for (int i = 0; i < n - 1; i++)
    {
        // En cada pasada, comparamos los elementos uno por uno hasta el final menos i
        for (int j = 0; j < n - i - 1; j++)
        {
            // Si el elemento actual es mayor que el siguiente, los intercambiamos
            if (arr[j] > arr[j + 1])
            {
                // Intercambio de valores usando una variable temporal
                int temp = arr[j];        // Guardamos el valor actual
                arr[j] = arr[j + 1];      // El siguiente valor pasa a la posición actual
                arr[j + 1] = temp;        // El valor guardado se coloca en la posición siguiente
            }
        }
    }
}

void mostrarArreglo(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int matriz[5] = {5, 1, 4, 2, 8};

    printf("Arreglo original: ");
    mostrarArreglo(matriz, 5);

    bubbleSort(matriz, 5);
    printf("Arreglo ordenado: ");
    mostrarArreglo(matriz, 5);

    return 0;
}