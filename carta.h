#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include "colores.h"

// Definims un tipus enum per a les palos de les cartes
typedef enum
{
    COPAS = 0,
    BASTOS = 1,
    OROS = 2,
    ESPADAS = 3
} enum_palo;

// Estructura per a la carta : {enum_palo palo, int valor}
typedef struct
{
    enum_palo palo;
    int valor;
} t_carta;

char *sufijo_palo(enum_palo palo);
char *necesita_espacio(int valor_carta);
void imprimir_carta(t_carta carta);

#endif // CARTA_H
