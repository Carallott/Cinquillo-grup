#ifndef BARAJA_H
#define BARAJA_H

#include <stdio.h>
#include "carta.h"

#define NUMERO_CARTES 10
#define NUMERO_PALOS 4
#define TOTAL_CARTAS (NUMERO_CARTES * NUMERO_PALOS)

// Creació tipus per a la baraja
typedef t_carta t_baraja[TOTAL_CARTAS];

void inicialitzacio_baraja(t_baraja baraja);
void imprimir_baraja(t_baraja baraja);

#endif // BARAJA_H