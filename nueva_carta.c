#include "carta_h"
typedef struct { 
  int jug;
  char car; //[(J)ugable (T)ablero (M)ano]
} t_carac;
typedef struct {
  t_carac carac;
  int carta; //inicialiazar carta[1]=1 y progresivamente
} t_carta;
t_carta c[MAX];
void iniciar_cartas(t_carta *p_c) {
	int i;
	char j,m;
	for(i=0;i<MAX;i++) {
		p_c[i].carta=i;
		if (p_c[i].carta==4 || p_c[i].carta==14 || p_c[i].carta==24 || p_c[i].carta==34) {
		p_c[i].carac.car='J';
		} else p_c[i].carac.car='M';
		}
}	  
