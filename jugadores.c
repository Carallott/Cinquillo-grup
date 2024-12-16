#include "JUGADORES_H"
typrdef tjug JUG
int i,j,n=41,m;
void asignar_carta() {
    for(j=0;j<J;j++) {
    for(i=0;i<CARTAS;i++) {
         m=numero_al_azar(n);
      JUG.JUG[j][i]=baraja[m];
    }
    }
}
