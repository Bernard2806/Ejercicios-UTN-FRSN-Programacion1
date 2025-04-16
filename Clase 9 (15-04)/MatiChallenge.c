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
    // i comienza desde el principio del arreglo
    // j comienza desde el final del arreglo
    int i = 0;
    int j = longitud - 1;

    // Usamos un solo while para recorrer el arreglo desde ambos extremos
    while (i < j)
    {
        // Verificamos si el número en la posición i (izquierda) es par
        int izquierdoEsPar = numeros[i] % 2 == 0;

        // Verificamos si el número en la posición j (derecha) es impar
        int derechoEsImpar = numeros[j] % 2 != 0;

        // Si el número de la izquierda ya es par, está en la posición correcta → avanzar
        if (izquierdoEsPar)
        {
            i++; // avanzamos a la siguiente posición desde la izquierda
        }
        // Si el número de la derecha ya es impar, está en la posición correcta → retroceder
        else if (derechoEsImpar)
        {
            j--; // retrocedemos desde la derecha
        }
        // Si el de la izquierda es impar y el de la derecha es par → están mal ubicados → intercambiamos
        else
        {
            // Intercambio de posiciones usando una variable temporal
            int temp = numeros[i];
            numeros[i] = numeros[j];
            numeros[j] = temp;

            // Después de intercambiar, ambos números ya están en su lugar
            // Así que movemos ambos índices
            i++;
            j--;
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