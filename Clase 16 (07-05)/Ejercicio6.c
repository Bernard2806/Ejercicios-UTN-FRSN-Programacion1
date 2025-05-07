#include <stdio.h>

// Prototipo de funciones
void aMayusculas(char *str);

int main()
{
    char str[] = "hola mundo";

    printf("Cadena original: %s\n", str); // Muestra la cadena original

    aMayusculas(str); // Convierte la cadena a mayúsculas   

    printf("Cadena en mayúsculas: %s\n", str);
    return 0;
}

// Función para convertir una cadena a mayúsculas
// Sin utilizar las funciones de la biblioteca <string.h>
void aMayusculas(char *str)
{
    while (*str != '\0')
    { // Mientras no se llegue al final de la cadena
        if (*str >= 'a' && *str <= 'z')
        {               // Si el carácter es minúscula
            *str -= 32; // Convierte a mayúscula restando 32 (diferencia entre ASCII de 'a' y 'A')
        }
        str++; // Avanza al siguiente carácter
    }
}