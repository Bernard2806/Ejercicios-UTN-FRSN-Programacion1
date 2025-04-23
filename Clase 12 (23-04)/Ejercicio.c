#include <stdio.h>
#include <stdlib.h>

// Prototipos de Funciones

void cargarNombreEquipos(char equipos[][25], int cantidadEquipos);
void cargarPuntosEquipos(int equipos[][4], char equiposNombres[][25], int cantidadEquipos);
void mostrarTablaEquipos(int equipos[][4], char equiposNombres[][25]);

int calcularPuntosTotalEquipo(int equipos[][4], int equipo);

int main()
{
    char equiposNombres[2][25];
    int equiposPuntos[2][4];

    cargarNombreEquipos(equiposNombres, 2);
    cargarPuntosEquipos(equiposPuntos, equiposNombres, 2);

    mostrarTablaEquipos(equiposPuntos, equiposNombres);
    
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
        printf("Ingrese los puntos del equipo %s: \n", equiposNombres[i]);

        for (int j = 0; j < 4; j++)
        {
            printf("\tPuntos %d: ", j + 1);
            scanf("%d", &equipos[i][j]);
        }
    }
}

void mostrarTablaEquipos(int equipos[][4], char equiposNombres[][25]){
    printf("\nTabla de Equipos:\n");
    printf("Equipo\tP1\tP2\tP3\tP4\n");
    for (int f = 0; f < 2; f++)
    {
        printf("%s\t", equiposNombres[f]);
        for (int c = 0; c < 4; c++)
        {
            printf("%d\t", equipos[f][c]);
        }
        printf("Total: %d\n", calcularPuntosTotalEquipo(equipos, f));
    }
}

int calcularPuntosTotalEquipo(int equipos[][4], int equipo)
{
    int total = 0;

    for (int i = 0; i < 4; i++)
    {
        total += equipos[equipo][i];
    }

    return total;
}