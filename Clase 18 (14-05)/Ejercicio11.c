#include <stdio.h>
#include <string.h>

#define MAX_ALUMNOS 40

typedef struct
{
    char nombre[51];
    int edad;
    float nota;
} Alumno;

// Prototipos
void cargarAlumnos(Alumno *alumnos, int *cantidad);
void procesarDatos(const Alumno *alumnos, int cantidad);

int main()
{
    Alumno alumnos[MAX_ALUMNOS];
    int cantidadAlumnos = 0;

    cargarAlumnos(alumnos, &cantidadAlumnos);
    procesarDatos(alumnos, cantidadAlumnos);

    return 0;
}

// Función para cargar los datos
void cargarAlumnos(Alumno *alumnos, int *cantidad)
{
    char nombreTemp[51];
    int i = 0;

    while (i < MAX_ALUMNOS)
    {
        printf("Ingrese el nombre del alumno %d (o * para terminar): ", i + 1);
        fgets(nombreTemp, sizeof(nombreTemp), stdin);
        nombreTemp[strcspn(nombreTemp, "\n")] = '\0'; // Quitar salto de línea

        if (strcmp(nombreTemp, "*") == 0)
        {
            break;
        }

        strcpy(alumnos[i].nombre, nombreTemp);

        printf("  Edad: ");
        scanf("%d", &alumnos[i].edad);

        printf("  Nota: ");
        scanf("%f", &alumnos[i].nota);

        getchar(); // Limpiar el buffer de entrada

        i++;
    }

    *cantidad = i;
}

// Función para procesar los datos
void procesarDatos(const Alumno *alumnos, int cantidad)
{
    int mayoresDe30 = 0;
    float sumaNotas = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (alumnos[i].edad > 30)
            mayoresDe30++;

        sumaNotas += alumnos[i].nota;
    }

    float promedio = (cantidad > 0) ? sumaNotas / cantidad : 0;

    printf("\n--- Informe ---\n");
    printf("Cantidad de alumnos mayores de 30 años: %d\n", mayoresDe30);
    printf("Promedio de notas: %.2f\n", promedio);
}