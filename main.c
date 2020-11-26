#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main()
{
	int exec=1;
	int choix;

	printf("--- DEBUT ---\n");
	int pid = fork();
	
	if(pid == 0) //demarrage du process time_cpt qui compte le nm de sec depuis le lancement du programme.
	{
		
		//lancement du processus à partir d'un autre fichier
		char *args[] = {"main", NULL, NULL};
		execv("/home/martin/Documents/Timeinator/process_time_cpt",args);
		

	}else{ //Tache mère
		sleep(1); 

		while(exec){//boucle principal;

			//Liste des choix possible
			printf("1) Eteindre Timeinator\n");
			scanf("%d", &choix);


			switch (choix) {
				case 1 ://Fermeture du programme
					exec=0;
					break;
			}
		}

		kill(pid, SIGUSR1);//Tue process_time_cpt
		wait(NULL);//Attend la mort de tout les fils;
	}
	
	printf("--- FIN ---\n");
	return 0;
}