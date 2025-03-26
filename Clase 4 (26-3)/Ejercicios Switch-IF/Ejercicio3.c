#include <stdio.h>

int main(){
    int diaDeLaSemana;

    printf("Ingrese un numero del 1 al 7: ");
    scanf("%d", &diaDeLaSemana);

    switch (diaDeLaSemana){
        case 1:
            printf("\nLunes");
            break;
        case 2:
            printf("\nMartes");
            break;
        case 3:
            printf("\nMiercoles");
            break;
        case 4:
            printf("\nJueves");
            break;
        case 5:
            printf("\nViernes");
            break;
        case 6:
            printf("\nSabado");
            break;
        case 7:
            printf("\nDomingo");
            break;
        default:
            printf("\nNumero incorrecto");
            break;
    }

    return 0;
}