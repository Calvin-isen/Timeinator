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

struct tm seco;
struct tm instant;

void endChrono();

int temps=0;

int s=0; //secondes
int m=0; //minutes
int h=0; //heures

int val=0;
int raz=0;


int ht1=0; //heure tour 1
int mt1=0; //minute tour 1
int st1=0; //seconde tour 1

int ht2=0; //heure tour 2
int mt2=0; //minute tour 2
int st2=0; //seconde tour 2

int ht3=0; //heure tour 3
int mt3=0; //minute tour 3
int st3=0; //seconde tour 3

int exitprg=0;
int indice_t=0;

int main(void)
{
    int fds[2]; //gestion E/S pipe
    
    pid_t pid;
    char var[5]; //chaine de caractère qui est envoyé au pipe
    char buf[5]; //chaine de caractère qui est recupèrée du pipe
    
    
    printf("Bienvenue sur le chronomètre de Timeinator\n\n");
	printf("Appuyer sur 'Entrer' pour lancer le chronomètre\n");
	
	getchar(); // Action 'Entree' de l'utilisateur permet de lancer le démarrage du chronomètre

    pipe(fds);

    pid = fork();
    
    
    /***Gestion de l'horloge *****/
    
    time_t secondes;
    time_t ser;
    time(&secondes);
    instant=*localtime(&secondes);
    temps=instant.tm_sec; //nombre de scondes écoulées depuis le dernier changement de minute
    
    /****************************/
    
    while(exitprg==0)
    {

		if ( pid )
		{
	
			while (indice_t<=3 )
			{
				scanf("%s",var);
				write( fds[1], var, sizeof(var)); //L'utilisateur doit saisir la commande 'a' ou 'z' en fonction de ce qu'il désire faire
				sleep(2);
			}
		}
		else
		{
			int retval = fcntl( fds[0], F_SETFL, fcntl(fds[0], F_GETFL) | O_NONBLOCK); //Pipe non bloquant 

			while (exitprg==0)
			{
				ssize_t r=read( fds[0], buf, 5 ); //Lecture du pipe
        
            /***** Lancement du temps ****/
				time(&ser);
				seco=*localtime(&ser);
				s=seco.tm_sec - temps;
			/****************************/
			
			
				if(s==0) //remise à zéro du temps réel sinon valeur négative qui décrémente, facilite le passage à la minute suivante
				{
					raz=0;
				}
				
				
				if(s<0) //le temps est basé sur le nombre de secondes écoulées depuis la dernière mintue au lancement du prg, cette condition permet de ne pas avoir de valeur négatives 
				{
					s=60+s;
				}
				
		
				if(val!=s) //Si une seconde est passée
				{
					system("clear");
					printf("Appuyez sur 'a' pour enregistrer 1 tour et 'z' pour arreter le chronomètre\n\n");
					printf("Temps: %d h: %d m: %d s\n\n", h,m,s);
				
					if(indice_t==1)
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1);
					}
				
					if(indice_t==2)
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1);
						printf("Tour 2: %d h: %d m: %d s\n", ht2,mt2,st2);
					}
				
					if(indice_t==3)
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1);
						printf("Tour 2: %d h: %d m: %d s\n", ht2,mt2,st2);
						printf("Tour 3: %d h: %d m: %d s\n\n", ht3,mt3,st3);
						printf("Vous ne pouvez plus faire de tours, appuyez sur 'z' pour stopper le chronomètre\n");
					}
					
				val=s; //Lorsque que la valeur de la seconde change, la valeur de val prend sa valeur aussi
				
				}
				
		
				if(s==59 && raz==0)
				{
					m++;
					s=0;
					raz=1;
				}
			
			
			
				if(buf[0]=='a') //saisie de la lettre 'a' puis 'Entree' de l'utilisateur --> Enregistrement d'un tour
				{
			
					if(indice_t==0) //tour 1
					{ 
						ht1=h;
						mt1=m;
						st1=s;
						memset(buf,0,sizeof(buf));
					}
		
					if(indice_t==1) //tour 2
					{
						ht2=h;
						mt2=m;
						st2=s;
						memset(buf,0,sizeof(buf));
					}
					if(indice_t==2) //tour 3
					{
						ht3=h;
						mt3=m;
						st3=s;
						memset(buf,0,sizeof(buf));
					}
					
				indice_t++; //variable qui s'incrémente dès que l'utilisateur réalise cette action
				
				}
				
				
				
				if(buf[0]=='z') //saisie de la lettre 'z' au clavier puis 'Entree' de l'utilisateur --> Arret du chronomètre
				{
					system("clear");
					
					printf("Chrono final : %dh : %dm : %d s\n",h,m,s); //Affichage de la valeur finale du chronomètre
					
					if(indice_t==1) //Affiche tour 1 si l'utilisateur n'a appuyé qu'une seule fois sur 'a'
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1); 
					}
					
					if(indice_t==2) //Affiche tour 1 et tour 2 si l'utilisateur a appuyé 2 fois sur 'a'
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1);
						printf("Tour 2: %d h: %d m: %d s\n", ht2,mt2,st2);
					}
					if(indice_t==3) //Affiche les 3 tours enregistrés par l'utlisateur
					{
						printf("Tour 1: %d h: %d m: %d s\n", ht1,mt1,st1);
						printf("Tour 2: %d h: %d m: %d s\n", ht2,mt2,st2);
						printf("Tour 3: %d h: %d m: %d s\n", ht3,mt3,st3);
					}
					
				exitprg++; //variable qui s'incrémente et qui permet de sortir de la boucle while
				
				}
				
			}
			
		}
		
	}
	
	printf("fin chronomètre\n");

    exit(0);
    return 0;
}
