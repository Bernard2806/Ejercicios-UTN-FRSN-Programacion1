#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Declaramos las variables necesarias
    double base, altura, area; // base y altura son los valores ingresados por el usuario, area es el resultado del cálculo.

    // Pedimos al usuario que ingrese la base del triángulo
    printf("Ingrese la base del triángulo: ");
    scanf("%lf", &base); // Leemos el valor de la base del triángulo.

    // Pedimos al usuario que ingrese la altura del triángulo
    printf("Ingrese la altura del triángulo: ");
    scanf("%lf", &altura); // Leemos el valor de la altura del triángulo.

    // Calculamos el área del triángulo
    area = (base * altura) / 2; // Aplicamos la fórmula del área de un triángulo: (base * altura) / 2.

    // Mostramos el resultado del área
    printf("\nEl área del triángulo es %.2lf", area); // Imprimimos el resultado del área con 2 decimales.

    return 0; // El programa finaliza correctamente.
}