#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
#include <wait.h>
#include <fcntl.h>
#include <string.h>


void endMonitoring();


int pid;
int var=0;
int i=0;

int main(void)
{
	signal(SIGINT,endMonitoring); //signal appuie 'Ctrl' + 'c'
	
	pid=fork();
	
	if(pid==0)
	{
		execl("/usr/bin/xterm","xterm","-hold","-e","htop",NULL); //ouverture sur un terminal xterm de la commande linux htop
	}
	
	while(var==0)
	{
		if(i==0) //Affichage sur le processus 
		{
			printf("Monitoring visible sur un autre terminal \n\n");
			printf("Appuyer sur 'Ctrl' + 'c' pour arreter le monitoring\n");
			i++;
		}
		
	}
	
	pause();
	exit(0);
	return 0;
}


void endMonitoring(int sig)
{
	system("clear");
	printf("fin monitoring\n");
	var++;
}
