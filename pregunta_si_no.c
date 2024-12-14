#include <stdio.h>

int preguntar_si_o_no() {
    char respuesta;

    printf("¿Quieres continuar? (s/n): ");
    scanf(" %c", &respuesta);

    if (respuesta == 's' || respuesta == 'S') {
        return 1;  // Sí
    } else if (respuesta == 'n' || respuesta == 'N') {
        return 0;  // No
    } else {
        return -1;
}



