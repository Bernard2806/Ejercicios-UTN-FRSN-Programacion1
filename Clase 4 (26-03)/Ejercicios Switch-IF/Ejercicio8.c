#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    float Lado1, Lado2, Lado3; // Variables para almacenar los tres lados del triángulo

    // Pedimos al usuario que ingrese los tres lados del triángulo
    printf("Ingrese el primer lado del triangulo: ");
    scanf("%f", &Lado1); // Guardamos el valor del primer lado

    printf("\nIngrese el segundo lado del triangulo: ");
    scanf("%f", &Lado2); // Guardamos el valor del segundo lado

    printf("\nIngrese el tercer lado del triangulo: ");
    scanf("%f", &Lado3); // Guardamos el valor del tercer lado

    printf("\n"); // Salto de línea para mejorar la legibilidad del resultado

    // Verificamos si los lados forman un triángulo válido
    // La suma de los dos lados de un triángulo siempre debe ser mayor que el tercer lado
    if (Lado1 + Lado2 > Lado3 && Lado1 + Lado3 > Lado2 && Lado2 + Lado3 > Lado1)
    {
        // Si los lados forman un triángulo, verificamos el tipo de triángulo
        if (Lado1 == Lado2 && Lado2 == Lado3)
        {
            // Si todos los lados son iguales, es un triángulo equilátero
            printf("Triangulo equilatero");
        }
        else if (Lado1 == Lado2 || Lado2 == Lado3 || Lado1 == Lado3)
        {
            // Si dos lados son iguales, es un triángulo isósceles
            printf("Triangulo isosceles");
        }
        else
        {
            // Si todos los lados son diferentes, es un triángulo escaleno
            printf("Triangulo escaleno");
        }
    }
    else
    {
        // Si no se cumple la regla de la suma de los lados, no es un triángulo válido
        printf("Los lados ingresados no forman un triangulo");
    }

    return 0; // Fin del programa, todo salió bien
}