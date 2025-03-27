#include <stdio.h> // Incluimos la biblioteca estándar para poder usar printf y scanf

int main()
{
    int edad; // Declaramos una variable para guardar la edad del usuario

    printf("Ingrese su edad: "); // Pedimos al usuario que ingrese su edad
    scanf("%d", &edad);          // Guardamos la edad ingresada en la variable 'edad'

    // Ahora viene la magia de las condiciones
    if (edad >= 18)
    {
        // Si la edad es 18 o más, el usuario es mayor de edad y puede votar libremente
        printf("\nPodes votar");
    }
    else if (edad >= 16)
    {
        // Si tiene 16 o 17, puede votar pero necesita permiso de los padres
        printf("\nPodes votar con permiso de tus padres");
    }
    else
    {
        // Si tiene menos de 16, todavía no puede votar. A esperar, amiguito.
        printf("\nNo podes votar");
    }

    return 0; // Fin del programa, devolvemos 0 para indicar que todo salió bien
}