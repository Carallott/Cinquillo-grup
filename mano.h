#ifndef MANO_H
#define MANO_H

#include <stdio.h>
#include "colores.h"
#include "carta.h"

#define MAX_CARTAS_EN_MANO 10
#define MIN_CARTAS_EN_MANO 0

// Estructura per a la mano
typedef t_carta t_mano[MAX_CARTAS_EN_MANO];

void iniciar_mano_vacia(t_mano mano);
int repartir_carta(t_mano mano, t_carta carta);
void imprimir_mano(t_mano mano, int mano_oculta);
void borrar_carta_de_la_mano(t_mano mano, int index_carta);
int mano_esta_llena(t_mano mano);

#endif // MANO_H