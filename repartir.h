// baraja
// jugadores

#ifndef REPARTIR_H
#define REPARTIR_H

#include "baraja.h"
#include "azar.h"
#include "jugadores.h"


int a_quien_repartir_carta(t_lista_jugadores jugadores); // para cada carta calcular el jugador aleatorio al que se la repartimos
void repartir_carta_a_jugador(t_jugador *jugador, t_baraja *baraja, int index_carta_baraja);
void repartir_todas_las_cartas(t_lista_jugadores jugadores, t_baraja *baraja);

#endif // REPARTIR_H