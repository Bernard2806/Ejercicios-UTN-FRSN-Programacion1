#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarArrayConNumerosAleatorios(int numeros[], int longitud)
{
    srand(time(NULL)); // Inicializar semilla
    for (int i = 0; i < longitud; i++)
    {
        numeros[i] = rand() % 100 + 1; // Números aleatorios entre 1 y 100
    }
}

void calcularCuadrados(int numeros[], int longitud, int cuadrados[])
{
    for (int i = 0; i < longitud; i++)
    {
        cuadrados[i] = numeros[i] * numeros[i];
    }
}

void mostrarArray(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

int main()
{
    int numeros[20];
    int cuadrado[20];
    int cubo[20];

    cargarArrayConNumerosAleatorios(numeros, 20);

    printf("Los numeros son: \n");
    mostrarArray(numeros, 20);

    calcularCuadrados(numeros, 20, cuadrado);

    printf("Los cuadrados son: \n");
    mostrarArray(cuadrado, 20);

    calcularCuadrados(cuadrado, 20, cubo);

    printf("Los cubos son: \n");
    mostrarArray(cubo, 20);

    return 0;
}