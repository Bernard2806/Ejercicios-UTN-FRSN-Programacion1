#include <stdio.h>
#include <stdlib.h>

// Definir el tamaño de la Matriz
#define FILAS 4
#define COLUMNAS 3

// Prototipos de Funciones
int generarNumeroAleatorio(int min, int max);
void cargarMatrizPorReferencia(int *matriz[FILAS][COLUMNAS]);

// Idea de un Ejercicio para el Parcial realizada por alguien más
// La verdad que no me acuerdo que planteamos el codigo, y la idea del Ejercicio Original
// Son de Lucas, Dinardo. (Preguntar otro dia si se acuerda de que era el ejercicio)


int main(){
    int matriz[FILAS][COLUMNAS];

    return 0;
}

int generarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min; // Genera un número aleatorio entre min y max
}

void cargarMatrizPorReferencia(int *matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = generarNumeroAleatorio(1, 100); // Carga la matriz con números aleatorios entre 1 y 100
        }
    }
}