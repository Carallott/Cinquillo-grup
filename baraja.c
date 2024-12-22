#include "baraja.h"

// Inicialització de la baraja
void inicialitzacio_baraja(t_baraja baraja)
{
    int palo, valor_carta;

    // Iteramos por los palos
    for (palo = COPAS; palo <= ESPADAS; palo++)
    {
        for (valor_carta = 0; valor_carta < NUMERO_CARTES; valor_carta++)
        {
            int index_carta = ((palo -1) * NUMERO_CARTES) + valor_carta;

            baraja[index_carta].palo = palo;
            baraja[index_carta].valor = valor_carta + 1; // Comienza desde 1

            if (es_cinco_de_oros(baraja[index_carta]))
            {
                // El cinco de oros es la unica carta de la baraja que empieza siendo jugable
                baraja[index_carta].estado = 1;
            }
            else
            {
                baraja[index_carta].estado = 0;
            }
        }
    }
}

void imprimir_baraja(t_baraja baraja)
{
    int index_carta;

    for (index_carta = 0; index_carta < TOTAL_CARTAS; index_carta++)
    {
        imprimir_carta(baraja[index_carta]);
        if ((index_carta + 1) % NUMERO_CARTES == 0)
        {
            printf("\n"); // Salto de línea por cada palo
        }
    }
}

int main()
{
    t_baraja baraja;
    inicialitzacio_baraja(baraja);
    imprimir_baraja(baraja);
}