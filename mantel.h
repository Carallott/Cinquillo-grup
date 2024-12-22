#ifndef MANTEL_H
#define MANTEL_H

#include <stdio.h>
#include "carta.h"

#define FILAS 10
#define COLUMNAS 4

typedef struct
{
    int fila;
    int columna;
    t_carta carta;
} t_casilla;

typedef struct
{
    t_casilla casillas[FILAS][COLUMNAS];
} t_mantel;

void iniciar_mantel(t_mantel *mantel);
void imprimir_mantel(t_mantel mantel);
void imprimir_cabecera();
void jugar_carta(t_mantel *mantel, t_carta carta);

// Actualiza las cartas que se pueden jugar en el proximo turno
void calcular_nuevas_cartas_jugables(t_mantel *mantel, t_casilla casilla);
void poner_los_cincos_jugables(t_mantel *mantel);
int es_jugable(t_mantel mantel, t_carta carta); // 0 no jugable, 1 jugable

#endif // MANTEL_H