#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUNTOS_POR_ACIERTO 3
#define NUM_JUGADORES 2

typedef struct {
    char nombre[30];
    int correctas;
    int errores;
    int puntos;
} Jugador;

// Lee un entero >= 0. Si el usuario escribe letras o un numero negativo,
// vuelve a preguntar.
int leerEnteroNoNegativo(const char *mensaje) {
    int valor;
    int c;

    while (1) {
        printf("%s", mensaje);
        int resultado = scanf("%d", &valor);
        if (resultado == EOF) {
            exit(1);   // se acabo la entrada, salir
        }
        while ((c = getchar()) != '\n' && c != EOF);   // limpiar el buffer
        if (resultado == 1 && valor >= 0) {
            return valor;
        }
        printf("Valor invalido. Escribe un numero entero (0 o mayor).\n");
    }
}

// 1. Calcular puntos base BOOM
int calcularPuntosJugador(int correctas) {
    return correctas * PUNTOS_POR_ACIERTO;
}

// 2 y 3. Bonificaciones y penalizaciones BOOM
int aplicarReglasBoom(int puntosBase, int errores) {
    int puntos = puntosBase;

    if (errores == 0) {
        puntos += 10; // SOBREVIVIENTE: nunca te exploto la bomba
        printf(" -> BONUS SOBREVIVIENTE +10\n");
    } else if (errores == 1) {
        puntos += 3;
    } else if (errores >= 2) {
        // En BOOM explotar mucho te mata los puntos
        int penalizacion = errores * 2;
        puntos -= penalizacion;
        printf(" -> PENALIZACION BOOM -%d por %d explosiones\n", penalizacion, errores);
    }

    if (puntos < 0) puntos = 0;
    return puntos;
}

// 4. Bonificacion por empate en BOOM
int bonificacionEmpateBoom(int puntos, int esEmpate) {
    if (esEmpate) {
        printf(" -> BONUS EMPATE +2 (ronda de desempate superada)\n");
        return puntos + 2;
    }
    return puntos;
}

// 5. Comparar con record
void compararConRecord(int puntos, int recordAnterior) {
    if (puntos > recordAnterior) {
        printf(">>> NUEVO RECORD BOOM! %d -> %d <<<\n", recordAnterior, puntos);
    } else {
        printf("Record actual BOOM: %d | Tu puntaje: %d\n", recordAnterior, puntos);
    }
}

// Devuelve el puntaje mas alto de la partida
int puntajeMaximo(Jugador jugadores[], int numJugadores) {
    int max = jugadores[0].puntos;
    for (int i = 1; i < numJugadores; i++) {
        if (jugadores[i].puntos > max) {
            max = jugadores[i].puntos;
        }
    }
    return max;
}

// 6. Mostrar resultado final de partida BOOM
void mostrarResultadosFinales(Jugador jugadores[], int numJugadores, int record) {
    int max = puntajeMaximo(jugadores, numJugadores);
    int empatados = 0;
    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].puntos == max) empatados++;
    }

    // Empate: ronda de desempate. Solo gana el bonus quien tenga
    // mas aciertos en el desempate (si siguen igual, no hay bonus).
    if (empatados > 1) {
        printf("\nEMPATE a %d puntos! Ronda de desempate...\n", max);
        int mejor = -1, mejorValor = -1, hayEmpate = 0;

        for (int i = 0; i < numJugadores; i++) {
            if (jugadores[i].puntos != max) continue;

            printf("%s - ", jugadores[i].nombre);
            int valor = leerEnteroNoNegativo("aciertos en el desempate: ");

            if (valor > mejorValor) {
                mejorValor = valor;
                mejor = i;
                hayEmpate = 0;
            } else if (valor == mejorValor) {
                hayEmpate = 1;
            }
        }

        if (!hayEmpate) {
            jugadores[mejor].puntos = bonificacionEmpateBoom(jugadores[mejor].puntos, 1);
        } else {
            printf("Siguen empatados en el desempate. No hay bonus.\n");
        }
        max = puntajeMaximo(jugadores, numJugadores);
    }

    // Tabla final (ya con el bonus aplicado)
    printf("\n===== RESULTADOS BOOM =====\n");
    for (int i = 0; i < numJugadores; i++) {
        printf("%s | Aciertos: %d | Explosiones: %d | PUNTOS: %d\n",
               jugadores[i].nombre, jugadores[i].correctas, jugadores[i].errores, jugadores[i].puntos);
    }
    printf("----------------------------\n");

    // Ganador
    int ganadores = 0, indiceGanador = 0;
    for (int i = 0; i < numJugadores; i++) {
        if (jugadores[i].puntos == max) {
            ganadores++;
            indiceGanador = i;
        }
    }
    if (ganadores == 1)
        printf("GANADOR: %s\n", jugadores[indiceGanador].nombre);
    else
        printf("EMPATE TOTAL!\n");

    compararConRecord(max, record);
}

int main(void) {
    int recordAnterior = 20; // puedes cargarlo de un archivo
    Jugador jugadores[NUM_JUGADORES] = { {"Jugador 1", 0, 0, 0}, {"Jugador 2", 0, 0, 0} };

    for (int i = 0; i < NUM_JUGADORES; i++) {
        printf("\n--- Turno de %s ---\n", jugadores[i].nombre);
        jugadores[i].correctas = leerEnteroNoNegativo("Cuantas veces respondio antes del BOOM? ");
        jugadores[i].errores   = leerEnteroNoNegativo("Cuantas veces te exploto la bomba? ");

        int base = calcularPuntosJugador(jugadores[i].correctas);
        jugadores[i].puntos = aplicarReglasBoom(base, jugadores[i].errores);
    }

    // En BOOM calculamos el empate al final, no por jugador
    mostrarResultadosFinales(jugadores, NUM_JUGADORES, recordAnterior);

    return 0;
}
