#include <stdio.h> // Incluimos la librería stdio.h para poder usar las funciones printf y scanf.

int main()
{
    // Declaramos las variables necesarias
    int horas, minutos, segundos, totalEnSegundos; // horas, minutos y segundos son los valores ingresados por el usuario, totalEnSegundos almacenará el cálculo final.

    // Pedimos al usuario que ingrese la cantidad de horas
    printf("Ingrese la Cantidad de Horas: ");
    scanf("%d", &horas); // Leemos el valor de las horas.

    // Pedimos al usuario que ingrese la cantidad de minutos
    printf("Ingrese la Cantidad de Minutos: ");
    scanf("%d", &minutos); // Leemos el valor de los minutos.

    // Pedimos al usuario que ingrese la cantidad de segundos
    printf("Ingrese la Cantidad de Segundos: ");
    scanf("%d", &segundos); // Leemos el valor de los segundos.

    // Calculamos el total en segundos
    totalEnSegundos = (horas * 3600) + (minutos * 60) + segundos; // Convertimos horas y minutos a segundos y sumamos los segundos.

    // Mostramos el resultado
    printf("\nEl total de segundos es %d", totalEnSegundos); // Imprimimos el total de segundos calculado.

    return 0; // El programa finaliza correctamente.
}