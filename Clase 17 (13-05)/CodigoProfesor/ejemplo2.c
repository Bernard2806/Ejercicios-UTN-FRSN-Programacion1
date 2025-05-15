#include <stdio.h>
#include <string.h>

typedef struct
{
    int dia;
    int mes;
    int anio;
}FechaNacimiento;


typedef struct
{
    char nombre[50];
    int edad;
    FechaNacimiento fecha;
}Persona;

int main(){

    /* struct Persona personas[3] = {
        {"matias", 33},
        {"guido", 24},
        {"rocio", 33}
    }; */

    Persona personas[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese Persona %d\n", i + 1);
        printf("Ingrese nombre: ");
        scanf("%s", personas[i].nombre);
        printf("Ingrese edad: ");
        scanf("%d", &personas[i].edad);
        printf("Ingrese dia de nac: ");
        scanf("%d", &personas[i].fecha.dia);
        printf("Ingrese numero mes nacimiento: ");
        scanf("%d", &personas[i].fecha.mes);
        printf("Ingrese anio nacimiento: ");
        scanf("%d", &personas[i].fecha.anio);
    }
    printf("\nImprimimos \n\n");

    for (int i = 0; i < 3; i++)
    {
        
        printf("Persona %d\n", i + 1);
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Edad: %d\n", personas[i].edad);
        printf("Fecha Nacimiento %d/%d/%d\n", personas[i].fecha.dia, personas[i].fecha.mes, personas[i].fecha.anio);
    }
    
    
    
    return 0;
}