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

// Coloca todos los pares al principio del array y todos los impares al final.
void paresAlPrincipioYImparesAlFinal(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        for (int j = i + 1; j < longitud; j++)
        {
            if (numeros[i] % 2 != 0 && numeros[j] % 2 == 0)
            {
                // Intercambiar los elementos
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
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
    int numerosAleatorios[20];

    cargarArrayConNumerosAleatorios(numerosAleatorios, sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]));

    printf("Los numeros son: \n");
    mostrarArray(numerosAleatorios, sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]));

    paresAlPrincipioYImparesAlFinal(numerosAleatorios, sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]));

    printf("Los numeros pares al principio y los impares al final son: \n");
    mostrarArray(numerosAleatorios, sizeof(numerosAleatorios) / sizeof(numerosAleatorios[0]));

    return 0;
}