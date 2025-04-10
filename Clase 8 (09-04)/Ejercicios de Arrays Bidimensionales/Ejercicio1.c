#include <stdio.h>

void mostrarMatriz(int matriz[3][4]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int matriz[3][4] = {{1, 2, 3}, {4}, {7, 9}};

    printf("Matriz:\n");
    mostrarMatriz(matriz);

    return 0;
}