#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numeroSecreto, intento, intentosRestantes;
    int mejorRecord = 999;
    char jugarDeNuevo;
    
    // Inicializar la semilla para números aleatorios
    srand(time(NULL));
    
    do {
        // Generar número aleatorio entre 1 y 100
        numeroSecreto = rand() % 100 + 1;
        intentosRestantes = 5;
        
        printf("\n¡Bienvenido al juego de adivinar el número!\n");
        printf("Tienes 5 intentos para adivinar un número entre 1 y 100\n");
        
        while (intentosRestantes > 0) {
            printf("\nIntentos restantes: %d\n", intentosRestantes);
            printf("Ingresa tu número: ");
            scanf("%d", &intento);
            
            if (intento == numeroSecreto) {
                printf("¡Felicitaciones! ¡Has adivinado el número!\n");
                if (6 - intentosRestantes < mejorRecord) {
                    mejorRecord = 6 - intentosRestantes;
                    printf("¡Nuevo récord! Lo lograste en %d intentos\n", mejorRecord);
                }
                break;
            } else if (intento < numeroSecreto) {
                printf("El número es mayor\n");
            } else {
                printf("El número es menor\n");
            }
            
            intentosRestantes--;
            
            if (intentosRestantes == 0) {
                printf("\n¡Game Over! El número era: %d\n", numeroSecreto);
            }
        }
        
        printf("\n¿Quieres jugar de nuevo? (s/n): ");
        scanf(" %c", &jugarDeNuevo);
        
    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');
    
    printf("\nMejor récord: %d intentos\n", mejorRecord == 999 ? 0 : mejorRecord);
    printf("¡Gracias por jugar!\n");
    
    return 0;
}