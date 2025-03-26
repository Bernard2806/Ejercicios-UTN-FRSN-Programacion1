#include <stdio.h>

int main(){
    int i = 0, cont = 0;
    while(i <= 20){

        printf("%d\n", i);
        i++;

        if(i % 2 == 0){
            cont++;
        }
    }

    printf("\nCantidad de numeros pares: %d", cont);
    return 0;
}