#include <stdio.h>

void cargarMatrizConNumerosAleatorios(int numeros[6][10])
{
    srand(time(NULL)); // Inicializar semilla

    for (int f = 0; f < 6; f++)
    {
        for (int c = 0; c < 10; c++)
        {
            numeros[f][c] = rand() % 1000 + 1; // Números aleatorios entre 1 y 1000
        }
    }
}

void mostrarMatriz(int numeros[6][10])
{
    for (int f = 0; f < 6; f++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%d ", numeros[f][c]);
        }
        printf("\n");
    }
}

void mostrarMaximoYMinimo(int numeros[6][10])
{
    int maximo = numeros[0][0];
    int posMaximo[2] = {0, 0};

    int minimo = numeros[0][0];
    int posMinimo[2] = {0, 0};

    for (int f = 0; f < 6; f++)
    {
        for (int c = 0; c < 10; c++)
        {
            if (numeros[f][c] > maximo)
            {
                maximo = numeros[f][c];
                posMaximo[0] = f;
                posMaximo[1] = c;
            }
            if (numeros[f][c] < minimo)
            {
                minimo = numeros[f][c];
                posMinimo[0] = f;
                posMinimo[1] = c;
            }
        }
    }

    printf("Máximo: %d --> %d,%d\n", maximo, posMaximo[0], posMaximo[1]);
    printf("Mínimo: %d --> %d,%d\n", minimo, posMinimo[0], posMinimo[1]);
}

int main()
{
    int matriz[6][10];

    cargarMatrizConNumerosAleatorios(matriz);

    printf("La matriz es:\n");
    mostrarMatriz(matriz);

    printf("\n");

    mostrarMaximoYMinimo(matriz);
    return 0;
}