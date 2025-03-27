#include <stdio.h> // Incluimos la librería stdio.h, que proporciona funciones para la entrada y salida estándar, como printf y scanf.

int main()
{
    // Declaración de variables para almacenar los datos del usuario
    char nombre[25];     // Array de caracteres para el nombre (máximo 25 caracteres)
    char direccion[150]; // Array de caracteres para la dirección (máximo 150 caracteres)
    char telefono[16];   // Array de caracteres para el teléfono (máximo 16 caracteres, para almacenar el número más el terminador nulo '\0')

    // Solicitud y lectura del nombre
    printf("Ingrese tu nombre: ");
    scanf("%s", nombre); // Leemos el nombre del usuario, usando %s para cadenas de caracteres (sin espacios).

    // Solicitud y lectura de la dirección
    printf("Ingresa tu direccion: ");
    fflush(stdin);   // Limpiamos el buffer de entrada para evitar problemas con fgets o gets.
    gets(direccion); // Leemos la dirección completa, incluyendo los espacios, utilizando gets.

    // Solicitud y lectura del teléfono
    printf("Ingresa tu telefono: ");
    scanf("%15s", telefono); // Leemos el teléfono del usuario, limitando a 15 caracteres como máximo (el número más el terminador nulo).

    // Bucle que imprime los datos 3 veces
    for (int i = 0; i < 3; i++)
    {
        // Imprime los datos ingresados (nombre, dirección y teléfono) en cada iteración.
        // Cada vez que el bucle se ejecute, se mostrarán los mismos datos.
        printf("\n\n Mi Nombre es %s, Mi Direccion es: %s, Mi Telefono es: %s",
               nombre, direccion, telefono); // Muestra todos los datos ingresados
    }

    return 0; // Finaliza la ejecución del programa correctamente.
}