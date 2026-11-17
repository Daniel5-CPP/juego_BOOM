#include <stdio.h>
#include <stdlib.h>

void registrarJugador(void);
void mostrarPuntuaciones(void);
void jugar(void);


int main() {
    int opcion = 0; // Variable para la opcion del men u
    do{ // Menu de opciones
    printf("Bienvenido al juego\n");
    printf("Que deceas hacer ahora?, Escribe un numero\n");
    printf("1. Registrar jugador\n");
    printf("2. Verificar puntuaciones\n");
    printf("3. Jugar\n");
    printf("4. Salir\n");
    scanf("%i", &opcion); // escriiendo la wea del menu
    
    switch (opcion) {
            case 1:
                registrarJugador();
                break;

            case 2:
                mostrarPuntuaciones();
                break;

            case 3:
                jugar();
                break;

            case 4:
                printf("\nGracias por jugar BOOM! owO\n");
                break;

            default:
                printf("\nOpcion no valida.\n");
                break;
        }
    
    }while (opcion != 4);

    
    return 0; 
}


