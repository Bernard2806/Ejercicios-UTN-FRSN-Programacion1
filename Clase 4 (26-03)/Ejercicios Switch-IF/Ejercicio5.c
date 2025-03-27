#include <stdio.h> // Biblioteca estándar para entrada y salida de datos

int main()
{
    int edadUsuario, tieneMembresia; // Variables para la edad y si tiene membresía

    // Pedimos la edad del usuario
    printf("Ingrese su edad: ");
    scanf("%d", &edadUsuario); // Guardamos la edad ingresada

    // Preguntamos si tiene membresía (1 para sí, 0 para no)
    printf("¿Tiene membresia? (1: Si, 0: No): ");
    scanf("%d", &tieneMembresia); // Guardamos la respuesta

    // Verificamos si el usuario cumple con los requisitos para cada tipo de acceso
    if (edadUsuario >= 18 && tieneMembresia == 1)
    {
        // Si es mayor de edad y tiene membresía, puede entrar a la sala VIP
        printf("Acceso permitido a la sala VIP");
    }
    else if (edadUsuario >= 18 && tieneMembresia == 0)
    {
        // Si es mayor de edad pero no tiene membresía, puede entrar a la pista común
        printf("Acceso permitido a la pista comun");
    }
    else
    {
        // Si no tiene 18 años, no entra ni a la pista común
        printf("Acceso denegado");
    }

    return 0; // Fin del programa, todo salió bien
}