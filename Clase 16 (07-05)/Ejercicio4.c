#include <stdio.h>

// Prototipo de funciones
int encontrarMaxArrayConPunterosYSinIndices(int *array, int size);
void mostrarArray(int arreglo[], int largo);

int main()
{
    int array[5] = {10, 20, 30, 40, 50};         // Inicializa un array de enteros
    int size = sizeof(array) / sizeof(array[0]); // Calcula el tamaño del array

    int *p = array; // Declara un puntero que apunta al primer elemento del array

    printf("El array es: ");
    mostrarArray(array, size); // Muestra el array

    printf("\nEl maximo es: %d\n", encontrarMaxArrayConPunterosYSinIndices(p, size)); // Encuentra y muestra el máximo del array

    return 0;
}

int encontrarMaxArrayConPunterosYSinIndices(int *array, int size)
{
    int max = *array; // Inicializa max con el primer elemento del array

    for (int i = 1; i < size; i++)
    {
        if (*(array + i) > max) // Compara el elemento actual con max
        {
            max = *(array + i); // Actualiza max si se encuentra un nuevo máximo
        }
    }

    return max; // Devuelve el valor máximo encontrado
}

void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
}