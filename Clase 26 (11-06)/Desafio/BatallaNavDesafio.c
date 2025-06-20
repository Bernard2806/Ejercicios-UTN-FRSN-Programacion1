#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Definiciones del juego original
#define TAMAÑO_TABLERO 10
#define NUM_PORTAAVIONES 1 // 5 casillas
#define NUM_ACORAZADOS 1   // 4 casillas
#define NUM_CRUCEROS 2     // 3 casillas
#define NUM_DESTRUCTORES 3 // 2 casillas
#define NUM_SUBMARINOS 4   // 1 casilla
#define TOTAL_BARCOS (NUM_PORTAAVIONES + NUM_ACORAZADOS + NUM_CRUCEROS + NUM_DESTRUCTORES + NUM_SUBMARINOS)

// Símbolos del tablero
#define AGUA '~'
#define BARCO '#'
#define IMPACTO 'X'
#define FALLO 'O'
#define HUNDIDO '*'

// Códigos de retorno
#define EXITO 0
#define ERROR_PARAMETRO -1
#define ERROR_POSICION -2
#define ERROR_OCUPADO -3
#define RESULTADO_AGUA 0
#define RESULTADO_IMPACTO 1
#define RESULTADO_HUNDIDO 2
#define RESULTADO_YA_DISPARADO -1

// Tipos de barcos según el juego original
typedef enum
{
    PORTAAVIONES = 5,
    ACORAZADO = 4,
    CRUCERO = 3,
    DESTRUCTOR = 2,
    SUBMARINO = 1
} TipoBarco;

// Estructura para coordenadas
typedef struct
{
    int fila;
    int columna;
} Coordenada;

// Estructura para un barco
typedef struct
{
    TipoBarco tipo;
    int longitud;
    Coordenada posiciones[5];
    bool hundido;
    int impactos;
    char nombre[20];
} Barco;

// Estructura del jugador
typedef struct
{
    char tablero_propio[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    char tablero_enemigo[TAMAÑO_TABLERO][TAMAÑO_TABLERO];
    Barco barcos[TOTAL_BARCOS];
    int num_barcos;
    int barcos_hundidos;
    char nombre[50];
} Jugador;

// Estructura del juego
typedef struct
{
    Jugador *jugador1;
    Jugador *jugador2;
    Jugador *jugador_actual;
    bool modo_un_jugador;
    bool juego_terminado;
} Juego;

// Prototipos de funciones
void inicializar_jugador(Jugador *jugador, const char *nombre);
void inicializar_tablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO]);
bool validar_coordenadas(int fila, int columna);
bool puede_colocar_barco(const Jugador *jugador, int fila, int columna, int longitud, bool horizontal);
int colocar_barco(Jugador *jugador, TipoBarco tipo, int fila, int columna, bool horizontal);
void colocar_barcos_aleatorios(Jugador *jugador);
void colocar_barcos_manual(Jugador *jugador);
int disparar(Jugador *atacante, Jugador *defensor, int fila, int columna);
bool verificar_barco_hundido(Jugador *jugador, int indice_barco);
bool verificar_ganador(const Jugador *jugador);
void mostrar_tablero_propio(const Jugador *jugador);
void mostrar_tablero_enemigo(const Jugador *jugador);
void mostrar_tableros_lado_a_lado(const Jugador *jugador);
void mostrar_estadisticas(const Jugador *jugador);
void limpiar_pantalla(void);
void pausar(void);
char *obtener_nombre_barco(TipoBarco tipo);
void mostrar_menu_principal(void);
void mostrar_instrucciones(void);
Coordenada leer_coordenada(void);
void turno_humano(Juego *juego);
void turno_ia(Juego *juego);
void inicializar_juego(Juego *juego);
void ejecutar_juego(void);

int main()
{
    srand(time(NULL));
    ejecutar_juego();
    return 0;
}

void inicializar_jugador(Jugador *jugador, const char *nombre)
{
    strcpy(jugador->nombre, nombre);
    inicializar_tablero(jugador->tablero_propio);
    inicializar_tablero(jugador->tablero_enemigo);
    jugador->num_barcos = 0;
    jugador->barcos_hundidos = 0;
}

void inicializar_tablero(char tablero[TAMAÑO_TABLERO][TAMAÑO_TABLERO])
{
    for (int i = 0; i < TAMAÑO_TABLERO; i++)
    {
        for (int j = 0; j < TAMAÑO_TABLERO; j++)
        {
            tablero[i][j] = AGUA;
        }
    }
}

bool validar_coordenadas(int fila, int columna)
{
    return (fila >= 0 && fila < TAMAÑO_TABLERO && columna >= 0 && columna < TAMAÑO_TABLERO);
}

