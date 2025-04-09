#include <stdio.h>

void ingresarNumerosAlArray(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
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

void invertirArray(int numeros[], int longitud, int numerosInvertidos[])
{
    for (int i = 0; i < longitud; i++)
    {
        numerosInvertidos[i] = numeros[longitud - 1 - i];
    }
}

int main()
{
    int numerosOrdenados[10];
    int numerosInvertidos[10];

    ingresarNumerosAlArray(numerosOrdenados, 10);
    printf("Los numeros ingresados son: \n");
    mostrarArray(numerosOrdenados, 10);

    invertirArray(numerosOrdenados, 10, numerosInvertidos);
    printf("Los numeros invertidos son: \n");
    mostrarArray(numerosInvertidos, 10);

    return 0;
}