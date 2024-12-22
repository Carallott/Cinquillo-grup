#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include "jugador.h"
#include "baraja.h"
#include "azar.h"
#include "mantel.h"
#include "preguntar.h"
#include "repartir.h"
#include "jugadores.h"
#include "duerme.h"

void turno_jugador(t_jugador *jugador, t_mantel *mantel);
void imprimir_estado_jugadores(t_lista_jugadores jugadores, int ver_todas_las_cartas);
void turno_jugadores(t_lista_jugadores jugadores, t_mantel *mantel, int ver_todas_las_cartas);
void iniciar_jugadores(t_lista_jugadores jugadores, int jugador_humano_azar);

#endif // PARTIDA_H

// Para compilar:
// gcc partida.c preguntar.c baraja.c mantel.c mano.c jugador.c carta.c colores.c azar.c repartir.c duerme.c -o partida
//
// Para ejecutar:
// ./partida
//