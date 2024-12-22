#include "jugador.h"

void imprimir_cartas_jugables(t_jugador jugador, t_mantel mantel)
{
    //int dentro del for para no tener que escribir una linea de mas.
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

void imprimir_jugador(t_jugador jugador, int ver_todas_las_cartas)
{
    if (jugador.bot == 1)
    {
        printf_color_negrita();
        printf("JUG #%d: ", jugador.numero_jugador);
        printf_reset_color();
    }
    else
    {
        printf("JUG #%d: ", jugador.numero_jugador);
    }

    if (ver_todas_las_cartas == 0 && jugador.bot == 0)
    {
        imprimir_mano(jugador.mano, 1); // imprimir mano oculta
    }
    else
    {
        imprimir_mano(jugador.mano, 0); // imprimir mano visible
    }
}

int tiene_mano_llena(t_jugador jugador)
{
    int mano_llena = mano_esta_llena(jugador.mano);
    return mano_llena;
}

void repartir_carta_jugador(t_jugador *jugador, t_carta carta)
{
    repartir_carta(jugador->mano, carta);
}

void borrar_carta_mano_jugador(t_jugador *jugador, int index_carta)
{
    borrar_carta_de_la_mano(jugador->mano, index_carta);
}
