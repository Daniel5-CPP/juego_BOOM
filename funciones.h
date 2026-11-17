
#ifndef FUNCIONES_H
#define FUNCIONES_H


// CONSTANTES DEL PROYECTO
#define MAX_JUGADORES 100
#define MAX_NOMBRE 30
#define NUM_JUGADORES_PARTIDA 2
#define MAX_RESPUESTA 20


// VARIABLES GLOBALES COMPARTIDAS

// Registro de jugadores - Integrante 2
extern char nombres[MAX_JUGADORES][MAX_NOMBRE];
extern int puntuaciones[MAX_JUGADORES];
extern int totalJugadores;
extern char nombreConsulta[MAX_NOMBRE];

// Datos de partida - Integrante 3
extern int indiceJugadorPartida[NUM_JUGADORES_PARTIDA];
extern int aciertosPartida[NUM_JUGADORES_PARTIDA];
extern int erroresPartida[NUM_JUGADORES_PARTIDA];
extern int puntosPartida[NUM_JUGADORES_PARTIDA];

extern int modoJuego;
extern int numeroActual;
extern char respuestaIngresada[MAX_RESPUESTA];


// INTEGRANTE 2 - REGISTRO Y RANKING

// Registrar jugadores y validar nombres
void registrarJugador(void);

// Buscar un jugador y devolver su indice
int buscarJugador(void);

// Consultar puntuaciones y mostrar ranking
void mostrarPuntuaciones(void);


// INTEGRANTE 3 - MECANICAS DEL JUEGO

// Seleccionar modalidad y verificar jugadores
void jugar(void);

// Modalidad de multiplos de 3
void JuegoMult3(void);

// Modalidad de multiplos de 7
void JuegoMult7(void);

// Controlar turnos, respuestas y errores
void ejecutarPartida(void);

// Verificar si la respuesta es correcta
int validarRespuesta(int numero, int multiplo);



// INTEGRANTE 4 - PUNTUACIONES

// Calcular puntos base
int calcularPuntosJugador(int correctas);

// Aplicar bonificaciones y penalizaciones
int aplicarReglasBoom(int puntosBase, int errores);

// Aplicar bonificacion por empate
int bonificacionEmpateBoom(int puntos, int esEmpate);

// Comparar y actualizar record
void compararConRecord(int indiceJugador, int puntos);

// Mostrar resultados finales
void mostrarResultadosFinales(void);


#endif
