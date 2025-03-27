#include <stdio.h>  // Incluimos la librería para poder usar printf y scanf
#include <stdlib.h> // Para usar funciones como rand() y srand()
#include <time.h>   // Para la función time() y generar números aleatorios

int main()
{
    int numeroSecreto, intento, intentosRestantes; // Variables del juego
    int mejorRecord = 999;                         // Variable para guardar el mejor récord (inicializado en 999 como placeholder)
    char jugarDeNuevo;                             // Variable para preguntar si se quiere jugar de nuevo

    // Inicializamos la semilla de los números aleatorios usando el tiempo actual
    srand(time(NULL));

    do
    {
        // Generamos un número aleatorio entre 1 y 100
        numeroSecreto = rand() % 100 + 1;
        intentosRestantes = 5; // El jugador tiene 5 intentos

        // Mensaje de bienvenida y reglas del juego
        printf("\n¡Bienvenido al juego de adivinar el número!\n");
        printf("Tienes 5 intentos para adivinar un número entre 1 y 100\n");

        // Comienza el bucle para los intentos
        while (intentosRestantes > 0)
        {
            printf("\nIntentos restantes: %d\n", intentosRestantes);
            printf("Ingresa tu número: ");
            scanf("%d", &intento); // Le pedimos al jugador que ingrese su intento

            // Comprobamos si el intento es correcto
            if (intento == numeroSecreto)
            {
                printf("¡Felicitaciones! ¡Has adivinado el número!\n");
                // Comprobamos si se ha logrado un nuevo récord
                if (6 - intentosRestantes < mejorRecord)
                {
                    mejorRecord = 6 - intentosRestantes; // Actualizamos el mejor récord
                    printf("¡Nuevo récord! Lo lograste en %d intentos\n", mejorRecord);
                }
                break; // Si el jugador acierta, se termina el juego
            }
            else if (intento < numeroSecreto)
            {
                printf("El número es mayor\n"); // Si el intento es menor, decimos que el número es mayor
            }
            else
            {
                printf("El número es menor\n"); // Si el intento es mayor, decimos que el número es menor
            }

            intentosRestantes--; // Restamos un intento cada vez

            // Si se acaban los intentos, mostramos el número secreto
            if (intentosRestantes == 0)
            {
                printf("\n¡Game Over! El número era: %d\n", numeroSecreto);
            }
        }

        // Preguntamos si el jugador quiere jugar otra vez
        printf("\n¿Quieres jugar de nuevo? (s/n): ");
        scanf(" %c", &jugarDeNuevo); // El espacio antes de %c es para ignorar el salto de línea del enter anterior

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S'); // Si responde 's' o 'S', el juego sigue

    // Mostramos el mejor récord, si no se ha logrado ninguno, mostramos 0
    printf("\nMejor récord: %d intentos\n", mejorRecord == 999 ? 0 : mejorRecord);
    printf("¡Gracias por jugar!\n"); // Mensaje final

    return 0; // Fin del programa
}