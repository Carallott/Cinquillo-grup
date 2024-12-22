#include "carta.h"

char *sufijo_palo(enum_palo palo)
{
    switch (palo)
    {
    case COPAS:
        return "C";
    case BASTOS:
        return "B";
    case OROS:
        return "O";
    case ESPADAS:
        return "E";
    }
}

char *necesita_espacio(int valor_carta)
{
    if (valor_carta < 10)
    {
        return " ";
    }

    return "";
}

void imprimir_carta(t_carta carta)
{
    printf_color_num(carta.palo + 1);
    printf("[%s%s%d]", sufijo_palo(carta.palo + 1), necesita_espacio(carta.valor), carta.valor);
    printf_reset_color();
}

void imprimir_carta_oculta()
{
    printf_color_negrita();
    printf("[? ?]");
    printf_reset_color();
}

void imprimir_carta_casilla(t_carta carta)
{
    if (carta.estado == 0 || carta.estado == 1)
    {
        printf("[- -]");
    }
    else
    {
        imprimir_carta(carta);
    }
}

int es_cinco_de_oros(t_carta carta)
{
    if (carta.palo == OROS - 1 && carta.valor == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}