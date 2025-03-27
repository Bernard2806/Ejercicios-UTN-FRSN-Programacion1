#include <stdio.h>  // Incluimos la librería para poder usar printf y scanf
#include <stdlib.h> // Incluimos la librería para usar system("cls") y limpiar la pantalla

int main()
{
    // Variable que controla el bucle del menú
    int trabarMenu = 1;

    // Empezamos el bucle para que el menú se repita hasta que el usuario elija salir
    do
    {
        system("cls"); // Limpia la pantalla para que el menú siempre aparezca limpio
        int opcion, num1, num2;

        // Imprimimos el menú de opciones
        printf("=== CALCULADORA ===\n");
        printf("1. Sumar dos numeros \n");
        printf("2. Restar dos numeros \n");
        printf("3. Multiplicar dos numeros \n");
        printf("4. Dividir dos numeros \n");
        printf("5. Salir \n");

        // Pedimos al usuario que ingrese una opción
        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);

        // Si el usuario elige 5, salimos del menú
        if (opcion == 5)
        {
            printf("Gracias por usar la calculadora!\n");
            trabarMenu = 0; // Cambiamos el valor de trabarMenu para salir del bucle
        }
        // Si la opción está entre 1 y 4, pedimos los dos números y realizamos la operación
        else if (opcion >= 1 && opcion <= 4)
        {
            printf("Ingrese el primer numero: ");
            scanf("%d", &num1);

            printf("Ingrese el segundo numero: ");
            scanf("%d", &num2);

            // Usamos un switch para elegir la operación según la opción seleccionada
            switch (opcion)
            {
            case 1:
                printf("La suma de %d y %d es %d\n", num1, num2, num1 + num2);
                break;
            case 2:
                printf("La resta de %d y %d es %d\n", num1, num2, num1 - num2);
                break;
            case 3:
                printf("La multiplicacion de %d y %d es %d\n", num1, num2, num1 * num2);
                break;
            case 4:
                // Si la opción es 4 (división), comprobamos que el divisor no sea 0
                if (num2 != 0)
                {
                    printf("La division de %d y %d es %.2f\n", num1, num2, (float)num1 / num2);
                }
                else
                {
                    printf("Error: No se puede dividir por cero!\n");
                }
                break;
            }

            // Mensaje para continuar y esperar que el usuario presione Enter
            printf("\nPresione Enter para continuar...");
            fflush(stdin); // Limpiamos el buffer de entrada
            getchar();     // Esperamos que el usuario presione Enter
        }
        // Si la opción no es válida (no está entre 1 y 5), mostramos un error
        else
        {
            printf("Opcion invalida!\n");
            printf("Presione Enter para continuar...");
            fflush(stdin); // Limpiamos el buffer de entrada
            getchar();     // Esperamos que el usuario presione Enter
        }
    } while (trabarMenu == 1); // El bucle continuará hasta que trabarMenu sea 0

    return 0; // Fin del programa
}