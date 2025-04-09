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

void desplazarArrayUnoALaDerecha(int numeros[], int longitud)
{
    int aux = numeros[0];

    for (int i = 0; i < longitud - 1; i++)
    {
        numeros[i] = numeros[i + 1];
    }

    numeros[longitud - 1] = aux;
}

int main()
{
    int num[15];

    ingresarNumerosAlArray(num, sizeof(num) / sizeof(num[0]));

    printf("Los numeros ingresados son: \n");
    mostrarArray(num, sizeof(num) / sizeof(num[0]));

    desplazarArrayUnoALaDerecha(num, sizeof(num) / sizeof(num[0]));
    printf("Los numeros con desplazo son: \n");
    mostrarArray(num, sizeof(num) / sizeof(num[0]));

    return 0;
}