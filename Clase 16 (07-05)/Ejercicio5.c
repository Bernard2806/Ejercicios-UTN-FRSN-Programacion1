#include <stdio.h>

// Prototipo de funciones
void invertirInPlace(int *arr, int size);
void mostrarArray(int arreglo[], int largo);

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int *p = arr;

    printf("Array original: \n");
    mostrarArray(arr, size); // Muestra el array original



    printf("Array invertido: \n");
    mostrarArray(arr, size); // Muestra el array invertido
    return 0;
}

void invertirInPlace(int *arr, int size)
{

}

void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n\n");
}