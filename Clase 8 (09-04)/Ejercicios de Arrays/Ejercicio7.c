#include <stdio.h>

void ingresarNumerosAlArray(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
}

void mostrarArrayEspecialParEImpar(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", numeros[i]);
        if (numeros[i] % 2 == 0)
        {
            printf("--> Es par");
        }
        else
        {
            printf("--> Es impar");
        }
        printf("\n");
    } 
}

int main()
{
    int num[8];

    ingresarNumerosAlArray(num, sizeof(num) / sizeof(num[0]));
    
    mostrarArrayEspecialParEImpar(num, sizeof(num) / sizeof(num[0]));
    return 0;
}