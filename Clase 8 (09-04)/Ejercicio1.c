#include <stdio.h>

void mostrarArrayDeNumeros(int numeros[], int longitud)
{

    printf("El array tiene %d elementos\n", longitud);

    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", numeros[i]);
    }
}

int main()
{
    int numeros[12] = {39, -2, 7};
    mostrarArrayDeNumeros(numeros, 12);
    return 0;
}