#include <stdio.h>

// Función que realiza la pregunta y devuelve 1 para 'sí' y 0 para 'no'
int preguntar_si_o_no() {
    char respuesta;

    printf("¿Quieres continuar? (s/n): ");
    scanf(" %c", &respuesta);  // Leer la respuesta

    if (respuesta == 's' || respuesta == 'S') {
        return 1;  // Sí
    } else if (respuesta == 'n' || respuesta == 'N') {
        return 0;  // No
    } else {
        return -1;  // Respuesta no válida
    }
}

int main() {
    int respuesta = preguntar_si_o_no();  // Llamar a la función

    if (respuesta == 1) {
        printf("Has elegido continuar.\n");
    } else if (respuesta == 0) {
        printf("Has elegido salir.\n");
    } else {
        printf("Respuesta no válida.\n");
    }

    return 0;
}


