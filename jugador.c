#include "jugador.h"

void imprimir_cartas_jugables(t_jugador jugador, t_mantel mantel)
{
    for (int index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (jugador.mano[index_carta_en_mano].palo != PALO_CARTA_VACIA && es_jugable(mantel, jugador.mano[index_carta_en_mano]))
        {
            imprimir_carta(jugador.mano[index_carta_en_mano]);
        }
    }

    printf("\n");
}

void iniciar_jugador(t_jugador *jugador, int numero_jugador)
{
    jugador->numero_jugador = numero_jugador;
    jugador->bot = 0;
    iniciar_mano_vacia(jugador->mano);
}

void fijar_jugador_humano(t_jugador *jugador)
{
    jugador->bot = 1;
}


int ha_ganado(t_jugador jugador)
{
    for (int index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (jugador.mano[index_carta_en_mano].palo != PALO_CARTA_VACIA)
        {
            return 0; // no ha ganado
        }
    }

    return 1; // ha ganado
}