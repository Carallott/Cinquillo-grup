#include "repartir.h"

int a_quien_repartir_carta(t_lista_jugadores jugadores)
{
    int jugador_al_que_repartir_tiene_sitio = 0; // no lo sabemos

    int jugador_al_quien_repartir = numero_al_azar(4);

    do
    {
        if (tiene_mano_llena(jugadores[jugador_al_quien_repartir]) == 0)
        {
            jugador_al_que_repartir_tiene_sitio = 1; // no tiene la mano llena
        }
        else
        {
            jugador_al_quien_repartir = numero_al_azar(4); // repetimos
        }
    } while (jugador_al_que_repartir_tiene_sitio == 0);

    return jugador_al_quien_repartir;
}

void repartir_carta_a_jugador(t_jugador *jugador, t_baraja *baraja, int index_carta_baraja)
{
    repartir_carta_jugador(jugador, (*baraja)[index_carta_baraja]); // Reparte la carta al jugador
    quitar_carta(baraja, index_carta_baraja); // Quita la carta de la baraja
}


void repartir_todas_las_cartas(t_lista_jugadores jugadores, t_baraja *baraja)
{
    int index_carta_baraja;

    for (index_carta_baraja = 0; index_carta_baraja < TOTAL_CARTAS; index_carta_baraja++)
    {
        int jugador_al_quien_repartir = a_quien_repartir_carta(jugadores);
        repartir_carta_a_jugador(&jugadores[jugador_al_quien_repartir], baraja, index_carta_baraja);
    }
}