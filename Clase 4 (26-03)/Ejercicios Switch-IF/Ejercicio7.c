#include <stdio.h>

int main(){
    int anio;

    printf("Ingrese un anio: ");
    scanf("%d", &anio);

    if(anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
    {
        printf("El anio es bisiesto");
    }
    else
    {
        printf("El anio no es bisiesto");
    }
    
    return 0;
}