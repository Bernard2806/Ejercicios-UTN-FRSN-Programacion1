#include <stdio.h>

// Función que solicita un número hasta que sea mayor a 0
void pedirNumeroPositivo()
{
    int numero;

    do
    {
        printf("Ingrese un número positivo: ");
        scanf("%d", &numero);

        if (numero <= 0)
        {
            printf("El número debe ser mayor a 0. Intente nuevamente.\n");
        }
    } while (numero <= 0);

    printf("¡Gracias! Ingresó el número positivo %d.\n", numero);
}

int main()
{
    // Llamamos a la función que pide un número positivo
    pedirNumeroPositivo();

    return 0;
}