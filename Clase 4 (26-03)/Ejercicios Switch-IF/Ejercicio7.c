#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    int anio; // Variable para almacenar el año ingresado

    // Pedimos al usuario que ingrese un año
    printf("Ingrese un anio: ");
    scanf("%d", &anio); // Guardamos el valor ingresado en la variable `anio`

    // Verificamos si el año es bisiesto usando las reglas del calendario gregoriano:
    // - Un año es bisiesto si es divisible por 4.
    // - Excepto si también es divisible por 100 (NO es bisiesto).
    // - A menos que sea divisible por 400 (SÍ es bisiesto).
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0)
    {
        printf("El anio es bisiesto"); // Si cumple la condición, es bisiesto.
    }
    else
    {
        printf("El anio no es bisiesto"); // Si no, no es bisiesto.
    }

    return 0; // Fin del programa, todo salió bien.
}