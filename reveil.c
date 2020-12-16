#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <wait.h>



void interrupt(int sig)//Gestion de l'interruption
{
	system("clear");
	printf("Arrêt du réveil ...\n");
	
}

int main (void)
{
	int h, min;
	int hr=-1, minr=-1;//heure du reveil
	int son;
	
	
	while((son<1 || son>7))
	{
		system("clear");
		printf("Quelle son voulez vous mettre ?\n");
		printf("1) son1\n");
		printf("2) son2\n");
		printf("3) son3\n");
		printf("4) music enfant\n");
		printf("5) bande organisée - Jul, SCH, Naps, ...\n");
		printf("6) mamie - PLK\n");
		printf("7) jump - Van Halen\n");
		printf("Entrer le numéro :");
		scanf("%d",&son);
	}

	
	while((hr<0 || hr>23) || (minr<0 || minr>59))
	{
		system("clear");
		printf("Pour quelle heure voulez vous programmer votre réveil ?\n");
		printf("hh:mm	:");
		scanf("%d:%d",&hr,&minr);
	}
	
	
	system("clear");
	if(hr<10 && minr<10)
	{
		printf("Votre réveil sonnera à 0%d:0%d avec le son n°%d\n",hr,minr,son); 
		
	}
	else if(hr<10)
	{
		printf("Votre réveil sonnera à 0%d:%d avec le son n°%d\n",hr,minr,son); 
	}
	else if(minr<10)
	{
		printf("Votre réveil sonnera à %d:0%d avec le son n°%d\n",hr,minr,son); 
	}
	else
	{
		printf("Votre réveil sonnera à %d:%d avec le son n°%d\n",hr,minr,son); 
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
					system("cvlc --loop SON/son1.wav");
					break;
					
				case 2:
					system("cvlc --loop SON/son2.wav");
					break;					
					
				case 3:
					system("cvlc --loop SON/son3.wav");
					break;
				
				case 4:
					system("cvlc --loop SON/music-enfant.wav");
					break;
					
				case 5:
					system("cvlc --loop SON/bande-organisee.wav");
					break;
					
				case 6:
					system("cvlc --loop SON/mamie.wav");
					break;
					
				case 7:
					system("cvlc --loop SON/jump.wav");
					break;				
			}
			break;
 			
		}
	}
	return 0;
	
}
