#include <stdio.h>

// Función que devuelve 1 si el número es positivo, 0 si es cero o negativo
int esPositivo(int numero) {
    return (numero > 0);
}

int main() {
    int numeroUsuario;
    
    // Solicita al usuario que ingrese un número
    printf("Ingrese un número: ");
    scanf("%d", &numeroUsuario);
    
    // Verifica si el número es positivo e imprime el resultado
    if (esPositivo(numeroUsuario)) {
        printf("El número es positivo\n");
    } else {
        printf("El número es negativo o cero\n");
    }
    
    return 0;
}