#include <stdio.h>

int main()
{

    int numeros[3] = {20, 30, 40};
    int *p = numeros;
    printf("Lo que tiene p: %p\n", p);
    printf("Lo que tiene *p (o sea adentro de la pos de memoria): %d\n", *p);
    p++;
    printf("Lo que tiene p: %p\n", p);
    printf("Lo que tiene *p (o sea adentro de la pos de memoria): %d\n", *p);
    p++;
    printf("Lo que tiene p: %p\n", p);
    printf("Lo que tiene *p (o sea adentro de la pos de memoria): %d\n", *p);

    return 0;
}