#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

void endChrono(int sig);
void waittemp(float millisec);
float sec = 0.0;
int min = 0;
int heure=0;
int nb = 0;

void interrupt()//Gestion de l'interruption
{
	printf("Fermerture du coucou ...\n");
	exit(0);
}

int main(void) {
   	 clock_t timer1, timer2;
   	 signal(SIGINT,endChrono);

 	timer1 = clock(); //temps initial
 	printf("Bienvenue dans la partie Chronomètre de votre réveil\n");
 	printf("Appuyez sur ''Entrée'' pour lancer et ''ctr+c'' stopper le Chronomètre\n");
 	getchar();
 	signal(SIGUSR1,interrupt);
   	 do
	{
		system("clear");  //efface screen

	    	timer2 = clock(); //Temps actuel d'execution
	    	sec = (float)((timer2-timer1)/CLOCKS_PER_SEC);

	    	if(sec<60)
		{

	    		printf("Chronomètre : %d:%d:%2.1f\n",heure, min, sec);  //affiche le chronomètre en temps réel
		}
		else 
		{
			timer1 = timer2;
			sec = 0.0;
			min++;

			if(min>=60)
			{
				heure++;
				min=0;
			}
		}

	    waittemp(1);

	}
	while(nb == 0);
 	pause();
    return 0;
}

void waittemp(float millisec) 
{
    clock_t arrivee=clock()+(millisec*CLOCKS_PER_SEC/10); // Attendre en 1ms

    while(clock()<arrivee);
}

void endChrono(int sig){
  system("clear");
  printf("Votre chrono est de : %dh:%dm:%2.1fs\n",heure, min, sec); //affiche la valeur finale du chrono une fois l'arret de l'utilisateur
  nb++;
}
