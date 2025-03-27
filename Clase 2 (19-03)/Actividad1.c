#include <stdio.h> // Incluimos la librería stdio.h, que nos permite trabajar con las funciones de entrada y salida estándar, como printf.

int main()
{
    // Comenzamos un bucle 'for', que se repite 3 veces.
    // El bucle va a imprimir un mensaje cada vez que pase por él.
    // i es la variable que se incrementa en cada iteración, comenzando desde 0, hasta que llega a 3.
    for (int i = 0; i < 3; i++)
    {
        // Imprime el mensaje con los datos del usuario (nombre, dirección y teléfono) en cada iteración.
        // El salto de línea \n\n al final crea un espacio entre cada mensaje impreso.
        printf("Mi Nombre es Bernardo, Mi Dirección es: Luis Mohr 127, Mi Telefono es: 2346-614492 \n\n");
    }

    return 0; // Devuelve 0, indicando que el programa terminó correctamente.
}