bool puede_colocar_barco(const Jugador *jugador, int fila, int columna, int longitud, bool horizontal)
{
    // Verificar límites
    if (horizontal && (columna + longitud > TAMAÑO_TABLERO))
        return false;
    if (!horizontal && (fila + longitud > TAMAÑO_TABLERO))
        return false;

    // Verificar espacios libres (incluye verificación de casillas adyacentes)
    for (int i = -1; i <= longitud; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int f = horizontal ? fila + j : fila + i;
            int c = horizontal ? columna + i : columna + j;

            if (validar_coordenadas(f, c))
            {
                if (i >= 0 && i < longitud && j == 0)
                {
                    // Casilla del barco
                    if (jugador->tablero_propio[f][c] != AGUA)
                        return false;
                }
                else
                {
                    // Casilla adyacente - solo verificar si hay otro barco
                    if (jugador->tablero_propio[f][c] == BARCO)
                        return false;
                }
            }
        }
    }
    return true;
}

int colocar_barco(Jugador *jugador, TipoBarco tipo, int fila, int columna, bool horizontal)
{
    int longitud = (int)tipo;

    if (!validar_coordenadas(fila, columna))
        return ERROR_POSICION;
    if (!puede_colocar_barco(jugador, fila, columna, longitud, horizontal))
        return ERROR_OCUPADO;

    // Crear el barco
    Barco *nuevo_barco = &jugador->barcos[jugador->num_barcos];
    nuevo_barco->tipo = tipo;
    nuevo_barco->longitud = longitud;
    nuevo_barco->hundido = false;
    nuevo_barco->impactos = 0;
    strcpy(nuevo_barco->nombre, obtener_nombre_barco(tipo));

    // Colocar el barco en el tablero
    for (int i = 0; i < longitud; i++)
    {
        int f = horizontal ? fila : fila + i;
        int c = horizontal ? columna + i : columna;

        jugador->tablero_propio[f][c] = BARCO;
        nuevo_barco->posiciones[i].fila = f;
        nuevo_barco->posiciones[i].columna = c;
    }

    jugador->num_barcos++;
    return EXITO;
}

void colocar_barcos_aleatorios(Jugador *jugador)
{
    TipoBarco tipos[] = {PORTAAVIONES, ACORAZADO, CRUCERO, CRUCERO, DESTRUCTOR, DESTRUCTOR, DESTRUCTOR, SUBMARINO, SUBMARINO, SUBMARINO, SUBMARINO};
    int num_tipos = sizeof(tipos) / sizeof(tipos[0]);

    for (int i = 0; i < num_tipos; i++)
    {
        bool colocado = false;
        int intentos = 0;

        while (!colocado && intentos < 1000)
        {
            int fila = rand() % TAMAÑO_TABLERO;
            int columna = rand() % TAMAÑO_TABLERO;
            bool horizontal = rand() % 2;

            if (colocar_barco(jugador, tipos[i], fila, columna, horizontal) == EXITO)
            {
                colocado = true;
            }
            intentos++;
        }
    }
}

void colocar_barcos_manual(Jugador *jugador)
{
    TipoBarco tipos[] = {PORTAAVIONES, ACORAZADO, CRUCERO, CRUCERO, DESTRUCTOR, DESTRUCTOR, DESTRUCTOR, SUBMARINO, SUBMARINO, SUBMARINO, SUBMARINO};
    int num_tipos = sizeof(tipos) / sizeof(tipos[0]);

    printf("\n=== COLOCACIÓN DE BARCOS PARA %s ===\n", jugador->nombre);
    printf("Instrucciones:\n");
    printf("- Ingresa las coordenadas como: fila(0-9) columna(0-9)\n");
    printf("- Ejemplo: 3 5 para fila 3, columna 5\n");
    printf("- Orientación: H para horizontal, V para vertical\n\n");

    for (int i = 0; i < num_tipos; i++)
    {
        bool colocado = false;

        while (!colocado)
        {
            limpiar_pantalla();
            mostrar_tablero_propio(jugador);

            printf("\nColocando: %s (Tamaño: %d casillas)\n", obtener_nombre_barco(tipos[i]), tipos[i]);
            printf("Ingresa fila y columna: ");

            int fila, columna;
            if (scanf("%d %d", &fila, &columna) != 2)
            {
                printf("Entrada inválida. Intenta de nuevo.\n");
                while (getchar() != '\n')
                    ; // Limpiar buffer
                pausar();
                continue;
            }

            printf("Orientación (H/V): ");
            char orientacion;
            scanf(" %c", &orientacion);

            bool horizontal = (orientacion == 'H' || orientacion == 'h');

            int resultado = colocar_barco(jugador, tipos[i], fila, columna, horizontal);

            switch (resultado)
            {
            case EXITO:
                colocado = true;
                printf("¡Barco colocado exitosamente!\n");
                break;
            case ERROR_POSICION:
                printf("Posición inválida. Intenta de nuevo.\n");
                break;
            case ERROR_OCUPADO:
                printf("Posición ocupada o muy cerca de otro barco. Intenta de nuevo.\n");
                break;
            }

            if (!colocado)
                pausar();
        }
    }
}

