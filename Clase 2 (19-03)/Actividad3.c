#include <stdio.h>

int main() {
    // Definimos la altura de la pirámide (número de filas)
    int altura = 5;  

    // Bucle principal que controla el número de filas
    for (int i = 0; i < altura; i++) {

        // Primer bucle interno: imprime los espacios en blanco
        // La cantidad de espacios disminuye en cada fila
        // En la primera fila son (altura - 1) espacios, y va disminuyendo
        for (int j = 0; j < altura - i - 1; j++) {
            printf(" ");
        }
        
        // Segundo bucle interno: imprime los asteriscos
        // La cantidad de asteriscos sigue la secuencia: 1,3,5,7,9
        // Se calcula como (2 * número_de_fila + 1)
        for (int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        
        // Después de cada fila, movemos el cursor a la siguiente línea
        printf("\n");
    }
    
    return 0;
}