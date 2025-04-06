#include <stdio.h>

char obtenerInicialDia(int numeroDia) {
    char inicial;
    
    switch(numeroDia) {
        case 1:
            inicial = 'L';
            break;
        case 2:
            inicial = 'M';
            break;
        case 3:
            inicial = 'X';
            break;
        case 4:
            inicial = 'J';
            break;
        case 5:
            inicial = 'V';
            break;
        case 6:
            inicial = 'S';
            break;
        case 7:
            inicial = 'D';
            break;
        default:
            inicial = ' ';
    }
    
    return inicial;
}

int main() {
    int numero;
    
    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &numero);
    
    char inicial = obtenerInicialDia(numero);
    
    if(inicial != ' ') {
        printf("La inicial del dia es: %c\n", inicial);
    } else {
        printf("Numero invalido. Debe ser entre 1 y 7.\n");
    }
    
    return 0;
}