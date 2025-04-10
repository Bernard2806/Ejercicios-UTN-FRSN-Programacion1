#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Carga un array con números aleatorios entre 1 y 100
void cargarArrayConNumerosAleatorios(int numeros[], int longitud)
{
    srand(time(NULL)); // Inicializar semilla para rand
    for (int i = 0; i < longitud; i++)
    {
        numeros[i] = rand() % 100 + 1; // Números entre 1 y 100
    }
}

// Muestra el contenido del array
void mostrarArray(int numeros[], int longitud)
{
    for (int i = 0; i < longitud; i++)
    {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

// Rota todos los elementos del array una posición hacia la derecha
void rotarDerecha(int numeros[], int longitud)
{
    int ultimo = numeros[longitud - 1]; // Guardar el último valor
    for (int i = longitud - 1; i > 0; i--)
    {
        numeros[i] = numeros[i - 1]; // Desplazar hacia la derecha
    }
    numeros[0] = ultimo; // Colocar el último en la primera posición
}

// Busca un número en el array y devuelve su posición o -1 si no está
int buscarNumeroEnArray(int numeros[], int longitud, int numeroBuscado)
{
    for (int i = 0; i < longitud; i++)
    {
        if (numeros[i] == numeroBuscado)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int numeros[10];
    int numeroUsuario;
    int posicionNumero;

    // Cargar y mostrar el array original
    cargarArrayConNumerosAleatorios(numeros, 10);
    printf("Array generado:\n");
    mostrarArray(numeros, 10);

    // Pedir un número hasta que esté en el array
    do
    {
        printf("Ingrese un numero que esté en el array: ");
        scanf("%d", &numeroUsuario);

        posicionNumero = buscarNumeroEnArray(numeros, 10, numeroUsuario);

        if (posicionNumero == -1)
        {
            printf("El numero no está en el array. Intente de nuevo.\n");
        }

    } while (posicionNumero == -1);

    // Rotar hasta que el número esté en la posición 0
    while (numeros[0] != numeroUsuario)
    {
        rotarDerecha(numeros, 10);
    }

    // Mostrar el array final
    printf("Array rotado con el numero %d en la posicion 0:\n", numeroUsuario);
    mostrarArray(numeros, 10);

    return 0;
}