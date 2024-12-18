#include "mano.h"

void iniciar_mano_vacia(t_mano mano)
{
    int index_carta_en_mano;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        mano[index_carta_en_mano].palo = PALO_CARTA_VACIA;
        mano[index_carta_en_mano].valor = VALOR_CARTA_VACIA;
    }
}

int repartir_carta(t_mano mano, t_carta carta)
{
    int index_carta_en_mano;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        // Buscamos la primera carta vacía
        if (mano[index_carta_en_mano].palo == PALO_CARTA_VACIA)
        {
            mano[index_carta_en_mano].palo = carta.palo;
            mano[index_carta_en_mano].valor = carta.valor;
            return 1;
        }
    }

    printf("La mano ya esta llena ! ");
    return -1;
}

void borrar_carta_de_la_mano(t_mano mano, int index_carta)
{
    mano[index_carta].palo = PALO_CARTA_VACIA;
    mano[index_carta].valor = VALOR_CARTA_VACIA;
}

void imprimir_mano(t_mano mano)
{
    int index_carta_en_mano;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (mano[index_carta_en_mano].palo != PALO_CARTA_VACIA)
        {
            imprimir_carta(mano[index_carta_en_mano]);
        }
    }
}


int main()
{
    t_carta carta1 = {0, 1};
    t_carta carta2 = {1, 2};
    t_carta carta3 = {2, 3};
    t_carta carta4 = {3, 4};
    t_carta carta5 = {0, 5};
    t_carta carta6 = {1, 6};
    t_carta carta7 = {2, 7};
    t_carta carta8 = {3, 8};
    t_carta carta9 = {2, 9};
    t_carta carta10 = {0, 10};
    t_carta carta11 = {1, 10};  

    t_mano mano;
    iniciar_mano_vacia(mano);
    imprimir_mano(mano);

    repartir_carta(mano, carta1);
    repartir_carta(mano, carta2);
    repartir_carta(mano, carta3);
    repartir_carta(mano, carta4);
    repartir_carta(mano, carta5);
    repartir_carta(mano, carta6);
    repartir_carta(mano, carta7);
    repartir_carta(mano, carta8);
    repartir_carta(mano, carta9);
    repartir_carta(mano, carta10);

    printf("10 cartas repartidas\n");
    imprimir_mano(mano);

    printf("Repartiendo carta 11...\n");
    repartir_carta(mano, carta11);

    borrar_carta_de_la_mano(mano, 8);
    imprimir_mano(mano);

    printf("Repartiendo carta 11...\n");
    repartir_carta(mano, carta11);
    imprimir_mano(mano);
}