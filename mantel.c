#include "mantel.h"

void iniciar_mantel(t_mantel *mantel)
{
    int fila, columna;

    for (fila = 0; fila < FILAS; fila++)
    {
        for (columna = COPAS; columna <= ESPADAS; columna++)
        {
            mantel->casillas[fila][columna - 1].fila = fila;
            mantel->casillas[fila][columna - 1].columna = columna - 1;
            mantel->casillas[fila][columna - 1].carta.palo = columna - 1;
            mantel->casillas[fila][columna - 1].carta.valor = FILAS - fila;

            if (es_cinco_de_oros(mantel->casillas[fila][columna - 1].carta))
            {
                mantel->casillas[fila][columna - 1].carta.estado = 1;
            }
            else
            {
                mantel->casillas[fila][columna - 1].carta.estado = 0;
            }
        }
    }
}

void imprimir_mantel(t_mantel mantel)
{
    imprimir_cabecera();
    printf("\n");

    int fila, columna;

    for (fila = 0; fila < FILAS; fila++)
    {
        for (columna = COPAS; columna <= ESPADAS; columna++)
        {
            imprimir_carta_casilla(mantel.casillas[fila][columna - 1].carta);

            if (columna == ESPADAS)
            {
                printf("\n");
            }
        }
    }
}

void imprimir_cabecera()
{
    printf_color_num(COPAS);
    printf("[COP]");
    printf_reset_color();

    printf_color_num(BASTOS);
    printf("[BAS]");
    printf_reset_color();

    printf_color_num(OROS);
    printf("[ORO]");
    printf_reset_color();

    printf_color_num(ESPADAS);
    printf("[ESP]");
    printf_reset_color();
}

void jugar_carta(t_mantel *mantel, t_carta carta)
{
    int fila_de_la_carta = FILAS - carta.valor;
    int columna_de_la_carta = carta.palo;
    mantel->casillas[fila_de_la_carta][columna_de_la_carta].carta.estado = 2;

    calcular_nuevas_cartas_jugables(mantel, mantel->casillas[fila_de_la_carta][columna_de_la_carta]);
}

void calcular_nuevas_cartas_jugables(t_mantel *mantel, t_casilla casilla)
{
    // 1. Todos los 5s son jugables si la carta que estamos jugando es el 5 de oros.
    int fila_cinco_de_oros = 5;
    int columna_cinco_de_oros = OROS - 1; // ESPADAS

    if (casilla.fila == fila_cinco_de_oros && casilla.columna == columna_cinco_de_oros)
    {
        poner_los_cincos_jugables(mantel);
    }

    // 2. Si una cartas esta en contacto y no ha sido jugada, es jugable
    int fila_carta_jugada = casilla.fila;
    int columna_carta_jugada = casilla.columna;

    int fila;

    for (fila = fila_carta_jugada - 1; fila <= fila_carta_jugada + 1; fila = fila + 2)
    {
        if (mantel->casillas[fila][columna_carta_jugada].carta.estado == 0)
        {
            mantel->casillas[fila][columna_carta_jugada].carta.estado = 1;
        }
    }
}

void poner_los_cincos_jugables(t_mantel *mantel)
{
    int fila_cincos = 5;

    int columna;
    for (columna = COPAS; columna <= ESPADAS; columna++)
    {
        if (columna != OROS)
        {
            mantel->casillas[fila_cincos][columna - 1].carta.estado = 1;
        }
    }
}

int es_jugable(t_mantel mantel, t_carta carta)
{
    int fila_de_la_carta = FILAS - carta.valor;
    int columna_de_la_carta = carta.palo;

    if (mantel.casillas[fila_de_la_carta][columna_de_la_carta].carta.estado == 1)
    {
        return 1;
    }

    return 0;
}
