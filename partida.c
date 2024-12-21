#include "partida.h"
typedef struct {
	int val;
} t_jugada; 
void mover_carta (t_carac *p_c, int n) {
	printf("\nsoy chivato 2 \n");
	if (n!=0&&n!=9&&n!=10&&n!=19&&n!=20&&n!=29&&n!=30&&n!=39) {
	printf("\nsoy chivato 2.1 \n");
	p_c[n].car='J';
	} else p_c[n].car='T';
	if ((n<9&&n>4)||(n<19&&n>14)||(n<29&&n>24)||n>34) {
		printf("\nsoy chivato 2.2 \n");
		p_c[n-1].car='T';
	} else p_c[n+1].car='T';
	if (n==4||n==14||n==24||n==34) {
		 printf("\nsoy chivato 2.3 \n");
		 if (p_c[n+1].car=='T' &&p_c[n-1].car=='T') {
			p_c[n].car='T';
			}} else p_c[n].car='J';
}	
int primera_jugada (t_carac *p_c) {
	int i;
	p_c[4].car='J';
	i=p_c[4].jug;
	return i;
}
int sig_jug (int i) {
	printf("\nsoy chivato 3 \n");
	if (i==3) {
		i=0;
		} else i++;
		return i;
}
int play (t_carac *p_c,int i) { //hacer funcion pritn carta
	int n,x,j=0,w;
	t_jugada p[MAX_P];
		for (int k = 0; k < MAX_P; k++) {
    			p[k].val = -1;
		}
printf("Jugadas posibles para jugador:%d\nSon:", i);
	for (n=0;n<MAX;n++) {
		if (p_c[n].car=='J') {
			else if(p_c[n+1].jug==i) { 
			
			p[j].val=n+1;	
			j++;
		}	else if (p_c[n-1].jug==i) {

			p[j].val=n-1;	
			j++;
		}}
		 if (n==14 && p_c[n].jug==i || n==24 && p_c[n].jug==i || n==34 && p_c[n].jug==i) {

			p[j].val=n;
			j++;
		
	} 		
	}
	printf("Jugadas posibles: ");
	j=0;
	while (p[j].val!=-1) {
		printf("%d | %d\t", j,p[j].val);
		j++;
		}
		/*	if (jug es controlado ) {
		scanf("%d", &x);
		x--;
		}*/
		scanf("%d", &x);
		
		// x=pensar(p, c, i);
		 printf("Jugada elegida numero: %d", x);
		w=p[x].val;
		return w;
}
int ganador (t_carac *p_c,int i) {
	int x,w;
		w=0;
		for (x=0;x<MAX;x++) {
		       if (p_c[x].jug==i && p_c[x].car=='T') {
					w++;
				}
			}
		if(w==10) {
			printf("El jugador %d ha ganadp la partida.\n Enhorabuena!!!!!",i);
			return TRUE;
		}
		else return FALSE;
}

				
	
