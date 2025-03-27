#include <stdio.h> // Incluimos la biblioteca estándar para manejar entrada y salida

int main()
{
    int hora; // Variable para guardar la hora ingresada por el usuario

    // Pedimos al usuario que ingrese la hora (entre 0 y 23)
    printf("Ingrese la hora (entre 0 y 23): ");
    scanf("%d", &hora); // Leemos la hora ingresada

    printf("\n"); // Salto de línea para que quede más prolijo el resultado

    // Condiciones para determinar en qué parte del día estamos
    if (hora >= 6 && hora <= 11)
    {
        // Si la hora está entre las 6 AM y las 11 AM, es de mañana
        printf("Es de mañana");
    }
    else if (hora >= 12 && hora <= 17)
    {
        // Si la hora está entre las 12 PM y las 5 PM, es de tarde
        printf("Es de tarde");
    }
    else if (hora >= 18 && hora <= 23)
    {
        // Si la hora está entre las 6 PM y las 11 PM, es de noche
        printf("Es de noche");
    }
    else if (hora >= 0 && hora <= 5)
    {
        // Si la hora está entre las 12 AM y las 5 AM, es de madrugada
        printf("Es de madrugada");
    }
    else
    {
        // Si la hora no está en el rango de 0 a 23, mostramos un mensaje de error
        printf("Hora incorrecta");
    }

    return 0; // Fin del programa
}