
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
    int opcion;
    char c; // necesation para limpiar la pila

    if (numero_opciones == 1)
    {
        printf("%s (1): ", pregunta);
    }
    else
    {
        printf("%s (1-%d): ", pregunta, numero_opciones);
    }

    int result = scanf("%d", &opcion);

    while ((c = getchar()) != '\n' && c != EOF); // limpia la pila si hay una letra dentro

    if (result == 1 && opcion >= 1 && opcion <= numero_opciones)
    {
        return opcion;
    }
    else
    {
        printf("Opcion introducida invalida. ");
        return -1;
    }
}