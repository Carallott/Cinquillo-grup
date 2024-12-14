<stdio.h>


int pregunta_si_no(char pregunta){
  char pregunta;
  scanf("%c", &pregunta);
  if(pregunta == 's' || pregunta == 'S'){
      return 1;
  }
  else{
      return 0;