int disparar(Jugador *atacante, Jugador *defensor, int fila, int columna)
{
    if (!validar_coordenadas(fila, columna))
        return ERROR_POSICION;

    char *casilla = &defensor->tablero_propio[fila][columna];
    char *casilla_atacante = &atacante->tablero_enemigo[fila][columna];

    // Verificar si ya se disparó a esta posición
    if (*casilla_atacante != AGUA)
        return RESULTADO_YA_DISPARADO;

    if (*casilla == BARCO)
    {
        *casilla = IMPACTO;
        *casilla_atacante = IMPACTO;

        // Buscar el barco impactado
        for (int i = 0; i < defensor->num_barcos; i++)
        {
            Barco *barco = &defensor->barcos[i];
            for (int j = 0; j < barco->longitud; j++)
            {
                if (barco->posiciones[j].fila == fila && barco->posiciones[j].columna == columna)
                {
                    barco->impactos++;
                    if (verificar_barco_hundido(defensor, i))
                    {
                        // Marcar barco como hundido en ambos tableros
                        for (int k = 0; k < barco->longitud; k++)
                        {
                            int f = barco->posiciones[k].fila;
                            int c = barco->posiciones[k].columna;
                            defensor->tablero_propio[f][c] = HUNDIDO;
                            atacante->tablero_enemigo[f][c] = HUNDIDO;
                        }
                        defensor->barcos_hundidos++;
                        return RESULTADO_HUNDIDO;
                    }
                    return RESULTADO_IMPACTO;
                }
            }
        }
    }
    else
    {
        *casilla_atacante = FALLO;
        return RESULTADO_AGUA;
    }

    return RESULTADO_AGUA;
}

bool verificar_barco_hundido(Jugador *jugador, int indice_barco)
{
    Barco *barco = &jugador->barcos[indice_barco];
    if (barco->impactos >= barco->longitud)
    {
        barco->hundido = true;
        return true;
    }
    return false;
}

bool verificar_ganador(const Jugador *jugador)
{
    return jugador->barcos_hundidos >= TOTAL_BARCOS;
}

void mostrar_tablero_propio(const Jugador *jugador)
{
    printf("\n=== TABLERO DE %s ===\n", jugador->nombre);
    printf("   ");
    for (int j = 0; j < TAMAÑO_TABLERO; j++)
    {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMAÑO_TABLERO; i++)
    {
        printf(" %d ", i);
        for (int j = 0; j < TAMAÑO_TABLERO; j++)
        {
            printf(" %c ", jugador->tablero_propio[i][j]);
        }
        printf("\n");
    }
}

void mostrar_tablero_enemigo(const Jugador *jugador)
{
    printf("\n=== TABLERO ENEMIGO ===\n");
    printf("   ");
    for (int j = 0; j < TAMAÑO_TABLERO; j++)
    {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMAÑO_TABLERO; i++)
    {
        printf(" %d ", i);
        for (int j = 0; j < TAMAÑO_TABLERO; j++)
        {
            printf(" %c ", jugador->tablero_enemigo[i][j]);
        }
        printf("\n");
    }
}

