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

int main()
{
    int num[10];
}