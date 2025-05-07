#include <stdio.h>

int main()
{

    int x = 20;
    int *puntero;
    puntero = &x;

    printf("Valor de x en x: %d \n", x);
    printf("Valor de &x en x: %p \n", &x);
    printf("Valor de puntero: %p \n", puntero);
    printf("Valor de x desde puntero: %d \n", *puntero);

    return 0;
}