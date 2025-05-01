#include <stdio.h>

int main()
{

    // Paso 1: Declarar arreglo y cantidad de elementos
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    // Paso 2: Leer el valor y la posición de Inserción
    int val = 25;
    int pos = 2;

    // Paso 3: Desplazar elementos a la derecha
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    // Paso 4: Insertacion el nuevo valor
    arr[pos] = val;
    n++; // Incrementar el tamaño del arreglo

    return 0;
}
