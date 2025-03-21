#include <stdio.h>

int main() {
    int altura = 5;  // Altura de la pirámide (5 filas para una base de 9 asteriscos)
    
    for (int i = 0; i < altura; i++) {
        // Imprimir espacios
        for (int j = 0; j < altura - i - 1; j++) {
            printf(" ");
        }
        
        // Imprimir asteriscos
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        
        // Mover a la siguiente línea
        printf("\n");
    }
    
    return 0;
}