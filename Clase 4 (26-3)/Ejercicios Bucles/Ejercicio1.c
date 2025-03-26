#include <stdio.h>

int main(){
    int sumaTotal = 0;

    for(int i = 1; i <= 10; i++){
        printf("%d\n", i);
        sumaTotal += i;
    }

    printf("La suma total es: %d\n", sumaTotal);
    return 0;
}