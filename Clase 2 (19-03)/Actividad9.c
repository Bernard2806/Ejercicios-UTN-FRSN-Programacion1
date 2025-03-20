#include <stdio.h>

int main(){
    int horas, minutos, segundos, totalEnSegundos;

    prinf("Ingrese la Cantidad de Horas");
    scanf("%d", &horas);

    prinf("Ingrese la Cantidad de Minutos");
    scanf("%d", &minutos);

    prinf("Ingrese la Cantidad de Segundos");
    scanf("%d", &segundos);

    totalEnSegundos = (horas * 3600) + (minutos * 60) + segundos;

    prinf("\n");

    prinf("El total de segundos es %d", totalEnSegundos);
    
    return 0;
}