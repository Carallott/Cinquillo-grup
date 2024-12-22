#include "mano.h"

void iniciar_mano_vacia(t_mano mano)
{
    int index_carta_en_mano;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        mano[index_carta_en_mano].palo = PALO_CARTA_VACIA;
        mano[index_carta_en_mano].valor = VALOR_CARTA_VACIA;
        mano[index_carta_en_mano].estado = ESTADO_CARTA_VACIA;
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
            mano[index_carta_en_mano].estado = carta.estado;
            return 1;
        }
    }

    printf("La mano ya esta llena ! \n");
    return -1;
}

void borrar_carta_de_la_mano(t_mano mano, int index_carta)
{
    mano[index_carta].palo = PALO_CARTA_VACIA;
    mano[index_carta].valor = VALOR_CARTA_VACIA;
    mano[index_carta].estado = ESTADO_CARTA_VACIA;
}

void imprimir_mano(t_mano mano, int mano_oculta)
{
    int index_carta_en_mano;

    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (mano[index_carta_en_mano].palo != PALO_CARTA_VACIA)
        {
            if (mano_oculta == 1)
            {
                imprimir_carta_oculta();
            }
            else
            {
                imprimir_carta(mano[index_carta_en_mano]);
            }
            printf(" ");
        }
    }

    printf("\n");
}

int mano_esta_llena(t_mano mano)
{
    int mano_llena = 1; // la mano esta llena

    int index_carta_en_mano;
    for (index_carta_en_mano = 0; index_carta_en_mano < MAX_CARTAS_EN_MANO; index_carta_en_mano++)
    {
        if (mano[index_carta_en_mano].palo == PALO_CARTA_VACIA)
        {
            mano_llena = 0; // la mano no esta llena
            break;
        }
    }

    return mano_llena;
}
