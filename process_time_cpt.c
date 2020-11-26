#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

unsigned long int time_start;

void interrupt()//Gestion de l'interruption
{
	printf("Enregistrement de temps d'execution\n");

	//enregistrement du temps d'exectution dans un fichier texte temps_exec.txt
	FILE* fichier = NULL;
	fichier = fopen("temps_exec.txt", "w+");
    fprintf(fichier, "Le programme a été exécuté %lds.\n", time(NULL)-time_start); //on enregistre la différence entre le temps actuelle d'execution et le temps au lancement du programme
    fclose(fichier);

    //fermeture du process time_cpt
	printf("Fermeture de time_cpt\n");
	exit(0);
}

int main(int argc, char* argv[])
{
	printf("Lancement de time_cpt\n");

	time_start=time(NULL);//Enregistre le temps au début du programme
	signal(SIGUSR1,interrupt); //on lance interrupt() quant on reçois SIGUSR1

	
	pause();
	
	return 0;
}