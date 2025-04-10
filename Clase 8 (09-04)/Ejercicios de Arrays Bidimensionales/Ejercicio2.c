#include <stdio.h>

void mostrarMatriz(int matriz[2][5]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void cargarMatriz(int matriz[2][5]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            printf("Ingrese el valor para la posicion [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main(){
    int matriz[2][5];

    cargarMatriz(matriz);

    printf("Matriz:\n");
    mostrarMatriz(matriz);

    return 0;
}