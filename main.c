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
	
	if(pid == 0) // Tache fille
	{
		
		char *args[] = {"main", NULL, NULL};
		execv("/home/martin/Documents/Timeinator/process_time_cpt",args);
		
	}else{ // Tache mère
		sleep(2);
		while(exec){
			printf("1) Eteindre Timeinator\n");
			scanf("&d", &choix);
			switch (choix) {
				case 1 :
					exec=0;
					break;
			}
		}

		kill(pid, SIGUSR1);
		wait(NULL);
	}
	
	printf("--- FIN ---\n");
	return 0;
}