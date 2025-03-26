#include <stdio.h>

int main(){
    int edad;

    printf("Ingrese su edad: ");
    scanf("%d", &edad);

    if(edad >= 18)
    {
        printf("\nPodes votar");
    }
    else if(edad >= 16)
    {
        printf("\nPodes votar con permiso de tus padres");
    }
    else
    {
        printf("\nNo podes votar");
    }

    return 0;
}