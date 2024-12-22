# Cinquillo-grup

És el joc del cinquillo, aquesta carpeta està dividida en:

.
├── azar.c   
├── azar.h      // Arxiu donat pel professor. Dona un número al atzar.
├── baraja.c 
├── baraja.h    // S'emcarrega de les funcions relacionades a la baralla.
├── carta.c
├── carta.h     // S'encarrega de les funcions relacionades a la carta.
├── colores.c
├── colores.h   // Arxiu donat pel professor. Dona els colors dels prints.
├── duerme.c
├── duerme.h    // Arxiu donat pel professor. Dona el temps de rest entre jugades.
├── jugador.c
├── jugador.h   // S'emcarrega de les funcions relacionades al jugador.
├── jugadores.h // Inicialitza la llista de jugadors.
├── mano.c   
├── mano.h      // S'emcarrega de les funcions relacionades a la mà del jugador.
├── mantel.c   
├── mantel.h    // S'emcarrega de les funcions relacionades a la gestió del mantell.
├── partida.c   
├── partida.h   // Main de la ejecució.
├── preguntar.c   
├── preguntar.h // S'emcarrega de fer les preguntes.
├── repartir.c   
├── repartir.h  // S'emcarrega de les funcions relacionades a la repartició de les cartes.
 
Per a compilar el codi:
gcc partida.c preguntar.c baraja.c mantel.c mano.c jugador.c carta.c colores.c azar.c repartir.c duerme.c -o partida

Per a ejecutar el cocdi:
./partida
