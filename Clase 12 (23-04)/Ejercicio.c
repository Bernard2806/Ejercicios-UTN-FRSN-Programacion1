#include <stdio.h>
#include <stdlib.h>

// Prototipos de Funciones

void cargarNombreEquipos(char equipos[][25], int cantidadEquipos);

int main()
{
    char equipos[2][25];

    cargarNombreEquipos(equipos, 2);

    return 0;
}

void cargarNombreEquipos(char equipos[][25], int cantidadEquipos)
{
    for (int i = 0; i < cantidadEquipos; i++)
    {
        printf("Ingrese el nombre del equipo %d: ", i + 1);
        fflush(stdin);
        fgets(equipos[i], 25, stdin);
    }
}
