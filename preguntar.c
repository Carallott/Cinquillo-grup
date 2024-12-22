
#include "preguntar.h"

int preguntar_2_opciones(char *pregunta)
{
    char respuesta;

    printf("%s (s/n): ", pregunta);
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S')
    {
        return 1;
    }
    else if (respuesta == 'n' || respuesta == 'N')
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int preguntar_multiples_opciones(char *pregunta, int numero_opciones)
{
    char respuesta;
    int opcion;

    printf("%s (0-%d): ", pregunta, numero_opciones - 1);
    scanf(" %d", &opcion);

    if (opcion >= 0 && opcion < numero_opciones)
    {
        return opcion;
    }
    else
    {
        return -1;
    }
}

int main(){
    int continuar = preguntar_2_opciones("¿Quieres continuar?");
    printf("continuar: %d\n", continuar);

    int elige_una_carta = preguntar_multiples_opciones("Elige una carta? ", 3);
    printf("elige_una_carta: %d\n", elige_una_carta);
}
