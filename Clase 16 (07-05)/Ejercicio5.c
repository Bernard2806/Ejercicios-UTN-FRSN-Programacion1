#include <stdio.h>

// Prototipo de funciones
void invertirInPlace(int *arr, int size);
void swap(int *a, int *b);
void mostrarArray(int arreglo[], int largo);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    mostrarArray(arr, size); // Muestra el array original

    invertirInPlace(arr, size); // Invierte el array en su lugar

    printf("Array invertido: \n");
    mostrarArray(arr, size); // Muestra el array invertido
    return 0;
}

// Función para invertir un array en su lugar (in-place)
void invertirInPlace(int *arr, int size)
{
    int *start = arr;          // Puntero al inicio del array
    int *end = arr + size - 1; // Puntero al final del array

    while (start < end) // Mientras el puntero de inicio sea menor que el de fin
    {
        swap(start, end); // Intercambia los valores apuntados por start y end
        start++;          // Mueve el puntero de inicio hacia adelante
        end--;            // Mueve el puntero de fin hacia atrás
    }
}

void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n\n");
}

// Función para intercambiar los valores de dos enteros en base a punteros
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}