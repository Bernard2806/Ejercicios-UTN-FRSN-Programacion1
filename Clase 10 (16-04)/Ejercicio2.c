#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void cargarArray(int arreglo[], int largo, int min, int max);
void mostrarArray(int arreglo[], int largo);
int sumaTotalArray(int arreglo[], int largo);
int contarDigitosRepetidos(int arreglo[], int largo);
void MostrarLosQueTienenDigitosDiferentes(int array[], int largo);

int main()
{
    int numeros[8];

    cargarArray(numeros, sizeof(numeros) / sizeof(numeros[0]), 100, 999);

    printf("Los numeros son: ");
    mostrarArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nLa cantidad de digitos repetidos es: %d\n", contarDigitosRepetidos(numeros, sizeof(numeros) / sizeof(numeros[0])));

    printf("\nLa suma total es: %d\n", sumaTotalArray(numeros, sizeof(numeros) / sizeof(numeros[0])));

    printf("\nLos numeros que tienen digitos diferentes son: ");
    MostrarLosQueTienenDigitosDiferentes(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\n");

    system("curl http://ascii.live/rick");
    return 0;
}

// Funciones

void cargarArray(int arreglo[], int largo, int min, int max)
{
    for (int i = 0; i < largo; i++)
    {
        do
        {
            printf("Ingrese el valor [%d] entre %d y %d: ", i + 1, min, max);
            scanf("%d", &arreglo[i]);
        } while (arreglo[i] < min - 1 || arreglo[i] > max + 1);
    }
}

void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
}

int sumaTotalArray(int arreglo[], int largo)
{
    int suma = 0;
    for (int i = 0; i < largo; i++)
    {
        suma += arreglo[i];
    }
    return suma;
}

int contarDigitosRepetidos(int arreglo[], int largo)
{
    int cantDigitosRep = 0;

    for (int i = 0; i < largo; i++)
    {

        int centena = arreglo[i] / 100;
        int decena = arreglo[i] / 10 % 10;
        int unidad = arreglo[i] % 10;

        if (centena == decena || centena == unidad || decena == unidad)
        {
            cantDigitosRep++;
        }
    }

    return cantDigitosRep;
}

void MostrarLosQueTienenDigitosDiferentes(int array[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        int centena = array[i] / 100;
        int decena = array[i] / 10 % 10;
        int unidad = array[i] % 10;

        if (centena != decena || centena != unidad || decena != unidad)
        {
            printf("%d, ", array[i]);
        }
    }
}