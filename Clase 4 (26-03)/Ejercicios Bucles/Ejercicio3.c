#include <stdio.h>

int main(){
    int i = 10;

    do{
        printf("%d\n", i);
        i--;
    } while(i >= 1);

    printf("\nFin del bucle");

    return 0;
}