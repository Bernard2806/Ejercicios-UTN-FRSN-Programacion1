#include <stdio.h>

int main(){
    int hora;

    printf("Ingrese la hora (entre 0 y 23): ");
    scanf("%d", &hora);

    printf("\n");

    if(hora >= 6 && hora <= 11)
    {
        printf("Es de mañana");
    }
    else if(hora >= 12 && hora <= 17)
    {
        printf("Es de tarde");
    }
    else if(hora >= 18 && hora <= 23)
    {
        printf("Es de noche");
    }
    else if(hora >= 0 && hora <= 5)
    {
        printf("Es de madrugada");
    }
    else
    {
        printf("Hora incorrecta");
    }

    return 0;
}