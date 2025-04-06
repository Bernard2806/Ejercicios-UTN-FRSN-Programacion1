#include <stdio.h>

// Función que recibe un número y muestra si es par o impar
void mostrarParidad(int numero)
{
    if (numero % 2 == 0)
    {
        printf("Par\n");
    }
    else
    {
        printf("Impar\n");
    }
}

int main()
{
    int numeroUsuario;

    // Solicita al usuario que ingrese un número
    printf("Ingrese un número: ");
    scanf("%d", &numeroUsuario);

    // Llama a la función para mostrar si el número es par o impar
    mostrarParidad(numeroUsuario);

    return 0;
}