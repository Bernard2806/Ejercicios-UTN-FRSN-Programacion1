#include <stdio.h>
#include <stdlib.h>

// Prototipo de funciónes
int sumaPorPunteros(int *a, int *b);
void mostrarPunteros(int *a, int *b);
void mostrarValores(int a, int b);

int main()
{
    // Variables enteras
    int valorA = 5, valorB = 10, suma = 0;

    // Variables punteros
    int *punteroA = &valorA, *punteroB = &valorB;

    // Mostrar valores iniciales
    printf("Valores:\n");
    mostrarValores(valorA, valorB);
    mostrarPunteros(punteroA, punteroB);
    getchar(); // Espera a que el usuario presione una tecla

    printf("Suma de los valores a través de punteros: %d\n", sumaPorPunteros(punteroA, punteroB));
    getchar(); // Espera a que el usuario presione una tecla
    return 0;
}

int sumaPorPunteros(int *a, int *b)
{
    return *a + *b; // Suma de los valores apuntados por los punteros
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