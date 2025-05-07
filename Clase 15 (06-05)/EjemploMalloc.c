#include <stdio.h>
#include <stdlib.h> // Necesario para malloc

int main()
{
    // 1. Declaramos un puntero a entero
    int *ptr;
    int *ptr2;

    // 2. Usamos malloc para reservar memoria dinámica para 5 enteros
    ptr = (int *)malloc(5 * sizeof(int)); // malloc devuelve un puntero de tipo void*, por eso se hace el cast a (int*)
    ptr2 = ptr;
    // 3. Verificamos si malloc devolvió NULL (es decir, si ocurrió un error al asignar memoria)
    if (ptr == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1; // Salimos del programa con un código de error
    }

    // 4. Inicializamos el arreglo con valores
    for (int i = 0; i < 5; i++)
    {
        *ptr = (i + 1) * 10; // Asignamos valores 10, 20, 30, 40, 50
        ptr++;
    }

    // 5. Imprimimos los valores almacenados en el arreglo
    printf("Los valores en el arreglo son:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("ptr[%d] = %d\n", i, ptr2[i]);
    }

    // 6. Liberamos la memoria dinámica que hemos reservado
    free(ptr2);

    return 0; // Finalizamos el programa exitosamente
}
