#include <stdio.h>

void cargarMatrizConNumerosAleatorios(int numeros[10][10])
{
    srand(time(NULL)); // Inicializar semilla

    for (int f = 0; f < 10; f++)
    {
        for (int c = 0; c < 10; c++)
        {
            numeros[f][c] = rand() % 1000 + 1; // Números aleatorios entre 1 y 1000
        }
    }
}

void mostrarMatriz(int numeros[10][10])
{
    for (int f = 0; f < 10; f++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%d ", numeros[f][c]);
        }
        printf("\n");
    }
}

void mostrarElementosDiagonalPrincipal(int numeros[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numeros[i][i]);
    }

    printf("\n");
}

int maximoElementosDiagonalPrincipal(int numeros[10][10])
{
    int maximo = numeros[0][0];

    for (int i = 1; i < 10; i++)
    {
        if (numeros[i][i] > maximo)
        {
            maximo = numeros[i][i];
        }
    }

    return maximo;
}

int minimoElementosDiagonalPrincipal(int numeros[10][10])
{
    int minimo = numeros[0][0];

    for (int i = 1; i < 10; i++)
    {
        if (numeros[i][i] < minimo)
        {
            minimo = numeros[i][i];
        }
    }

    return minimo;
}

float promedioElementosDiagonalPrincipal(int numeros[10][10])
{
    int suma = 0;

    for (int i = 0; i < 10; i++)
    {
        suma += numeros[i][i];
    }

    return (float)suma / 10;
}

int main()
{
    int matriz[10][10];

    cargarMatrizConNumerosAleatorios(matriz);
    printf("----- Matriz Aleatoria 10x10 -----\n");
    mostrarMatriz(matriz);
    printf("\n");

    printf("Elementos de la diagonal principal:\n");
    mostrarElementosDiagonalPrincipal(matriz);
    printf("\n");

    printf("Máximo elemento de la diagonal principal: %d\n", maximoElementosDiagonalPrincipal(matriz));

    printf("Mínimo elemento de la diagonal principal: %d\n", minimoElementosDiagonalPrincipal(matriz));

    printf("Promedio de los elementos de la diagonal principal: %.2f\n", promedioElementosDiagonalPrincipal(matriz));
    return 0;
}