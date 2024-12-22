#ifndef JUGADOR_H
#define JUGADOR_H

#include "mano.h"
#include "mantel.h"

typedef struct
{
    int numero_jugador;
    int bot;
    t_mano mano;
} t_jugador;

void imprimir_cartas_jugables(t_jugador jugador, t_mantel mantel);
void iniciar_jugador(t_jugador *jugador, int numero_jugador);
int ha_ganado(t_jugador jugador);
void fijar_jugador_humano(t_jugador *jugador);

#endif // JUGADOR_H