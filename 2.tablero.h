#ifndef TABLERO_H
#define TABLERO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colores.h"

#define MAX_CARTAS 10  
#define NUM_PALOS 4    
#define MAX_JUGADORES 4 


typedef struct {
    int valor;  
    char palo;  
} Carta;


typedef struct {
    Carta columnas[NUM_PALOS][MAX_CARTAS];  // Cartas por cada palo
} Tablero;

// Prototipos de funciones
void inicializar_tablero(Tablero *tablero);
void asignar_carta_tablero(Tablero *tablero, Carta carta);
void mostrar_tablero(const Tablero *tablero);
int es_carta_valida(Tablero *tablero, Carta carta);

#endif
