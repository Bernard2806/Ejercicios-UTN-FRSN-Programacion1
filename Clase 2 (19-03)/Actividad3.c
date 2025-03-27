#include <stdio.h> // Incluimos la librería stdio.h para utilizar funciones de entrada/salida como printf.

int main()
{
    // Definimos la altura de la pirámide (número de filas)
    int altura = 5; // La pirámide tendrá 5 filas de altura

    // Bucle principal que controla el número de filas de la pirámide
    for (int i = 0; i < altura; i++)
    {

        // Primer bucle interno: imprime los espacios en blanco
        // La cantidad de espacios disminuye en cada fila
        // En la primera fila son (altura - 1) espacios, y va disminuyendo en cada fila siguiente
        for (int j = 0; j < altura - i - 1; j++)
        {
            printf(" "); // Imprime los espacios antes de los asteriscos
        }

        // Segundo bucle interno: imprime los asteriscos
        // La cantidad de asteriscos sigue la secuencia: 1, 3, 5, 7, 9
        // Se calcula como (2 * número_de_fila + 1), para que se añadan más asteriscos en cada fila
        for (int k = 0; k < (2 * i + 1); k++)
        {
            printf("*"); // Imprime los asteriscos que forman la pirámide
        }

        // Después de cada fila, movemos el cursor a la siguiente línea
        // Esto es necesario para comenzar a imprimir la siguiente fila
        printf("\n");
    }

    return 0; // El programa termina correctamente
}