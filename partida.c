typedef struct {
	int val;
} t_jugada; 
void mover_carta (t_carac *p_c, int n) {
	if (n!=0||n!=9||n!=10||n!=19||n!=20||n!=29||n!=30||n!=39) {
	p_c[n].car='J';
	} else p_c[n].car='T';
	if ((n<9&&n>4)||(n<19&&n>14)||(n<29&&n>24)||n>34) {
		p_c[n-1].car='T';
	} else p_c[n+1].car='T';
	if (n==4||n==14||n==24||n==34) {
		 if (p_c[n+1].car=='T' &&p_c[n-1].car=='T') {
			p_c[n].car='T';
			}} else p_c[n].car='J';
}	
int primera_juagada (t_carac *p_c) {
	int i;
	p_c[4].car='J';
	i=p_c[4].jug;
	return i;
}
int sig_jug (int i) {
	if (i==3) {
		i=0;
		} else i++;
}
int play (int i, t_carac *p_c) {
	int n,x,j=0;
	t_jugada p[MAX_P]={0};
	printf("Jugadas posibles:");
	for (n=0;n<MAX;n++) {
		if (p_c[n].car=='J') {
			if(p_c[n+1].jug==i) { 
			printf("%d: %c  ", j+1, print_carta(n+1));
			p[j].val=n+1;	
			j++;
		}	if (p_c[n-1].jug==i) {
			printf("%d: %c  ", j+1, print_carta(n-1));
			p[j].val=n-1;	
			j++;
		} 	if (n==14|| n==24|| n==34 && p_c[n].jug==i) {
			printf("%d: %c  ", j+1, print_carta(n));
			p[j].val=n;
		}
	} 
	}
		scanf("%d", &x);
		return p[x].val;
}	
