#include <stdio.h>

void ingresarNumerosAlArray(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
}

int calcularMaximo(int numeros[], int longitud)
{
    int maximo = numeros[0];
    for (int i = 1; i < longitud; i++)
    {
        if (numeros[i] > maximo)
        {
            maximo = numeros[i];
        }
    }
    return maximo;
}

int calcularMinimo(int numeros[], int longitud)
{
    int minimo = numeros[0];
    for (int i = 1; i < longitud; i++)
    {
        if (numeros[i] < minimo)
        {
            minimo = numeros[i];
        }
    }
    return minimo;
}

void mostrarArrayEspecial(int numeros[], int longitud, int maximo, int minimo)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("%d", numeros[i]);

        if (numeros[i] == maximo)
        {
            printf(" --> MAXIMO");
        }
        else if (numeros[i] == minimo)
        {
            printf(" --> MINIMO");
        }

        printf("\n");
    }
}


int main(){
    int num[10];

    ingresarNumerosAlArray(num, sizeof(num)/sizeof(num[0]));

    int maximo = calcularMaximo(num, sizeof(num)/sizeof(num[0]));
    int minimo = calcularMinimo(num, sizeof(num)/sizeof(num[0]));

    mostrarArrayEspecial(num, sizeof(num)/sizeof(num[0]), maximo, minimo);

    return 0;
}