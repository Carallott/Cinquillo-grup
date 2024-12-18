#include "JUGADORES_H"
void repartir_cartas(t_carta *p_c, t_jug *p_jug) {
		int i,x,j;		
		for(x=0;x<JUG;x++) {
			j=0;			
			for(i=0;i<MAX;i++) {
				if (p_c[i].carac.jug==x) {
					p_jug->J[x][j]=p_c[i].carta;
					j++;
					}
				}
			}
		}

