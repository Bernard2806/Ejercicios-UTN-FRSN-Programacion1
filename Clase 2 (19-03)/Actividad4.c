#include <stdio.h> // Incluimos la librería stdio.h para usar funciones de entrada/salida, como printf y scanf.

int main()
{
    // Definimos el precio del dólar para turistas como una constante
    const float precioDolarTurista = 1364.03; // El valor de 1 dólar en pesos según el tipo de cambio actual.

    float pesos, dolares; // Variables para almacenar los valores de pesos y la conversión a dólares.

    // Solicitamos al usuario que ingrese la cantidad de pesos que desea convertir
    printf("Ingrese la cantidad de pesos a convertir: ");
    scanf("%f", &pesos); // Leemos el valor de pesos ingresado por el usuario.

    // Realizamos la conversión de pesos a dólares dividiendo el monto en pesos por el valor del dólar
    dolares = pesos / precioDolarTurista; // Calculamos la cantidad de dólares.

    // Mostramos el resultado de la conversión con dos decimales
    printf("\nLa cantidad de dolares es: %.2f", dolares); // Imprimimos el valor en dólares con dos decimales.

    return 0; // El programa termina correctamente.
}