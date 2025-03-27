#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Declaramos las variables necesarias
    float celcius, fahrenheit; // celcius almacenará la temperatura ingresada por el usuario, fahrenheit almacenará el resultado de la conversión.

    // Pedimos al usuario que ingrese la cantidad de grados Celsius
    printf("Ingrese la cantidad de grados Celcius: ");
    scanf("%f", &celcius); // Leemos el valor de los grados Celsius.

    // Realizamos la conversión de Celsius a Fahrenheit utilizando la fórmula
    fahrenheit = (celcius * 9 / 5) + 32; // Fórmula de conversión de Celsius a Fahrenheit.

    // Mostramos el resultado
    printf("\nLa cantidad de grados Fahrenheit es %.2f", fahrenheit); // Imprimimos el resultado de la conversión.

    return 0; // El programa finaliza correctamente.
}