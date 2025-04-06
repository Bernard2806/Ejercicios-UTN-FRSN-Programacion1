#include <stdio.h>

// Función que recibe un número e imprime del 1 al número ingresado
void contarHasta(int numero)
{
    for (int i = 1; i <= numero; i++)
    {
        printf("%d\n", i);
    }
}

int main()
{
    int numeroUsuario;

    // Solicita al usuario que ingrese un número
    printf("Ingrese un número: ");
    scanf("%d", &numeroUsuario);

    // Llama a la función para contar hasta el número ingresado
    contarHasta(numeroUsuario);

    return 0;
}