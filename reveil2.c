#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <signal.h>

#include <time.h>

#include <sys/types.h>

#include <sys/wait.h>

#include <wait.h>



#define FICHIER_SAVE "ReveilMatin.txt"

void enregistre(FILE *file, int heure, int minute,int son);

void affiche(int heure, int minute, int son);



int main (void)

{

	int h, min;

	int hr=-1, minr=-1;//heure du reveil

	int son;

	int choix;

	FILE *file;

	

	file=fopen(FICHIER_SAVE,"r+");

	

	if(file==NULL)

	{

		file=fopen(FICHIER_SAVE,"w+");

		

		while((son<1 || son>7))

		{

			system("clear");

			printf("Quelle son voulez vous mettre ?\n");

			printf("1) son1\n");

			printf("2) son2\n");

			printf("3) son3\n");

			printf("4) music enfant\n");

			printf("5) bande organis√©e - Jul, SCH, Naps, ...\n");

			printf("6) mamie - PLK\n");

			printf("7) jump - Van Halen\n");

			printf("Entrer le num√©ro :");

			scanf("%d",&son);

		}

	

		

		while((hr<0 || hr>23) || (minr<0 || minr>59))

		{

			system("clear");

			printf("Pour quelle heure voulez vous programmer votre r√©veil ?\n");

			printf("hh:mm	:");

			scanf("%d:%d",&hr,&minr);

		}

		

		enregistre(file,hr,minr,son);

		

		fclose(file);

	}

	else

	{

		fscanf(file,"%d:%d %d",&hr,&minr,&son);

		

		affiche(hr,minr,son);

		

		printf("Voulez-vous changer l'heure ?\n");

		printf("1) Oui\n2) Non\n");

		scanf("%d",&choix);

		

		if(choix==1)

		{

			hr=-1;minr=-1;son=0;

			fclose(file);

			file=fopen(FICHIER_SAVE,"w+");

		

			while((son<1 || son>7))

			{

				system("clear");

				printf("Quelle son voulez vous mettre ?\n");

				printf("1) son1\n");

				printf("2) son2\n");

				printf("3) son3\n");

				printf("4) music enfant\n");

				printf("5) bande organisee - Jul, SCH, Naps, ...\n");

				printf("6) mamie - PLK\n");

				printf("7) jump - Van Halen\n");

				printf("Entrer le num√©ro :");

				scanf("%d",&son);

			}

		

			

			while((hr<0 || hr>23) || (minr<0 || minr>59))

			{

				system("clear");

				printf("Pour quelle heure voulez vous programmer votre rÈveil ?\n");

				printf("hh:mm	:");

				scanf("%d:%d",&hr,&minr);

			}

			

			enregistre(file,hr,minr,son);

			fclose(file);

			affiche(hr,minr,son);

			

		}

				

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







void enregistre(FILE *file, int heure, int minute, int son)

{	

	system("clear");

	if(heure<10 && minute<10)

	{

		fprintf(file,"0%d:0%d %d\n",heure,minute,son); 

		

	}

	else if(heure<10)

	{

		fprintf(file,"0%d:%d %d\n",heure,minute,son); 

	}

	else if(minute<10)

	{

		fprintf(file,"%d:0%d %d\n",heure,minute,son); 

	}

	else

	{

		fprintf(file,"%d:%d %d\n",heure,minute,son); 

	}

}



void affiche(int heure, int minute, int son)

{

	if(heure<10 && minute<10)

	{

		printf("Votre rÈveil sonnera ‡ 0%d:0%d avec le son n∞%d\n",heure,minute,son); 

		

	}

	else if(heure<10)

	{

		printf("Votre rÈveil sonnera ‡ 0%d:%d avec le son n∞%d\n",heure,minute,son); 

	}

	else if(minute<10)

	{

		printf("Votre rÈveil sonnera ‡ %d:0%d avec le son n∞%d\n",heure,minute,son); 

	}

	else

	{

		printf("Votre rÈveil sonnera ‡ %d:%d avec le son n∞%d\n",heure,minute,son); 

	}

}




