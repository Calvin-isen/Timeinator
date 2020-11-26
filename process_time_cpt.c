#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>

unsigned long int time_start;

void interrupt()
{
	printf("Enregistrement de temps d'execution\n");
	FILE* fichier = NULL;
	fichier = fopen("temps_exec.txt", "w+");
    fprintf(fichier, "Le programme a été exécuté %lds.\n", time_start-time(NULL));
    fclose(fichier);

	printf("Fermeture de time_cpt\n");
	exit(0);
}

int main(int argc, char* argv[])
{
	printf("Lancement de time_cpt\n");

	time_start=time(NULL);
	signal(SIGUSR1,interrupt); // On connecte le signa

	
	pause();
	
	return 0;
}