#include <stdio.h>

int main(){
    int sumaTotal = 0;

    for(int i = 1; i <= 10; i++){
        printf("%d\n", i);
        sumaTotal += i;
    }

    printf("\nLa suma total es: %d", sumaTotal);
    return 0;
}