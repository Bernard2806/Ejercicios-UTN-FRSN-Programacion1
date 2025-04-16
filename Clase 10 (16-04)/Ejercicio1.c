#include <stdio.h>
#include <stdlib.h>

// Prototipos de funciones
void cargarArray(int arreglo[], int largo);
void mostrarArray(int arreglo[], int largo);
float calcularPromedio(int arreglo[], int largo);
void mostrarArrayNumerosPares(int arreglo[], int largo);
void mostrarNumerosMayoresAlPromedio(int arreglo[], int largo);

int main()
{
    int numeros[12];
    cargarArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("Los numeros son: ");
    mostrarArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nEl Promedio es: ");
    printf("%.2f", calcularPromedio(numeros, sizeof(numeros) / sizeof(numeros[0])));

    printf("\nLos numeros pares son: ");
    mostrarArrayNumerosPares(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nLos numeros mayores al promedio son: ");
    mostrarNumerosMayoresAlPromedio(numeros, sizeof(numeros) / sizeof(numeros[0]));

    system("curl http://ascii.live/rick");

    return 0;
}

// Funciones

void cargarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        do
        {
            printf("Ingrese el valor [%d] entre 1 y 100: ", i + 1);
            scanf("%d", &arreglo[i]);
        } while (arreglo[i] < 1 || arreglo[i] > 100);
    }
}

void mostrarArray(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        printf("%d, ", arreglo[i]);
    }
}

float calcularPromedio(int arreglo[], int largo)
{
    int suma = 0;

    for (int i = 0; i < largo; i++)
    {
        suma += arreglo[i];
    }

    return (float)suma / largo;
}

void mostrarArrayNumerosPares(int arreglo[], int largo)
{
    for (int i = 0; i < largo; i++)
    {
        if (arreglo[i] % 2 == 0)
        {
            printf("%d, ", arreglo[i]);
        }
    }
}

void mostrarNumerosMayoresAlPromedio(int arreglo[], int largo)
{
    float promedio = calcularPromedio(arreglo, largo);
    
    for(int i = 0; i < largo; i++)
    {
        if(arreglo[i] > promedio)
        {
            printf("%d, ", arreglo[i]);
        }
    }
}