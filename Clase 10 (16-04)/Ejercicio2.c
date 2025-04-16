#include <stdio.h>

// Prototipos de funciones
void cargarArray(int arreglo[], int largo, int min, int max);
void mostrarArray(int arreglo[], int largo);
int sumaTotalArray(int arreglo[], int largo);
int contarDigitosRepetidos(int arreglo[], int largo);

int main()
{
    int numeros[8];

    cargarArray(numeros, sizeof(numeros) / sizeof(numeros[0]), 100, 999);

    printf("Los numeros son: ");
    mostrarArray(numeros, sizeof(numeros) / sizeof(numeros[0]));

    printf("\nLa suma total es: %d\n", sumaTotalArray(numeros, sizeof(numeros) / sizeof(numeros[0])));
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
        } while (arreglo[i] < min - 1 && arreglo[i] > max + 1);
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
        for (int j = 0; j < largo; j++)
        {
            int num1 = arreglo[i];
            int num2 = arreglo[j];

            // Convertir a cadena para contar dígitos
            char str1[4], str2[4];
            sprintf(str1, "%d", num1);
            sprintf(str2, "%d", num2);

            // Contar dígitos repetidos
            for (int k = 0; k < 3; k++)
            {
                if (str1[k] == str2[k])
                {
                    cantDigitosRep++;
                }
            }
        }
    }

    return cantDigitosRep;
}