#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

// Funcion para decidir al azar que jugador empieza 
int decidirJugadorInicial(char jugadores[2][20]) {
    int turno = rand() % 2;
    printf("El jugador %s empieza primero\n", jugadores[turno]);
    Sleep(1500);
    system("cls");
    return turno;
}

// Funcion del juego
void Juego(char jugadores[2][20], int multiplo, int limite) {
    int numero = 1,vidasJ1 = 3, vidasJ2 = 3, aciertosJ1 = 0, aciertosJ2 = 0, fallosJ1 = 0, fallosJ2 = 0;
    char respuesta[10], jugada[10];

    printf("Preparence para jugar...\n");
    Sleep(2000);
    system("cls");

    // Se decide quien empieza antes de comenzar la partida
    int actual = decidirJugadorInicial(jugadores);

    // Ciclo del juego
    while (vidasJ1 > 0 && vidasJ2 > 0 && numero <= limite) {
        // Comprobacion de si el numero es multiplo
        if (numero % multiplo == 0) {
            strcpy(respuesta, "BOOM");
        } else {
            sprintf(respuesta, "%d", numero);
        }

        printf("Turno de: %s\n", jugadores[actual]);
        scanf("%9s", jugada);

        if (_stricmp(jugada, respuesta) == 0) {
            printf("Correcto!\n");
            if (actual == 0) {
                aciertosJ1++;
            } else {
                aciertosJ2++;
            }
        } else {
            printf("Incorrecto! la respuesta correcta es: %s\n", respuesta);
            if (actual == 0) {
                vidasJ1--;
                fallosJ1++;
                printf("Vidas restantes de %s: %d\n", jugadores[actual], vidasJ1);
            } else {
                vidasJ2--;
                fallosJ2++;
                printf("Vidas restantes de %s: %d\n", jugadores[actual], vidasJ2);
            }
        }
        Sleep(1000);
        system("cls");

        numero++;
        actual = 1 - actual; // Cambio de turno
    }

    // Resultado final
    if (vidasJ1 > vidasJ2) {
        printf("Felicidades %s, ganaste!\n", jugadores[0]);
    } else if (vidasJ2 > vidasJ1) {
        printf("Felicidades %s, ganaste!\n", jugadores[1]);
    } else {
        printf("Empate!\n");
    }
    printf("\nEstadisticas:\n");
    printf("%s -> Aciertos: %d | Fallos: %d\n", jugadores[0], aciertosJ1, fallosJ1);
    printf("%s -> Aciertos: %d | Fallos: %d\n", jugadores[1], aciertosJ2, fallosJ2);

}

// Funcion que define el multiplo segun el modo elegido y ejecuta el juego
void iniciarModo(char jugadores[2][20], int modoJuego) {
    int multiplo;
    if(modoJuego == 1){
    multiplo = 3;
    } else if(modoJuego == 2){
    multiplo = 7;
    }
    int limite = multiplo * 30; // 90 para el 3 y 210 para el 7

    printf("Modo de juego: Multiplos de %d\n", multiplo);
    Sleep(1500);
    system("cls");
    printf("El juego consiste en que ambos jugadores deben ir escribiendo consecutivamente los numeros del 1 al %d,\n"
           "pero si el numero es multiplo de %d el jugador debe escribir BOOM\n", limite, multiplo);
    Sleep(5000);
    system("cls");

    Juego(jugadores, multiplo, limite);
}

int main() {
    int modoJuego;
    srand(time(NULL));

    // Arreglo para almacenar los nombres de los jugadores
    char jugadores[2][20];
    printf("Ingrese el nombre del jugador 1: ");
    scanf("%19s", jugadores[0]);
    printf("Ingrese el nombre del jugador 2: ");
    scanf("%19s", jugadores[1]);

    // Menu para elegir el modo de juego
    do {
        printf("Modo de juego:\n\n Elije un modo de juego:\n\n1. Multiplos de 3 \n2. Multiplos de 7\n");
        scanf("%d", &modoJuego);
        if (modoJuego <= 0 || modoJuego > 2) {
            printf("Opcion invalida, intente de nuevo\n");
            Sleep(1000);
            system("cls");
        }
    } while (modoJuego <= 0 || modoJuego > 2);
    Sleep(1000);
    system("cls");

    iniciarModo(jugadores, modoJuego);

    system("pause");
    return 0;
}