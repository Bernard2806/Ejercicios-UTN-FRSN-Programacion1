#include <stdio.h>

// La diferencia entre este código y el anterior es que aquí se inserta un valor en la posición 6, mientras que en el anterior se inserta en la posición 0.
// En este caso, el valor 5 se inserta en la posición 6, desplazando los elementos a la derecha.
// Esto significa que el nuevo arreglo será {10, 20, 30, 40, 50, 5}.
// Esto consume menos tiempo y espacio, ya que se están desplazando menos elementos.

int main(){

    // Paso 1: Declarar arreglo y cantidad de elementos
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    // Paso 2: Leer el valor y la posición de Inserción
    int val = 5;
    int pos = 6;

    // Paso 3: Desplazar elementos a la derecha
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Paso 4: Insertacion el nuevo valor
    arr[pos] = val;
    n++; // Incrementar el tamaño del arreglo

    return 0;
}