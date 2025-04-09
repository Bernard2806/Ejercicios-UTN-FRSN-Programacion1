#include <stdio.h>

void mostrarArrayDeCaracteres(char caracteres[], int longitud)
{

    printf("El array tiene %d elementos\n", longitud);

    for (int i = 0; i < longitud; i++)
    {
        printf("%c ", caracteres[i]);
    }
}

int main(){
    char simbolos[10];

    simbolos[0] = 'a';
    simbolos[1] = 'x';
    simbolos[4] = '@';

    mostrarArrayDeCaracteres(simbolos, 10);
    return 0;
}