void mostrar_tableros_lado_a_lado(const Jugador *jugador)
{
    printf("\n=== TU FLOTA ===              === TABLERO ENEMIGO ===\n");
    printf("   ");
    for (int j = 0; j < TAMAÑO_TABLERO; j++)
    {
        printf(" %d ", j);
    }
    printf("           ");
    for (int j = 0; j < TAMAÑO_TABLERO; j++)
    {
        printf(" %d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMAÑO_TABLERO; i++)
    {
        printf(" %d ", i);
        for (int j = 0; j < TAMAÑO_TABLERO; j++)
        {
            printf(" %c ", jugador->tablero_propio[i][j]);
        }
        printf("       %d ", i);
        for (int j = 0; j < TAMAÑO_TABLERO; j++)
        {
            printf(" %c ", jugador->tablero_enemigo[i][j]);
        }
        printf("\n");
    }
}

void mostrar_estadisticas(const Jugador *jugador)
{
    printf("\n=== ESTADÍSTICAS DE %s ===\n", jugador->nombre);
    printf("Barcos hundidos: %d/%d\n", jugador->barcos_hundidos, TOTAL_BARCOS);
    printf("Barcos restantes:\n");

    for (int i = 0; i < jugador->num_barcos; i++)
    {
        Barco *barco = &jugador->barcos[i];
        if (!barco->hundido)
        {
            printf("- %s (%d/%d impactos)\n", barco->nombre, barco->impactos, barco->longitud);
        }
    }
}

void limpiar_pantalla(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausar(void)
{
    printf("\nPresiona Enter para continuar...");
    while (getchar() != '\n')
        ;
    getchar();
}

char *obtener_nombre_barco(TipoBarco tipo)
{
    switch (tipo)
    {
    case PORTAAVIONES:
        return "Portaaviones";
    case ACORAZADO:
        return "Acorazado";
    case CRUCERO:
        return "Crucero";
    case DESTRUCTOR:
        return "Destructor";
    case SUBMARINO:
        return "Submarino";
    default:
        return "Desconocido";
    }
}

void mostrar_menu_principal(void)
{
    limpiar_pantalla();
    printf("=================================\n");
    printf("      BATALLA NAVAL v2.0\n");
    printf("=================================\n");
    printf("1. Jugar contra la computadora\n");
    printf("2. Jugar dos jugadores\n");
    printf("3. Instrucciones\n");
    printf("4. Salir\n");
    printf("=================================\n");
    printf("Selecciona una opción: ");
}

void mostrar_instrucciones(void)
{
    limpiar_pantalla();
    printf("=== INSTRUCCIONES DE BATALLA NAVAL ===\n\n");
    printf("OBJETIVO:\n");
    printf("Hundir todos los barcos del enemigo antes que él hunda los tuyos.\n\n");
    printf("BARCOS (Juego clásico):\n");
    printf("- 1 Portaaviones (5 casillas)\n");
    printf("- 1 Acorazado (4 casillas)\n");
    printf("- 2 Cruceros (3 casillas cada uno)\n");
    printf("- 3 Destructores (2 casillas cada uno)\n");
    printf("- 4 Submarinos (1 casilla cada uno)\n\n");
    printf("SÍMBOLOS:\n");
    printf("~ = Agua\n");
    printf("# = Tu barco\n");
    printf("O = Disparo fallido\n");
    printf("X = Impacto\n");
    printf("* = Barco hundido\n\n");
    printf("REGLAS:\n");
    printf("- Los barcos no pueden tocarse (ni siquiera en diagonal)\n");
    printf("- Debes disparar por turnos\n");
    printf("- Si aciertas, puedes disparar de nuevo\n");
    printf("- Gana quien hunda todos los barcos enemigos primero\n\n");
    pausar();
}

Coordenada leer_coordenada(void)
{
    Coordenada coord = {-1, -1};
    printf("Ingresa fila y columna (0-9 0-9): ");
    if (scanf("%d %d", &coord.fila, &coord.columna) != 2)
    {
        while (getchar() != '\n')
            ; // Limpiar buffer
    }
    return coord;
}

void turno_humano(Juego *juego)
{
    Jugador *atacante = juego->jugador_actual;
    Jugador *defensor = (juego->jugador_actual == juego->jugador1) ? juego->jugador2 : juego->jugador1;

    bool turno_continua = true;

    while (turno_continua && !juego->juego_terminado)
    {
        limpiar_pantalla();
        printf("=== TURNO DE %s ===\n", atacante->nombre);
        mostrar_tableros_lado_a_lado(atacante);
        mostrar_estadisticas(defensor);

        Coordenada coord = leer_coordenada();

        if (!validar_coordenadas(coord.fila, coord.columna))
        {
            printf("Coordenadas inválidas. Intenta de nuevo.\n");
            pausar();
            continue;
        }

        int resultado = disparar(atacante, defensor, coord.fila, coord.columna);

        switch (resultado)
        {
        case RESULTADO_AGUA:
            printf("¡Agua! Turno perdido.\n");
            turno_continua = false;
            break;
        case RESULTADO_IMPACTO:
            printf("¡IMPACTO! Puedes disparar de nuevo.\n");
            break;
        case RESULTADO_HUNDIDO:
            printf("¡BARCO HUNDIDO! Puedes disparar de nuevo.\n");
            if (verificar_ganador(defensor))
            {
                printf("¡%s HA GANADO LA BATALLA!\n", atacante->nombre);
                juego->juego_terminado = true;
                turno_continua = false;
            }
            break;
        case RESULTADO_YA_DISPARADO:
            printf("Ya disparaste a esa posición. Intenta otra.\n");
            break;
        }

        if (!juego->juego_terminado && resultado != RESULTADO_YA_DISPARADO)
        {
            pausar();
        }
    }
}

void turno_ia(Juego *juego)
{
    Jugador *atacante = juego->jugador2; // IA
    Jugador *defensor = juego->jugador1; // Humano

    bool turno_continua = true;

    while (turno_continua && !juego->juego_terminado)
    {
        printf("=== TURNO DE LA COMPUTADORA ===\n");

        // IA simple: disparo aleatorio
        int fila, columna;
        do
        {
            fila = rand() % TAMAÑO_TABLERO;
            columna = rand() % TAMAÑO_TABLERO;
        } while (atacante->tablero_enemigo[fila][columna] != AGUA);

        printf("La computadora dispara a (%d, %d)...\n", fila, columna);

        int resultado = disparar(atacante, defensor, fila, columna);

        switch (resultado)
        {
        case RESULTADO_AGUA:
            printf("La computadora falló. Tu turno.\n");
            turno_continua = false;
            break;
        case RESULTADO_IMPACTO:
            printf("¡La computadora te impactó! Sigue su turno.\n");
            break;
        case RESULTADO_HUNDIDO:
            printf("¡La computadora hundió uno de tus barcos!\n");
            if (verificar_ganador(defensor))
            {
                printf("¡LA COMPUTADORA HA GANADO!\n");
                juego->juego_terminado = true;
                turno_continua = false;
            }
            break;
        }

        pausar();
    }
}

void inicializar_juego(Juego *juego)
{
    juego->juego_terminado = false;
    juego->jugador_actual = juego->jugador1;
}

void ejecutar_juego(void)
{
    int opcion;

    do
    {
        mostrar_menu_principal();
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            // Juego contra IA
            Juego juego;
            Jugador jugador1, jugador2;

            printf("Ingresa tu nombre: ");
            scanf("%s", jugador1.nombre);

            inicializar_jugador(&jugador1, jugador1.nombre);
            inicializar_jugador(&jugador2, "Computadora");

            juego.jugador1 = &jugador1;
            juego.jugador2 = &jugador2;
            juego.modo_un_jugador = true;
            inicializar_juego(&juego);

            // Colocar barcos
            printf("\n¿Cómo quieres colocar tus barcos?\n1. Manual\n2. Automático\nOpción: ");
            int modo_colocacion;
            scanf("%d", &modo_colocacion);

            if (modo_colocacion == 1)
            {
                colocar_barcos_manual(&jugador1);
            }
            else
            {
                colocar_barcos_aleatorios(&jugador1);
            }

            colocar_barcos_aleatorios(&jugador2);

            // Bucle principal del juego
            while (!juego.juego_terminado)
            {
                if (juego.jugador_actual == &jugador1)
                {
                    turno_humano(&juego);
                    juego.jugador_actual = &jugador2;
                }
                else
                {
                    turno_ia(&juego);
                    juego.jugador_actual = &jugador1;
                }
            }

            printf("\n¡JUEGO TERMINADO!\n");
            pausar();
            break;
        }
        case 2:
        {
            // Juego para dos jugadores
            Juego juego;
            Jugador jugador1, jugador2;

            printf("Ingresa nombre del Jugador 1: ");
            scanf("%s", jugador1.nombre);
            printf("Ingresa nombre del Jugador 2: ");
            scanf("%s", jugador2.nombre);

            inicializar_jugador(&jugador1, jugador1.nombre);
            inicializar_jugador(&jugador2, jugador2.nombre);

            juego.jugador1 = &jugador1;
            juego.jugador2 = &jugador2;
            juego.modo_un_jugador = false;
            inicializar_juego(&juego);

            // Colocar barcos para ambos jugadores
            colocar_barcos_manual(&jugador1);
            colocar_barcos_manual(&jugador2);

            // Bucle principal del juego
            while (!juego.juego_terminado)
            {
                turno_humano(&juego);
                if (!juego.juego_terminado)
                {
                    juego.jugador_actual = (juego.jugador_actual == &jugador1) ? &jugador2 : &jugador1;
                }
            }

            printf("\n¡JUEGO TERMINADO!\n");
            pausar();
            break;
        }
        case 3:
            mostrar_instrucciones();
            break;
        case 4:
            printf("¡Gracias por jugar Batalla Naval!\n");
            break;
        default:
            printf("Opción inválida.\n");
            pausar();
        }
    } while (opcion != 4);
}