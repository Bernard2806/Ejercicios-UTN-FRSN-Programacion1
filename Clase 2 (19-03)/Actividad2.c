#include <stdio.h>

int main(){
    // Declaración de variables para almacenar los datos del usuario
    char nombre[25];      // Array de caracteres para el nombre (25 caracteres máximo)
    char direccion[150];   // Array de caracteres para la dirección (150 caracteres máximo)
    char telefono[16];    // Array de caracteres para el teléfono (16 caracteres máximo (15 caracteres + terminador nulo)) (La longitud máxima de un número de teléfono está establecida por el estándar E.164 15 caracteres)

    // Solicitud y lectura del nombre
    printf("Ingrese tu nombre: ");
    scanf("%s", nombre);

    // Solicitud y lectura de la dirección
    printf("Ingresa tu direccion: ");
    fflush(stdin);        // Limpia el buffer de entrada
    gets(direccion);      // Lee la dirección completa (permite espacios)

    // Solicitud y lectura del teléfono
    printf("Ingresa tu telefono: ");
    scanf("%15s", telefono); // Limitamos el número de caracteres que se pueden ingresar

    // Bucle que imprime los datos 3 veces
    for(int i = 0; i < 3; i++){
        printf("\n\n Mi Nombre es %s, Mi Direccion es: %s, Mi Telefono es: %s", 
               nombre, direccion, telefono); // Muestra todos los datos
    }
    
    return 0; 
}