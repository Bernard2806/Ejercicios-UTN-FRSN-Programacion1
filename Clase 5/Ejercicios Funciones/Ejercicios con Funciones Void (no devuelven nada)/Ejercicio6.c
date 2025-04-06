#include <stdio.h>

// Función sin parámetros que imprime un saludo general
void saludo()
{
    printf("¡Hola, bienvenido a C!\n");
}

// Función que recibe un nombre e imprime un saludo personalizado
void saludoPersonalizado(char nombre[])
{
    printf("¡Hola, %s!\n", nombre);
}

int main()
{
    // Llamamos a la función de saludo general
    saludo();

    // Variable para almacenar el nombre del usuario
    char nombreUsuario[50];

    // Solicita al usuario que ingrese su nombre
    printf("Ingrese su nombre: ");
    scanf("%49s", nombreUsuario); // %49s para evitar desbordamiento de búfer

    // Llamamos a la función de saludo personalizado
    saludoPersonalizado(nombreUsuario);

    return 0;
}