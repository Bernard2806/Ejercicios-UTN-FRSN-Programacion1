#include <stdio.h>

// Prototipo de funciónes
void swap(int *a, int *b);
void mostrar(int *a, int *b);

int main()
{
    int valorA = 5, valorB = 10;

    int *punteroA = &valorA, *punteroB = &valorB;

    printf("Valores iniciales:\n");
    mostrar(punteroA, punteroB);

    printf("Intercambiando valores...\n");
    swap(punteroA, punteroB);

    printf("Valores después del intercambio:\n");
    mostrar(punteroA, punteroB);

    return 0;
}

// Función para intercambiar los valores de dos enteros
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para mostrar los valores de dos enteros
void mostrar(int *a, int *b)
{
    printf("Valor A: %d\n", *a);
    printf("Valor B: %d\n", *b);
}