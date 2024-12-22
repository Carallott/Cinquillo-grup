#ifndef CARTA_H
#define CARTA_H

#include <stdio.h>
#include "colores.h"

#define PALO_CARTA_VACIA -1
#define VALOR_CARTA_VACIA -1
#define ESTADO_CARTA_VACIA -1

// Definims un tipus enum per a les palos de les cartes
// Ordenat aixi perque els colors segueixin el mateix ordre
typedef enum
{
    COPAS = 1,
    BASTOS = 2,
    OROS = 3,
    ESPADAS = 4,
} enum_palo;

// Estructura per a la carta : {enum_palo palo, int valor, int estado}
typedef struct
{
    enum_palo palo;
    int valor;
    char estado; // no jugada: 0, jugable: 1, jugada: 2
} t_carta;

char *sufijo_palo(enum_palo palo);
char *necesita_espacio(int valor_carta);
void imprimir_carta(t_carta carta);
void imprimir_carta_casilla(t_carta carta);
void imprimir_carta_oculta();
int es_cinco_de_oros(t_carta carta);

#endif // CARTA_H
