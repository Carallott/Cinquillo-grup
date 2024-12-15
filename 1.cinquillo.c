#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablero.h"
#include "mazo.h"
#include "jugador.h"
#include "juego.h"
#include "colores.h" 

// Variables globales (tablero, mazo, jugadores)
Tablero tablero;
Mazo mazo;
Jugador jugadores[NUM_JUGADORES];

int main() {
    // Inicialización
    inicializar_mazo(&mazo);                      
    inicializar_jugadores(jugadores, NUM_JUGADORES);  
    inicializar_tablero(&tablero);                

    // Repartir cartas a los jugadores
    repartir_cartas(&mazo, jugadores, NUM_JUGADORES);

    // Mostrar el tablero inicial
    mostrar_tablero(&tablero);

    // Jugar mientras no haya un ganador
    while (!fin_de_juego(jugadores)) {
        
        for (int i = 0; i < NUM_JUGADORES; i++) {
            if (turno_jugador(&jugadores[i])) {
                
                realizar_jugada(&jugadores[i], &tablero);

                
                mostrar_tablero(&tablero);

                // Pausar por un segundo (para simular un turno)
                duerme(1);
            }
        }
    }

    
    obtener_ganador(jugadores);

    return 0;
}