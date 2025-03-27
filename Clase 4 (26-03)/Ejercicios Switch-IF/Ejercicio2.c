#include <stdio.h> // Biblioteca estándar para poder usar printf y scanf

int main()
{
    int num1, num2, num3; // Declaramos tres variables para guardar los números ingresados

    // Pedimos al usuario que ingrese tres números y los guardamos en las variables
    printf("Ingrese el primer numero: ");
    scanf("%d", &num1);

    printf("\nIngrese el segundo numero: ");
    scanf("%d", &num2);

    printf("\nIngrese el tercer numero: ");
    scanf("%d", &num3);

    // Ahora comparamos para ver cuál es el más grande
    if (num1 > num2 && num1 > num3)
    {
        // Si el primer número es mayor a los otros dos, mostramos que es el más grande
        printf("\nEl numero mayor es: %d", num1);
    }
    else if (num2 > num1 && num2 > num3)
    {
        // Si el segundo número es mayor a los otros dos, lo mostramos como el más grande
        printf("\nEl numero mayor es: %d", num2);
    }
    else if (num3 > num1 && num3 > num2)
    {
        // Si el tercero es el más grande, lo mostramos
        printf("\nEl numero mayor es: %d", num3);
    }
    else
    {
        // Si ninguno es mayor, significa que los tres son iguales
        printf("\nLos tres numeros son iguales");
    }

    return 0; // Fin del programa, devolvemos 0 para indicar que todo salió bien
}