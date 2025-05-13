#include <stdio.h>

// Estructura de datos que representa una persona
typedef struct {
    char nombre[25];
    char apellido[25]; 
    int edad;
    float altura;
} Persona;

// Prototipo de funciónes

void mostrarPersona(Persona p);
void cargarPersona(Persona *p);

int main(){
    Persona p1; // Declaración de una variable de tipo Persona

    cargarPersona(&p1); // Llamada a la función para cargar los datos de la persona

    printf("\nDatos de la persona:\n");
    mostrarPersona(p1); // Llamada a la función para mostrar los datos de la persona
    return 0;
}

void cargarPersona(Persona *p){
    printf("Ingrese el nombre: ");
    scanf("%s", p->nombre);
    printf("Ingrese el apellido: ");
    scanf("%s", p->apellido);
    printf("Ingrese la edad: ");
    scanf("%d", &p->edad);
    printf("Ingrese la altura: ");
    scanf("%f", &p->altura);
}

void mostrarPersona(Persona p){
    printf("Nombre: %s\n", p.nombre);
    printf("Edad: %d\n", p.edad);
    printf("Altura: %.2f\n", p.altura);
}