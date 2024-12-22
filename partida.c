#include "partida.h"

void turno_jugador(t_jugador *jugador, t_mantel *mantel)
{
    printf("\nTurno de JUG#%d: \n", jugador->numero_jugador);
    int index_carta_en_mano;

    t_carta cartas_jugables[MAX_CARTAS_EN_MANO];
    int ultimo_index_carta_jugable = 0;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (jugador->mano[index_carta_en_mano].palo != PALO_CARTA_VACIA && es_jugable(*mantel, jugador->mano[index_carta_en_mano]))
        {
            cartas_jugables[ultimo_index_carta_jugable] = jugador->mano[index_carta_en_mano];
            ultimo_index_carta_jugable++;
        }
    }

    printf("Tiradas posibles: ");

    // no hay jugadas posibles
    if (ultimo_index_carta_jugable == 0)
    {
        printf("\nNinguna ! :-/ Paso.\n");
        return;
    }
    else
    {
        int index_carta_jugable;
        for (index_carta_jugable = 0; index_carta_jugable < ultimo_index_carta_jugable; index_carta_jugable++)
        {
            printf("%d: ", index_carta_jugable + 1);
            imprimir_carta(cartas_jugables[index_carta_jugable]);
            printf(", ");
        }

        printf("\n");

        int opcion = -1;

        if (jugador->bot == 0)
        {
            opcion = numero_al_azar(index_carta_jugable) + 1;
            printf("¿ Que tirada realizas ? %d\n", opcion);
        }
        else
        {
            do
            {
                opcion = preguntar_multiples_opciones("¿ Que tirada realizas ? ", ultimo_index_carta_jugable);
            } while (opcion == -1);
        }

        jugar_carta(mantel, cartas_jugables[opcion - 1]);
        printf("\n");
        imprimir_mantel(*mantel);

        // Indice de la carta en la mano del jugador
        t_carta carta_jugada = cartas_jugables[opcion - 1];
        int indice_mano;
        for (indice_mano = 0; indice_mano < MAX_CARTAS_EN_MANO; indice_mano++)
        {

            if (jugador->mano[indice_mano].palo == carta_jugada.palo && jugador->mano[indice_mano].valor == carta_jugada.valor)
            {
                break;
            }
        }

        borrar_carta_mano_jugador(&(*jugador), indice_mano);
    }
}

void imprimir_estado_jugadores(t_lista_jugadores jugadores, int ver_todas_las_cartas)
{
    printf("\n");
    printf("        [ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ] [ 6 ] [ 7 ] [ 8 ] [ 9 ] [10 ]\n");
    int index_jugador;
    for (index_jugador = 0; index_jugador < MAX_JUGADORES; index_jugador++)
    {
        imprimir_jugador(jugadores[index_jugador], ver_todas_las_cartas);
    }
}

void turno_jugadores(t_lista_jugadores jugadores, t_mantel *mantel, int ver_todas_las_cartas)
{
    int index_jugador;
    for (index_jugador = 0; index_jugador < MAX_JUGADORES; index_jugador++)
    {
        imprimir_estado_jugadores(jugadores, ver_todas_las_cartas);
        turno_jugador(&jugadores[index_jugador], mantel); // Passa jugador como pointer
        duerme_un_rato();

		int i;
		int ha_ganado_alguien = 0;
		for (i = 0; i < MAX_JUGADORES; i++)
        {
            if (ha_ganado(jugadores[i]))
            {
				ha_ganado_alguien = 1;
                break;
            }
        }
		
		if (ha_ganado_alguien == 1)
		{
			break;
		}
    }
}

void iniciar_jugadores(t_lista_jugadores jugadores, int jugador_humano_azar)
{
    int index_jugador;
    for (index_jugador = 0; index_jugador < MAX_JUGADORES; index_jugador++)
    {
        iniciar_jugador(&jugadores[index_jugador], index_jugador + 1);
    }

    fijar_jugador_humano(&jugadores[jugador_humano_azar]);
}

int main()
{
    printf("Iniciando partida de cinquillo...\n");

    printf("\n");

    t_baraja baraja;
    inicialitzacio_baraja(baraja);
    // imprimir_baraja(baraja);

    t_mantel mantel;
    iniciar_mantel(&mantel);
    imprimir_mantel(mantel);

    printf("\n");

    inicializar_azar();

    int jugador_humano;
    do
    {
	jugador_humano = preguntar_2_opciones("¿ Hay algun jugador humano ?");
	printf("Opción introducida invalida. ");
    } while (jugador_humano == -1); 

    t_lista_jugadores jugadores;

    int jugador_humano_azar = -1;
    if (jugador_humano == 1)
    {
        jugador_humano_azar = numero_al_azar(4);
    }

    iniciar_jugadores(jugadores, jugador_humano_azar);

    int ver_todas_las_cartas;
    do
    {
	ver_todas_las_cartas = preguntar_2_opciones("¿ Quieres ver todas las cartas ?");
	printf("Opción introducida invalida. ");
    } while (ver_todas_las_cartas == -1);

    repartir_todas_las_cartas(jugadores, &baraja);

    int ha_ganado_alguien = 0;

    do
    {
        turno_jugadores(jugadores, &mantel, ver_todas_las_cartas);

        for (int i = 0; i < MAX_JUGADORES; i++)
        {
            if (ha_ganado(jugadores[i]))
            {
                ha_ganado_alguien = 1;
                printf("¡El jugador #%d ha ganado!\n", jugadores[i].numero_jugador);
                break;
            }
        }

    } while (ha_ganado_alguien == 0);
}
