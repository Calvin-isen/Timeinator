#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

void interrupt()//Gestion de l'interruption
{
	printf("Arrêt du réveil ...\n");
	exit(0);
}

int main (void)
{
	int h, min;
	int hr, minr;//heure du reveil
	int son;

	
	printf("Quelle son voulez vous mettre ?\n");
	printf("son1\n");
	printf("son2\n");
	printf("son3\n");
	printf("son4\n");
	printf("son5\n");
	printf("son6\n");
	printf("son7\n");
	printf("Entrer le numéro :");
	scanf("%d",&son);
	
	printf("Pour quel heure voulez vous programmer votre réveil ?\n");
	
	printf("hh:mm	:");
	scanf("%d:%d",&hr,&minr);
	if(minr<0)
	{
		minr=00;
	}
	
	system("clear");
	if(minr<10)
	{
		printf("Votre réveil sonnera à %d:0%d\n",hr,minr); 
	}
	else
	{
		printf("Votre réveil sonnera à %d:%d\n",hr,minr); 
	}
	
	
	           
 	
 	while(1)
 	{
 		time_t now;
 		time(&now);
 		struct tm *local = localtime(&now);
		h = local->tm_hour;        
		min = local->tm_min;
 		if(h==hr && min==minr)
 		{
 			switch(son)
 			{
				case 1:
					system("aplay SON/son1.wav");
					break;
					
				case 2:
					system("aplay SON/son2.wav");
					break;					
					
				case 3:
					system("aplay SON/son3.wav");
					break;
				
				case 4:
					system("aplay SON/son4.wav");
					break;
					
				case 5:
					system("aplay SON/son5.wav");
					break;
					
				case 6:
					system("aplay SON/son6.wav");
					break;
					
				case 7:
					system("aplay SON/son7.wav");
					break;				
			}
			break;
 			
		}
	}
 	
	return 0;
	
}
