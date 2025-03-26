#include <stdio.h>

int main(){
    int edadUsuario, tieneMembresia;

    printf("Ingrese su edad: ");
    scanf("%d", &edadUsuario);

    printf("¿Tiene membresia? (1: Si, 0: No): ");
    scanf("%d", &tieneMembresia);

    if(edadUsuario >= 18 && tieneMembresia == 1){
        printf("Acceso permitido a la sala VIP");
    }
    else if(edadUsuario >= 18 && tieneMembresia == 0){
        printf("Acceso permitido a la pista comun");
    }
    else
    {
        printf("Acceso denegado");
    }
    return 0;
}