#include <stdio.h> // Incluimos la librería stdio.h para poder usar funciones como printf y scanf.

int main()
{
    // Definimos el precio del dólar para turistas como una constante
    const float precioDolarTurista = 1364.03; // El valor de 1 dólar en pesos según el tipo de cambio actual.

    float pesos, dolares; // Variables para almacenar los valores de pesos y la conversión de dólares.

    // Solicitamos al usuario que ingrese la cantidad de dólares que desea convertir
    printf("Ingrese la cantidad de dolares a convertir: ");
    scanf("%f", &dolares); // Leemos el valor de dólares ingresado por el usuario.

    // Realizamos la conversión de dólares a pesos multiplicando los dólares por el valor del tipo de cambio
    pesos = dolares * precioDolarTurista; // Calculamos la cantidad de pesos.

    // Mostramos el resultado de la conversión con dos decimales
    printf("\nLa cantidad de pesos es: %.2f", pesos); // Imprimimos el valor en pesos con dos decimales.

    return 0; // El programa termina correctamente.
}