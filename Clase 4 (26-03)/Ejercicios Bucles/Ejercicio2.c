#include <stdio.h> // Incluimos la librería estándar para las funciones de entrada y salida

int main()
{
    int i = 0, cont = 0; // Inicializamos i en 0 para empezar desde ahí y cont en 0 para contar los pares

    // Bucle "while" que sigue ejecutándose mientras i sea menor o igual a 20
    while (i <= 20)
    {

        printf("%d\n", i); // Imprimimos el valor actual de i
        i++;               // Aumentamos i en 1 en cada vuelta

        // Comprobamos si i es un número par
        if (i % 2 == 0)
        {
            cont++; // Si es par, sumamos 1 a la variable cont
        }
    }

    // Al final, imprimimos cuántos números pares hubo entre 0 y 20
    printf("\nCantidad de numeros pares: %d", cont);
    return 0; // Fin del programa
}