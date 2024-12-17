#include "JUGADORES_H"
typrdef tjug JUG
void asignar_carta() {
    int i,j,n=41,m;
    for(j=0;j<J;j++) {
    for(i=0;i<CARTAS;i++) {
         m=numero_al_azar(n);
      JUG.JUG[j][i]=baraja[m];
    }
    }
}
