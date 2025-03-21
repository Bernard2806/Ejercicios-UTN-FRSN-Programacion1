#include <stdio.h>

int main(){
    int horas, minutos, segundos, totalEnSegundos;

    printf("Ingrese la Cantidad de Horas");
    scanf("%d", &horas);

    printf("Ingrese la Cantidad de Minutos");
    scanf("%d", &minutos);

    printf("Ingrese la Cantidad de Segundos");
    scanf("%d", &segundos);

    totalEnSegundos = (horas * 3600) + (minutos * 60) + segundos;

    printf("\n");

    printf("El total de segundos es %d", totalEnSegundos);
    
    return 0;
}