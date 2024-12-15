#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tablero.h"
#include "colores.h"

// Función para inicializar el tablero
void inicializar_tablero(Tablero *tablero) {
    for (int i = 0; i < MAX_PALOS; i++) {
        for (int j = 0; j < MAX_CARTAS_POR_PALO; j++) {
            tablero->cartas[i][j] = -1;  // Inicializar las cartas a -1 (vacío)
        }
    }
}

// Función para asignar una carta al tablero
void asignar_carta_tablero(Tablero *tablero, int palo, int valor) {
    for (int i = 0; i < MAX_CARTAS_POR_PALO; i++) {
        if (tablero->cartas[palo][i] == -1) {  // Buscar la primera posición vacía
            tablero->cartas[palo][i] = valor;   // Asignar el valor de la carta
            break;
        }
    }
}

// Función para imprimir el tablero
void mostrar_tablero(const Tablero *tablero) {
    // Imprimir los encabezados de los palos
    printf("%-15s%-15s%-15s%-15s\n", "OROS", "ESPADAS", "COPAS", "BASTOS");

    // Mostrar las cartas de cada fila (de 1 a 10)
    for (int i = 0; i < MAX_CARTAS_POR_PALO; i++) {
        // Para cada palo, se imprime la carta correspondiente
        for (int j = 0; j < MAX_PALOS; j++) {
            int valor = tablero->cartas[j][i];

            if (valor != -1) {
                // Imprimir las cartas con los colores adecuados según el palo
                if (j == 0) {
                    printf(ANSI_COLOR_YELLOW "[%2d O]%-12s" ANSI_COLOR_RESET, valor, " ");  
                } else if (j == 1) {
                    printf(ANSI_COLOR_BLUE "[%2d E]%-12s" ANSI_COLOR_RESET, valor, " ");  
                } else if (j == 2) {
                    printf(ANSI_COLOR_RED "[%2d C]%-12s" ANSI_COLOR_RESET, valor, " ");  
                } else if (j == 3) {
                    printf(ANSI_COLOR_GREEN "[%2d B]%-12s" ANSI_COLOR_RESET, valor, " ");  
                }
            } else {
                // Si no hay carta en la posición, se imprime un espacio vacío
                printf("%-15s", "");
            }
        }
        printf("\n");
    }
}
