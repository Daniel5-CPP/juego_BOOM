#include <stdio.h>
#include <string.h>

#define MAX_JUGADORES 100
#define MAX_NOMBRE 30

/* aqui estan los arreglos globlaes  */
char nombres[MAX_JUGADORES][MAX_NOMBRE];
int puntuaciones[MAX_JUGADORES];
int totalJugadores = 0;

/* con este se busca a los juagdores sino existe es un -1 y se devuelve? */
int buscarJugador(const char *nombre) {
    for (int i = 0; i < totalJugadores; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

/* aqui se registarn a los jugadores 
    0 -> registrado | -1 -> duplicado | -2 -> lleno
   -3 -> vacio      | -4 -> nombre muy largo */
int registrarJugador(const char *nombre) {
    if (totalJugadores >= MAX_JUGADORES) return -2;
    if (strlen(nombre) == 0) return -3;
    if (strlen(nombre) >= MAX_NOMBRE) return -4;
    if (buscarJugador(nombre) != -1) return -1;

    strcpy(nombres[totalJugadores], nombre);
    puntuaciones[totalJugadores] = 0;
    totalJugadores++;
    return 0;
}

/* Este es el mainde prueba cunando lo vayan a iniciar lo borran xd */
int main(void) {
    int opcion;
    char nombre[100];

    do {
        printf("\n--- PRUEBA DE FUNCIONES ---\n");
        printf("1. Registrar jugador\n");
        printf("2. Buscar jugador\n");
        printf("3. Ver todos los jugadores\n");
        printf("0. Salir\n");
        printf("Opcion: ");
        if (scanf("%d", &opcion) != 1) {
            return 1;
        }
        while (getchar() != '\n');   /* limpiar el buffer */

        if (opcion == 1 || opcion == 2) {
            printf("Nombre: ");
            fgets(nombre, sizeof(nombre), stdin);
            nombre[strcspn(nombre, "\n")] = '\0';   /* quitar el salto de linea */
        }

        if (opcion == 1) {
            switch (registrarJugador(nombre)) {
                case 0:  printf("Jugador registrado con 0 puntos.\n"); break;
                case -1: printf("Error: ese nombre ya existe.\n"); break;
                case -2: printf("Error: no caben mas jugadores.\n"); break;
                case -3: printf("Error: el nombre no puede estar vacio.\n"); break;
                case -4: printf("Error: el nombre es demasiado largo (max %d).\n", MAX_NOMBRE - 1); break;
            }
        } else if (opcion == 2) {
            int pos = buscarJugador(nombre);
            if (pos == -1) {
                printf("Jugador no encontrado.\n");
            } else {
                printf("Encontrado: %s | Puntuacion: %d\n", nombres[pos], puntuaciones[pos]);
            }
        } else if (opcion == 3) {
            if (totalJugadores == 0) {
                printf("No hay jugadores registrados.\n");
            }
            for (int i = 0; i < totalJugadores; i++) {
                printf("%d. %s - %d puntos\n", i + 1, nombres[i], puntuaciones[i]);
            }
        }
    } while (opcion != 0);

    return 0;
}
