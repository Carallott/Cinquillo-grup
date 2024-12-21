#include "JUGADORES_H"
int pensar (t_jugada *p_p,t_carac *p_c, int i) { //hacer caso no hay jugada dispo
	int x,n,y;
	if (p_p[2].val== -1) {
		return 1;
		}
	else {
	      for(n=0;n<MAX;n++) {
		if(p_c[n].jug==i) {
			if(n==9||n==19||n==29||n==39) {
				for(x=0;x<MAX_P;x++) {
					y=n-p_p[x].val;
					if(y<=5 && y>=0) return x;}}
			if(n==0||n==10||n==20||n==30) {
				for(x=0;x<MAX_P;x++) {
					y=n-p_p[x].val;
					if(y<=0 && y>-5) return x;}}
			if(n==8||n==18||n==28||n==38) {
				for(x=0;x<MAX_P;x++) {
					y=n-p_p[x].val;
					if(y>=0 && y<5) return x;}}
	}		
	}				
	}		
}	

		

