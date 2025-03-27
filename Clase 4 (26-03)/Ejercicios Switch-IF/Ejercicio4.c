#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    int temperatura; // Variable para guardar la temperatura ingresada por el usuario

    // Pedimos al usuario que ingrese la temperatura actual
    printf("Ingrese la temperatura: ");
    scanf("%d", &temperatura); // Guardamos el valor en la variable 'temperatura'

    // Evaluamos la temperatura para determinar cómo está el clima
    if (temperatura > 30)
        // Si la temperatura es mayor a 30 grados, hace un calor infernal
        printf("\nHace mucho calor");
    else if (temperatura >= 15)
        // Si está entre 15 y 30 grados, el clima está piola, ni frío ni calor
        printf("\nEl clima esta templado");
    else
        // Si es menor a 15 grados, mejor sacar el abrigo porque hace frío
        printf("\nHace frío");

    return 0; // Fin del programa, devolvemos 0 para indicar que todo salió bien
}