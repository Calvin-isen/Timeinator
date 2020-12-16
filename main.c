#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include<fcntl.h>
#define NBMAXPROC 15
#define NOM 15
int cptPid=0;

typedef struct{
	char nom[NOM];
	int temps;
}stat;

int main()
{
	int exec=1;
	int choix;
	pid_t pid[NBMAXPROC];
	int status = -1;
	char CMD[15];
	char spid[10];
	int stats=0;
	stat tmpsExec[NBMAXPROC];
	
	char tempo[50];

	//Création/ouverture d'un pipe.
		int desc,nb;
		char statsBuf[255];
		unlink(" pipe ");
		mkfifo("pipe" ,7777);
		//desc=open("pipe",O_WRONLY);
	//fin création/ouverture pipe
	
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
			printf("2) Chrono\n");
			printf("3) Eteindre Timeinator\n");
			printf("4) Eteindre Timeinator\n");

			scanf("%d", &choix);
			printf("\n");
			
			switch (choix) {
				case 1 : //reveil
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "Reveil");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement du reveil\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/reveil", NULL);
						printf("%d\n", cptPid);
						
					}
					break;

				case 2 : //chrono
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "Chrono");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement du chrono\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/chrono", NULL);
						printf("%d\n", cptPid);
						
				}
				break;

				case 3 : //chrono
					stats=1;
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "stats");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement des stats\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/stats", NULL);
						printf("%d\n", cptPid);
						
				}
				break;


				case 4 ://Fermeture du programme
					exec=0;
					break;

				default:
					choix=0;
					break;
			}
			if (stats==1)
			{
				statsBuf[0]='\0';
				for (int i = 1; i <= cptPid; ++i)
				{
					sprintf(tempo, "%d) %s est executer depuis %ld secondes\n", i, tmpsExec[i].nom, time(NULL)-tmpsExec[i].temps);
					strcat(statsBuf, tempo);
				}
				desc=open("pipe",O_WRONLY);
				write(desc, statsBuf,255);
				printf("Hello %s\n", statsBuf);
				close(desc);
			}
		}


		

		for (int i = 0; i <= cptPid; ++i)
		{
			kill(pid[i], SIGUSR1);//Tue process_time_cpt
		}
		wait(&status);
		printf("Message d'erreur : %d\n", status>>8);
	}
	
	printf("--- FIN ---\n");
	return 0;
}