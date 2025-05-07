#include <stdio.h>

// Prototipo de funciones
void aMinusculas(char *str);

int main()
{
    char str[] = "HOLA MUNDO"; // Cadena de caracteres a convertir

    printf("Cadena original: %s\n", str); // Muestra la cadena original

    aMinusculas(str); // Convierte la cadena a minusculas

    printf("Cadena en minúsculas: %s\n", str); // Muestra la cadena convertida a minúsculas
    return 0;
}

// Función para convertir una cadena a minúsculas
// Sin utilizar las funciones de la biblioteca <string.h>
void aMinusculas(char *str)
{
    while (*str != '\0')
    { // Mientras no se llegue al final de la cadena
        if (*str >= 'a' && *str <= 'z')
        {               // Si el carácter es minúscula
            *str += 32; // Convierte a minúscula sumando 32 (diferencia entre ASCII de 'a' y 'A')
        }
        str++; // Avanza al siguiente carácter
    }
}