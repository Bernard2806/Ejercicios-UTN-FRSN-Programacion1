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

void paresAlPrincipioYImparesAlFinal(int numeros[], int longitud)
{
    int contador = 0;
    int siguiente = 1;

    while (contador < longitud)
    {
        if (numeros[contador] % 2 != 0 && numeros[siguiente] % 2 == 0)
        {
            int temp = numeros[contador];
            numeros[contador] = numeros[siguiente];
            numeros[contador] = temp;
        }

        siguiente++;

        if (siguiente == longitud)
        {
            siguiente = 1;
            contador++;
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