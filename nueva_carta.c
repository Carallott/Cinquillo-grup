#include "carta_h"
typedef struct { 
  int jug;
  char car; //[(J)ugable(esta en la mesa y se puedejugar con ella) (T)ablero (M)ano]
} t_carac;
t_carac c[MAX];
void iniciar_cartas(t_carta *p_c) {
	int i;
	char M;
	for(i=0;i<MAX;i++) {
		p_c[i].carac.car='M';
}
}
void asignar_cartas (t_carta *p_c) {
	int cont[4]={0};
	int i,x;
	for(i=0;i<MAX;i++) {
		x=numero_al_azar(4);
		cont[x]++;
		if (cont[x]<=10) {
		p_c[i].jug=x;
		
	}	else i=i -1;
	}
	}
