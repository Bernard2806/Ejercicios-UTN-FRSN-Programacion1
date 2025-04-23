#include <stdio.h>
#include <stdlib.h>

// Prototipos de Funciones

void cargarNombreEquipos(char equipos[][25], int cantidadEquipos);
void cargarPuntosEquipos(int equipos[][4], char equiposNombres[][25], int cantidadEquipos);

int main()
{
    char equiposNombres[2][25];
    int equiposPuntos[2][4];

    cargarNombreEquipos(equiposNombres, 2);
    cargarPuntosEquipos(equiposPuntos, equiposNombres, 2);

    return 0;
}

void cargarNombreEquipos(char equipos[][25], int cantidadEquipos)
{
    for (int i = 0; i < cantidadEquipos; i++)
    {
        printf("Ingrese el nombre del equipo %d: ", i + 1);

        fflush(stdin);                // Limpiar el buffer de entrada
        fgets(equipos[i], 25, stdin); // Leer el nombre del equipo
    }
}

void cargarPuntosEquipos(int equipos[][4], char equiposNombres[][25], int cantidadEquipos)
{
    for (int i = 0; i < cantidadEquipos; i++)
    {
        printf("Ingrese los puntos del equipo %s: ", equiposNombres[i]);
        
        for (int j = 0; j < 4; j++)
        {
            printf("Puntos %d: ", j + 1);
            scanf("%d", &equipos[i][j]);
        }
    }
}