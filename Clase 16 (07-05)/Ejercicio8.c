#include <stdio.h>

int longitud(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main()
{
    char cadena[] = "Hola Mundo!";

    prinf("La cadena es: %s\n", cadena);
    printf("La longitud de la cadena es: %d\n", longitud(cadena));
    return 0;
}