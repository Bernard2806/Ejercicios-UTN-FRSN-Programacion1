#include <stdio.h>

// Prototipo de funciones
void recorrerArrayConPunteros(int *array, int size);

int main()
{
    int array[5] = {10, 20, 30, 40, 50};
    int size = sizeof(array) / sizeof(array[0]); // Calcula el tamaño del array

    int *p = array; // Inicializa puntero p con la dirección del primer elemento de array

    recorrerArrayConPunteros(p, size); // Llama a la función imprimir pasando el puntero y el tamaño del array

    return 0;
}

void recorrerArrayConPunteros(int *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Elemento %d: %d\n", i, *(array + i)); // Accede a los elementos del array usando punteros
    }
}