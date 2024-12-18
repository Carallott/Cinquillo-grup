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
    printf_color_num(carta.palo);
    printf("[%s%s%d]", sufijo_palo(carta.palo), necesita_espacio(carta.valor), carta.valor);
    printf_reset_color();
}