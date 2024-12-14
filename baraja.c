#import <Foundation/Foundation.h>

#include <stdio.h>

#define NUM 10
#define PALO 4
#define CARTAS (NUM*PALO) 
//ho poso així per si volem cambiar el nuemero de cartas --> versió 40 cartes
#define OROS 0
#define ESPADAS 1
#define BASTOS 2
#define COPAS 3


typedef struct{
    int pal;
    int num;
}t_carta;

typedef t_carta baraja[CARTAS]; //s'ha de declarar d'alguna manera --> preguntar dema
                                //google dice que puedo meter un typedef delante para que quede declarada.

void crear_baraja(baraja B){
    int i, j;
    for(i = 0; i < PALO; i++){
        for(j = 0; j < NUM; j++){
            B[NUM * i + j].pal = i;
            B[NUM * i + j].num = j;
        }
    }
}
void crear_carta(t_carta C){
    switch(C.pal){
        case 0:
            printf("O", C.pal);
            break;
        case 1:
            printf("E", C.pal);
            break;
        case 2:
            printf("B", C.pal);
            break;
        case 3:
            printf("C", C.pal);
            break;
    }
    if (C.num < NUM){
        C.num = C.num + 1;
    }
    
    printf("%c %d] ",C.pal, C.num);
}

void print_baraja(baraja *p_B){
    int i;
    for(i = 0; i < CARTAS; i++){
        crear_carta(B[i]);
    }
}

int main(){
    t_carta B;
    t_carta C;
    crear_baraja(&B);
    crear_carta(C);  
    print_baraja(&B);
}

