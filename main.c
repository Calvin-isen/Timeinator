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
	int stats=0;
	stat tmpsExec[NBMAXPROC];
	
	char tempo[50];

	//Création/ouverture d'un pipe.
		int desc;
		char statsBuf[255];
		unlink(" pipe ");
		//mkfifo("pipe" ,7777);
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
			system("clear");
			printf("compteur pid=%d\n", cptPid);
			//Liste des choix possible
			printf("1) Reveil\n");
			printf("2) Reveil automatisé\n");
			printf("3) Chrono\n");
			printf("4) Statistique\n");
			printf("5) Monitoring\n");
			printf("6) Compte à rebours\n");
			printf("7) Eteindre Timeinator\n");

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

				case 2 : //reveil auto
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "Réveil automatisé");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement du réveil automatisé\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/reveil2", NULL);
						printf("%d\n", cptPid);
						
				}
				break;


				case 3 : //chrono
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

				case 4 : //statistiques
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

				case 5 : //monitoring
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "Monitoring");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement du monitoring\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/monitoring", NULL);
						printf("%d\n", cptPid);
						
				}
				break;

				case 6 : //compte a rebours
					cptPid+=1;	
					pid[cptPid]=fork();
					sprintf(tmpsExec[cptPid].nom, "Compte à rebours");
					tmpsExec[cptPid].temps=time(NULL);
					if(pid[cptPid] == 0) { 
						printf("Lancement du compte à rebours\n");
						execl("/usr/bin/xterm", "xterm","-hold","-e","/home/martin/Documents/Timeinator/compte_a_rebours", NULL);
						printf("%d\n", cptPid);
						
				}
				break;

				case 7 ://Fermeture du programme
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