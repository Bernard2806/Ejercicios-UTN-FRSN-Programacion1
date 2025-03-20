#include <stdio.h>

int main(){
    char nombre[50];
    char direccion[50];
    int telefono;

    printf("Ingrese tu nombre: ");
    scanf("%s", nombre);

    printf("Ingresa tu dirección: ");
    scanf("%s", direccion);

    printf("Ingersa tu telefono: ");
    scanf("%d", &telefono);

    printf("Mi Nombre es %s, Mi Dirección es: %s, Mi Telefono es: %d \n\n", nombre, direccion, telefono);

    return 0; 
}