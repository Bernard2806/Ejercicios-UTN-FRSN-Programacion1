#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    int x; // Declaramos una variable de tipo entero llamada x.

    // Pedimos al usuario que ingrese un número entero
    printf("Ingrese un número entero: ");
    scanf("%d", &x); // Leemos el número entero ingresado por el usuario.

    // Mostramos el valor original de x
    printf("\nValor original de x: %d\n", x);

    // Post-incremento: muestra el valor de x antes de incrementarlo
    printf("x++  (Post-incremento): %d  -> Ahora x vale: %d\n", x++, x);
    // Primero muestra el valor actual de x, luego incrementa x.

    // Pre-incremento: incrementa x antes de mostrarlo
    printf("++x  (Pre-incremento): %d  -> Ahora x vale: %d\n", ++x, x);
    // Primero incrementa x y luego muestra su nuevo valor.

    // Pre-decremento: decrementa x antes de mostrarlo
    printf("--x  (Pre-decremento): %d  -> Ahora x vale: %d\n", --x, x);
    // Primero decrementa x y luego muestra su nuevo valor.

    // Post-decremento: muestra el valor de x antes de decrementarlo
    printf("x--  (Post-decremento): %d  -> Ahora x vale: %d\n", x--, x);
    // Primero muestra el valor actual de x, luego decrementa x.

    return 0; // El programa finaliza correctamente.
}