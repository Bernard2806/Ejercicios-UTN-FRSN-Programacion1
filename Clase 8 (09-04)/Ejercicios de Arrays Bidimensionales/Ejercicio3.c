#include <stdio.h>

void cargarCantidadDeAlumnos(int c_matriz[3][3]){
    for(int i = 0; i < 3; i++){
        printf("\nCarrera %d (0=Programacion, 1=Alimentos, 2=Seguridad e Higiene)\n", i);
        for(int j = 0; j < 3; j++){
            printf("Ingrese cantidad de alumnos para el año %d: ", j+1);
            scanf("%d", &c_matriz[i][j]);
        }
    }
}

void mostrarMatrizComoTabla(int c_matriz[3][3]){
    printf("\n----- Tabla de Alumnos -----\n");
    printf("Carrera/Año:\t1º\t2º\t3º\n");
    char* carreras[] = {"Programacion", "Alimentos", "Seg. e Hig."};
    
    for(int i = 0; i < 3; i++){
        printf("%s\t", carreras[i]);
        for(int j = 0; j < 3; j++){
            printf("%d\t", c_matriz[i][j]);
        }
        printf("\n");
    }
}

void calcularEstadisticas(int c_matriz[3][3]){
    int totalPorCarrera[3] = {0};
    int totalPorAnio[3] = {0};
    int totalGeneral = 0;
    int maxAlumnos = 0;
    int carreraConMax = 0;
    
    // Calcular totales por carrera y encontrar la carrera con más alumnos
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            totalPorCarrera[i] += c_matriz[i][j];
            totalPorAnio[j] += c_matriz[i][j];
            totalGeneral += c_matriz[i][j];
        }
        if(totalPorCarrera[i] > maxAlumnos){
            maxAlumnos = totalPorCarrera[i];
            carreraConMax = i;
        }
    }
    
    // Mostrar resultados
    printf("\n----- Estadísticas -----\n");
    char* carreras[] = {"Programacion", "Alimentos", "Seguridad e Higiene"};
    
    printf("\nTotal de alumnos por carrera:");
    for(int i = 0; i < 3; i++){
        printf("\n%s: %d alumnos", carreras[i], totalPorCarrera[i]);
    }
    
    printf("\n\nTotal de alumnos por año:");
    for(int i = 0; i < 3; i++){
        printf("\nAño %d: %d alumnos", i+1, totalPorAnio[i]);
    }
    
    printf("\n\nCarrera con mayor cantidad de alumnos: %s con %d alumnos", 
           carreras[carreraConMax], maxAlumnos);
    
    printf("\n\nTotal general de estudiantes: %d\n", totalGeneral);
}

int main()
{
    int matriz[3][3];
    
    cargarCantidadDeAlumnos(matriz);
    mostrarMatrizComoTabla(matriz);
    calcularEstadisticas(matriz);

    return 0;
}