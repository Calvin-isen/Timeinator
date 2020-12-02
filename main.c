#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>

#define NBMAXPROC 15

int cptPid=0;

int main()
{
	int exec=1;
	int choix;
	pid_t pid[NBMAXPROC];
	
	char CMD[15];
	char spid[10];

	printf("--- DEBUT ---\n");
	pid[0] = fork();
	if(pid[0] == 0) //demarrage du process time_cpt qui compte le nb de sec depuis le lancement du programme.
	{
		
		//lancement du processus à partir d'un autre fichier
		char *args[] = {"main", NULL, NULL};
		execv("/home/martin/Documents/Timeinator/process_time_cpt",args);
		

	}else{ //Tache mère
		sleep(1); 

		while(exec){//boucle principal;
			printf("compteur pid=%d\n", cptPid);
			//Liste des choix possible
			printf("1) Reveil\n");
			printf("3) Eteindre Timeinator\n");

			scanf("%d", &choix);
			printf("\n");

			switch (choix) {
				case 1 : //reveil
					cptPid+=1;	
					pid[cptPid]=fork();

					if(pid[cptPid] == 0) { 
						printf("Mon pid est %d\n", getpid());
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/coucou", NULL);
						printf("%d\n", cptPid);
						
					}
					break;

				case 3 ://Fermeture du programme
					exec=0;
					break;

				default:
					choix=0;
					break;
			}
		}


		

		for (int i = 0; i <= cptPid; ++i)
		{
			kill(pid[i], SIGUSR1);//Tue process_time_cpt
		}
		wait(NULL);//Attend la mort de tout les fils;
	}
	
	printf("--- FIN ---\n");
	return 0;
}