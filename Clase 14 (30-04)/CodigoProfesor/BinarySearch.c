#include <stdio.h>

int busquedaBinaria(int arr[], int n, int elemento, int *comparaciones)
{
    // comparaciones psa por referencia
    int izquierda = 0;
    int derecha = n - 1;
    *comparaciones = 0;

    while (izquierda <= derecha)
    {
        int medio = izquierda + (derecha - izquierda) / 2;

        (*comparaciones)++;
        if (arr[medio] == elemento)
            return medio;

        if (arr[medio] < elemento)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparaciones = 0;
    int elemento, resultado;

    printf("Arreglo ordenado: \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    elemento = 23;
    resultado = busquedaBinaria(arr, n, elemento, &comparaciones);

    if (resultado != -1)
        printf("El elemento %d se encontró en la posición %d\n", elemento, resultado);
    else
        printf("El elemento %d no se encontró en el arreglo\n", elemento);

    printf("Número de comparaciones realizadas: %d\n", comparaciones);

    // Buscar un elemento que no existe
    elemento = 42;
    resultado = busquedaBinaria(arr, n, elemento, &comparaciones);

    if (resultado != -1)
        printf("El elemento %d se encontró en la posición %d\n", elemento, resultado);
    else
        printf("El elemento %d no se encontró en el arreglo\n", elemento);

    printf("Número de comparaciones realizadas: %d\n", comparaciones);

    return 0;
}