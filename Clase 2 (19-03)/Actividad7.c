#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Declaramos las variables necesarias
    int num1, num2, suma; // num1 y num2 son los números que el usuario ingresará, suma es el resultado de la adición.

    // Pedimos al usuario que ingrese el primer número
    printf("Ingrese el primer número: ");
    scanf("%d", &num1); // Leemos el primer número ingresado por el usuario.

    // Pedimos al usuario que ingrese el segundo número
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2); // Leemos el segundo número ingresado por el usuario.

    // Calculamos la suma de los dos números
    suma = num1 + num2; // Sumamos los dos números y almacenamos el resultado en la variable suma.

    // Imprimimos el resultado de la suma
    printf("\nLa suma de %d y %d es %d", num1, num2, suma); // Mostramos el resultado de la suma en pantalla.

    return 0; // El programa finaliza correctamente.
}
