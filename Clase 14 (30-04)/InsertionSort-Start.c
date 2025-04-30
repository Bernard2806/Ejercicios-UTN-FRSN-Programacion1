#include <stdio.h>

// La diferencia entre este código y el anterior es que aquí se inserta un valor en la posición 0, mientras que en el anterior se inserta en la posición 2.
// En este caso, el valor 5 se inserta en la posición 0, desplazando los elementos a la derecha.
// Esto significa que el nuevo arreglo será {5, 10, 20, 30, 40, 50}.
// Esto consume más tiempo y espacio, ya que se están desplazando más elementos.

int main(){

    // Paso 1: Declarar arreglo y cantidad de elementos
    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    // Paso 2: Leer el valor y la posición de Inserción
    int val = 5;
    int pos = 0;

    // Paso 3: Desplazar elementos a la derecha
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Paso 4: Insertacion el nuevo valor
    arr[pos] = val;
    n++; // Incrementar el tamaño del arreglo

    return 0;
}