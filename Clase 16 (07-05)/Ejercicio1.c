#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciónes
void swap(int *a, int *b);
void mostrarPunteros(int *a, int *b);
void mostrarValores(int a, int b);

int main()
{
    int valorA = 5, valorB = 10;

    int *punteroA = &valorA, *punteroB = &valorB;

    printf("Valores iniciales:\n");
    mostrarValores(valorA, valorB);
    mostrarPunteros(punteroA, punteroB);
    getchar(); // Espera a que el usuario presione una tecla

    printf("Intercambiando valores...\n");
    swap(punteroA, punteroB);
    getchar(); // Espera a que el usuario presione una tecla

    printf("Valores después del intercambio:\n");
    mostrarValores(valorA, valorB);
    mostrarPunteros(punteroA, punteroB);
    getchar(); // Espera a que el usuario presione una tecla

    return 0;
}

// Función para intercambiar los valores de dos enteros en base a punteros
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para mostrar los valores de dos enteros en base a punteros
void mostrarPunteros(int *a, int *b)
{
    printf("Valores relacionados con punteros:\n");
    printf("Dirección A: %p\n", (void *)a);
    printf("Dirección B: %p\n", (void *)b);
    printf("Valor A (En base al puntero): %d\n", *a);
    printf("Valor B (En base al puntero): %d\n", *b);
}

// Función para mostrar los valores de dos enteros directamente
void mostrarValores(int a, int b)
{
    printf("Valores directo de variables:\n");
    printf("Valor A: %d\n", a);
    printf("Valor B: %d\n", b);
}